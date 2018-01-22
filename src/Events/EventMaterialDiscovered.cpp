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

#include "EventMaterialDiscovered.h"

namespace Journal {
    EventMaterialDiscovered::EventMaterialDiscovered(const QJsonObject &obj, const JFile *file)
        : Event(obj, file, MaterialDiscovered),
          _material(Materials::material(obj.value(Key::Name))),
          _discoveryNumber(obj.value(Key::DiscoveryNumber).toInt(0)) {

    }

    const Material &EventMaterialDiscovered::material() const {
        return _material;
    }

    int EventMaterialDiscovered::discoveryNumber() const {
        return _discoveryNumber;
    }
}

