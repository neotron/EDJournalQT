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
#include <QtCore/QString>
#include "Types/Materials.h"

namespace Journal::Extension {
    class CreditsChanged {
    public:
        explicit CreditsChanged(int64_t creditChange)
            : _creditChange(creditChange) {}

        // Credit change is either negative or positive depending on if it's a profit or not.
        int64_t creditChange() const {
            return _creditChange;
        }

    protected:
        int64_t _creditChange;
    };

    class CommodityExchange: public CreditsChanged {
    public:
        explicit CommodityExchange(QString type, int64_t perItemCredits = 0, int16_t count = 1)
            : CreditsChanged(perItemCredits * count), _type(std::move(type)), _perItemCredits(perItemCredits), _count(count) {}

        const QString &type() const {
            return _type;
        }

        int16_t count() const {
            return _count;
        }

        int64_t perItemCredits() const {
            return _perItemCredits;
        }

    protected:
        QString _type{};
        int64_t _perItemCredits{};
        int16_t _count{};
    };

    class MaterialsChanged {
    public:
        explicit MaterialsChanged(const QJsonObject &material)
        : _materials({ Materials::material(material) })
        {}

        explicit MaterialsChanged(const QJsonValue &materials) {
            if(materials.isArray()) {
            } else {
                _materials += Materials::material(materials);
            }
        }

        const QList<Material> &materials() const {
            return _materials;
        }

    protected:
        QList<Material> _materials;
    };
}

