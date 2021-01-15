#include "student.h"
#include "QTableWidget"
#include"QWidget"
#include"QPushButton"
#include"QLineEdit"
#include"QListWidget"
#include"QListWidgetItem"
#include"QTableWidget"
#include "iostream"
#include"QObject"
#include"booklist.h"
#include"videolist.h"
#include"picturelist.h"
#include"QLabel"

Student::Student(QWidget *parent,QPushButton *user,QPushButton *admin)
{
    this->lendNum=10;
    this->name=new QLabel(parent);
    this->logout=new QPushButton(QObject::tr("退出"),parent);
    this->name->move(970,5);
    this->logout->move(1021,6);
    this->logout->resize(60,20);

    QWidget *bookTab=new QWidget(parent);
    QWidget *videoTab=new QWidget(parent);
    QWidget *pictureTab=new QWidget(parent);

    QTabWidget *tabs=new QTabWidget(parent);

    tabs->addTab(bookTab,QObject::tr("图书"));
    tabs->addTab(videoTab,QObject::tr("视频"));
    tabs->addTab(pictureTab,QObject::tr("绘画"));

    tabs->setTabShape(QTabWidget::Rounded);

    tabs->show();
    tabs->resize(1100,600);
    tabs->move(0,3);
    tabs->setStyleSheet("QTabBar::tab { height: 30px; width: 150px; }");

    BookList* a=new BookList(bookTab,false,2);
    VideoList* b=new VideoList(videoTab,false,2);
    PictureList* c=new PictureList(pictureTab,false,2);

    tabs->connect(tabs,&QTabWidget::tabBarClicked,[=](int index){
        switch (index) {
        case 0:
            a->render();
            break;
        case 1:
            b->render();
            break;
        case 2:
            c->render();
            break;
        default:
            break;
        }
    });

    a->render();
    b->render();
    c->render();

    tabs->stackUnder(this->logout);
    parent->connect(logout,&QPushButton::clicked,[=](){
        user->show();
        admin->show();

        tabs->close();
        this->name->close();
        this->logout->close();
    });
}

void Student::setInfo(QString name)
{
    this->usename=name;
    this->name->setText(this->usename);
    this->name->show();
    this->logout->show();
}
