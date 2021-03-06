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
//
// Singleton class used to get live event updates.
//

#pragma once
#include <QCoreApplication>
#include "JFile.h"
#include "Events/Event.h"
#include "Watcher.h"
namespace Journal {
    class LiveJournal : public QObject {
    Q_OBJECT

    public:
        static LiveJournal *instance();

        void startWatching(const QDateTime &newerThanDate, const QString &path, int maxFiles = 0);

        void deregisterHandler(QObject *handler);

         void registerHandler(QObject *handler);

        const State::Commander * commanderState(const QString &name) const;

    public slots:

        void journalPathChanged(const QString &from, const QString &to);

    private:
        explicit LiveJournal(QObject *parent);

        Watcher *_watcher;
    };
}

