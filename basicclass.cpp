#include "basicclass.h"

BasicClass::BasicClass(int code,QString title,QString author,QString status ,QString level)
{
    this->code=code;
    this->author=author;
    this->title=title;
    this->status=status;
    this->level=level;
}

BasicClass::BasicClass()
{

}

void BasicClass::setCode(int code)
{
    this->code=code;
}

void BasicClass::setAuthor(QString author)
{
    this->author=author;
}

void BasicClass::setLevel(QString level)
{
    this->level=level;
}

void BasicClass::setTitle(QString title)
{
    this->title=title;
}

void BasicClass::setStatus(QString status)
{
    this->status=status;
}

BasicClass::~BasicClass()
{

}
