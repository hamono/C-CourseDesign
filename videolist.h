#ifndef VIDEOLIST_H
#define VIDEOLIST_H

#include "videos.h"
#include"QTableWidget"
#include"QStringList"
#include"QLabel"

struct NodeV
{
    Videos book;
    NodeV *next;


    NodeV();
    NodeV(Videos book);
};

class VideoList
{
    NodeV* head;
    int length;
    QTableWidget* table;
    QLabel *nums;
    bool flag;
    int borNum;
    QLabel *dorNum;

signals:
    void borBok(int t);

public:
    VideoList(QWidget *parent,bool flag,int borNum);
    void insert(Videos book);
    void render();
    void readFile(QStringList p[]);
    void searchByCode(int code,QWidget *parent);
    void searchByTitle(QString title,QWidget *parent);
    void setLend(int code);
    void delItem(int code);
    void borBook(int code);
    void retBook(int code);
    void outFile();
};

#endif // VIDEOLIST_H
