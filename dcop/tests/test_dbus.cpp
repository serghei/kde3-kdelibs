#include <qapplication.h>
#include <qtimer.h>

#include "dcopclient.h"

#include "test_dbus.h"


TestApp::TestApp()
    : QObject(), DCOPObject("TestApp")
{
    qWarning("TestApp::TestApp()");
}

void TestApp::testAsync()
{
    qWarning("void TestApp::testAsync()");
}


QString TestApp::testSync()
{
    qWarning("QString TestApp::testSync()");
    return "executed TestApp::testSync()";
}


class Executor : public QObject {

    Q_OBJECT

public:
    Executor(){}

public slots:
    void execute()
    {
        system("/home/serghei/.build/kde3-kdelibs-Desktop-Default/dcop/client/dcop test_dbus &");
        QTimer::singleShot(500, qApp, SLOT(quit()));
    }

};

int main(int argc, char *argv[])
{
    QApplication app(argc, argv, false);
    Executor exe;

    TestApp testApp;

    //QTimer::singleShot(0, &exe, SLOT(execute()));

    DCOPClient dcopClient;

    dcopClient.attach();
    dcopClient.registerAs("test_dbus", false);
    dcopClient.registerAs("test_dbus1", false);

    return app.exec();
}

#include "test_dbus.moc"

#include "test_dbus.moc.cpp"
