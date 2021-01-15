#ifndef BOOKS_H
#define BOOKS_H

#include <QWidget>
#include "basicclass.h"
#include "QString"

struct Attributes
{
    int code;
    QString title;
    QString author;
    QString status;
    QString level;
    QString publisHouse;
    QString isbnCode;
    int pageNum;

    Attributes();
    Attributes(int code,QString title,QString author,QString publisHouse,QString isbnCode,int pageNum,QString status ,QString level);
};

class Books:public BasicClass
{
private:
    QString publisHouse;
    QString isbnCode;
    int pageNum;
public:
    Books();
    Books(int code,QString title,QString author,QString publisHouse,QString isbnCode,int pageNum,QString status ,QString level);
    void create(int code,QString title,QString author,QString publisHouse,QString isbnCode,int pageNum,QString status ,QString level);
    void setISBNCode(QString isbnCode);
    void setPageNum(int num);
    void setPublishHouse(QString publisHouse);
    Attributes getItems();
    ~Books();
};

#endif // BOOKS_H
