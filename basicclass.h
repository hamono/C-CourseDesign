#ifndef BASICCLASS_H
#define BASICCLASS_H
#include "qstring.h"

#include <QWidget>

class BasicClass
{
protected:
    int code;
    QString title;
    QString author;
    QString level;
    QString status;
public:
    BasicClass(int code,QString title,QString author,QString status="可借",QString level="未评级");
    BasicClass();
    void setCode(int code);
    void setTitle(QString title);
    void setAuthor(QString author);
    void setLevel(QString level);
    void setStatus(QString status);
    ~BasicClass();
};

#endif // BASICCLASS_H
