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

#include "EventMaterialCollected.h"
#include "Events/Key.h"

namespace Journal {

    EventMaterialCollected::EventMaterialCollected(const QJsonObject &obj, const JournalFile *file)
        : EventMaterialChanged(obj, file, MaterialCollected) {
    }

    EventMaterialDiscarded::EventMaterialDiscarded(const QJsonObject &obj, const JournalFile *file)
        : EventMaterialChanged(obj, file, MaterialDiscarded) {
    }

    EventMaterialChanged::EventMaterialChanged(const QJsonObject &obj, const JournalFile *file, JournalEvent event)
        : Event(obj, file, event), MaterialsChanged(obj) {
        auto change = static_cast<int16_t>(integer(Key::Count));
        switch(event) {
            case MaterialCollected:
                _materials.first().setQuantity(change);
                break;
            case MaterialDiscarded:
                _materials.first().setQuantity(-change);
                break;
            default:
                break; // no-op
        }
    }

    const Material &EventMaterialChanged::material() const {
        return _materials.first();
    }
}

