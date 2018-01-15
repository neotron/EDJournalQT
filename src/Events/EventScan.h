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

#include <QtCore/QDateTime>
#include <QtCore/QString>
#include <QMap>
#include <memory>
#include "Types.h"
#include "Event.h"

namespace Journal {

    class EventScan: public Event {
    public:
        EventScan(const QJsonObject &obj, const JournalFile *file);
        ~EventScan() override = default;

        Body::Type bodyType() const;

        StarPtr star() const;

        PlanetPtr planet() const;

    private:

        Body::Type _bodyType;
        StarPtr _star{};
        PlanetPtr _planet{};

    public:
        void createBodyInstance();
    };
}
