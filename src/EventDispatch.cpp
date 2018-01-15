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

#include <QtWidgets/QMainWindow>
#include "EventDispatch.h"
#include "Events.h"
#include <QDebug>

#define EVENT(EVENT) case Event::##EVENT: {\
    auto evptr = dynamic_cast<Event##EVENT *>(event);\
    if(evptr) { onEvent##EVENT(evptr); } \
    onEventGeneric(event); \
  }; \
  break;

namespace Journal {
    void EventDispatch::customEvent(QEvent *qEvent) {
        if(!dispatchJournalEvent(qEvent)) {
            QObject::customEvent(qEvent);
        }
    }

    EventDispatch::EventDispatch(QObject *parent)
        : QObject(parent) {}

    bool EventDispatcher::dispatchJournalEvent(QEvent *qEvent) {
        auto event = dynamic_cast<Event *>(qEvent);
        if(!event) {
            return false;
        }
//        qDebug() << "Dispatching event"<<event<<"of type"<<event->string(Key::event);

        switch(event->journalEvent()) {
            // Handle events we have full implementations for.
            // This calls both a specialized method, and the generic method.
#include "events.inc"

            default:
                // Sent generic events for those without special handling.
                onEventGeneric(event);
                break;
        }
        return true;
    }

    EventDispatchMainWindow::EventDispatchMainWindow(QWidget *parent, const Qt::WindowFlags &flags)
        : QMainWindow(parent, flags) {}

    void EventDispatchMainWindow::customEvent(QEvent *qEvent) {
        if(!dispatchJournalEvent(qEvent)) {
            QObject::customEvent(qEvent);
        }
    }
}
