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
//

#include <src/JFile.h>
#include "EventLoadGame.h"
#include "Event.h"

namespace  Journal {
    EventLoadGame::EventLoadGame(const QJsonObject &obj, const JFile *file)
        : Event(obj, file, LoadGame),
          _commander(string(Key::Commander)),
          _ship(string(Key::Ship)),
          _shipID(integer(Key::ShipID)),
          _shipName(string(Key::ShipName)),
          _shipIdent(string(Key::ShipIdent)),
          _fuelLevel(doubleValue(Key::FuelLevel)),
          _fuelCapacity(doubleValue(Key::FuelCapacity)),
          _gameMode(string(Key::GameMode)),
          _credits(integer(Key::Credits)),
          _loan(integer(Key::Loan))
    {

    }

    const QString &EventLoadGame::commander() const {
        return _commander;
    }

    const QString &EventLoadGame::ship() const {
        return _ship;
    }

    int64_t EventLoadGame::shipID() const {
        return _shipID;
    }

    const QString &EventLoadGame::shipName() const {
        return _shipName;
    }

    const QString &EventLoadGame::shipIdent() const {
        return _shipIdent;
    }

    double EventLoadGame::fuelLevel() const {
        return _fuelLevel;
    }

    double EventLoadGame::fuelCapacity() const {
        return _fuelCapacity;
    }

    const QString &EventLoadGame::gameMode() const {
        return _gameMode;
    }

    int64_t EventLoadGame::credits() const {
        return _credits;
    }

    int64_t EventLoadGame::loan() const {
        return _loan;
    }
}
