/*
 *  This file is part of the KDE libraries
 *  Copyright (c) 2001 Michael Goffioul <kdeprint@swing.be>
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Library General Public
 *  License version 2 as published by the Free Software Foundation.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Library General Public License for more details.
 *
 *  You should have received a copy of the GNU Library General Public License
 *  along with this library; see the file COPYING.LIB.  If not, write to
 *  the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 *  Boston, MA 02110-1301, USA.
 **/

#ifndef KMSPECIALMANAGER_H
#define KMSPECIALMANAGER_H

#include <qobject.h>
#include <qmap.h>

class KMPrinter;
class KMManager;
class KXmlCommand;
class DrMain;

class KMSpecialManager : public QObject {
public:
    KMSpecialManager(KMManager *parent, const char *name = 0);

    bool loadPrinters();
    bool savePrinters();
    void refresh();
    KXmlCommand *loadCommand(KMPrinter *);
    KXmlCommand *loadCommand(const QString &cmd);
    DrMain *loadDriver(KMPrinter *);
    QString setupCommand(const QString &cmd, const QMap< QString, QString > &opts);

protected:
    bool loadDesktopFile(const QString &);

private:
    KMManager *m_mgr;
    bool m_loaded;
};

#endif
