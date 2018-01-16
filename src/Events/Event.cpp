//
//  Copyright (C) 2016  David Hedbor <neotron@gmail.com>
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>
#include <QJsonArray>
#include <QDebug>
#include <src/JournalFile.h>

#include "Events.h"
#include "EventTable.h"

namespace Journal {

    Event *Event::eventFromDocument(QJsonDocument &document, Journal::JournalFile *file) {

        if(!document.isObject()) {
            return nullptr;
        }

        auto obj = document.object();
        auto event = obj.value(Key::event).toString().toLower();

        auto eventType = s_eventLookupMap.contains(event) ? s_eventLookupMap[event] : Unknown;

        if(eventType == Unknown) {
            qDebug() << "Unknown event" << event;
        }
        switch(eventType) {
#define EVENT(EV) case EV: return new Event##EV(obj, file);
#include "events.inc"
#undef EVENT
            default:
                return new Event(obj, file, eventType);
        }
    }

#define FLOAT(OBJ, VAL) do { if((OBJ).isDouble()) { success &= true;  (VAL) = static_cast<float>((OBJ).toDouble()); } else { success = false; }} while(false)


    QVector3D Event::position() const {
        auto value = _obj.value(Key::StarPos);
        if(value.isArray()) {
            auto array = value.toArray();
            if(array.size() == 3) {
                bool success = true;
                float x = 0, y = 0, z = 0;
                FLOAT(array[0], x);
                FLOAT(array[1], x);
                FLOAT(array[2], z);
                if(success) {
                    return { x, y, z };
                }
            }
        }
        return {};
    }

#undef FLOAT

    QDateTime Event::date(const QString &key) const {
        return QDateTime::fromString(string(key), Qt::ISODate);
    }

    int64_t Event::integer(const QString &key) const {
        auto value = _obj.value(key);
        return static_cast<int64_t>(value.isDouble() ? value.toDouble() : 0);
    }

    QString Event::string(const QString &key) const {
        auto value = _obj.value(key);
        return value.isString() ? value.toString() : QString();
    }

    QJsonArray Event::array(const QString &key) const {
        auto value = _obj.value(key);
        return value.toArray();
    }


    QDateTime Event::timestamp() const {
        return date(Key::timestamp);
    }

    const QJsonObject &Event::obj() const {
        return _obj;
    }

    double Event::doubleValue(const QString &key) const {
        auto value = _obj.value(key);
        return value.isDouble() ? value.toDouble() : 0.0;
    }

    bool Event::boolean(const QString &key) const {
        auto value = _obj.value(key);
        return value.isBool() ? value.toBool() : false;
    }

    Event::Event(const QJsonObject &obj, const JournalFile *file, JournalEvent event)
        : QEvent(static_cast<QEvent::Type>(event)), _file(file), _obj(obj) {
    }

    Event::JournalEvent Event::journalEvent() const {
        auto type = QEvent::type();
        if(type >= Unknown && type < NumEvents){
            return static_cast<JournalEvent>(type);
        }
        return Unknown;
    }

    const JournalFile *Event::file() const {
        return _file;
    }
}

