//
//  Copyright (C) 2016-2017  David Hedbor <neotron@gmail.com>
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

#pragma once

#include <QObject>
#include <QJsonObject>
#include <QMap>
#include <QDateTime>
#include <QVector3D>

enum EventType {
    EventTypeUnknown,
    EventTypeFileHeader,
    EventTypeClearSavedGame,
    EventTypeNewCommander,
    EventTypeLoadGame,
    EventTypeProgress,
    EventTypeRank,
    EventTypeDocked,
    EventTypeDockingCancelled,
    EventTypeDockingDenied,
    EventTypeDockingGranted,
    EventTypeDockingRequested,
    EventTypeDockingTimeout,
    EventTypeFSDJump,
    EventTypeLiftoff,
    EventTypeLocation,
    EventTypeSupercruiseEntry,
    EventTypeSupercruiseExit,
    EventTypeTouchdown,
    EventTypeUndocked,
    EventTypeBounty,
    EventTypeCapShipBond,
    EventTypeDied,
    EventTypeEscapeInterdiction,
    EventTypeFactionKillBond,
    EventTypeHeatDamage,
    EventTypeHeatWarning,
    EventTypeHullDamage,
    EventTypeInterdicted,
    EventTypeInterdiction,
    EventTypePVPKill,
    EventTypeShieldState,
    EventTypeScan,
    EventTypeMaterialCollected,
    EventTypeMaterialDiscarded,
    EventTypeMaterialDiscovered,
    EventTypeBuyExplorationData,
    EventTypeSellExplorationData,
    EventTypeScreenshot,
    EventTypeBuyTradeData,
    EventTypeCollectCargo,
    EventTypeEjectCargo,
    EventTypeMarketBuy,
    EventTypeMarketSell,
    EventTypeMiningRefined,
    EventTypeBuyAmmo,
    EventTypeBuyDrones,
    EventTypeCommunityGoalDiscard,
    EventTypeCommunityGoalJoin,
    EventTypeCommunityGoalReward,
    EventTypeCrewAssign,
    EventTypeCrewFire,
    EventTypeCrewHire,
    EventTypeEngineerApply,
    EventTypeEngineerCraft,
    EventTypeEngineerProgress,
    EventTypeFetchRemoteModule,
    EventTypeMassModuleStore,
    EventTypeMissionAbandoned,
    EventTypeMissionAccepted,
    EventTypeMissionCompleted,
    EventTypeMissionFailed,
    EventTypeModuleBuy,
    EventTypeModuleRetrieve,
    EventTypeApproachSettlement,
    EventTypeCockpitBreached,
    EventTypeCommitCrime,
    EventTypeContinued,
    EventTypeDataScanned,
    EventTypeDatalinkScan,
    EventTypeDatalinkVoucher,
    EventTypeDockFighter,
    EventTypeDockSRV,
    EventTypeFuelScoop,
    EventTypeJetConeBoost,
    EventTypeJetConeDamage,
    EventTypeLaunchFighter,
    EventTypeLaunchSRV,
    EventTypeModuleSell,
    EventTypeModuleSellRemote,
    EventTypeModuleStore,
    EventTypeModuleSwap,
    EventTypePayFines,
    EventTypePayLegacyFines,
    EventTypePowerplayCollect,
    EventTypePowerplayDefect,
    EventTypePowerplayDeliver,
    EventTypePowerplayFastTrack,
    EventTypePowerplayJoin,
    EventTypePowerplayLeave,
    EventTypePowerplaySalary,
    EventTypePowerplayVote,
    EventTypePowerplayVoucher,
    EventTypePromotion,
    EventTypeRebootRepair,
    EventTypeReceiveText,
    EventTypeRedeemVoucher,
    EventTypeRefuelAll,
    EventTypeRefuelPartial,
    EventTypeRepair,
    EventTypeRepairAll,
    EventTypeRestockVehicle,
    EventTypeResurrect,
    EventTypeScientificResearch,
    EventTypeSelfDestruct,
    EventTypeSellDrones,
    EventTypeSendText,
    EventTypeShipyardBuy,
    EventTypeShipyardNew,
    EventTypeShipyardSell,
    EventTypeShipyardSwap,
    EventTypeShipyardTransfer,
    EventTypeSynthesis,
    EventTypeUSSDrop,
    EventTypeVehicleSwitch,
    EventTypeWingAdd,
    EventTypeWingJoin,
    EventTypeWingLeave,
    EventTypeSystemsShutdown,
    EventTypeCargo,
    EventTypeLoadout,
    EventTypeScanned,
    EventTypeStartJump,
    EventTypeMaterials,
    EventTypeSetUserShipName,
    EventTypeChangeCrewRole,
    EventTypeCrewMemberJoins,
    EventTypeCrewMemberQuits,
    EventTypeCrewMemberRoleChange,
    EventTypeEndCrewSession,
    EventTypeJoinACrew,
    EventTypeQuitACrew,
    EventTypeMusic,
    EventTypeFriends,
    EventTypePassengers,
    EventTypeWingInvite,
    EventTypeNavBeaconScan,
    EventTypeMissionRedirected,
    EventTypeEngineerContribution,
};

class Event : public QObject {
Q_OBJECT

public:
    virtual ~Event() { }
    static Event eventFromDocument(const QJsonDocument &document);

    QDateTime timestamp() const;

    EventType type() const;

    QString string(QString key) const;

    int integer(QString key) const;

    QDateTime date(QString key) const;

    const QJsonObject &obj() const;

    QVector3D position() const;

    explicit Event(QObject *parent=nullptr) : QObject(parent), _eventType(EventTypeUnknown), _obj() { }

    bool isValid() const { return _eventType != EventTypeUnknown; }

    Event(const Event &other) : _eventType(other._eventType), _obj(other._obj) {}
    Event(Event &&other) : _eventType(other._eventType), _obj(std::move(other._obj)) {}

private:
    Event(QJsonObject obj, EventType type) : QObject(), _eventType(type), _obj(obj) {}

private:
    static QMap<QString,EventType> s_makeEventLookupMap();
    static QMap<QString,EventType> s_eventLookupMap;

    EventType _eventType;
    QJsonObject _obj;
};



