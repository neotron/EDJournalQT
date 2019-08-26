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

#include <QDebug>
#include "Planet.h"
#include "Events/Event.h"
#include "Utility/BodyWorth.h"

namespace  Journal {

    Planet::Planet(const Event &ev)
        : StellarBody(ev, Body::Planet), _type(Unknown),
          _atmosphereType(Atmosphere::Unknown),
          _atmosphere(ev.string(Key::Atmosphere)),
          _volcanism(ev.string(Key::Volcanism)),
          _massEm(ev.doubleValue(Key::MassEM)),
          _surfaceGravity(ev.doubleValue(Key::SurfaceGravity)),
          _surfacePressure(ev.doubleValue(Key::SurfacePressure)),
          _landable(ev.boolean(Key::Landable)),
          _tidalLock(ev.boolean(Key::TidalLock)),
          _terraformState(TerraformState::None),
          _isMapped(false),
          _isEfficient(false)
    {
        if(s_planetToType.contains(_typeName)) {
            _type = s_planetToType[_typeName];
        }
        auto atmType = ev.string(Key::AtmosphereType);
        if(s_atmoToType.contains(atmType)) {
            _atmosphereType = s_atmoToType[atmType];
        }

        auto tfs = ev.string(Key::TerraformState);
        if(s_tfsToType.contains(tfs)) {
            _terraformState = s_tfsToType[tfs];
        }
        _materials = Materials::materials(ev.array(Key::Materials));

        // We might have to calculate gravity - without a DSS it's not included in the output
        // but we get mass and radius which is all we need.
        const double earthG = 9.807;
        if(_surfaceGravity > 0.0) {
            // Even if we have it, we want to convert to G's
            _surfaceGravity /= earthG;
        } else {
            // If not, let's calculate it
            auto G = 6.67408e-11;
            auto earthMass = 5.9721986e24;
            _surfaceGravity = (G * _massEm * earthMass / (_radius * _radius)) / earthG;
        }
    }

    // Atmosphere in 16 or under letters.
    QString Planet::atmosphereShort() const {
        switch(_atmosphereType) {
            case Atmosphere::Ammonia:
                return "Ammonia";
            case Atmosphere::AmmoniaOxygen:
                return "Ammonia O2";
            case Atmosphere::AmmoniaRich:
                return "Ammonia Rich";
            case Atmosphere::Argon:
                return "Argon";
            case Atmosphere::ArgonRich:
                return "Argon Rich";
            case Atmosphere::CarbonDioxide:
                return "Carbon Dioxide";
            case Atmosphere::CarbonDioxideRich:
                return "CO2 Rich";
            case Atmosphere::EarthLike:
                return "Earth Like";
            case Atmosphere::Helium:
                return "Helium";
            case Atmosphere::Methane:
                return "Methane";
            case Atmosphere::MethaneRich:
                return "Methane Rich";
            case Atmosphere::Neon:
                return "Neon";
            case Atmosphere::NeonRich:
                return "Neon Rich";
            case Atmosphere::Nitrogen:
                return "Nitrogen";
            case Atmosphere::Oxygen:
                return "Oxygen";
            case Atmosphere::SilicateVapour:
                return "Silicate Vapour";
            case Atmosphere::SulphurDioxide:
                return "Sulphur Dioxide";
            case Atmosphere::Water:
                return "Water";
            case Atmosphere::WaterRich:
                return "Water Rich";
            case Atmosphere::None:
                return "None";
            default:
                return "Unknown";
        }
    }


// This maps the details planet type to a shorthand for the summary display.
    QString Planet::typeNameShort() const {
        switch(_type) {
            case MetalRich:
                return "MR";
            case HighMetalContent:
                return "HMC";
            case Rocky:
                return "Rocky";
            case Icy:
                return "Icy";
            case RockyIce:
                return "RoIcy";
            case Earthlike:
                return "ELW";
            case WaterWorld:
                return "WW";
            case AmmoniaWorld:
                return "AW";
            case WaterGiant:
                return "WaGi";
            case WaterGiantWithLife:
                return "WaGiL";
            case GasGiantWithWaterBasedLife:
                return "GG WL";
            case GasGiantWithAmmoniaBasedLife:
                return "WW AL";
            case SudarskyClassIGasGiant:
                return "GG I";
            case SudarskyClassIIGasGiant:
                return "GG II";
            case SudarskyClassIIIGasGiant:
                return "GGIII";
            case SudarskyClassIVGasGiant:
                return "GG IV";
            case SudarskyClassVGasGiant:
                return "GG V";
            case HeliumRichGasGiant:
                return "HR GG";
            case HeliumGasGiant:
                return "H GG";
            default:
                return "Unk";
        }
    }
// This is a somewhat longer shorthand, but below 16 characters
    QString Planet::typeNameMedium() const {
        qDebug() << _type << _typeName;
        switch(_type) {
            case MetalRich:
                return "Metal Rich";
            case HighMetalContent:
                return "High Metal Cont.";
            case Rocky:
                return "Rocky";
            case Icy:
                return "Icy";
            case RockyIce:
                return "Rocky Ice";
            case Earthlike:
                return "Earth Like";
            case WaterWorld:
                return "Water World";
            case AmmoniaWorld:
                return "Ammonia World";
            case WaterGiant:
                return "Water Giant";
            case WaterGiantWithLife:
                return "Water Giant Life";
            case GasGiantWithWaterBasedLife:
                return "GG, Water Life";
            case GasGiantWithAmmoniaBasedLife:
                return "GG, Ammonia Life";
            case SudarskyClassIGasGiant:
                return "Class I G. Giant";
            case SudarskyClassIIGasGiant:
                return "Class II G.Giant";
            case SudarskyClassIIIGasGiant:
                return "Class III GGiant";
            case SudarskyClassIVGasGiant:
                return "Class IV G.Giant";
            case SudarskyClassVGasGiant:
                return "Class V G. Giant";
            case HeliumRichGasGiant:
                return "Helium Rich GG";
            case HeliumGasGiant:
                return "Helium G. Giant";
            default:
                return "Unknown";
        }
    }

    Planet::Type Planet::type() const {
        return _type;
    }

    Atmosphere::Type Planet::atmosphereType() const {
        return _atmosphereType;
    }

    const QString &Planet::atmosphere() const {
        return _atmosphere;
    }

    const QString &Planet::volcanism() const {
        return _volcanism;
    }

    double Planet::mass() const {
        return _massEm;
    }

    double Planet::surfaceGravity() const {
        return _surfaceGravity;
    }

    double Planet::surfacePressureBar() const {
        return _surfacePressure/101325.0;
    }

    double Planet::surfacePressure() const {
        return _surfacePressure;
    }

    bool Planet::landable() const {
        return _landable;
    }

    bool Planet::tidalLock() const {
        return _tidalLock;
    }

    TerraformState::State Planet::terraformState() const {
        return _terraformState;
    }

    const QList<Material> &Planet::materials() const {
        return _materials;
    }

    bool Planet::isTerraformable() const {
        return _terraformState != TerraformState::None;
    }

    int64_t Planet::estimatedValue() const {
        return Util::BodyWorth::estimatedWorth(*this);
    }

    bool Planet::isMapped() const {
        return _isMapped;
    }

    void Planet::setIsMapped(bool isMapped) {
        _isMapped = isMapped;
    }

    bool Planet::isEfficient() const {
        return _isEfficient;
    }

    void Planet::setIsEfficient(bool isEfficient) {
        _isEfficient = isEfficient;
    }
}
