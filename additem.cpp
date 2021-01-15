#include "additem.h"
#include"QString"

Additem::Additem(QWidget *parent) : QWidget(parent)
{
    this->setWindowTitle(tr("添加元素"));

    QIcon ti(":/new/prefix1/title.png");
    this->setWindowIcon(ti);

    code=new QLineEdit(this);
    code->move(130,60);
    code->resize(200,30);

    title=new QLineEdit(this);
    title->move(130,110);
    title->resize(200,30);

    author=new QLineEdit(this);
    author->move(130,160);
    author->resize(200,30);

    pubHouse=new QLineEdit(this);
    pubHouse->move(130,210);
    pubHouse->resize(200,30);

    isbnCode=new QLineEdit(this);
    isbnCode->move(420,60);
    isbnCode->resize(200,30);

    pageNum=new QLineEdit(this);
    pageNum->move(420,110);
    pageNum->resize(200,30);

    status=new QLineEdit(this);
    status->move(420,160);
    status->resize(200,30);

    level=new QLineEdit(this);
    level->move(420,210);
    level->resize(200,30);

    codeLab=new QLabel(this);
    codeLab->move(80,66);
    codeLab->setText(tr("编码："));

    titleLab=new QLabel(this);
    titleLab->move(80,116);
    titleLab->setText(tr("标题："));

    authorLab=new QLabel(this);
    authorLab->move(80,166);
    authorLab->setText(tr("作者："));

    pubLab=new QLabel(this);
    pubLab->move(80,216);
    pubLab->setText(tr("出版社："));

    isbnLab=new QLabel(this);
    isbnLab->move(360,66);
    isbnLab->setText(tr("ISBN码："));

    pageLab=new QLabel(this);
    pageLab->move(360,116);
    pageLab->setText(tr("页数："));

    statLab=new QLabel(this);
    statLab->move(360,166);
    statLab->setText(tr("状态："));

    leLab=new QLabel(this);
    leLab->move(360,216);
    leLab->setText(tr("评级："));

    add=new QPushButton(tr("添加"),this);
    add->resize(60,25);
    add->move(560,271);

    setFixedSize(670,311);

    this->show();

    connect(add,&QPushButton::clicked,[=](){
        QString newCode,newtitle,newAuthor,newPubHouse,newisbn,newPage,newStatus,newLevel;
        newCode=this->code->text();
        newtitle=this->title->text();
        newAuthor=this->author->text();
        newPubHouse=this->pubHouse->text();
        newisbn=this->isbnCode->text();
        newPage=this->pageNum->text();
        newStatus=this->status->text();
        newLevel=this->level->text();

        if(newCode==""||newtitle==""||newAuthor==""||newPubHouse==""||newisbn==""||newPage==""||newStatus==""||newLevel=="")
        {
            QLabel *msg=new QLabel(this);
            msg->setText(tr("请完善信息！"));
            msg->move(300,20);
            msg->setStyleSheet("QLabel{color:red;}");
            msg->show();
        }
        else
        {
            Books bok(newCode.toInt(),newtitle,newAuthor,newPubHouse,newisbn,newPage.toInt(),newStatus,newLevel);
            this->newBook=bok;
            emit checkOK(true);
            this->close();
        }
    });
}

Books Additem::getBook()
{
    return this->newBook;
}
