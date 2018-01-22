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

#include "EventSellDrones.h"

namespace Journal {
    EventSellDrones::EventSellDrones(const QJsonObject &obj, const JFile *file)
        : Event(obj, file, SellDrones),
          CommodityExchange(obj.value(Key::Type).toString(),
                            obj.value(Key::SellPrice).toInt(),
                            static_cast<int16_t>(obj.value(Key::Count).toInt())) {
    }
}

