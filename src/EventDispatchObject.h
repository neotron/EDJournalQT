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
#include <QObject>
#include <QMainWindow>
#include "Events/Event.h"
namespace Journal {
    class EventDispatcher {
    public:
        virtual bool dispatchJournalEvent(QEvent *qEvent);

    protected:
#define EVENT(EVENT) virtual void onEvent##EVENT(Event##EVENT *) {}
#include "events.inc"
#undef EVENT
        virtual void onEventGeneric(Event *){}

    };

    class EventDispatchObject : public QObject, public EventDispatcher {
    Q_OBJECT

    public:
        explicit EventDispatchObject(QObject *parent);

    protected:
        void customEvent(QEvent *qEvent) override;
    };

    class EventDispatchMainWindow: public QMainWindow, public EventDispatcher {
    Q_OBJECT
    public:
        explicit EventDispatchMainWindow(QWidget *parent = nullptr, const Qt::WindowFlags &flags = Qt::WindowFlags());
    protected:
        void customEvent(QEvent *qEvent) override;
    };

}

