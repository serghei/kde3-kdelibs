/* This file is part of the KDE libraries
   Copyright (C) 2000 Matej Koss <koss@miesto.sk>

   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Library General Public
   License version 2 as published by the Free Software Foundation.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Library General Public License for more details.

   You should have received a copy of the GNU Library General Public License
   along with this library; see the file COPYING.LIB.  If not, write to
   the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.
*/
#ifndef __defaultprogress_h__
#define __defaultprogress_h__

#include <qlabel.h>

#include <kio/global.h>

#include <kprogress.h>

#include "progressbase.h"

class KLineEdit;

namespace KIO {

/*
 * A default implementation of the progress dialog ProgressBase.
 * ProgressBase
 */
class KIO_EXPORT DefaultProgress : public ProgressBase {

    Q_OBJECT

public:
    /**
     * Creates a new default progress dialog.
     * @param showNow true to show immediately, false to show when
     *                needed
     */
    DefaultProgress(bool showNow = true);
    /**
     * Creates a new default progress dialog.
     * @param parent the parent of the dialog (or 0 for top-level)
     * @param name the name of the dialog, can be 0
     * @since 3.1
     */
    DefaultProgress(QWidget *parent, const char *name = 0);
    ~DefaultProgress();

    bool keepOpen() const;

    /// Shared with uiserver.cpp
    static QString makePercentString(unsigned long percent, KIO::filesize_t totalSize, unsigned long totalFiles);

public slots:
    virtual void slotTotalSize(KIO::Job *job, KIO::filesize_t size);
    virtual void slotTotalFiles(KIO::Job *job, unsigned long files);
    virtual void slotTotalDirs(KIO::Job *job, unsigned long dirs);

    virtual void slotProcessedSize(KIO::Job *job, KIO::filesize_t bytes);
    virtual void slotProcessedFiles(KIO::Job *job, unsigned long files);
    virtual void slotProcessedDirs(KIO::Job *job, unsigned long dirs);

    virtual void slotSpeed(KIO::Job *job, unsigned long speed);
    virtual void slotPercent(KIO::Job *job, unsigned long percent);
    /**
     * Called to set an information message.
     * @param job the KIO::Job
     * @param msg the message to set
     */
    virtual void slotInfoMessage(KIO::Job *job, const QString &msg);

    virtual void slotCopying(KIO::Job *job, const KURL &src, const KURL &dest);
    virtual void slotMoving(KIO::Job *job, const KURL &src, const KURL &dest);
    virtual void slotDeleting(KIO::Job *job, const KURL &url);
    /**
     * Called when the job is transferring.
     * @param job the KIO::Job
     * @param url the url to transfer
     * @since 3.1
     */
    void slotTransferring(KIO::Job *job, const KURL &url);
    virtual void slotCreatingDir(KIO::Job *job, const KURL &dir);
    /**
     * Called when the job is requesting a stat.
     * @param job the KIO::Job
     * @param dir the dir to stat
     * @since 3.1
     */
    virtual void slotStating(KIO::Job *job, const KURL &dir);
    /**
     * Called when the job is mounting.
     * @param job the KIO::Job
     * @param dev the device to mount
     * @param point the mount point
     */
    virtual void slotMounting(KIO::Job *job, const QString &dev, const QString &point);
    /**
     * Called when the job is unmounting.
     * @param job the KIO::Job
     * @param point the mount point
     */
    virtual void slotUnmounting(KIO::Job *job, const QString &point);
    virtual void slotCanResume(KIO::Job *job, KIO::filesize_t from);

    /**
     * Called when the job is cleaned.
     * @since 3.1
     */
    void slotClean();

protected:
    /// @since 3.1
    void init();
    void showTotals();
    void setDestVisible(bool visible);
    /// @since 3.1
    void checkDestination(const KURL &dest);

    KLineEdit *sourceEdit;
    KLineEdit *destEdit;
    QLabel *progressLabel;
    QLabel *destInvite;
    QLabel *speedLabel;
    QLabel *sizeLabel;
    QLabel *resumeLabel;

    KProgress *m_pProgressBar;

    KIO::filesize_t m_iTotalSize;
    unsigned long m_iTotalFiles;
    unsigned long m_iTotalDirs;

    KIO::filesize_t m_iProcessedSize;
    unsigned long m_iProcessedDirs;
    unsigned long m_iProcessedFiles;

    enum ModeType
    {
        Copy,
        Move,
        Delete,
        Create,
        Done
    };
    ModeType mode;

protected:
    virtual void virtual_hook(int id, void *data);

private:
    class DefaultProgressPrivate;
    DefaultProgressPrivate *d;
private slots:
    void slotKeepOpenToggled(bool);
    void slotOpenFile();
    void slotOpenLocation();
};

} /* namespace */

#endif // __defaultprogress_h__
