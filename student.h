#ifndef STUDENT_H
#define STUDENT_H

#include <QObject>
#include"QString"
#include"QWidget"
#include"QLabel"
#include"QPushButton"

class Student
{
    QString usename;
    QString gender;
    int id;
    int lendNum;

    QLabel *name;
    QPushButton *logout;
public:
    Student(QWidget *parent,QPushButton *user,QPushButton *admin);
    void setInfo(QString name);
};

#endif // STUDENT_H
