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
#include <QApplication>
#include "JFile.h"
#include "Events.h"

namespace Journal {
    JFile::~JFile() {
        stopWatching();
        _file.close();
    }

    JFile::JFile(const QString &path)
        : QObject(), _path(path), _file(path), _timer(nullptr), _beta(false) {
        if(!_file.open(QIODevice::ReadOnly)) {
            qDebug() << "Couldn't open file for reading.";
            return;
        }
    }

    void JFile::parse() {
        while(!_file.atEnd()) {
            auto lineBytes = _file.readLine();
            if(lineBytes.isEmpty()) {
                continue;
            }
            auto doc = QJsonDocument::fromJson(lineBytes);
            if(doc.isEmpty() || !doc.isObject()) {
                continue;
            }
            auto event = Event::eventFromDocument(doc, this);
            if(event) {
                handleEvent(event);
            }
        }
    }

    void JFile::startWatching() {
        if(!_timer) {
            _timer = new QTimer(this);
            connect(_timer, SIGNAL(timeout()), this, SLOT(parse()));
            _timer->start(1000);
        }
    }

    void JFile::stopWatching() {
        delete _timer;
        _timer = nullptr;
    }

    void JFile::handleEvent(Event *event) {
        switch(event->journalEvent()) {
            case Event::Materials:
                // This event happens before load game so need to keep it here;
                _materials += dynamic_cast<EventMaterials*>(event)->manufactured();
                _materials += dynamic_cast<EventMaterials*>(event)->raw();
                _materials += dynamic_cast<EventMaterials*>(event)->encoded();
                break;
            case Event::LoadGame:
                _commander = dynamic_cast<EventLoadGame*>(event)->commander();
                break;
            case Event::ApproachSettlement:
                _settlement = event->string(Key::Name);
                break;
            case Event::SupercruiseEntry:
                // Reset body
                _body = "";
                break;
            case Event::SupercruiseExit:
                _body = event->string(Key::Body);
                // intentional Fallthrough
            case Event::Location:
            case Event::FSDJump:
                _system = event->string(Key::StarSystem);
                break;
            case Event::FileHeader:
                _beta = event->string(Key::gameversion).contains("beta", Qt::CaseInsensitive);
            default:
                // Ignore
                break;
        }
        postEvent(event);
    }

    void JFile::postEvent(Event *event) {
        for(auto h: _eventHandlers) {
            QApplication::sendEvent(h, event);
        }
    }

    void JFile::deregisterHandler(QObject *handler) {
        _eventHandlers.remove(handler);
        qDebug() << "Deregistering handler" << handler << "for file"<<_path;
    }

    void JFile::registerHandler(QObject *handler) {
        _eventHandlers.insert(handler);
        connect(handler, &QObject::destroyed, this, &JFile::deregisterHandler);
        qDebug() << "Registering handler" << handler << "for file"<<_path;
    }

    const QList<Material> &JFile::materials() const {
        return _materials;
    }

    bool JFile::beta() const {
        return _beta;
    }

    const QString &JFile::commander() const {
        return _commander;
    }
}

