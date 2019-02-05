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
#include <QJsonValue>
#include "EventExtensions.h"
namespace Journal::Extension {
    CreditsChanged::~CreditsChanged() = default;
    MaterialsChanged::~MaterialsChanged() = default;
    CommodityExchange::~CommodityExchange() = default;

    MaterialsChanged::MaterialsChanged(const QJsonValue &materials) {
        if(materials.isArray()) {
        } else {
            _materials += Materials::material(materials);
        }
    }

    MaterialsChanged::MaterialsChanged(const QJsonObject &material)
        : _materials({ Materials::material(material) })
    {}

    const QList<Material> &MaterialsChanged::materials() const {
        return _materials;
    }

    CommodityExchange::CommodityExchange(QString type, int64_t perItemCredits, int16_t count)
        : CreditsChanged(perItemCredits * count), _type(std::move(type)), _perItemCredits(perItemCredits), _count(count) {}

    CreditsChanged::CreditsChanged(int64_t creditChange)
        : _creditChange(creditChange) {}
}
#pragma once
