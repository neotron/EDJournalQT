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


#include <QtCore/QString>
#include <QtCore/QMap>
#include <memory>
#include "Enums.h"
#include "Materials.h"

namespace  Journal {
    class Event;

    class StellarBody {
    protected:
        explicit StellarBody(const Event &ev, Body::Type type);
    public:
        const QString &typeName() const;

        const QString &bodyName() const;

        double surfaceTemperature() const;

        double radius() const;

        double radiusSol() const;

        double semiMajorAxis() const;

        double eccentricity() const;

        double orbitalInclination() const;

        double periapsis() const;

        double orbitalPeriod() const;

        double rotationPeriod() const;

        double distanceFromArrivalLs() const;

        Body::Type bodyType() const;

        virtual int64_t estimatedValue() const;

    protected:
        QString _typeName{};
        QString _bodyName{};
        double _surfaceTemperature;
        double _radius;
        double _semiMajorAxis;
        double _eccentricity;
        double _orbitalInclination;
        double _periapsis;
        double _orbitalPeriod;
        double _rotationPeriod;
        double _distanceFromArrivalLs;
        Body::Type _bodyType;


    };

}
