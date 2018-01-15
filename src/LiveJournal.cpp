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

#include "JournalWatcher.h"
#include "LiveJournal.h"
namespace Journal {
    LiveJournal::LiveJournal(QObject *parent)
        : QObject(parent), _watcher(new JournalWatcher(this)) {
    }

    LiveJournal *LiveJournal::instance() {
        static LiveJournal *s_journal = nullptr;
        if(!s_journal) {
            s_journal = new LiveJournal(qApp);
        }
        return s_journal;
    }

    void LiveJournal::startWatching(const QDateTime &newerThanDate, const QString &path) {
        _watcher->watchDirectory(path, newerThanDate);
    }

    void LiveJournal::journalPathChanged(const QString &from, const QString &to) {
        _watcher->journalPathChanged(from, to);
    }

    void LiveJournal::registerHandler(QObject *handler) {
        _watcher->registerHandler(handler);
    }

    void LiveJournal::deregisterHandler(QObject *handler) {
        _watcher->deregisterHandler(handler);
    }
}
