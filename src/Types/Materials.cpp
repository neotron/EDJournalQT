//
// Created by neotron on 2018-01-07.
//

#include "Materials.h"
#include "MaterialTable.h"
#include <utility>
namespace Journal {

    Material::Material(QString id, QString name, QString abbreviation, Material::Rarity rarity, Material::Type type)
        : _id(std::move(id)), _name(std::move(name)), _abbreviation(std::move(abbreviation)), _rarity(rarity),
          _type(type) {}

    const QString &Material::id() const {
        return _id;
    }

    const QString &Material::name() const {
        return _name;
    }

    const QString &Material::abbreviation() const {
        return _abbreviation;
    }

    Material::Rarity Material::rarity() const {
        return _rarity;
    }

    Material::Type Material::type() const {
        return _type;
    }

    bool Material::isValid() const {
        return _type != Invalid;
    }

    QString Material::typeName() const {
        switch(_type) {
            case Manufactured:
                return "Man";
            case Encoded:
                return "Enc";
            case Raw:
                return "Raw";
            default:
                return "Unk";
        }
    }

    QString Material::rarityName() const {
        switch(_rarity) {
            case VeryCommon:
                return "    ";
            case Common:
                return "+   ";
            case Standard:
                return "++  ";
            case Rare:
                return "+++ ";
            case VeryRare:
                return "++++";
        }
        return "     ";
    }

    quint16 Material::quantity() const {
        return _quantity;
    }

    void Material::setQuantity(quint16 quantity) {
        _quantity = quantity;
    }

    double Material::percentage() const {
        return _percentage;
    }

    void Material::setPercentage(double percentage) {
        _percentage = percentage;
    }

    Material Materials::material(const QString &id) {
        return _materialTable[id];
    }
}
