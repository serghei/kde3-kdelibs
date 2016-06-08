#include <unistd.h>

#include <qstringlist.h>
#include <qdbusconnection.h>
#include <qdbusdata.h>
#include <qdbusdatalist.h>
#include <qdbusmessage.h>
#include <qdbusobject.h>

#include <kdebug.h>

#include "dcopclient.h"


class DCOPClientPrivate : public QDBusObjectBase {
protected:
    bool handleMethodCall(const QDBusMessage &message);
    
public:
    QDBusConnection dbusConnection;
    QCString appId;
};


bool DCOPClientPrivate::handleMethodCall(const QDBusMessage &message)
{
    qWarning("%s", message.interface().toAscii());
    qWarning("%s", message.member().toAscii());

    // the message is not for us
    //if(message.interface() != QString("org.kde3."+ appId))
    //    return false;

    qWarning("DCOPClientPrivate::handleMethodCall()");

    QDBusMessage reply = QDBusMessage::methodReply(message);

    QStringList list;

    if("ListObjects" == message.member())
    {
        list << "qt";
        list << "KDebug";
        list << "KWinInterface";
        list << "MainApplication-Interface";
    }
    else if("ListFunctions" == message.member())
    {
        list << "KStringList functions()"
             << "KStringList interfaces()"
             << "KStringList objects()"
             << "KStringList find(QCString)";
    }

    reply << QDBusData::fromList(list);

    dbusConnection.send(reply);

    return true;
}


DCOPClient::DCOPClient()
{
    d = new DCOPClientPrivate;
}


DCOPClient::~DCOPClient()
{
    delete d;
}


void DCOPClient::setServerAddress(const QCString &addr)
{

}


bool DCOPClient::attach()
{
    d->dbusConnection = QDBusConnection::addConnection(QDBusConnection::SessionBus);
    return isAttached();
}


void DCOPClient::bindToApp()
{

}

bool DCOPClient::detach()
{

}


bool DCOPClient::isAttached() const
{
    return d->dbusConnection.isConnected();
}


bool DCOPClient::isAttachedToForeignServer() const
{

}


void DCOPClient::setAcceptCalls(bool b)
{

}


void DCOPClient::setQtBridgeEnabled(bool b)
{

}


QCString DCOPClient::registerAs(const QCString &appId, bool addPID)
{
    QCString newAppId = appId;

    // append the pid
    if(addPID)
        newAppId.append(QCString().sprintf("-%d", getpid()));

    // already registered
    if(d->appId == newAppId)
        return newAppId;

    // assign the new app id
    d->appId = newAppId;

    // register the object to dbus
    d->dbusConnection.requestName(QCString("org.kde3.").append(newAppId));

    // register paths
    d->dbusConnection.registerObject("/", d);
    d->dbusConnection.registerObject("/org/kde3/dcop", d);

    return newAppId;
}


bool DCOPClient::isRegistered() const
{

}


QCString DCOPClient::appId() const
{
    return d->appId;
}


int DCOPClient::socket() const
{

}


bool DCOPClient::isSuspended() const
{

}


bool DCOPClient::send(const QCString &remApp, const QCString &remObj, const QCString &remFun, const QByteArray &data)
{

}


bool DCOPClient::send(const QCString &remApp, const QCString &remObj, const QCString &remFun, const QString &data)
{

}


bool DCOPClient::call(const QCString &remApp, const QCString &remObj, const QCString &remFun, const QByteArray &data, QCString &replyType, QByteArray &replyData, bool useEventLoop, int timeout)
{

}


bool DCOPClient::call(const QCString &remApp, const QCString &remObj, const QCString &remFun, const QByteArray &data, QCString &replyType, QByteArray &replyData, bool useEventLoop)
{

}


int DCOPClient::callAsync(const QCString &remApp, const QCString &remObj, const QCString &remFun, const QByteArray &data, QObject *callBackObj, const char *callBackSlot)
{

}


bool DCOPClient::findObject(const QCString &remApp, const QCString &remObj, const QCString &remFun, const QByteArray &data, QCString &foundApp, QCString &foundObj, bool useEventLoop, int timeout)
{

}


bool DCOPClient::findObject(const QCString &remApp, const QCString &remObj, const QCString &remFun, const QByteArray &data, QCString &foundApp, QCString &foundObj, bool useEventLoop)
{

}


void DCOPClient::emitDCOPSignal(const QCString &object, const QCString &signal, const QByteArray &data)
{

}


bool DCOPClient::connectDCOPSignal(const QCString &sender, const QCString &senderObj, const QCString &signal, const QCString &receiverObj, const QCString &slot, bool Volatile)
{

}


bool DCOPClient::disconnectDCOPSignal(const QCString &sender, const QCString &senderObj, const QCString &signal, const QCString &receiverObj, const QCString &slot)
{

}


bool DCOPClient::process(const QCString &fun, const QByteArray &data, QCString &replyType, QByteArray &replyData)
{

}


DCOPClientTransaction *DCOPClient::beginTransaction()
{

}


void DCOPClient::endTransaction(DCOPClientTransaction *t, QCString &replyType, QByteArray &replyData)
{

}


bool DCOPClient::isApplicationRegistered(const QCString &remApp)
{
    return registeredApplications().contains(remApp);
}


KStringList DCOPClient::registeredApplications()
{
    KStringList list;

    QDBusMessage call = QDBusMessage::methodCall("org.freedesktop.DBus", "/org/freedesktop/DBus", "org.freedesktop.DBus", "ListNames");
    QDBusMessage reply = d->dbusConnection.sendWithReply(call, nullptr);

    for(const auto &app : reply.front().toQValueList())
    {
        QCString name = app.toString().toUtf8();
        if("org.kde3." == name.left(9))
            list << name.mid(9);
    }

    return list;
}


KStringList DCOPClient::remoteObjects(const QCString &remApp, bool *ok)
{
    qWarning("DCOPClient::remoteObjects(remApp: \"%s\")", remApp.data());

    if(ok)
        *ok = false;

    KStringList list;

    QDBusMessage call = QDBusMessage::methodCall(QString("org.kde3.%1").arg(remApp), "/org/kde3/dcop", "org.kde3.dcop", "ListObjects");
    QDBusMessage reply = d->dbusConnection.sendWithReply(call, nullptr);

    for(const auto &obj : reply.front().toQValueList())
            list << obj.toString().toUtf8();

    if(ok)
        *ok = true;

    return list;
}


KStringList DCOPClient::remoteFunctions(const QCString &remApp, const QCString &remObj, bool *ok)
{
    qWarning("DCOPClient::remoteFunctions(remApp: \"%s\", remObj: \"%s\")", remApp.data(), remObj.data());

    if(ok)
        *ok = false;

    KStringList list;

    QDBusMessage call = QDBusMessage::methodCall(QString("org.kde3.%1").arg(remApp), "/org/kde3/dcop", "org.kde3.dcop", "ListFunctions");
    QDBusMessage reply = d->dbusConnection.sendWithReply(call, nullptr);

    for(const auto &obj : reply.front().toQValueList())
            list << obj.toString().toUtf8();

    if(ok)
        *ok = true;

    return list;
}


QCString DCOPClient::senderId() const
{

}


void DCOPClient::setDefaultObject(const QCString &objId)
{

}


void DCOPClient::setNotifications(bool enabled)
{

}


void DCOPClient::setDaemonMode(bool daemonMode)
{

}


void DCOPClient::setPriorityCall(bool)
{

}


DCOPClient *DCOPClient::mainClient()
{

}

void DCOPClient::setMainClient(DCOPClient *mainClient)
{

}


void DCOPClient::emergencyClose()
{

}


const char *DCOPClient::postMortemSender()
{

}


const char *DCOPClient::postMortemObject()
{

}


const char *DCOPClient::postMortemFunction()
{

}


QCString DCOPClient::dcopServerFile(const QCString &hostname)
{

}


QCString DCOPClient::dcopServerFileOld(const QCString &hostname)
{

}


QCString DCOPClient::iceauthPath()
{

}


void DCOPClient::processSocketData(int socknum)
{

}


void DCOPClient::processPostedMessagesInternal()
{

}


void DCOPClient::asyncReplyReady()
{

}


void DCOPClient::eventLoopTimeout()
{

}


void DCOPClient::virtual_hook(int id, void *data)
{

}


#include "dcopclient.moc"
