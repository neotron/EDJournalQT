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
#include "Utility/HabZone.h"

namespace Journal {

    class Star : public StellarBody {
    public:
        enum Type {
            Unknown, // Main Sequence
            O, B, A, F, G, K, M, L, T, Y, // Proto stars
            TTS, AeBe, //Wolf-Rayet
            W, WN, WNC, WC, WO, // Carbon stars
            CS, C, CN, CJ, CH, CHd, MS, S, // white dwarfs
            D, DA, DAB, DAO, DAZ, DAV, DB, DBZ, DBV, DO, DOV, DQ, DC, DCV, DX, // Neutron
            N, // Black Hole
            H, SupermassiveBlackHole, // exotic ??
            X, // Giants
            A_BlueWhiteSuperGiant, F_WhiteSuperGiant, M_RedSuperGiant, M_RedGiant, K_OrangeGiant, // Other
            RoguePlanet, Nebula, StellarRemnantNebula
        };

        explicit Star(const Event &event);

        Type type() const;

        double stellarAge() const;

        double absoluteMagnitude() const;

        double stellarMass() const;

        const QString &luminosity() const;

        QString typeNameShort() const;

        QString typeNameMedium() const;

        Util::HabZone habitableZone() const;

        int64_t estimatedValue() const override;

    private:
        Type _type;
        double _stellarAge;
        double _absoluteMagnitude;
        double _stellarMass;
        QString _luminosity;
        static QMap<QString, Type> s_starToType;

    };
    typedef std::shared_ptr<const Star> StarPtr;
}

