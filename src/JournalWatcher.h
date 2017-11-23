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
#include "JournalFile.h"

class JournalWatcher : public QObject {
Q_OBJECT

public:
    explicit JournalWatcher(QObject *parent = nullptr);

    ~JournalWatcher() override;

    void watchDirectory(const QString &dir, const QDateTime &parseNewerThanDate = QDateTime());

public slots:

    void fileChanged(const QString &path);

    void directoryChanged(const QString &path);

    void handleEvent(const JournalFile &journal, const Event &event);

    void journalPathChanged(const QString &from, const QString &to);

signals:

    void onEvent(const JournalFile &journal, const Event &event);

private:
    QFileSystemWatcher           _watcher;
    QMap<QString, JournalFile *> _watchedFiles;
    QDateTime _lastTimeStamp;
    QDateTime _newerThanDate;
};



