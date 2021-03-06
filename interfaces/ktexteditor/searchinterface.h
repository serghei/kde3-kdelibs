/* This file is part of the KDE project
   Copyright (C) 2001 Christoph Cullmann (cullmann@kde.org)

   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Library General Public
   License as published by the Free Software Foundation; either
   version 2 of the License, or (at your option) any later version.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Library General Public License for more details.

   You should have received a copy of the GNU Library General Public License
   along with this library; see the file COPYING.LIB.  If not, write to
   the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.
*/

#ifndef __ktexteditor_searchinterface_h__
#define __ktexteditor_searchinterface_h__

#include <kdelibs_export.h>

class QRegExp;
class QString;
class QCString;

namespace KTextEditor {

/**
*  This is an interface to allow searching of a Document.
*/
class KTEXTEDITOR_EXPORT SearchInterface {
    friend class PrivateSearchInterface;

public:
    SearchInterface();
    virtual ~SearchInterface();

    unsigned int searchInterfaceNumber() const;

protected:
    void setSearchInterfaceDCOPSuffix(const QCString &suffix);

    //
    // slots !!!
    //
public:
    virtual bool searchText(unsigned int startLine, unsigned int startCol, const QString &text, unsigned int *foundAtLine, unsigned int *foundAtCol,
                            unsigned int *matchLen, bool casesensitive = true, bool backwards = false) = 0;
    virtual bool searchText(unsigned int startLine, unsigned int startCol, const QRegExp &regexp, unsigned int *foundAtLine, unsigned int *foundAtCol,
                            unsigned int *matchLen, bool backwards = false) = 0;

private:
    class PrivateSearchInterface *d;
    static unsigned int globalSearchInterfaceNumber;
    unsigned int mySearchInterfaceNumber;
};

KTEXTEDITOR_EXPORT SearchInterface *searchInterface(class Document *doc);
}

#endif
