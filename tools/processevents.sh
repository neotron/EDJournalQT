#!/bin/zsh


cd "$(dirname $0)"
rm -rf output events.inc eventclasses.inc Events.h table.h
mkdir output
cat events.txt | while read ev ; do
    echo "$ev"
    evn="Event${ev}"
    cat > output/${evn}.h  <<EOF
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
#include "Event.h"

namespace Journal {
    class ${evn} : public Event {
    public:
        ${evn}(const QJsonObject &obj, const JFile *file);

    private:

    };
}

EOF

cat > output/${evn}.cpp <<EOF
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

#include "${evn}.h"

namespace Journal {
    ${evn}::${evn}(const QJsonObject &obj, const JFile *file)
        : Event(obj, file, ${ev}) {
    }
}

EOF
cat >> events.inc <<EOF
EVENT(${ev})
EOF
cat >> eventclasses.inc <<EOF
class ${evn};
EOF
cat >> Events.h <<EOF
#include "Events/${evn}.h"
EOF

cat >> table.h <<EOF
                                   { "${ev:l}",              Event::${ev} },
EOF
done
