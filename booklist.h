#ifndef BOOKLIST_H
#define BOOKLIST_H

#include "books.h"
#include"QTableWidget"
#include"QStringList"
#include"QLabel"

struct Node
{
    Books book;
    Node *next;


    Node();
    Node(Books book);
};

class BookList
{
    Node* head;
    int length;
    QTableWidget* table;
    QLabel *nums;
    //user
    QLabel *dorNum;
    bool flag;
    int borNum;

signals:
    void borBok(int t);

public:
    BookList(QWidget *parent,bool flag,int borNum);
    void insert(Books book);
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

#endif // BOOKLIST_H
