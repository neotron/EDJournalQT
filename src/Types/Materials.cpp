//
// Created by neotron on 2018-01-07.
//

#include <QtCore/QJsonObject>
#include <QtCore/QJsonValue>
#include <QtCore/QJsonArray>
#include "Materials.h"
#include "MaterialTable.h"
#include <utility>
#include <src/Events/Key.h>

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

    int16_t Material::quantity() const {
        return _quantity;
    }

    void Material::setQuantity(int16_t quantity) {
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

    // Create a material object from a json value.
    // Handles both raw strings, should those ever occur,
    // and Name/Count or Name/Percent dictionaries.
    Material Materials::material(const QJsonValue &value) {
        Material material;
        if(value.isString()) {
            material = Materials::material(value.toString());
        } else if(value.isObject()) {
            material = Materials::material(value.toObject());
        }
        return material;
    }

    Material Materials::material(const QJsonObject &obj) {
        Material material = Materials::material(obj.value(Key::Name).toString());
        if(material.isValid()) {
            material.setQuantity(static_cast<int16_t>(obj.value(Key::Count).toInt(0)));
            material.setPercentage(obj.value(Key::Percent).toDouble(0.0));
        }
        return material;
    }

    QList<Material> Materials::materials(const QJsonArray &arr) {
        QList<Material> materials;
        for(auto const &mat: arr) {
            auto material = Materials::material(mat);
            if(material.isValid()) {
                materials += material;
            }
        }
        return materials;
    }

    QList<Material> Materials::materials(const QJsonValue &value) {
        return materials(value.toArray());
    }
}
