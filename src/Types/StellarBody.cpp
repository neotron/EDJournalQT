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

#include "StellarBody.h"
#include "Event.h"
#include "StellarBodesTables.h"

namespace  Journal {

    StellarBody::StellarBody(const Event &ev, Body::Type type)
        : _bodyName(ev.string("BodyName")),
          _surfaceTemperature(ev.doubleValue("SurfaceTemperature")),
          _radius(ev.doubleValue("Radius")),
          _semiMajorAxis(ev.doubleValue("SemiMajorAxis")),
          _eccentricity(ev.doubleValue("Eccentricity")),
          _orbitalInclination(ev.doubleValue("OrbitalInclination")),
          _periapsis(ev.doubleValue("Periapsis")),
          _orbitalPeriod(ev.doubleValue("OrbitalPeriod")),
          _rotationPeriod(ev.doubleValue("RotationPeriod")),
          _distanceFromArrivalLs(ev.doubleValue("distanceFromArrivalLs")),
          _bodyType(type)
    {
        switch(type) {
            case Body::Planet:
                _typeName = ev.string("PlanetClass");
                break;
            case Body::Star:
                _typeName = ev.string("StarType");
                break;
            default:
                _typeName = "Unknown";
                break;
        }
    }

    const QString &StellarBody::typeName() const {
        return _typeName;
    }

    double StellarBody::surfaceTemperature() const {
        return _surfaceTemperature;
    }

    double StellarBody::radius() const {
        return _radius;
    }
    double StellarBody::radiusSol() const {
        return _radius / 695700000.0;
    }

    double StellarBody::semiMajorAxis() const {
        return _semiMajorAxis;
    }

    double StellarBody::eccentricity() const {
        return _eccentricity;
    }

    double StellarBody::orbitalInclination() const {
        return _orbitalInclination;
    }

    double StellarBody::periapsis() const {
        return _periapsis;
    }

    double StellarBody::orbitalPeriod() const {
        return _orbitalPeriod;
    }

    double StellarBody::rotationPeriod() const {
        return _rotationPeriod;
    }

    double StellarBody::distanceFromArrivalLs() const {
        return _distanceFromArrivalLs;
    }

    Body::Type StellarBody::bodyType() const {
        return _bodyType;
    }

    const QString &StellarBody::bodyName() const {
        return _bodyName;
    }
}
