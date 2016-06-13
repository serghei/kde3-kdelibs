#include <unistd.h>

#include <qstringlist.h>
#include <qdbusconnection.h>
#include <qdbuserror.h>
#include <qdbusdata.h>
#include <qdbusdatalist.h>
#include <qdbusmessage.h>
#include <qdbusobject.h>

#include <kdebug.h>

#include <dcopobject.h>

#include "dcopclient.h"


extern std::map<QCString, DCOPObject *> *kde_dcopObjMap; // defined in dcopobject.cpp


class DCOPClientPrivate : public QDBusObjectBase {
protected:
    bool handleMethodCall(const QDBusMessage &message);

private:
    bool listObjects(const QDBusMessage &message) const;
    bool listFunctions(const QDBusMessage &message) const;

public:
    QDBusConnection dbusConnection;
    QCString appId;
    bool isRegistered;
};


bool DCOPClientPrivate::handleMethodCall(const QDBusMessage &message)
{
//    qWarning("%s", message.interface().toAscii());
//    qWarning("%s", message.member().toAscii());
//    qWarning("DCOPClientPrivate::handleMethodCall()");

    if("ListObjects" == message.member())
        return listObjects(message);
    else if("ListFunctions" == message.member())
        return listFunctions(message);

    return false;
}


bool DCOPClientPrivate::listObjects(const QDBusMessage &message) const
{
    QStringList list;

    if(kde_dcopObjMap)
        for(const auto &it : *kde_dcopObjMap)
            list << it.first;

    QDBusMessage reply = QDBusMessage::methodReply(message);
    reply << QDBusData::fromList(list);
    dbusConnection.send(reply);

    return true;
}


bool DCOPClientPrivate::listFunctions(const QDBusMessage &message) const
{
    QDBusMessage reply;

    if(message.count() == 1 && message[0].type() == QDBusData::String)
    {
        QStringList list;

        // the argument contains objId (the name of DCOPObject)
        DCOPObject *obj = DCOPObject::find(message[0].toString().toUtf8());

        // the requested DCOPObject exists?
        if(obj)
            // yes, populate the list of functions
            for(const auto &fun : obj->functions())
                list << fun;

        // prepare the DBus reply
        reply = QDBusMessage::methodReply(message);
        reply << QDBusData::fromList(list);
    }
    else
    {
        // invalid message, reply an error (probably is missing the name of object)
        QDBusError error = QDBusError::stdInvalidArgs("Expected one argument of string type");
        reply = QDBusMessage::methodError(message, error);
    }

    // send the DBus reply
    dbusConnection.send(reply);
    return true;
}


DCOPClient::DCOPClient()
{
    d = new DCOPClientPrivate;
    d->isRegistered = false;
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
    if(isAttached())
        return true;

    d->dbusConnection = QDBusConnection::addConnection(QDBusConnection::SessionBus);
    return isAttached();
}


void DCOPClient::bindToApp()
{

}


bool DCOPClient::detach()
{
    d->dbusConnection.closeConnection();
    d->appId.clear();
    d->isRegistered = false;
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

    // already registered with this app id
    if(d->appId == newAppId)
        return newAppId;

    // check if we are connected to DBus
    if(!isAttached())
        // if not, attach to DBus
        if(!attach())
        {
            // error, impossible to attach and register
            d->isRegistered = false;
            return QCString();
        }

    // already registered with another name, release the old DBus interface
    if(isRegistered())
    {
        if(!d->dbusConnection.releaseName(QCString("org.kde3.").append(d->appId)))
        {
            // error, impossible to unregister the old name
            return d->appId;
        }
    }

    // register the object to dbus
    if(!d->dbusConnection.requestName(QCString("org.kde3.").append(newAppId)))
    {
        // error, impossible to register
        d->isRegistered = false;
        return QCString();
    }

    // register paths, if the registration is for the first time
    if(!isRegistered())
    {
        d->dbusConnection.registerObject("/", d);
        d->dbusConnection.registerObject("/org/kde3/dcop", d);
    }

    // assign the new app id
    d->appId = newAppId;

    // mark as registered
    d->isRegistered = true;

    return newAppId;
}


bool DCOPClient::isRegistered() const
{
    return d->isRegistered;
}


QCString DCOPClient::appId() const
{
    return d->appId;
}


int DCOPClient::socket() const
{
    return -1;
}


bool DCOPClient::isSuspended() const
{
    return false;
}


bool DCOPClient::send(const QCString &remApp, const QCString &remObj, const QCString &remFun, const QByteArray &data)
{
    return false;
}


bool DCOPClient::send(const QCString &remApp, const QCString &remObj, const QCString &remFun, const QString &data)
{
    return false;
}


bool DCOPClient::call(const QCString &remApp, const QCString &remObj, const QCString &remFun, const QByteArray &data, QCString &replyType, QByteArray &replyData, bool useEventLoop, int timeout)
{
    return false;
}


bool DCOPClient::call(const QCString &remApp, const QCString &remObj, const QCString &remFun, const QByteArray &data, QCString &replyType, QByteArray &replyData, bool useEventLoop)
{
    return false;
}


int DCOPClient::callAsync(const QCString &remApp, const QCString &remObj, const QCString &remFun, const QByteArray &data, QObject *callBackObj, const char *callBackSlot)
{
    return 0;
}


bool DCOPClient::findObject(const QCString &remApp, const QCString &remObj, const QCString &remFun, const QByteArray &data, QCString &foundApp, QCString &foundObj, bool useEventLoop, int timeout)
{
    return false;
}


bool DCOPClient::findObject(const QCString &remApp, const QCString &remObj, const QCString &remFun, const QByteArray &data, QCString &foundApp, QCString &foundObj, bool useEventLoop)
{
    return false;
}


void DCOPClient::emitDCOPSignal(const QCString &object, const QCString &signal, const QByteArray &data)
{

}


bool DCOPClient::connectDCOPSignal(const QCString &sender, const QCString &senderObj, const QCString &signal, const QCString &receiverObj, const QCString &slot, bool Volatile)
{
    return false;
}


bool DCOPClient::disconnectDCOPSignal(const QCString &sender, const QCString &senderObj, const QCString &signal, const QCString &receiverObj, const QCString &slot)
{
    return false;
}


bool DCOPClient::process(const QCString &fun, const QByteArray &data, QCString &replyType, QByteArray &replyData)
{
    return false;
}


DCOPClientTransaction *DCOPClient::beginTransaction()
{
    return nullptr;
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
    call << QDBusData::fromString(remObj);
    QDBusMessage reply = d->dbusConnection.sendWithReply(call, nullptr);

    for(const auto &obj : reply.front().toQValueList())
            list << obj.toString().toUtf8();

    if(ok)
        *ok = true;

    return list;
}


QCString DCOPClient::senderId() const
{
    return QCString();
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
    return nullptr;
}

void DCOPClient::setMainClient(DCOPClient *mainClient)
{

}


void DCOPClient::emergencyClose()
{

}


const char *DCOPClient::postMortemSender()
{
    return nullptr;
}


const char *DCOPClient::postMortemObject()
{
    return nullptr;
}


const char *DCOPClient::postMortemFunction()
{
    return nullptr;
}


QCString DCOPClient::dcopServerFile(const QCString &hostname)
{
    return QCString();
}


QCString DCOPClient::dcopServerFileOld(const QCString &hostname)
{
    return QCString();
}


QCString DCOPClient::iceauthPath()
{
    return QCString();
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
