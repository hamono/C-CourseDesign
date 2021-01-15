#include "books.h"

Books::Books(int code,QString title,QString author,QString publisHouse,QString isbnCode,int pageNUm,QString status ,QString level)
    :BasicClass(code, title,author,status,level)
{
    this->publisHouse=publisHouse;
    this->isbnCode=isbnCode;
    this->pageNum=pageNUm;
}

void Books::create(int code,QString title,QString author,QString publisHouse,QString isbnCode,int pageNum,QString status ,QString level)
{
    this->code=code;
    this->author=author;
    this->title=title;
    this->status=status;
    this->level=level;
    this->publisHouse=publisHouse;
    this->isbnCode=isbnCode;
    this->pageNum=pageNum;
}

Books::Books()
:BasicClass()
{

}

void Books::setISBNCode(QString isbnCode)
{
    this->isbnCode=isbnCode;
}

void Books::setPageNum(int num)
{
    this->pageNum=num;
}

void Books::setPublishHouse(QString publisHouse)
{
    this->publisHouse=publisHouse;
}

Attributes Books::getItems()
{
    Attributes items(this->code,this->title,this->author,this->publisHouse,this->isbnCode,this->pageNum,this->status,this->level);

    return items;
}

Books::~Books()
{

}

Attributes::Attributes()
{

}

Attributes::Attributes(int code, QString title, QString author, QString publisHouse, QString isbnCode, int pageNum, QString status, QString level)
{
    this->code=code;
    this->author=author;
    this->title=title;
    this->status=status;
    this->level=level;
    this->publisHouse=publisHouse;
    this->isbnCode=isbnCode;
    this->pageNum=pageNum;
}
