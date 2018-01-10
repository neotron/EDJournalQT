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
#include <QFile>
#include <QSet>
#include <QTimer>
#include "Events/Event.h"

namespace Journal {

    class JournalFile : public QObject {
    Q_OBJECT

    public:
        explicit JournalFile(const QString &path);

        ~JournalFile() override;

        void startWatching();

        void stopWatching();


        const QString commander() const {
            QString commander(_commander);
            if(_beta) {
                commander += " (beta)";
            }
            return commander;
        }

        const QString &system() const {
            return _system;
        }

        const QString &body() const {
            return _body;
        }

        const QString &settlement() const {
            return _settlement;
        }

    public slots:
        void parse();

    signals:
        void onEvent(const JournalFile &journal, EventPtr event);

    private:
        void handleEvent(EventPtr event);


        QString _commander;
        QString _path;
        QFile _file;
        QString _system;
        QString _body;
        QString _settlement;
        QTimer *_timer;
        bool _beta;
    };
}
