#ifndef _QCSTRING_H_
#define _QCSTRING_H_

#include <QtCore/QByteArray>


class QCString : public QByteArray {
public:
    QCString(){}
    QCString(const char*){}
    QCString(const QCString&){}
    QCString(const QByteArray&){}
    void sprintf(const char *format, ...){}
    int find(char) const { return 0; }
    int find(const char *) const { return 0; }
    void prepend(const QString&) {}
    QCString &operator=(const char*) {}
    QCString &operator=(const QByteArray&) {}
    int findRev(char) { return -1; }
};


inline QCString operator+(const char *str1, const QCString &str2)
{
    QCString tmp(str1);
    tmp.append(str2);
    return tmp;
}


inline QCString operator+(const QCString &str1, const char *str2)
{
    QCString tmp(str1);
    tmp.append(str2);
    return tmp;
}


inline QCString operator+(const QCString &str1, const QCString &str2)
{
    QCString tmp(str1);
    tmp.append(str2);
    return tmp;
}


#endif
