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
#include <QDebug>
#include <chrono>
#include <QFileInfo>
#include <thread>
#include <QDir>
#include "JournalWatcher.h"

void JournalWatcher::watchDirectory(const QString &path, const QDateTime &parseNewerThanDate) {
    _watcher.addPath(path);
    _newerThanDate = parseNewerThanDate;
    QDir dir(path, "Journal.*.log");
    QFileInfoList list = dir.entryInfoList(QDir::NoDotAndDotDot | QDir::Files, QDir::Time);
    bool didStartMonitoring = false;
    auto monitorDate = QDateTime::currentDateTime().addSecs(-3600); // Things changed in the last hour.
    for(const auto &entry : list) {
        if(entry.lastModified() > monitorDate && !didStartMonitoring) {
            fileChanged(entry.absoluteFilePath());
            didStartMonitoring = true;
        } else if(parseNewerThanDate.isValid() && entry.lastModified() >= parseNewerThanDate) {
            JournalFile journal(entry.absoluteFilePath());
            connect(&journal, SIGNAL(onEvent(const JournalFile &, const Event &)), this, SLOT(handleEvent(const JournalFile &, const Event &)));
            journal.parse();
        }
    }
}

JournalWatcher::JournalWatcher(QObject *parent) : QObject(parent), _watcher(), _watchedFiles(), _lastTimeStamp() {
    connect(&_watcher, SIGNAL(fileChanged(const QString &)), this, SLOT(fileChanged(const QString &)));
    connect(&_watcher, SIGNAL(directoryChanged(const QString &)), this, SLOT(directoryChanged(const QString &)));
}

void JournalWatcher::directoryChanged(const QString &path) {
    QDir dir(path, "Journal.*.log");
    QFileInfoList list = dir.entryInfoList(QDir::NoDotAndDotDot | QDir::Files, QDir::Time);
    auto newest = list.first();

    auto latestFile = newest.absoluteFilePath();

    if(newest.lastModified() > _lastTimeStamp && !_watchedFiles.contains(latestFile)) {
        _lastTimeStamp = newest.lastModified();
        fileChanged(latestFile);
    }

}

void JournalWatcher::fileChanged(const QString &path) {
    auto journal = _watchedFiles[path];
    QFileInfo checkFile(path);
    if(!checkFile.exists()) {
        if(journal) {
            _watchedFiles.remove(path);
            delete journal;
        }
        return;
    }
    if(!journal) {
        journal = new JournalFile(path);
        _watchedFiles[path] = journal;
        connect(journal, SIGNAL(onEvent(const JournalFile &, const Event &)), this, SLOT(handleEvent(const JournalFile &, const Event &)));
        journal->startWatching();
    }
    journal->parse();
    _watcher.addPath(path);
}


JournalWatcher::~JournalWatcher() {
    _watcher.removePaths(_watcher.directories());
    _watcher.removePaths(_watcher.files());
    for(auto ptr: _watchedFiles) {
        delete ptr;
    }
    _watchedFiles.clear();
}

void JournalWatcher::handleEvent(const JournalFile &journal, const Event &event) {
    emit onEvent(journal, event);
}

void JournalWatcher::journalPathChanged(const QString &from, const QString &to) {
    _watcher.removePath(from);
    watchDirectory(to, _newerThanDate);
}


