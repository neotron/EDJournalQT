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
#include <deps/EDJournalQT/src/JournalFile.h>
#include <deps/EDJournalQT/src/Event.h>
#include <deps/EDJournalQT/src/JournalWatcher.h>

class LiveJournal : public QObject {
    Q_OBJECT


public:
    static LiveJournal *instance();
    void startWatching(const QDateTime &newerThanDate);

public slots:
    void handleEvent(const JournalFile &, const Event &);
    void journalPathChanged(const QString &from, const QString &to);

signals:
    void onEvent(const JournalFile &, const Event &);
private:
    explicit LiveJournal(QObject *parent);

    JournalWatcher *_watcher;
};


