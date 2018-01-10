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

#include "HabitableZone.h"
#include "HabZone.h"
const double lsInAU = 499.005;
bool HabZone::isValid() const {
    return _inner >= 0 && _outer > 0;
}

double HabZone::innerAU() const {
    return _inner;
}

double HabZone::outerAU() const {
    return _outer;
}

int HabZone::innerLS() const {
    return static_cast<int>(_inner * lsInAU);
}

int HabZone::outerLS() const {
    return static_cast<int>(_outer * lsInAU);
}

HabZone::HabZone(double inner, double outer)
    : _inner(inner), _outer(outer) {}

HabZone::HabZone(): _inner(-1), _outer(-1){}
