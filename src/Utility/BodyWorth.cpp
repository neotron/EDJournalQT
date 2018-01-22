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

#include "BodyWorth.h"
namespace Journal::Util  {

    // Planet base values
    static const int64_t kValueMetalRich = 52292;
    static const int64_t kValueHMC_GGII = 23168;
    static const int64_t kValueELW_WW = 155581;
    static const int64_t kValueAmmoniaWorld = 232619;
    static const int64_t kValueGGI = 3974;
    static const int64_t kValueDefaultPlanet = 720;
    // Planet terraformable bonus
    static const int64_t KBonusHMC = 241607;
    static const int64_t kBonusELW_WW = 279088;
    static const int64_t kBonusDefaultPlanet = 233971;
    // Stars
    static const int64_t kValueWhiteDwarf = 33737;
    static const int64_t kValueNS_BH = 54309;
    static const int64_t kValueStar = 2880;


    int64_t BodyWorth::estimatedWorth(PlanetPtr planet) {
        return planet ? estimatedWorth(*planet) : 0;
    }

    int64_t BodyWorth::estimatedWorth(StarPtr star) {
        return star ? estimatedWorth(*star) : 0;
    }

    int64_t BodyWorth::estimatedWorth(const Planet &planet) {
        int64_t value = 0;
        int64_t bonus = 0;
        switch(planet.type()) {
            case Planet::MetalRich:
                value = kValueMetalRich;
                break;
            case Planet::SudarskyClassIIGasGiant:
            case Planet::HighMetalContent:
                value = kValueHMC_GGII;
                if(planet.isTerraformable()) {
                    bonus = KBonusHMC;
                }
                break;
            case Planet::Earthlike:
                value = kValueELW_WW;
                bonus = kBonusELW_WW;
                break;
            case Planet::WaterWorld:
                value = kValueELW_WW;
                if(planet.isTerraformable()) {
                    bonus = kBonusELW_WW;
                }
                break;
            case Planet::AmmoniaWorld:
                value = kValueAmmoniaWorld;
                break;
            case Planet::SudarskyClassIGasGiant:
                value = kValueGGI;
                break;
            default:
                value = kValueDefaultPlanet;
                if(planet.isTerraformable()) {
                    bonus = kBonusDefaultPlanet;
                }
        }
        double mass = planet.mass() <= 0.0 ? 1.0 : planet.mass();
        value = adjustedPlanetValue(value, mass);
        if(bonus > 0) {
            value += adjustedPlanetValue(bonus, mass);
        }
        return value;
    }

    int64_t BodyWorth::estimatedWorth(const Star &star) {
        int64_t value = 0;
        switch(star.type()) {
            case Star::D:
            case Star::DA:
            case Star::DAB:
            case Star::DAO:
            case Star::DAZ:
            case Star::DAV:
            case Star::DB:
            case Star::DBZ:
            case Star::DBV:
            case Star::DO:
            case Star::DOV:
            case Star::DQ:
            case Star::DC:
            case Star::DCV:
            case Star::DX:
                // White dwarf stars
                value = kValueWhiteDwarf;
                break;
            case Star::N:
            case Star::H:
                value = kValueNS_BH; // black holes
                break;
            default:
                value = kValueStar;
                break;
        }
        return adjustedStarValue(value, star.stellarMass());
    }

    int64_t BodyWorth::adjustedStarValue(int64_t value, double mass) {
        return static_cast<int64_t>(value + (mass * value / 66.25));
    }

    int64_t BodyWorth::adjustedPlanetValue(int64_t value, double mass) {
        return static_cast<int64_t>(value + (3 * value * pow(mass, 0.199977) / 5.3));
    }

}
