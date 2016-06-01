#!/bin/sh

DEST=./qt3-compat

write_header()
{
    fname=$1

    YEAR=`date +%Y`
    cat > $DEST/$fname <<EOF
/************************************************************************\\
 *
 *  (c) $YEAR by Serghei Amelian <serghei.amelian@gmail.com>
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
\************************************************************************/
EOF
}

class_name=$1
var_name=`echo -n $1 | sed 's/^ice_//g'`

if [ -z $class_name ]; then
    echo "Missing the name of class!"
    exit
fi

# DECLARATION

h_fname=`echo "${class_name}.h" | tr '[:upper:]' '[:lower:]'`

if [ -f $h_fname ]; then
    echo "This class already exists!"
    exit
fi

write_header $h_fname
guard=`echo "_${class_name}_H_" | tr '[:lower:]' '[:upper:]'`

cat>>$DEST/$h_fname<<EOF
#ifndef $guard
#define $guard

#include <QtCore/>

#endif // $guard
EOF
