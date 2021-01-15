#ifndef PICTURES_H
#define PICTURES_H

#include <QWidget>
#include "basicclass.h"
#include "QString"

struct AttributesP
{
    int code;
    QString title;
    QString author;
    QString country;
    int height;
    int weight;
    QString status;
    QString level;

    AttributesP();
    AttributesP(int code,QString title,QString author,QString country,int height,int weight,QString status ,QString level);
};

class Pictures:public BasicClass
{
    QString country;
    int height;
    int weight;
public:
    Pictures();
    Pictures(QString country,int height,int weight,int code,QString title,QString author,QString status ,QString level);
    void create(QString country,int height,int weight,int code,QString title,QString author,QString status ,QString level);
    void setHeight(int h);
    void setWeight(int w);
    void setCountry(QString country);
    AttributesP getItems();
    ~Pictures();
};

#endif // PICTURES_H
