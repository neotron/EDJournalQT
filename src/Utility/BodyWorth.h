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

#include <cstdint>
#include <src/Types.h>

namespace Journal::Util {
    class BodyWorth {
    public:
        static int64_t estimatedWorth(PlanetPtr planet);
        static int64_t estimatedWorth(StarPtr star);
        static int64_t estimatedWorth(const Planet &planet);
        static int64_t estimatedWorth(const Star &star);
    private:
        static int64_t adjustedStarValue(int64_t value, double mass);
        static int64_t adjustedPlanetValue(int64_t value, double mass, double map = 1.0);
};
}
