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

#include "EventDispatchObject.h"
namespace Journal::State {
    class Commander;

    class CommanderState : public EventDispatchObject {
    public:
        explicit CommanderState(QObject *parent = nullptr);

        const Commander *commanderState(const QString &name) const;

        QList<QString> knownCommanders() const;
    protected:
        void onEventGeneric(Event *event) override;

    private:
        QMap<QString,Commander *> _commanderState;
    };
}
