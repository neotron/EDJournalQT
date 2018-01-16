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

#include "Commander.h"
namespace Journal::State {
    Commander::Commander(Journal::EventLoadGame *game, QObject *parent)
        : QObject(parent)
    {
        onEventLoadGame(game);
    }


    void Commander::onEventMaterials(EventMaterials *materials) {
        _materials.clear();
        for(auto &mat:  materials->encoded()) {
            _materials[mat.id()] = mat;
        }
        for(auto &mat:  materials->manufactured()) {
            _materials[mat.id()] = mat;
        }
        for(auto &mat:  materials->raw()) {
            _materials[mat.id()] = mat;
        }
    }

    void Commander::onEventLoadGame(EventLoadGame *game) {
        _name = game->commander();
        _ship = game->ship();
        _shipID = game->shipID();
        _shipName = game->shipName();
        _shipIdent = game->shipIdent();
        _fuelLevel = game->fuelLevel();
        _fuelCapacity = game->fuelCapacity();
        _gameMode = game->gameMode();
        _credits = game->credits();
        _loan = game->loan();
    }

    void Commander::onEventRank(EventRank *eventRank) {
        for(auto &rank: eventRank->ranks()) {
            auto type = rank.type();
            if(_ranks.contains(type)) {
                _ranks[type].setRank(rank.rank());
            } else {
                _ranks[type] = rank;
            }
        }
    }

    void Commander::onEventProgress(EventProgress *progress) {
        for(auto &rank: progress->progress()) {
            auto type = rank.type();
            if(_ranks.contains(type)) {
                _ranks[type].setProgress(rank.progress());
            } else {
                _ranks[type] = rank;
            }
        }
    }

    void Commander::onEventGeneric(Event *event) {
        switch(event->journalEvent()) {
            case Event::MaterialDiscarded:
            case Event::MaterialCollected:
            case Event::EngineerCraft:
                handleMaterialsChanged(dynamic_cast<Extension::MaterialsChanged *>(event)->materials());
                break;
            default: {
                // This is used as a base class on any event that changes credits such as commodity transactions
                auto creditsChanged = dynamic_cast<Extension::CreditsChanged*>(event);
                if(creditsChanged) {
                    _credits += creditsChanged->creditChange();
                }
            }
                break; // No-op
        }
    }

    void Commander::handleMaterialChanged(const Material &material) {
        if(!material.isValid()) {
            return;
        }
        Material &current = _materials[material.id()];
        if(current.isValid()) {
            current.setQuantity(current.quantity() + material.quantity());
        } else {
            _materials[material.id()] = material;
        }
    }

    void Commander::handleMaterialsChanged(const QList<Material> &list) {

        for(auto &mat: list) {
            handleMaterialChanged(mat);
        }
    }
}
