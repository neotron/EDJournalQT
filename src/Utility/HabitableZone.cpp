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
#include <QDebug>
const double bolSol = 4.72;
const double pogsonsRatio = -2.5;
const double innerStellarFlux = 1.1;
const double outerStellarFlux = 0.53;
namespace Journal {

    HabZone HabitableZone:: habitableZone(Star::Type starClass, double temp, double absoluteMagnitude) {
        if(!s_lookup.contains(starClass)) {
            return {};
        }
        auto bcLookup = s_lookup[starClass];
        double BC;
        if(temp > bcLookup.first().K) {
            BC = bcLookup.first().BC; // Hotter than hottest
        } else if(temp < bcLookup.last().K) {
            BC = bcLookup.last().BC; // Cooler than coolest
        } else {
            // It's inside the range, so let's find the right spot.
            BCEntry last = { 0, 0 };
            BCEntry match = { 0, 0 };
            for(const auto &bc: bcLookup) {
                if(temp > bc.K) {
                    match = bc;
                    break;
                }
                last = bc; // Keep the one above the match for reference.
            }
            // Temp range of the two BC steps
            double bcDeltaK = last.K - match.K;
            // Where in the range the star temp is
            double starDeltaK = temp - match.K;

            double percentage = starDeltaK / bcDeltaK; // How far in the range we are.
            BC = percentage * (last.BC - match.BC) + match.BC;
        }

        // We now got the approximate Bolometric Correction constant (BC). Let's estimate the habitable zone.
        double bolStar = absoluteMagnitude + BC;
        double absLuminosity = pow(10, (bolStar - bolSol) / pogsonsRatio);

        return {
            sqrt(absLuminosity / innerStellarFlux),
            sqrt(absLuminosity / outerStellarFlux)
        };
    }

    QMap<Star::Type, QList<BCEntry>>
        HabitableZone::s_lookup
        = {{
               Star::B, {{ 30000, -3.16 }, { 22000, -2.35 }, { 18700, -1.94 },
                            { 15400, -1.46 }, { 13000, -1.02 }, { 11900, -0.8 }}},
           {
               Star::A, {{ 9520,  -0.3 },  { 8200,  -0.15 }}},
           {
               Star::F, {{ 7200,  -0.09 }, { 6440,  -0.14 }}},
           {
               Star::G, {{ 6030,  -0.18 }, { 5860,  -0.2 },  { 5770,  -0.21 }},
           }, {
               Star::K, {{ 5250,  -0.31 }, { 4350,  -0.72 }}},
           {
               Star::M, {{ 3850,  -1.28 }, { 3250,  -2.73 }, { 2640,  -4.1 }}
           }};

}
