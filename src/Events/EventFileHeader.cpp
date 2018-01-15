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

#include "EventFileHeader.h"

namespace Journal {
    EventFileHeader::EventFileHeader(const QJsonObject &obj, const JournalFile *file)
        : Event(obj, file, FileHeader) {
        _language = string(Key::language);
        _version = string(Key::gameversion);
        _build = string(Key::build);
        _isBeta = _version.contains("beta", Qt::CaseInsensitive);
    }

    const QString &EventFileHeader::language() const {
        return _language;
    }

    const QString &EventFileHeader::version() const {
        return _version;
    }

    const QString &EventFileHeader::build() const {
        return _build;
    }

    bool EventFileHeader::isBeta() const {
        return _isBeta;
    }
}

