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
#include <QJsonArray>
#include <QDebug>
#include "JournalFile.h"

JournalFile::~JournalFile() {
    stopWatching();
    _file.close();
}

JournalFile::JournalFile(const QString &path) : QObject(), _path(path), _file(path), _timer(nullptr) {
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
        if(event.isValid()) {
            handleEvent(event);
        }
    }
}

void JournalFile::startWatching() {
#ifdef Q_OS_OSX
    // OS X doesn't have working file monitoring! At least not for Elite.
    if(!_timer) {
        _timer = new QTimer(this);
        connect(_timer, SIGNAL(timeout()), this, SLOT(parse()));
        _timer->start(1000);
    }
#endif
}

void JournalFile::stopWatching() {
    delete _timer;
    _timer = nullptr;
}

void JournalFile::handleEvent(const Event &event) {
    switch(event.type()) {
        case EventTypeLoadGame:
            _commander = event.string("Commander");
            break;
        case EventTypeApproachSettlement:
            _settlement = event.string("Name");
            break;
        case EventTypeSupercruiseEntry:
            // Reset body
            _body = "";
            break;
        case EventTypeSupercruiseExit:
            _body   = event.string("Body");
            // intentional Fallthrough
        case EventTypeLocation:
        case EventTypeFSDJump:
            _system = event.string("StarSystem");
            break;
        default:
            // Ignore
            break;
    }
    emit onEvent(*this, event);
}


