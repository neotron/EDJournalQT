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

#include "EventEngineerCraft.h"

namespace Journal {
    EventEngineerCraft::EventEngineerCraft(const QJsonObject &obj, const JFile *file)
        : Event(obj, file, EngineerCraft),
          MaterialsChanged(obj.value(Key::Ingredients)),
          _engineer(obj.value(Key::Engineer).toString()),
          _blueprint(obj.value(Key::Blueprint).toString()),
          _level(static_cast<uint8_t>(obj.value(Key::Level).toInt()))
    {
    }

    const QString &EventEngineerCraft::engineer() const {
        return _engineer;
    }

    const QString &EventEngineerCraft::blueprint() const {
        return _blueprint;
    }

    uint8_t EventEngineerCraft::level() const {
        return _level;
    }

    const QList<Material> &EventEngineerCraft::ingredients() const {
        return materials();
    }
}

#pragma once
