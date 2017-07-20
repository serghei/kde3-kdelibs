#include <unistd.h>

#include <qstringlist.h>
#include <qdbusconnection.h>
#include <qdbuserror.h>
#include <qdbusdata.h>
#include <qdbusdatalist.h>
#include <qdbusmessage.h>
#include <qdbusobject.h>

#include <dcopobject.h>

#include "dcopclient.h"


extern std::map<QCString, DCOPObject *> *kde_dcopObjMap; // defined in dcopobject.cpp
static DCOPClient *dcop_mainClient = nullptr;


class DCOPClientPrivate : public QDBusObjectBase {
protected:
    bool handleMethodCall(const QDBusMessage &message);

private:
    bool listObjects(const QDBusMessage &message) const;
    bool listFunctions(const QDBusMessage &message) const;
    bool call(const QDBusMessage &message) const;

    bool replyError(const QDBusMessage &message, const QCString &error) const;

public:
    QDBusConnection dbusConnection;
    QCString appId;
    bool isRegistered;
};


bool DCOPClientPrivate::handleMethodCall(const QDBusMessage &message)
{
    if("ListObjects" == message.member())
        return listObjects(message);
    else if("ListFunctions" == message.member())
        return listFunctions(message);
    else if("Call" == message.member())
        return call(message);

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


bool DCOPClientPrivate::call(const QDBusMessage &message) const
{
    // check the correctness of message
    if(message.count() != 3
       || message[0].type() != QDBusData::String
       || message[1].type() != QDBusData::String
       || message[2].type() != QDBusData::List)
    {
        return replyError(message, "Invalid number or type of arguments");
    }

    // object id
    QCString objId = message[0].toString().toUtf8();

    // try to find the object
    DCOPObject *obj = DCOPObject::find(objId);

    // the requested object doesn't exists
    if(nullptr == obj)
        return replyError(message, "No such object");

    // function
    QCString fun = message[1].toString().toUtf8();

    // data
    QValueList<uint8_t> dbusData = message[2].toList().toByteList();
    QByteArray data(dbusData.size());
    for(int i = 0; i < dbusData.size(); i++)
        data[i] = dbusData[i];

    // result data
    QCString replyType;
    QByteArray replyData;

    // try to execute the function
    if(!obj->process(fun, data, replyType, replyData))
        return replyError(message, "No such function");

    // QDBus can handle only lists of bytes,
    // convert QByteArray to QValueList<uint8_t>
    dbusData.clear();
    for(const uint8_t byte : replyData)
        dbusData << byte;

    // add data to reply message
    QDBusMessage reply = QDBusMessage::methodReply(message);
    reply << QDBusData::fromString(replyType);
    reply << QDBusData::fromList(dbusData);

    // send the DBus reply
    return dbusConnection.send(reply);
}


bool DCOPClientPrivate::replyError(const QDBusMessage &message, const QCString &error) const
{
    QDBusMessage reply = QDBusMessage::methodError(message, QDBusError::stdInvalidArgs(error));
    return dbusConnection.send(reply);
}



// ################################################################################################



DCOPClient::DCOPClient()
{
    d = new DCOPClientPrivate;
    d->isRegistered = false;

    if(!mainClient())
        setMainClient(this);
}


DCOPClient::~DCOPClient()
{
    delete d;
}


void DCOPClient::setServerAddress(const QCString &addr)
{
    qWarning("DCOPClient::setServerAddress(addr: \"%s\") -- not implemented", addr.data());
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
    qWarning("DCOPClient::bindToApp() -- not implemented");
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
    qWarning("DCOPClient::isAttachedToForeignServer() -- not implemented");
    return false;
}


void DCOPClient::setAcceptCalls(bool b)
{
    qWarning("DCOPClient::setAcceptCalls(b: %d) -- not implemented", b);
}


void DCOPClient::setQtBridgeEnabled(bool b)
{
    qWarning("DCOPClient::setQtBridgeEnabled(b: %d) -- not implemented", b);
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
    {
        // if not, attach to DBus
        if(!attach())
        {
            // error, impossible to attach and register
            d->isRegistered = false;
            return QCString();
        }
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
    qWarning("DCOPClient::socket() -- not implemented");
    return -1;
}


bool DCOPClient::isSuspended() const
{
    qWarning("DCOPClient::isSuspended() -- not implemented");
    return false;
}


bool DCOPClient::send(const QCString &remApp, const QCString &remObj, const QCString &remFun, const QByteArray &data)
{
    qWarning("DCOPClient::send(remApp: \"%s\", remObj: \"%s\", remFun: \"%s\", data: \"%s\") -- not implemented", remApp.data(), remObj.data(), remFun.data(), data.data());
    return false;
}


bool DCOPClient::send(const QCString &remApp, const QCString &remObj, const QCString &remFun, const QString &data)
{
    qWarning("DCOPClient::send(remApp: \"%s\", remObj: \"%s\", remFun: \"%s\", data: \"%s\") -- not implemented", remApp.data(), remObj.data(), remFun.data(), data.data());
    return false;
}


bool DCOPClient::call(const QCString &remApp, const QCString &remObj, const QCString &remFun, const QByteArray &data, QCString &replyType, QByteArray &replyData, bool useEventLoop, int timeout)
{
    qWarning("DCOPClient::call(remApp: \"%s\", remObj: \"%s\", remFun: \"%s\")", remApp.data(), remObj.data(), remFun.data());

    if(remApp.isEmpty())
        return false;

    // QDBus can handle only lists of bytes,
    // convert QByteArray to QValueList<uint8_t>
    QValueList<uint8_t> dbusData;
    for(const uint8_t byte : data)
        dbusData << byte;

    // send request to DBus
    QDBusMessage call = QDBusMessage::methodCall(QString("org.kde3.%1").arg(remApp), "/org/kde3/dcop", "org.kde3.dcop", "Call");
    call << QDBusData::fromString(remObj);
    call << QDBusData::fromString(remFun);
    call << QDBusData::fromList(dbusData);

    // receive the response from DBus
    QDBusError error;
    QDBusMessage reply = d->dbusConnection.sendWithReply(call, &error);

    // received error?
    if(QDBusError::InvalidError != error.type())
    {
        qWarning("error: %s", error.message().latin1());
        return false;
    }

    // get reply type
    replyType = reply[0].toString().toUtf8();

    // convert list of bytes to QByteArray
    dbusData = reply[1].toList().toByteList();
    replyData.resize(dbusData.size());
    for(int i = 0; i < dbusData.size(); i++)
        replyData[i] = dbusData[i];

    return true;
}


bool DCOPClient::call(const QCString &remApp, const QCString &remObj, const QCString &remFun, const QByteArray &data, QCString &replyType, QByteArray &replyData, bool useEventLoop)
{
    return call(remApp, remObj, remFun, data, replyType, replyData, useEventLoop, -1);
}


int DCOPClient::callAsync(const QCString &remApp, const QCString &remObj, const QCString &remFun, const QByteArray &data, QObject *callBackObj, const char *callBackSlot)
{
    qWarning("DCOPClient::callAsync(remApp: \"%s\", remObj: \"%s\", remFun: \"%s\", data: \"%s\", callBackObj: %p, callBackSlot: \"%s\") -- not implemented", remApp.data(), remObj.data(), remFun.data(), data.data(), callBackObj, callBackSlot);
    return 0;
}


bool DCOPClient::findObject(const QCString &remApp, const QCString &remObj, const QCString &remFun, const QByteArray &data, QCString &foundApp, QCString &foundObj, bool useEventLoop, int timeout)
{
    qWarning("DCOPClient::findObject() -- not implemented");
    return false;
}


bool DCOPClient::findObject(const QCString &remApp, const QCString &remObj, const QCString &remFun, const QByteArray &data, QCString &foundApp, QCString &foundObj, bool useEventLoop)
{
    qWarning("DCOPClient::findObject() -- not implemented");
    return false;
}


void DCOPClient::emitDCOPSignal(const QCString &object, const QCString &signal, const QByteArray &data)
{
    qWarning("DCOPClient::emitDCOPSignal(object: \"%s\", signal: \"%s\", data: \"%s\") -- not implemented", object.data(), signal.data(), data.data());
}


bool DCOPClient::connectDCOPSignal(const QCString &sender, const QCString &senderObj, const QCString &signal, const QCString &receiverObj, const QCString &slot, bool Volatile)
{
    qWarning("DCOPClient::connectDCOPSignal(sender: \"%s\", senderObj: \"%s\", signal: \"%s\", receiverObj: \"%s\", slot: \"%s\", Volatile: %d) -- not implemented", sender.data(), senderObj.data(), signal.data(), receiverObj.data(), slot.data(), Volatile);
    return false;
}


bool DCOPClient::disconnectDCOPSignal(const QCString &sender, const QCString &senderObj, const QCString &signal, const QCString &receiverObj, const QCString &slot)
{
    qWarning("DCOPClient::disconnectDCOPSignal(sender: \"%s\", senderObj: \"%s\", signal: \"%s\", receiverObj: \"%s\", slot: \"%s\") -- not implemented", sender.data(), senderObj.data(), signal.data(), receiverObj.data(), slot.data());
    return false;
}


bool DCOPClient::process(const QCString &fun, const QByteArray &data, QCString &replyType, QByteArray &replyData)
{
    qWarning("DCOPClient::process(fun: \"%s\", data: \"%s\", replyType: OUT, replyData: OUT) -- not implemented", fun.data(), data.data());
    return false;
}


DCOPClientTransaction *DCOPClient::beginTransaction()
{
    qWarning("DCOPClient::beginTransaction() -- not implemented");
    return nullptr;
}


void DCOPClient::endTransaction(DCOPClientTransaction *t, QCString &replyType, QByteArray &replyData)
{
    qWarning("DCOPClient::endTransaction(t: %p, replyType: OUT, replyData: OUT) -- not implemented", t);
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
    qWarning("DCOPClient::remoteObjects(remApp: \"%s\", ok: OUT)", remApp.data());

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
    qWarning("DCOPClient::remoteFunctions(remApp: \"%s\", remObj: \"%s\", ok: OUT)", remApp.data(), remObj.data());

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
    qWarning("DCOPClient::senderId() -- not implemented");
    return QCString();
}


void DCOPClient::setDefaultObject(const QCString &objId)
{
    qWarning("DCOPClient::setDefaultObject(objId: \"%s\") -- not implemented", objId.data());
}


void DCOPClient::setNotifications(bool enabled)
{
    qWarning("DCOPClient::setNotifications(enabled: %d) -- not implemented", enabled);
}


void DCOPClient::setDaemonMode(bool daemonMode)
{
    qWarning("DCOPClient::setDaemonMode(daemonMode: %d) -- not implemented", daemonMode);
}


void DCOPClient::setPriorityCall(bool b)
{
    qWarning("DCOPClient::setPriorityCall(b: %d) -- not implemented", b);
}


DCOPClient *DCOPClient::mainClient()
{
    return dcop_mainClient;
}


void DCOPClient::setMainClient(DCOPClient *mainClient)
{
    dcop_mainClient = mainClient;
}


void DCOPClient::emergencyClose()
{
    qWarning("DCOPClient::emergencyClose() -- not implemented");
}


const char *DCOPClient::postMortemSender()
{
    qWarning("DCOPClient::postMortemSender() -- not implemented");
    return nullptr;
}


const char *DCOPClient::postMortemObject()
{
    qWarning("DCOPClient::postMortemObject() -- not implemented");
    return nullptr;
}


const char *DCOPClient::postMortemFunction()
{
    qWarning("DCOPClient::postMortemFunction() -- not implemented");
    return nullptr;
}


QCString DCOPClient::dcopServerFile(const QCString &hostname)
{
    qWarning("DCOPClient::dcopServerFile(hostname: \"%s\") -- not implemented", hostname.data());
    return QCString();
}


QCString DCOPClient::dcopServerFileOld(const QCString &hostname)
{
    qWarning("DCOPClient::dcopServerFileOld(hostname: \"%s\") -- not implemented", hostname);
    return QCString();
}


QCString DCOPClient::iceauthPath()
{
    qWarning("DCOPClient::iceauthPath() -- not implemented");
    return QCString();
}


void DCOPClient::processSocketData(int socknum)
{
    qWarning("DCOPClient::processSocketData(socknum: %d) -- not implemented", socknum);
}


void DCOPClient::processPostedMessagesInternal()
{
    qWarning("DCOPClient::processPostedMessagesInternal() -- not implemented");
}


void DCOPClient::asyncReplyReady()
{
    qWarning("DCOPClient::asyncReplyReady() -- not implemented");
}


void DCOPClient::eventLoopTimeout()
{
    qWarning("DCOPClient::eventLoopTimeout() -- not implemented");
}


void DCOPClient::virtual_hook(int id, void *data)
{
    qWarning("DCOPClient::virtual_hook(id: %d, data: %p) -- not implemented", id, data);
}


#include "dcopclient.moc"
