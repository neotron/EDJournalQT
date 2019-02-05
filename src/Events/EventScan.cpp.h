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

#include <src/JFile.h>
#include <src/Types/Enums.h>
#include "EventScan.h"
#include "Event.h"
namespace Journal {

    EventScan::EventScan(const QJsonObject &obj, const JFile *file)
        : Event(obj, file, Scan), _bodyType(Body::UnknownBody) {
        createBodyInstance();
    }

    void EventScan::createBodyInstance() {
        auto type = string(Key::PlanetClass);
        if(!type.isEmpty()) {
            _bodyType = Body::Planet;
            _planet = std::make_shared<Planet>(*this);
        }

        type = string(Key::StarType);
        if(!type.isEmpty()) {
            _bodyType = Body::Star;
            _star = std::make_shared<Star>(*this);
        }
    }

    Body::Type EventScan::bodyType() const {
        return _bodyType;
    }

    StarPtr EventScan::star() const {
        return _star;
    }

    PlanetPtr EventScan::planet() const {
        return _planet;
    }

    int64_t EventScan::estimatedValue() const {
        switch(_bodyType) {
            case Journal::Body::Star:
                return _star->estimatedValue();
            case Journal::Body::Planet:
                return _planet->estimatedValue();
            default:
                return 0;
        }
    }
}
#pragma once
