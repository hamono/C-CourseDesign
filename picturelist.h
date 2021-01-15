#ifndef PICTURELIST_H
#define PICTURELIST_H

#include "pictures.h"
#include"QTableWidget"
#include"QStringList"
#include"QLabel"

struct NodeP
{
    Pictures book;
    NodeP *next;


    NodeP();
    NodeP(Pictures book);
};

class PictureList
{
    NodeP* head;
    int length;
    QTableWidget* table;
    QLabel *nums;
    bool flag;
    int borNum;
    QLabel *dorNum;

signals:
    void borBok(int t);

public:
    PictureList();
    PictureList(QWidget *parent,bool flag,int borNum);
    void insert(Pictures book);
    void render();
    void readFile(QStringList p[]);
    void searchByCode(int code,QWidget *parent);
    void searchByTitle(QString title,QWidget *parent);
    void setLend(int code);
    void borBook(int code);
    void retBook(int code);
    void delItem(int code);
    void outFile();
};

#endif // PICTURELIST_H
