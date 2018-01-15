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

#include "EventMaterials.h"

namespace  Journal {
    EventMaterials::EventMaterials(const QJsonObject &obj, const JournalFile *file)
        : Event(obj, file, Materials) {
        _raw = std::move(Materials::materials(obj.value(Key::Raw)));
        _encoded = std::move(Materials::materials(obj.value(Key::Encoded)));
        _manufactured= std::move(Materials::materials(obj.value(Key::Manufactured)));
    }

    const QList<Material> &EventMaterials::raw() const {
        return _raw;
    }

    const QList<Material> &EventMaterials::encoded() const {
        return _encoded;
    }

    const QList<Material> &EventMaterials::manufactured() const {
        return _manufactured;
    }
}
