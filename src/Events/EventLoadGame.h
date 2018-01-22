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


#pragma once

#include "Event.h"

namespace Journal {
    class EventLoadGame: public Event {
    public:
        explicit EventLoadGame(const QJsonObject &obj, const JFile *file);

        const QString &commander() const;

        const QString &ship() const;

        int64_t shipID() const;

        const QString &shipName() const;

        const QString &shipIdent() const;

        double fuelLevel() const;

        double fuelCapacity() const;

        const QString &gameMode() const;

        int64_t credits() const;

        int64_t loan() const;

    private:
        QString _commander;
        QString _ship;
        int64_t _shipID;
        QString _shipName;
        QString _shipIdent;
        double _fuelLevel;
        double _fuelCapacity;
        QString _gameMode;
        int64_t _credits;
        int64_t _loan;

    };
}

