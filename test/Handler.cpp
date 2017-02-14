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

#include "Handler.h"
void Handler::handleEvent(const JournalFile &journal, const Event &event ) {
    if(journal.commander() == "NeoTron") {
        switch(event.eventType()) {
            case EventTypeMissionAbandoned:
            case EventTypeMissionCompleted:
            case EventTypeMissionFailed:
                _missions.remove(event.integer("MissionID"));
                qDebug() << "Active mission count: " << _missions.count();
                break;
            case EventTypeMissionAccepted:
                _missions.insert(event.integer("MissionID"));
                qDebug() << "Active mission count: " << _missions.count();
                break;

            default:
                break;
        }
    }
}

Handler::Handler(QObject *parent) : QObject(parent), _missions() {
    QDirIterator it("/Users/neotron/Elite Dangerous/");
    while(it.hasNext()) {
        auto file = it.next();
        qDebug() << "Parsing file" << file;
        JournalFile journalFile(file);
        connect(&journalFile, SIGNAL(onEvent(const JournalFile &, const Event &)), this, SLOT(handleEvent(const JournalFile &, const Event &)));
        journalFile.parse();
    }
}
