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

#include <cstdint>

namespace Journal {
    class RankProgress {
    public:
        enum Type {
            Unknown,
            Combat,
            Trade,
            Explore,
            CQC,
            Empire,
            Federation
        };
        enum Rank {
            Rank0,
            Rank1,
            Rank2,
            Rank3,
            Rank4,
            Rank5,
            Rank6,
            Rank7,
            Rank8,
        };
        RankProgress();
        explicit RankProgress(Type type, uint8_t progress);
        explicit RankProgress(Type type, Rank rank);

        Type type() const;

        uint8_t progress() const;

        void setProgress(uint8_t progress);

        Rank rank() const;

        void setRank(Rank rank);

        bool isValid() const;

        static Type typeFromString(const QString &typeStr);
    private:
        Type _type{};
        uint8_t _progress{};
        Rank _rank{};

        static QMap<QString,RankProgress::Type> s_rankLookupMap;
    };
}
