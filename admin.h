#ifndef ADMIN_H
#define ADMIN_H

#include <QObject>
#include<QTabWidget>
#include<QString>
#include"QLabel"
#include"QPushButton"

class Admin
{

    QLabel *name;
    QPushButton *logout;
public:
    Admin(QWidget *parent,QPushButton *user,QPushButton *admin);
    void setInfo(QString name);
};

#endif // ADMIN_H
