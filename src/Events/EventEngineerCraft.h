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
#include "EventExtensions.h"
namespace Journal {
    class EventEngineerCraft : public Event, public Extension::MaterialsChanged {
    public:
        EventEngineerCraft(const QJsonObject &obj, const JFile *file);

        const QString &engineer() const;

        const QString &blueprint() const;

        uint8_t level() const;

        const QList<Material> &ingredients() const;

    private:
        QString _engineer;
        QString _blueprint;
        uint8_t _level;
    };
}

