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

#include "EventRank.h"

namespace Journal {
    EventRank::EventRank(const QJsonObject &obj, const JFile *file)
        : Event(obj, file, Rank) {
        for(auto &key: obj.keys()) {
            auto value = obj[key];
            if(!value.isDouble()) {
                continue;
            }
            RankProgress::Type type = RankProgress::typeFromString(key);
            if(type != RankProgress::Unknown) {
                auto charval = static_cast<uint8_t>(value.toDouble(0));
                if(charval >= RankProgress::Rank0 && charval <= RankProgress::Rank8) {
                    _ranks[type] = RankProgress(type, static_cast<RankProgress::Rank>(charval));
                }
            }
        }
    }

    const QMap<RankProgress::Type, RankProgress> &EventRank::ranks() const {
        return _ranks;
    }

    RankProgress EventRank::rankFor(RankProgress::Type type) const {
        return _ranks[type];
    }
}

#pragma once
