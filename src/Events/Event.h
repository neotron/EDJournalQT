//
//  Copyright (C) 2016-2017  David Hedbor <neotron@gmail.com>
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

#pragma once

#include <QObject>
#include <QJsonObject>
#include <QMap>
#include <QDateTime>
#include <QVector3D>
#include <QJsonArray>
#include <QEvent>
#include <memory>
#include "Key.h"

namespace Journal {
#include "eventclasses.inc"
    class JFile;

    class Event : public QEvent {
    public:
        enum JournalEvent {
            Unknown = QEvent::User+1000,
#define EVENT(X) X,
#include "events.inc"
#undef EVENT
            NumEvents
        };

        Event(const QJsonObject &obj, const JFile *file, JournalEvent event);

        ~Event() override = default;

        static Event *eventFromDocument(QJsonDocument &document, Journal::JFile *pFile);

        QDateTime timestamp() const;

        JournalEvent journalEvent() const;

        QString string(const QString &key) const;

        int64_t integer(const QString &key) const;

        bool boolean(const QString &key) const;

        double doubleValue(const QString &key) const;

        QDateTime date(const QString &key) const;

        const QJsonObject &obj() const;

        QVector3D position() const;

        QJsonArray array(const QString &key) const;

        bool isValid() const { return journalEvent() != Unknown; }

        const JFile *file() const;

    private:
        static QMap<QString, JournalEvent> s_eventLookupMap;

        const JFile *_file;
        QJsonObject _obj;

    };
}


