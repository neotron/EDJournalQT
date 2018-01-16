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

#include "CommanderState.h"
#include "Commander.h"

namespace Journal::State {
    CommanderState::CommanderState(QObject *parent)
    : EventDispatch(parent) {}

    void CommanderState::onEventGeneric(Event *event) {
        auto commanderName = event->file()->commander();
        if(commanderName.isEmpty()) {
            return; // We need a valid commander to parse it;
        }
        switch(event->journalEvent()) {
            case Event::LoadGame:
                _commanderState[commanderName] = new Commander(dynamic_cast<EventLoadGame*>(event), this);
                break;
            default: {
                auto commander = _commanderState[commanderName];
                if(commander) {
                    commander->dispatchJournalEvent(event);
                }
                break;
            }
        }
    }

    const Commander *CommanderState::commanderState(const QString &name) const {
        return _commanderState[name];
    }

    QList<QString> CommanderState::knownCommanders() const {
        return _commanderState.keys();
    }
}
