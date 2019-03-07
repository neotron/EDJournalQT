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
/*
{
  "timestamp": "2019-01-19T22:35:46Z",
  "event": "SAAScanComplete",
  "BodyName": "Omega Sector IR-W d1-181 3",
  "BodyID": 4,
  "ProbesUsed": 4,
  "EfficiencyTarget": 6
}
 */
namespace Journal {
    class EventSAAScanComplete : public Event {
    public:
        EventSAAScanComplete(const QJsonObject &obj, const JFile *file);

        QString bodyName() const;

        int64_t bodyId() const;

        int64_t probesUsed() const;

        int64_t efficiencyTarget() const;

        bool efficiencyTargetMet() const;

    };
}

