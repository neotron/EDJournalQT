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

#include "Event.h"
#include "EventScan.h"
#include "EventTable.h"
#include <QDebug>

namespace Journal {


    EventPtr Event::eventFromDocument(const QJsonDocument &document) {

        if(!document.isObject()) {
            return EventPtr();
        }

        auto obj = document.object();
        auto event = obj.value("event").toString().toLower();

        auto eventType = s_eventLookupMap.contains(event) ? s_eventLookupMap[event] : Unknown;

        if(eventType == Unknown) {
            qDebug() << "Unknown event" << event;
        }
        switch(eventType) {
            case Scan:
                return std::make_shared<EventScan>(obj);
            default:
                return std::make_shared<Event>(obj, eventType);
        }
    }

#define FLOAT(OBJ, VAL) do { if((OBJ).isDouble()) { success &= true;  VAL = static_cast<float>((OBJ).toDouble()); } else { success = false; }} while(false)

    QVector3D Event::position() const {
        auto value = _obj.value("StarPos");
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

    int Event::integer(const QString &key) const {
        auto value = _obj.value(key);
        return (int) (value.isDouble() ? value.toDouble() : 0);
    }

    QString Event::string(const QString &key) const {
        auto value = _obj.value(key);
        return value.isString() ? value.toString() : QString();
    }

    QJsonArray Event::array(const QString &key) const {
        auto value = _obj.value(key);
        return value.toArray();
    }

    Event::Type Event::type() const {
        return _eventType;
    }

    QDateTime Event::timestamp() const {
        return date("timestamp");
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

    Event::Event(const QJsonObject &obj, Type type)
        : QObject(), _eventType(type), _obj(obj) {}

    const EventScan *Event::scan() const {
        qDebug() << typeid(this).name();
        return dynamic_cast<const EventScan*>(this);
    }
}
