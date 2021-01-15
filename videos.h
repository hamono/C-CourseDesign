#ifndef VIDEOS_H
#define VIDEOS_H

#include <QWidget>
#include "basicclass.h"
#include "QString"

struct AttributesV
{
    int code;
    QString title;
    QString author;
    QString status;
    QString level;
    QString publishAuthor;
    QString publishYear;
    long videoTime;

    AttributesV();
    AttributesV(int code,QString title,QString author,QString publishAuthor,QString publishYear, long videoTime,QString status ,QString level);
};

class Videos:public BasicClass
{
    QString publishAuthor;
    QString publishYear;
    long videoTime;
public:
    Videos();
    Videos(QString publishAuthor,QString publishYear,long videoTime,int code,QString title,QString author,QString status ,QString level);
    void create(QString publishAuthor,QString publishYear,long videoTime,int code,QString title,QString author,QString status ,QString level);
    void setPublishYear(QString year);
    void setTime(long time);
    void setPublishAuthor(QString author);
    AttributesV getItems();
    ~Videos();
};

#endif // VIDEOS_H
