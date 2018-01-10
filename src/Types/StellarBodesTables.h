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
#include "Enums.h"
#include "Star.h"
#include "Planet.h"
namespace Journal {
    QMap<QString, Atmosphere::Type>
        Planet::s_atmoToType = {{ "Ammonia",           Atmosphere::Ammonia },
                                { "AmmoniaOxygen",     Atmosphere::AmmoniaOxygen },
                                { "AmmoniaRich",       Atmosphere::AmmoniaRich },
                                { "Argon",             Atmosphere::Argon },
                                { "ArgonRich",         Atmosphere::ArgonRich },
                                { "CarbonDioxide",     Atmosphere::CarbonDioxide },
                                { "CarbonDioxideRich", Atmosphere::CarbonDioxideRich },
                                { "EarthLike",         Atmosphere::EarthLike },
                                { "Helium",            Atmosphere::Helium },
                                { "Methane",           Atmosphere::Methane },
                                { "MethaneRich",       Atmosphere::MethaneRich },
                                { "Neon",              Atmosphere::Neon },
                                { "NeonRich",          Atmosphere::NeonRich },
                                { "Nitrogen",          Atmosphere::Nitrogen },
                                { "None",              Atmosphere::None },
                                { "Oxygen",            Atmosphere::Oxygen },
                                { "SilicateVapour",    Atmosphere::SilicateVapour },
                                { "SulphurDioxide",    Atmosphere::SulphurDioxide },
                                { "Water",             Atmosphere::Water },
                                { "WaterRich",         Atmosphere::WaterRich }};

    QMap<QString, Planet::Type>
        Planet::s_planetToType = {{ "Metal rich body",                   Planet::MetalRich },
                                  { "High metal content body",           Planet::HighMetalContent },
                                  { "Rocky body",                        Planet::Rocky },
                                  { "Icy body",                          Planet::Icy },
                                  { "Rocky ice body",                    Planet::RockyIce },
                                  { "Earthlike body",                    Planet::Earthlike },
                                  { "Water world",                       Planet::WaterWorld },
                                  { "Ammonia world",                     Planet::AmmoniaWorld },
                                  { "Water giant",                       Planet::WaterGiant },
                                  { "Water giant with life",             Planet::WaterGiantWithLife },
                                  { "Gas giant with water based life",   Planet::GasGiantWithWaterBasedLife },
                                  { "Gas giant with ammonia based life", Planet::GasGiantWithAmmoniaBasedLife },
                                  { "Sudarsky class I gas giant",        Planet::SudarskyClassIGasGiant },
                                  { "Sudarsky class II gas giant",       Planet::SudarskyClassIIGasGiant },
                                  { "Sudarsky class III gas giant",      Planet::SudarskyClassIIIGasGiant },
                                  { "Sudarsky class IV gas giant",       Planet::SudarskyClassIVGasGiant },
                                  { "Sudarsky class V gas giant",        Planet::SudarskyClassVGasGiant },
                                  { "Helium rich gas giant",             Planet::HeliumRichGasGiant },
                                  { "Helium gas giant",                  Planet::HeliumGasGiant },
                                  { "Unknown",                           Planet::Unknown }};

    QMap<QString, Star::Type>
        Star::s_starToType = {{ "O",                     Star::O },
                              { "B",                     Star::B },
                              { "A",                     Star::A },
                              { "F",                     Star::F },
                              { "G",                     Star::G },
                              { "K",                     Star::K },
                              { "M",                     Star::M },
                              { "L",                     Star::L },
                              { "T",                     Star::T },
                              { "Y",                     Star::Y },
                              { "TTS",                   Star::TTS },
                              { "AeBe",                  Star::AeBe },
                              { "W",                     Star::W },
                              { "WN",                    Star::WN },
                              { "WNC",                   Star::WNC },
                              { "WC",                    Star::WC },
                              { "WO",                    Star::WO },
                              { "CS",                    Star::CS },
                              { "C",                     Star::C },
                              { "CN",                    Star::CN },
                              { "CJ",                    Star::CJ },
                              { "CH",                    Star::CH },
                              { "CHd",                   Star::CHd },
                              { "MS",                    Star::MS },
                              { "S",                     Star::S },
                              { "D",                     Star::D },
                              { "DA",                    Star::DA },
                              { "DAB",                   Star::DAB },
                              { "DAO",                   Star::DAO },
                              { "DAZ",                   Star::DAZ },
                              { "DAV",                   Star::DAV },
                              { "DB",                    Star::DB },
                              { "DBZ",                   Star::DBZ },
                              { "DBV",                   Star::DBV },
                              { "DO",                    Star::DO },
                              { "DOV",                   Star::DOV },
                              { "DQ",                    Star::DQ },
                              { "DC",                    Star::DC },
                              { "DCV",                   Star::DCV },
                              { "DX",                    Star::DX },
                              { "N",                     Star::N },
                              { "H",                     Star::H },
                              { "SupermassiveBlackHole", Star::SupermassiveBlackHole },
                              { "X",                     Star::X },
                              { "A_BlueWhiteSuperGiant", Star::A_BlueWhiteSuperGiant },
                              { "F_WhiteSuperGiant",     Star::F_WhiteSuperGiant },
                              { "M_RedSuperGiant",       Star::M_RedSuperGiant },
                              { "M_RedGiant",            Star::M_RedGiant },
                              { "K_OrangeGiant",         Star::K_OrangeGiant },
                              { "RoguePlanet",           Star::RoguePlanet },
                              { "Nebula",                Star::Nebula },
                              { "StellarRemnantNebula",  Star::StellarRemnantNebula }};

    QMap<QString, TerraformState::State> Planet::s_tfsToType = {{ "Terraformable", TerraformState::Terraformable },
                                                                { "Terraforming",  TerraformState::Terraforming },
                                                                { "Terraformed",   TerraformState::Terraformed },
    };
}
