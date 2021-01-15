#ifndef ADDITEM_H
#define ADDITEM_H

#include <QWidget>
#include "QLineEdit"
#include "QPushButton"
#include <QLabel>
#include "books.h"

class Additem : public QWidget
{
    Q_OBJECT
private:
    QLineEdit *code;
    QLineEdit *title;
    QLineEdit *author;
    QLineEdit *pubHouse;
    QLineEdit *isbnCode;
    QLineEdit *pageNum;
    QLineEdit *status;
    QLineEdit *level;

    QLabel *codeLab;
    QLabel *titleLab;
    QLabel *authorLab;
    QLabel *pubLab;
    QLabel *isbnLab;
    QLabel *pageLab;
    QLabel *statLab;
    QLabel *leLab;

    QPushButton *add;
    QPushButton *cancel;

    Books newBook;
public:
    explicit Additem(QWidget *parent = nullptr);
    Books getBook();
signals:
    void checkOK(bool);
public slots:
};

#endif // ADDITEM_H
