#include "widget.h"
#include "ui_widget.h"
#include "qpushbutton.h"
#include "iostream"
#include "student.h"
#include"QHBoxLayout"
#include "QFile"
#include "QInputDialog"
#include "login.h"
#include"QTableWidget"
#include"QTableWidgetItem"
#include "QTableWidget"
#include "QListWidget"
#include "QListWidgetItem"
#include "admin.h"
#include "QDebug"

Widget::Widget(QWidget *parent) :
    QWidget(parent)
{

    this->setWindowTitle(tr("媒体资料借阅管理系统"));
    QIcon title(":/new/prefix1/title.png");
    this->setWindowIcon(title);

    user=new QPushButton("用户",this);
    admin=new QPushButton("管理员",this);
    QIcon iconS(":/new/prefix1/user.png");
    QIcon iconT(":/new/prefix1/admin.png");
    QSize size(30,30);

    user->setFixedSize(150,150);
    user->setIcon(iconS);
    user->setIconSize(size);
    admin->setIcon(iconT);
    admin->setIconSize(size);
    admin->setFixedSize(150,150);

    user->setStyleSheet("QPushButton {"
                           "text-align: center ;"
                           "color: black;"
                           "font:bold 20px;"
                         "}"
                         );
    admin->setStyleSheet("QPushButton {"
                           " text-align:bottom ;"
                           "color: black;"
                           "font:bold 20px;"
                         "}");

    QHBoxLayout *pHLayout = new QHBoxLayout();
    pHLayout->addStretch();
    pHLayout->addWidget(user);
    pHLayout->addWidget(admin);
    pHLayout->addStretch();
    pHLayout->setSpacing(100);

    window()->setLayout(pHLayout);

    user->show();
    admin->show();
    connect(user,&QPushButton::clicked,this,&Widget::userLogin);
    connect(admin,&QPushButton::clicked,this,&Widget::adminLogin);

    setFixedSize(1100,600);
}

void Widget::userLogin()
{

    Login* userLogin=new Login("用户");
    userLogin->show();

    connect(userLogin,&Login::logInSuccess,this,&Widget::onUserLoginEd);
}

void Widget::adminLogin()
{

    Login* adminLogin=new Login("管理员");
    adminLogin->show();

    connect(adminLogin,&Login::logInSuccess,this,&Widget::onAdminLoginEd);
}

void Widget::onUserLoginEd(QString name)
{
        user->close();
        admin->close();

        user->close();
        admin->close();

        Student *a=new Student(this,user,admin);
        a->setInfo(name);
}

void Widget::onAdminLoginEd(QString name)
{
        user->close();
        admin->close();

        Admin *a=new Admin(this,user,admin);
        a->setInfo(name);
}

Widget::~Widget()
{
}
