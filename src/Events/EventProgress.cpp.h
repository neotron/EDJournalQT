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

#include "EventProgress.h"

namespace Journal {
    EventProgress::EventProgress(const QJsonObject &obj, const JFile *file)
        : Event(obj, file, Progress) {
        for(auto &key: obj.keys()) {
            auto value = obj[key];
            if(!value.isDouble()) {
                continue;
            }
            RankProgress::Type type = RankProgress::typeFromString(key);
            if(type != RankProgress::Unknown) {
                _progress[type] = RankProgress(type, static_cast<uint8_t>(value.toDouble(0)));
            }
        }
    }

    const QMap<RankProgress::Type, RankProgress> &EventProgress::progress() const {
        return _progress;
    }

    RankProgress EventProgress::progressFor(RankProgress::Type type) const {
        return _progress[type];
    }
}

#pragma once
