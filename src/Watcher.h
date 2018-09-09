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

#include <QFileSystemWatcher>
#include <QMap>
#include "JFile.h"

namespace Journal {
    namespace State {
        class Commander;
        class CommanderState;
    }
    class Watcher : public QObject {
    Q_OBJECT

    public:
        explicit Watcher(QObject *parent = nullptr);

        ~Watcher() override;

        void watchDirectory(const QString &dir, const QDateTime &parseNewerThanDate, int newestOnly = false);

        void registerHandler(QObject *handler);

        void deregisterHandler(QObject *handler);

        State::CommanderState *state() const;

        const State::Commander * commanderState(const QString &name) const;

    public slots:

        void fileChanged(const QString &path);

        void directoryChanged(const QString &path);

        void journalPathChanged(const QString &from, const QString &to);

    private:
        State::CommanderState *_state;
        QSet<QObject *> _eventHandlers;
        QFileSystemWatcher           _watcher;
        QMap<QString, JFile *> _watchedFiles;
        QDateTime _lastTimeStamp;
        QDateTime _newerThanDate;
    };
}

