#include "pictures.h"

Pictures::Pictures(QString country,int height,int weight,int code,QString title,QString author,QString status,QString level):BasicClass(code,title,author,status,level)
{
    this->country=country;
    this->height=height;
    this->weight=weight;
}

void Pictures::create(QString country,int height,int weight,int code,QString title,QString author,QString status,QString level)
{
    this->code=code;
    this->author=author;
    this->title=title;
    this->status=status;
    this->level=level;
    this->country=country;
    this->height=height;
    this->weight=weight;
}

Pictures::Pictures():BasicClass()
{

}

void Pictures::setCountry(QString country)
{
    this->country=country;
}

void Pictures::setHeight(int h)
{
    this->height=h;
}

void Pictures::setWeight(int w)
{
    this->weight=w;
}

AttributesP Pictures::getItems()
{
    AttributesP items(this->code,this->title,this->author,this->country,this->height,this->weight,this->status,this->level);

    return items;
}

Pictures::~Pictures()
{

}

AttributesP::AttributesP()
{

}

AttributesP::AttributesP(int code,QString title,QString author,QString country,int height,int weight,QString status ,QString level)
{
    this->code=code;
    this->author=author;
    this->title=title;
    this->status=status;
    this->level=level;
    this->country=country;
    this->height=height;
    this->weight=weight;
}

