//
//  Copyright (C) 2016  David Hedbor <neotron@gmail.com>
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

#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>
#include "Event.h"

QMap<QString, EventType> Event::s_eventLookupMap = Event::s_makeEventLookupMap();


Event Event::eventFromDocument(const QJsonDocument &document) {

    if(!document.isObject()) {
        return Event(QJsonObject(), EventTypeUnknown);
    }

    auto obj = document.object();
    auto event = obj.value("event").toString().toLower();

    auto eventType = s_eventLookupMap.contains(event) ? s_eventLookupMap[event] : EventTypeUnknown;

    if(eventType == EventTypeUnknown) {
        qDebug() << "Unknown event" << event;
    }
    return Event(obj, eventType);

}

QMap<QString, EventType> Event::s_makeEventLookupMap() {
    auto map = QMap<QString, EventType>();
    map["fileheader"] = EventTypeFileHeader;
    map["clearsavedgame"] = EventTypeClearSavedGame;
    map["newcommander"] = EventTypeNewCommander;
    map["loadgame"] = EventTypeLoadGame;
    map["progress"] = EventTypeProgress;
    map["rank"] = EventTypeRank;
    map["docked"] = EventTypeDocked;
    map["dockingcancelled"] = EventTypeDockingCancelled;
    map["dockingdenied"] = EventTypeDockingDenied;
    map["dockinggranted"] = EventTypeDockingGranted;
    map["dockingrequested"] = EventTypeDockingRequested;
    map["dockingtimeout"] = EventTypeDockingTimeout;
    map["fsdjump"] = EventTypeFSDJump;
    map["liftoff"] = EventTypeLiftoff;
    map["location"] = EventTypeLocation;
    map["supercruiseentry"] = EventTypeSupercruiseEntry;
    map["supercruiseexit"] = EventTypeSupercruiseExit;
    map["touchdown"] = EventTypeTouchdown;
    map["undocked"] = EventTypeUndocked;
    map["bounty"] = EventTypeBounty;
    map["capshipbond"] = EventTypeCapShipBond;
    map["died"] = EventTypeDied;
    map["escapeinterdiction"] = EventTypeEscapeInterdiction;
    map["factionkillbond"] = EventTypeFactionKillBond;
    map["heatdamage"] = EventTypeHeatDamage;
    map["heatwarning"] = EventTypeHeatWarning;
    map["hulldamage"] = EventTypeHullDamage;
    map["interdicted"] = EventTypeInterdicted;
    map["interdiction"] = EventTypeInterdiction;
    map["pvpkill"] = EventTypePVPKill;
    map["shieldstate"] = EventTypeShieldState;
    map["scan"] = EventTypeScan;
    map["materialcollected"] = EventTypeMaterialCollected;
    map["materialdiscarded"] = EventTypeMaterialDiscarded;
    map["materialdiscovered"] = EventTypeMaterialDiscovered;
    map["buyexplorationdata"] = EventTypeBuyExplorationData;
    map["sellexplorationdata"] = EventTypeSellExplorationData;
    map["screenshot"] = EventTypeScreenshot;
    map["buytradedata"] = EventTypeBuyTradeData;
    map["collectcargo"] = EventTypeCollectCargo;
    map["ejectcargo"] = EventTypeEjectCargo;
    map["marketbuy"] = EventTypeMarketBuy;
    map["marketsell"] = EventTypeMarketSell;
    map["miningrefined"] = EventTypeMiningRefined;
    map["buyammo"] = EventTypeBuyAmmo;
    map["buydrones"] = EventTypeBuyDrones;
    map["communitygoaldiscard"] = EventTypeCommunityGoalDiscard;
    map["communitygoaljoin"] = EventTypeCommunityGoalJoin;
    map["communitygoalreward"] = EventTypeCommunityGoalReward;
    map["crewassign"] = EventTypeCrewAssign;
    map["crewfire"] = EventTypeCrewFire;
    map["crewhire"] = EventTypeCrewHire;
    map["engineerapply"] = EventTypeEngineerApply;
    map["engineercraft"] = EventTypeEngineerCraft;
    map["engineerprogress"] = EventTypeEngineerProgress;
    map["fetchremotemodule"] = EventTypeFetchRemoteModule;
    map["massmodulestore"] = EventTypeMassModuleStore;
    map["missionabandoned"] = EventTypeMissionAbandoned;
    map["missionaccepted"] = EventTypeMissionAccepted;
    map["missioncompleted"] = EventTypeMissionCompleted;
    map["missionfailed"] = EventTypeMissionFailed;
    map["modulebuy"] = EventTypeModuleBuy;
    map["moduleretrieve"] = EventTypeModuleRetrieve;
    map["approachsettlement"] = EventTypeApproachSettlement;
    map["cockpitbreached"] = EventTypeCockpitBreached;
    map["commitcrime"] = EventTypeCommitCrime;
    map["continued"] = EventTypeContinued;
    map["datascanned"] = EventTypeDataScanned;
    map["datalinkscan"] = EventTypeDatalinkScan;
    map["datalinkvoucher"] = EventTypeDatalinkVoucher;
    map["dockfighter"] = EventTypeDockFighter;
    map["docksrv"] = EventTypeDockSRV;
    map["fuelscoop"] = EventTypeFuelScoop;
    map["jetconeboost"] = EventTypeJetConeBoost;
    map["jetconedamage"] = EventTypeJetConeDamage;
    map["launchfighter"] = EventTypeLaunchFighter;
    map["launchsrv"] = EventTypeLaunchSRV;
    map["modulesell"] = EventTypeModuleSell;
    map["modulesellremote"] = EventTypeModuleSellRemote;
    map["modulestore"] = EventTypeModuleStore;
    map["moduleswap"] = EventTypeModuleSwap;
    map["payfines"] = EventTypePayFines;
    map["paylegacyfines"] = EventTypePayLegacyFines;
    map["powerplaycollect"] = EventTypePowerplayCollect;
    map["powerplaydefect"] = EventTypePowerplayDefect;
    map["powerplaydeliver"] = EventTypePowerplayDeliver;
    map["powerplayfasttrack"] = EventTypePowerplayFastTrack;
    map["powerplayjoin"] = EventTypePowerplayJoin;
    map["powerplayleave"] = EventTypePowerplayLeave;
    map["powerplaysalary"] = EventTypePowerplaySalary;
    map["powerplayvote"] = EventTypePowerplayVote;
    map["powerplayvoucher"] = EventTypePowerplayVoucher;
    map["promotion"] = EventTypePromotion;
    map["rebootrepair"] = EventTypeRebootRepair;
    map["receivetext"] = EventTypeReceiveText;
    map["redeemvoucher"] = EventTypeRedeemVoucher;
    map["refuelall"] = EventTypeRefuelAll;
    map["refuelpartial"] = EventTypeRefuelPartial;
    map["repair"] = EventTypeRepair;
    map["repairall"] = EventTypeRepairAll;
    map["restockvehicle"] = EventTypeRestockVehicle;
    map["resurrect"] = EventTypeResurrect;
    map["scientificresearch"] = EventTypeScientificResearch;
    map["selfdestruct"] = EventTypeSelfDestruct;
    map["selldrones"] = EventTypeSellDrones;
    map["sendtext"] = EventTypeSendText;
    map["shipyardbuy"] = EventTypeShipyardBuy;
    map["shipyardnew"] = EventTypeShipyardNew;
    map["shipyardsell"] = EventTypeShipyardSell;
    map["shipyardswap"] = EventTypeShipyardSwap;
    map["shipyardtransfer"] = EventTypeShipyardTransfer;
    map["synthesis"] = EventTypeSynthesis;
    map["ussdrop"] = EventTypeUSSDrop;
    map["vehicleswitch"] = EventTypeVehicleSwitch;
    map["wingadd"] = EventTypeWingAdd;
    map["wingjoin"] = EventTypeWingJoin;
    map["wingleave"] = EventTypeWingLeave;
    map["systemsshutdown"] = EventTypeSystemsShutdown;
    map["cargo"] = EventTypeCargo;
    map["loadout"] = EventTypeLoadout;
    map["scanned"] = EventTypeScanned;
    map["startjump"] = EventTypeStartJump;
    map["materials"] = EventTypeMaterials;
    map["setusershipname"] = EventTypeSetUserShipName;
    return map;
}



