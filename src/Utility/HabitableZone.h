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

#include <QtCore/QMap>
#include "Types/Star.h"
#include "HabZone.h"

namespace Journal::Util  {
    struct BCEntry {
        int K;
        double BC;
    };

    class HabitableZone;

    class HabitableZone {
    public:
        static HabZone habitableZone(Star::Type starClass, double temp, double absoluteMagnitude);

    private:
        static QMap<Star::Type, QList<BCEntry>> s_lookup;
    };
}
