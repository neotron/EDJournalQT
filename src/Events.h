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
#include "Events/Event.h"
#include "Events/EventScan.h"
#include "Events/EventMaterials.h"
#include "Events/EventLoadGame.h"
#include "Events/EventAFMURepairs.h"
#include "Events/EventApproachSettlement.h"
#include "Events/EventBounty.h"
#include "Events/EventBuyAmmo.h"
#include "Events/EventBuyDrones.h"
#include "Events/EventBuyExplorationData.h"
#include "Events/EventBuyTradeData.h"
#include "Events/EventCapShipBond.h"
#include "Events/EventCargo.h"
#include "Events/EventChangeCrewRole.h"
#include "Events/EventClearSavedGame.h"
#include "Events/EventCockpitBreached.h"
#include "Events/EventCollectCargo.h"
#include "Events/EventCommitCrime.h"
#include "Events/EventCommunityGoal.h"
#include "Events/EventCommunityGoalDiscard.h"
#include "Events/EventCommunityGoalJoin.h"
#include "Events/EventCommunityGoalReward.h"
#include "Events/EventContinued.h"
#include "Events/EventCrewAssign.h"
#include "Events/EventCrewFire.h"
#include "Events/EventCrewHire.h"
#include "Events/EventCrewMemberJoins.h"
#include "Events/EventCrewMemberQuits.h"
#include "Events/EventCrewMemberRoleChange.h"
#include "Events/EventDataScanned.h"
#include "Events/EventDatalinkScan.h"
#include "Events/EventDatalinkVoucher.h"
#include "Events/EventDied.h"
#include "Events/EventDockFighter.h"
#include "Events/EventDockSRV.h"
#include "Events/EventDocked.h"
#include "Events/EventDockingCancelled.h"
#include "Events/EventDockingDenied.h"
#include "Events/EventDockingGranted.h"
#include "Events/EventDockingRequested.h"
#include "Events/EventDockingTimeout.h"
#include "Events/EventEjectCargo.h"
#include "Events/EventEndCrewSession.h"
#include "Events/EventEngineerApply.h"
#include "Events/EventEngineerContribution.h"
#include "Events/EventEngineerCraft.h"
#include "Events/EventEngineerProgress.h"
#include "Events/EventEscapeInterdiction.h"
#include "Events/EventFSDJump.h"
#include "Events/EventFactionKillBond.h"
#include "Events/EventFetchRemoteModule.h"
#include "Events/EventFileHeader.h"
#include "Events/EventFriends.h"
#include "Events/EventFuelScoop.h"
#include "Events/EventHeatDamage.h"
#include "Events/EventHeatWarning.h"
#include "Events/EventHullDamage.h"
#include "Events/EventInterdicted.h"
#include "Events/EventInterdiction.h"
#include "Events/EventJetConeBoost.h"
#include "Events/EventJetConeDamage.h"
#include "Events/EventJoinACrew.h"
#include "Events/EventLaunchFighter.h"
#include "Events/EventLaunchSRV.h"
#include "Events/EventLiftoff.h"
#include "Events/EventLoadout.h"
#include "Events/EventLocation.h"
#include "Events/EventMarketBuy.h"
#include "Events/EventMarketSell.h"
#include "Events/EventMassModuleStore.h"
#include "Events/EventMaterialCollected.h"
#include "Events/EventMaterialDiscovered.h"
#include "Events/EventMiningRefined.h"
#include "Events/EventMissionAbandoned.h"
#include "Events/EventMissionAccepted.h"
#include "Events/EventMissionCompleted.h"
#include "Events/EventMissionFailed.h"
#include "Events/EventMissionRedirected.h"
#include "Events/EventModuleBuy.h"
#include "Events/EventModuleRetrieve.h"
#include "Events/EventModuleSell.h"
#include "Events/EventModuleSellRemote.h"
#include "Events/EventModuleStore.h"
#include "Events/EventModuleSwap.h"
#include "Events/EventMusic.h"
#include "Events/EventNavBeaconScan.h"
#include "Events/EventNewCommander.h"
#include "Events/EventPVPKill.h"
#include "Events/EventPassengers.h"
#include "Events/EventPayFines.h"
#include "Events/EventPayLegacyFines.h"
#include "Events/EventPowerplayCollect.h"
#include "Events/EventPowerplayDefect.h"
#include "Events/EventPowerplayDeliver.h"
#include "Events/EventPowerplayFastTrack.h"
#include "Events/EventPowerplayJoin.h"
#include "Events/EventPowerplayLeave.h"
#include "Events/EventPowerplaySalary.h"
#include "Events/EventPowerplayVote.h"
#include "Events/EventPowerplayVoucher.h"
#include "Events/EventProgress.h"
#include "Events/EventPromotion.h"
#include "Events/EventQuitACrew.h"
#include "Events/EventRank.h"
#include "Events/EventRebootRepair.h"
#include "Events/EventReceiveText.h"
#include "Events/EventRedeemVoucher.h"
#include "Events/EventRefuelAll.h"
#include "Events/EventRefuelPartial.h"
#include "Events/EventRepair.h"
#include "Events/EventRepairAll.h"
#include "Events/EventRestockVehicle.h"
#include "Events/EventResurrect.h"
#include "Events/EventScanned.h"
#include "Events/EventScientificResearch.h"
#include "Events/EventScreenshot.h"
#include "Events/EventSelfDestruct.h"
#include "Events/EventSellDrones.h"
#include "Events/EventSellExplorationData.h"
#include "Events/EventSendText.h"
#include "Events/EventSetUserShipName.h"
#include "Events/EventShieldState.h"
#include "Events/EventShipyardBuy.h"
#include "Events/EventShipyardNew.h"
#include "Events/EventShipyardSell.h"
#include "Events/EventShipyardSwap.h"
#include "Events/EventShipyardTransfer.h"
#include "Events/EventStartJump.h"
#include "Events/EventSupercruiseEntry.h"
#include "Events/EventSupercruiseExit.h"
#include "Events/EventSynthesis.h"
#include "Events/EventSystemsShutdown.h"
#include "Events/EventTouchdown.h"
#include "Events/EventUSSDrop.h"
#include "Events/EventUndocked.h"
#include "Events/EventVehicleSwitch.h"
#include "Events/EventWingAdd.h"
#include "Events/EventWingInvite.h"
#include "Events/EventWingJoin.h"
#include "Events/EventWingLeave.h"

#include "Watcher.h"
#include "JFile.h"
#include "LiveJournal.h"

