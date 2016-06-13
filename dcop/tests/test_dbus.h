#ifndef _TEST_DBUS_H_
#define _TEST_DBUS_H_

#include <dcopobject.h>

class TestApp : public QObject, virtual public DCOPObject {

    Q_OBJECT
    K_DCOP

public:
     TestApp();

k_dcop:
    virtual ASYNC testAsync();
    virtual QString testSync();
};

#endif
