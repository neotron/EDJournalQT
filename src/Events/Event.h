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
#include <QJsonArray>
#include <memory>

namespace Journal {
    class EventScan;

    class Event;
    typedef std::shared_ptr<const Event> EventPtr;

    class Event : public QObject {
    Q_OBJECT

    public:
        enum Type {
            Unknown,
            FileHeader,
            ClearSavedGame,
            NewCommander,
            LoadGame,
            Progress,
            Rank,
            Docked,
            DockingCancelled,
            DockingDenied,
            DockingGranted,
            DockingRequested,
            DockingTimeout,
            FSDJump,
            Liftoff,
            Location,
            SupercruiseEntry,
            SupercruiseExit,
            Touchdown,
            Undocked,
            Bounty,
            CapShipBond,
            Died,
            EscapeInterdiction,
            FactionKillBond,
            HeatDamage,
            HeatWarning,
            HullDamage,
            Interdicted,
            Interdiction,
            PVPKill,
            ShieldState,
            Scan,
            MaterialCollected,
            MaterialDiscarded,
            MaterialDiscovered,
            BuyExplorationData,
            SellExplorationData,
            Screenshot,
            BuyTradeData,
            CollectCargo,
            EjectCargo,
            MarketBuy,
            MarketSell,
            MiningRefined,
            BuyAmmo,
            BuyDrones,
            CommunityGoalDiscard,
            CommunityGoalJoin,
            CommunityGoalReward,
            CrewAssign,
            CrewFire,
            CrewHire,
            EngineerApply,
            EngineerCraft,
            EngineerProgress,
            FetchRemoteModule,
            MassModuleStore,
            MissionAbandoned,
            MissionAccepted,
            MissionCompleted,
            MissionFailed,
            ModuleBuy,
            ModuleRetrieve,
            ApproachSettlement,
            CockpitBreached,
            CommitCrime,
            Continued,
            DataScanned,
            DatalinkScan,
            DatalinkVoucher,
            DockFighter,
            DockSRV,
            FuelScoop,
            JetConeBoost,
            JetConeDamage,
            LaunchFighter,
            LaunchSRV,
            ModuleSell,
            ModuleSellRemote,
            ModuleStore,
            ModuleSwap,
            PayFines,
            PayLegacyFines,
            PowerplayCollect,
            PowerplayDefect,
            PowerplayDeliver,
            PowerplayFastTrack,
            PowerplayJoin,
            PowerplayLeave,
            PowerplaySalary,
            PowerplayVote,
            PowerplayVoucher,
            Promotion,
            RebootRepair,
            ReceiveText,
            RedeemVoucher,
            RefuelAll,
            RefuelPartial,
            Repair,
            RepairAll,
            RestockVehicle,
            Resurrect,
            ScientificResearch,
            SelfDestruct,
            SellDrones,
            SendText,
            ShipyardBuy,
            ShipyardNew,
            ShipyardSell,
            ShipyardSwap,
            ShipyardTransfer,
            Synthesis,
            USSDrop,
            VehicleSwitch,
            WingAdd,
            WingJoin,
            WingLeave,
            SystemsShutdown,
            Cargo,
            Loadout,
            Scanned,
            StartJump,
            Materials,
            SetUserShipName,
            ChangeCrewRole,
            CrewMemberJoins,
            CrewMemberQuits,
            CrewMemberRoleChange,
            EndCrewSession,
            JoinACrew,
            QuitACrew,
            Music,
            Friends,
            Passengers,
            WingInvite,
            NavBeaconScan,
            MissionRedirected,
            EngineerContribution,
            CommunityGoal,
            AFMURepairs
        };

        explicit Event(QObject *parent = nullptr)
            : QObject(parent), _eventType(Unknown), _obj() {}

        Event(const Event &other) : _eventType(other._eventType), _obj(other._obj) {}

        Event(Event &&other) noexcept : _eventType(other._eventType), _obj(std::move(other._obj)) {}

        Event(const QJsonObject &obj, Type type);

        ~Event() override = default;

        static EventPtr eventFromDocument(const QJsonDocument &document);

        QDateTime timestamp() const;


        Type type() const;

        QString string(const QString &key) const;

        int integer(const QString &key) const;

        bool boolean(const QString &key) const;

        double doubleValue(const QString &key) const;

        QDateTime date(const QString &key) const;

        const QJsonObject &obj() const;

        QVector3D position() const;

        QJsonArray array(const QString &key) const;

        bool isValid() const { return _eventType != Unknown; }

        const EventScan *scan() const;

    private:
        static QMap<QString, Type> s_eventLookupMap;

        Type _eventType;
        QJsonObject _obj;
    };
}


