#include <qapplication.h>
#include <qtimer.h>

#include "dcopclient.h"

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

    //QTimer::singleShot(0, &exe, SLOT(execute()));

    DCOPClient dcopClient;

    dcopClient.attach();
    dcopClient.registerAs("test_dbus", false);

    return app.exec();
}


#include "test_dbus.moc.cpp"
