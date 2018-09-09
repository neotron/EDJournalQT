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
namespace Journal {
    QMap<QString, Event::JournalEvent>
        Event::s_eventLookupMap = {{"fileheader",            Event::FileHeader},
                                   {"clearsavedgame",        Event::ClearSavedGame},
                                   {"newcommander",          Event::NewCommander},
                                   {"loadgame",              Event::LoadGame},
                                   {"progress",              Event::Progress},
                                   {"rank",                  Event::Rank},
                                   {"docked",                Event::Docked},
                                   {"dockingcancelled",      Event::DockingCancelled},
                                   {"dockingdenied",         Event::DockingDenied},
                                   {"dockinggranted",        Event::DockingGranted},
                                   {"dockingrequested",      Event::DockingRequested},
                                   {"dockingtimeout",        Event::DockingTimeout},
                                   {"fsdjump",               Event::FSDJump},
                                   {"liftoff",               Event::Liftoff},
                                   {"location",              Event::Location},
                                   {"supercruiseentry",      Event::SupercruiseEntry},
                                   {"supercruiseexit",       Event::SupercruiseExit},
                                   {"touchdown",             Event::Touchdown},
                                   {"undocked",              Event::Undocked},
                                   {"bounty",                Event::Bounty},
                                   {"capshipbond",           Event::CapShipBond},
                                   {"died",                  Event::Died},
                                   {"escapeinterdiction",    Event::EscapeInterdiction},
                                   {"factionkillbond",       Event::FactionKillBond},
                                   {"heatdamage",            Event::HeatDamage},
                                   {"heatwarning",           Event::HeatWarning},
                                   {"hulldamage",            Event::HullDamage},
                                   {"interdicted",           Event::Interdicted},
                                   {"interdiction",          Event::Interdiction},
                                   {"pvpkill",               Event::PVPKill},
                                   {"shieldstate",           Event::ShieldState},
                                   {"scan",                  Event::Scan},
                                   {"materialcollected",     Event::MaterialCollected},
                                   {"materialdiscarded",     Event::MaterialDiscarded},
                                   {"materialdiscovered",    Event::MaterialDiscovered},
                                   {"buyexplorationdata",    Event::BuyExplorationData},
                                   {"sellexplorationdata",   Event::SellExplorationData},
                                   {"screenshot",            Event::Screenshot},
                                   {"buytradedata",          Event::BuyTradeData},
                                   {"collectcargo",          Event::CollectCargo},
                                   {"ejectcargo",            Event::EjectCargo},
                                   {"marketbuy",             Event::MarketBuy},
                                   {"marketsell",            Event::MarketSell},
                                   {"miningrefined",         Event::MiningRefined},
                                   {"buyammo",               Event::BuyAmmo},
                                   {"buydrones",             Event::BuyDrones},
                                   {"communitygoaldiscard",  Event::CommunityGoalDiscard},
                                   {"communitygoaljoin",     Event::CommunityGoalJoin},
                                   {"communitygoalreward",   Event::CommunityGoalReward},
                                   {"crewassign",            Event::CrewAssign},
                                   {"crewfire",              Event::CrewFire},
                                   {"crewhire",              Event::CrewHire},
                                   {"engineerapply",         Event::EngineerApply},
                                   {"engineercraft",         Event::EngineerCraft},
                                   {"engineerprogress",      Event::EngineerProgress},
                                   {"fetchremotemodule",     Event::FetchRemoteModule},
                                   {"massmodulestore",       Event::MassModuleStore},
                                   {"missionabandoned",      Event::MissionAbandoned},
                                   {"missionaccepted",       Event::MissionAccepted},
                                   {"missioncompleted",      Event::MissionCompleted},
                                   {"missionfailed",         Event::MissionFailed},
                                   {"modulebuy",             Event::ModuleBuy},
                                   {"moduleretrieve",        Event::ModuleRetrieve},
                                   {"approachsettlement",    Event::ApproachSettlement},
                                   {"cockpitbreached",       Event::CockpitBreached},
                                   {"commitcrime",           Event::CommitCrime},
                                   {"continued",             Event::Continued},
                                   {"datascanned",           Event::DataScanned},
                                   {"datalinkscan",          Event::DatalinkScan},
                                   {"datalinkvoucher",       Event::DatalinkVoucher},
                                   {"dockfighter",           Event::DockFighter},
                                   {"docksrv",               Event::DockSRV},
                                   {"fuelscoop",             Event::FuelScoop},
                                   {"jetconeboost",          Event::JetConeBoost},
                                   {"jetconedamage",         Event::JetConeDamage},
                                   {"launchfighter",         Event::LaunchFighter},
                                   {"launchsrv",             Event::LaunchSRV},
                                   {"modulesell",            Event::ModuleSell},
                                   {"modulesellremote",      Event::ModuleSellRemote},
                                   {"modulestore",           Event::ModuleStore},
                                   {"moduleswap",            Event::ModuleSwap},
                                   {"payfines",              Event::PayFines},
                                   {"paylegacyfines",        Event::PayLegacyFines},
                                   {"powerplaycollect",      Event::PowerplayCollect},
                                   {"powerplaydefect",       Event::PowerplayDefect},
                                   {"powerplaydeliver",      Event::PowerplayDeliver},
                                   {"powerplayfasttrack",    Event::PowerplayFastTrack},
                                   {"powerplayjoin",         Event::PowerplayJoin},
                                   {"powerplayleave",        Event::PowerplayLeave},
                                   {"powerplaysalary",       Event::PowerplaySalary},
                                   {"powerplayvote",         Event::PowerplayVote},
                                   {"powerplayvoucher",      Event::PowerplayVoucher},
                                   {"promotion",             Event::Promotion},
                                   {"rebootrepair",          Event::RebootRepair},
                                   {"receivetext",           Event::ReceiveText},
                                   {"redeemvoucher",         Event::RedeemVoucher},
                                   {"refuelall",             Event::RefuelAll},
                                   {"refuelpartial",         Event::RefuelPartial},
                                   {"repair",                Event::Repair},
                                   {"repairall",             Event::RepairAll},
                                   {"restockvehicle",        Event::RestockVehicle},
                                   {"resurrect",             Event::Resurrect},
                                   {"scientificresearch",    Event::ScientificResearch},
                                   {"selfdestruct",          Event::SelfDestruct},
                                   {"selldrones",            Event::SellDrones},
                                   {"sendtext",              Event::SendText},
                                   {"shipyardbuy",           Event::ShipyardBuy},
                                   {"shipyardnew",           Event::ShipyardNew},
                                   {"shipyardsell",          Event::ShipyardSell},
                                   {"shipyardswap",          Event::ShipyardSwap},
                                   {"shipyardtransfer",      Event::ShipyardTransfer},
                                   {"synthesis",             Event::Synthesis},
                                   {"ussdrop",               Event::USSDrop},
                                   {"vehicleswitch",         Event::VehicleSwitch},
                                   {"wingadd",               Event::WingAdd},
                                   {"wingjoin",              Event::WingJoin},
                                   {"wingleave",             Event::WingLeave},
                                   {"systemsshutdown",       Event::SystemsShutdown},
                                   {"cargo",                 Event::Cargo},
                                   {"loadout",               Event::Loadout},
                                   {"scanned",               Event::Scanned},
                                   {"startjump",             Event::StartJump},
                                   {"materials",             Event::Materials},
                                   {"setusershipname",       Event::SetUserShipName},
                                   {"changecrewrole",        Event::ChangeCrewRole},
                                   {"crewmemberjoins",       Event::CrewMemberJoins},
                                   {"crewmemberquits",       Event::CrewMemberQuits},
                                   {"crewmemberrolechange",  Event::CrewMemberRoleChange},
                                   {"endcrewsession",        Event::EndCrewSession},
                                   {"joinacrew",             Event::JoinACrew},
                                   {"quitacrew",             Event::QuitACrew},
                                   {"music",                 Event::Music},
                                   {"friends",               Event::Friends},
                                   {"passengers",            Event::Passengers},
                                   {"winginvite",            Event::WingInvite},
                                   {"navbeaconscan",         Event::NavBeaconScan},
                                   {"missionredirected",     Event::MissionRedirected},
                                   {"engineercontribution",  Event::EngineerContribution},
                                   {"communitygoal",         Event::CommunityGoal},
                                   {"afmurepairs",           Event::AFMURepairs},
                                   {"crewlaunchfighter",     Event::CrewLaunchFighter},
                                   {"kickcrewmember",        Event::KickCrewMember},
                                   {"commander",             Event::Commander},
                                   {"reputation",            Event::Reputation},
                                   {"missions",              Event::Missions},
                                   {"statistics",            Event::Statistics},
                                   {"npccrewpaidwage",       Event::NpcCrewPaidWage},
                                   {"shipyard",              Event::Shipyard},
                                   {"storedships",           Event::StoredShips},
                                   {"outfitting",            Event::Outfitting},
                                   {"storedmodules",         Event::StoredModules},
                                   {"moduleinfo",            Event::ModuleInfo},
                                   {"materialtrade",         Event::MaterialTrade},
                                   {"discoveryscan",         Event::DiscoveryScan},
                                   {"approachbody",          Event::ApproachBody},
                                   {"shutdown",              Event::Shutdown},
                                   {"shiptargeted",          Event::ShipTargeted},
                                   {"leavebody",             Event::LeaveBody},
                                   {"underattack",           Event::UnderAttack},
                                   {"market",                Event::Market},
                                   {"technologybroker",      Event::TechnologyBroker},
                                   {"launchdrone",           Event::LaunchDrone},
                                   {"fighterdestroyed",      Event::FighterDestroyed},
                                   {"fighterrebuilt",        Event::FighterRebuilt},
                                   {"engineerlegacyconvert", Event::EngineerLegacyConvert},
                                   {"srvdestroyed",          Event::SRVDestroyed},
                                   {"powerplay",             Event::Powerplay},
                                   {"repairdrone",           Event::RepairDrone},
                                   {"searchandrescue",       Event::SearchAndRescue},
                                   {"npccrewrank",           Event::NpcCrewRank},
                                   {"cargodepot",            Event::CargoDepot},
    };
}
