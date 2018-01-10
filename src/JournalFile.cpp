//
//  Copyright (C) 2018-  David Hedbor <neotron@gmail.com>
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
#include <QJsonArray>
#include <QDebug>
#include "JournalFile.h"
namespace Journal {
    JournalFile::~JournalFile() {
        stopWatching();
        _file.close();
    }

    JournalFile::JournalFile(const QString &path)
        : QObject(), _path(path), _file(path), _timer(nullptr), _beta(false) {
        if(!_file.open(QIODevice::ReadOnly)) {
            qDebug() << "Couldn't open file for reading.";
            return;
        }
    }

    void JournalFile::parse() {
        while(!_file.atEnd()) {
            auto lineBytes = _file.readLine();
            if(lineBytes.isEmpty()) {
                continue;
            }
            auto doc = QJsonDocument::fromJson(lineBytes);
            if(doc.isEmpty() || !doc.isObject()) {
                continue;
            }
            auto event = Event::eventFromDocument(doc);
            if(event) {
                handleEvent(event);
            }
        }
    }

    void JournalFile::startWatching() {
        if(!_timer) {
            _timer = new QTimer(this);
            connect(_timer, SIGNAL(timeout()), this, SLOT(parse()));
            _timer->start(1000);
        }
    }

    void JournalFile::stopWatching() {
        delete _timer;
        _timer = nullptr;
    }

    void JournalFile::handleEvent(EventPtr event) {
        switch(event->type()) {
        case Event::LoadGame:
            _commander = event->string("Commander");
            break;
        case Event::ApproachSettlement:
            _settlement = event->string("Name");
            break;
        case Event::SupercruiseEntry:
            // Reset body
            _body = "";
            break;
        case Event::SupercruiseExit:
            _body = event->string("Body");
            // intentional Fallthrough
        case Event::Location:
        case Event::FSDJump:
            _system = event->string("StarSystem");
            break;
        case Event::FileHeader:
            _beta = event->string("gameversion").contains("beta", Qt::CaseInsensitive);
        default:
            // Ignore
            break;
        emit onEvent(*this, event);
    }
        }
}

