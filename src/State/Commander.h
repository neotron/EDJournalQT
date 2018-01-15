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
#include <QString>
#include <QObject>
#include "Types.h"
#include "Events.h"
namespace Journal::State {
// Keeps track of the current state of commander data. Every state we need to track, such as current system,
// current material counts, assets etc starts at this level.
    class Commander: public QObject, public EventDispatcher {
        Q_OBJECT

    private:
        QString _name;
        QString _ship;
        int64_t _shipID;
        QString _shipName;
        QString _shipIdent;
        double _fuelLevel;
        double _fuelCapacity;
        QString _gameMode;
        int64_t _credits;
        int64_t _loan;
        QMap<QString,Material> _materials;
        QMap<RankProgress::Type, RankProgress> _ranks;
    public:
        explicit Commander(EventLoadGame *game, QObject *parent = nullptr);

    protected:
        // These are all used to update commander related data for the event.
        void onEventLoadGame(EventLoadGame *game) override;
        void onEventMaterials(EventMaterials *materials) override;
        void onEventRank(EventRank *eventRank) override;
        void onEventProgress(EventProgress *progress) override;

        void onEventGeneric(Event *event) override;

        void handleMaterialChanged(const Material &material);
    };
}
