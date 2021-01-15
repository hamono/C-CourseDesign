#include "videos.h"

Videos::Videos(QString publishAuthor,QString publishYear,long videoTime,int code,QString title,QString author,QString status,QString level):BasicClass(code, title,author,status,level)
{
    this->publishAuthor=publishAuthor;
    this->publishYear=publishYear;
    this->videoTime=videoTime;
}

void Videos::create(QString publishAuthor,QString publishYear,long videoTime,int code,QString title,QString author,QString status,QString level)
{
    this->code=code;
    this->author=author;
    this->title=title;
    this->status=status;
    this->level=level;
    this->publishAuthor=publishAuthor;
    this->publishYear=publishYear;
    this->videoTime=videoTime;
}

Videos::Videos():BasicClass()
{

}

void Videos::setPublishAuthor(QString author)
{
    this->publishAuthor=author;
}

void Videos::setPublishYear(QString year)
{
    this->publishYear=year;
}

void Videos::setTime(long time)
{
    this->videoTime=time;
}

AttributesV Videos::getItems()
{
    AttributesV items(this->code,this->title,this->author,this->publishAuthor,this->publishYear,this->videoTime,this->status,this->level);
    return items;
}

Videos::~Videos()
{

}

AttributesV::AttributesV()
{

}

AttributesV::AttributesV(int code,QString title,QString author,QString publishAuthor,QString publishYear, long videoTime,QString status ,QString level)
{
    this->code=code;
    this->author=author;
    this->title=title;
    this->status=status;
    this->level=level;
    this->publishAuthor=publishAuthor;
    this->publishYear=publishYear;
    this->videoTime=videoTime;
}
