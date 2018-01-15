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

#include <QtCore/QString>
#include <QtCore/QMap>
#include <QDebug>
#include "RankProgress.h"
namespace Journal {
    RankProgress::RankProgress() : _type(Unknown) { }

    RankProgress::RankProgress(Type type, uint8_t progress)
        : _type(type), _progress(progress) {}

    RankProgress::RankProgress(Type type, Rank rank)
        : _type(type), _rank(rank) {}

    RankProgress::Type RankProgress::type() const {
        return _type;
    }

    bool RankProgress::isValid() const {
        return _type != Unknown;
    }

    RankProgress::Type RankProgress::typeFromString(const QString &typeStr) {
        if(s_rankLookupMap.contains(typeStr)) {
            return s_rankLookupMap[typeStr];
        }
        qDebug() << "Unknown rank type:" << typeStr;
        return Unknown;
    }

    uint8_t RankProgress::progress() const {
        return _progress;
    }

    void RankProgress::setProgress(uint8_t progress) {
        _progress = progress;
    }

    RankProgress::Rank RankProgress::rank() const {
        return _rank;
    }

    void RankProgress::setRank(RankProgress::Rank rank) {
        _rank = rank;
    }

    QMap<QString,RankProgress::Type>
        RankProgress::s_rankLookupMap = {{ "Combat", Combat },
                                         { "Trade", Trade },
                                         { "Explore", Explore },
                                         { "Empire", Empire },
                                         { "Federation", Federation },
                                         { "CQC", CQC },
    };

}
