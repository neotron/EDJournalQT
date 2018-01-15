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

#include "Event.h"
#include "Star.h"
#include "Utility/HabitableZone.h"

namespace Journal {

    Star::Star(const Event &ev)
        : StellarBody(ev, Body::Star), _type(Unknown), _stellarAge(ev.doubleValue(Key::StellarAge)),
          _absoluteMagnitude(ev.doubleValue(Key::AbsoluteMagnitude)), _stellarMass(ev.doubleValue(Key::StellarMass)),
          _luminosity(ev.string(Key::Luminosity)) {
        if(s_starToType.contains(_typeName)) {
            _type = s_starToType[_typeName];
        }
    }

    QString Star::typeNameShort() const{
        switch(_type) {
            case SupermassiveBlackHole:
                return "SM BH";
            case A_BlueWhiteSuperGiant:
                return "A SG";
            case F_WhiteSuperGiant:
                return "F SG";
            case M_RedSuperGiant:
                return "M SG";
            case M_RedGiant:
                return "M RG";
            case K_OrangeGiant:
                return "K OG";
            case RoguePlanet:
                return "RP";
            case Nebula:
                return "NB";
            case StellarRemnantNebula:
                return "SRNB";
            default:
                return _typeName;
        }
    }

    QString Star::typeNameMedium() const {
        switch(_type) {
            case SupermassiveBlackHole:
                return "Supermas Blk Hl";
            case A_BlueWhiteSuperGiant:
                return "A Super Giant";
            case F_WhiteSuperGiant:
                return "F Super Giant";
            case M_RedSuperGiant:
                return "M Super Giant";
            case M_RedGiant:
                return "M Red Giant";
            case K_OrangeGiant:
                return "K OG";
            case RoguePlanet:
                return "Rogue Planet";
            case Nebula:
                return "Nebula";
            case StellarRemnantNebula:
                return "Str Remnant Neb";
            default:
                return _typeName;
        }
    }

    Star::Type Star::type() const {
        return _type;
    }

    double Star::stellarAge() const {
        return _stellarAge;
    }

    double Star::absoluteMagnitude() const {
        return _absoluteMagnitude;
    }

    double Star::stellarMass() const {
        return _stellarMass;
    }

    const QString &Star::luminosity() const {
        return _luminosity;
    }

    HabZone Star::habitableZone() const {
        return HabitableZone::habitableZone(_type, _surfaceTemperature, _absoluteMagnitude);
    }
}
