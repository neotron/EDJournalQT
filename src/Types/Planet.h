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
#include "StellarBody.h"

namespace Journal {
    class Planet : public StellarBody {
    public:
        explicit Planet(const Event &ev);

        enum Type {
            Unknown,
            MetalRich,
            HighMetalContent,
            Rocky,
            Icy,
            RockyIce,
            Earthlike,
            WaterWorld,
            AmmoniaWorld,
            WaterGiant,
            WaterGiantWithLife,
            GasGiantWithWaterBasedLife,
            GasGiantWithAmmoniaBasedLife,
            SudarskyClassIGasGiant,
            SudarskyClassIIGasGiant,
            SudarskyClassIIIGasGiant,
            SudarskyClassIVGasGiant,
            SudarskyClassVGasGiant,
            HeliumRichGasGiant,
            HeliumGasGiant,
        };

        Type type() const;

        Atmosphere::Type atmosphereType() const;

        QString atmosphereShort() const;

        const QString &atmosphere() const;

        const QString &volcanism() const;

        double mass() const;

        double surfaceGravity() const;

        double surfacePressureBar() const;

        double surfacePressure() const;

        bool landable() const;

        bool tidalLock() const;

        TerraformState::State terraformState() const;

        const QList<Material> &materials() const;

        QString typeNameShort() const;

        QString typeNameMedium() const;

    private:
        Type _type;
        Atmosphere::Type _atmosphereType;
        QString _atmosphere;
        QString _volcanism;
        double _massEm;
        double _surfaceGravity;
        double _surfacePressure;
        bool _landable;
        bool _tidalLock;
        TerraformState::State _terraformState;
        QList<Material> _materials{};

        static QMap<QString, Planet::Type> s_planetToType;
        static QMap<QString, Atmosphere::Type> s_atmoToType;
        static QMap<QString, TerraformState::State> s_tfsToType;

    };

    typedef std::shared_ptr<const Planet> PlanetPtr;

}
