#include "booklist.h"
#include "books.h"
#include "QObject"
#include"iostream"
#include "QDir"
#include"QFile"
#include"QFileDialog"
#include"QPushButton"
#include"QHBoxLayout"
#include"QLineEdit"
#include"QString"
#include"QMessageBox"
#include"additem.h"
#include"QDebug"
#include"QStatusBar"
#include"QLabel"

BookList::BookList(QWidget *parent,bool flag,int borNum)
{
    head=new Node;
    this->length=0;
    this->flag=flag;
    this->borNum=borNum;

    QStringList p[20];
    readFile(p);
    int code,pageNum;
    Books book;
    QString author,title,pubHouse,lever,isbn,status;
    for(int i=0;i<20;i++)
    {
        qDebug()<<p[i];
        code=p[i].at(0).toInt();
        title=p[i].at(1);
        author=p[i].at(2);
        pubHouse=p[i].at(3);
        isbn=p[i].at(4);
        pageNum=p[i].at(5).toInt();
        status=p[i].at(6);
        lever=p[i].at(7);

        book.create(code,title,author,pubHouse,isbn,pageNum,status,lever);
        this->insert(book);
    }

    QTableWidgetItem *item;
    QStringList headText;

    table=new QTableWidget(parent);
    table->setSelectionBehavior(QAbstractItemView::SelectRows);

    headText<<"编码"<<"标题"<<"作者"<<"出版社"<<"ISBN码"<<"页数"<<"状态"<<"评级"<<"操作";
    table->setColumnCount(headText.count());

    table->move(0,40);
    table->resize(1100,500);

    // user
    if(!this->flag)
    {
        table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    }

    for(int i=0;i<table->columnCount();i++)
    {
        item=new QTableWidgetItem(headText.at(i));
        item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

        table->setColumnWidth(table->columnCount()-1,200);
        QFont font=item->font();
        font.setBold(true);
        item->setFont(font);

        table->setHorizontalHeaderItem(i,item);

    }

    table->setColumnWidth(table->columnCount()-1,190);
    table->setColumnWidth(4,160);
    table->setStyleSheet("QTableWidget::item:selected { background-color: rgb(207, 207, 207) }");

    QPushButton *searchBytitle=new QPushButton(QObject::tr("标题搜索"),parent);
    searchBytitle->move(1010,9);
    searchBytitle->resize(70,25);
    searchBytitle->show();

    QLineEdit *searchBytitleEdit=new QLineEdit(parent);
    searchBytitleEdit->move(860,10);
    searchBytitleEdit->resize(150,23);
    searchBytitleEdit->show();

    QPushButton *searchByCode=new QPushButton(QObject::tr("编码搜索"),parent);
    searchByCode->move(750,9);
    searchByCode->resize(70,25);
    searchByCode->show();

    QLineEdit *searchByCodeEdit=new QLineEdit(parent);
    searchByCodeEdit->move(600,10);
    searchByCodeEdit->resize(150,23);
    searchByCodeEdit->show();

    //user
    if(this->flag)
    {
        QPushButton *addItemBtn=new QPushButton(QObject::tr("添加"),parent);
        addItemBtn->move(10,9);
        addItemBtn->resize(60,25);
        addItemBtn->show();

        //添加
        table->connect(addItemBtn,&QPushButton::clicked,[=](){
            Additem *addWidget=new Additem(0);
            addWidget->connect(addWidget,&Additem::checkOK,[=](){
                this->insert(addWidget->getBook());
                this->render();
            });
        });

        QPushButton *out=new QPushButton(QObject::tr("导出"),parent);
        out->move(100,9);
        out->resize(60,25);
        out->show();

        table->connect(out,&QPushButton::clicked,[=](){
            this->outFile();
        });
    }else{
        this->dorNum=new QLabel(parent);
        this->dorNum->setText(QObject::tr("当前可借本数：")+QString::number(this->borNum));
        this->dorNum->move(10,9);
        this->dorNum->show();
    }

    QStatusBar *state=new QStatusBar(parent);
    this->nums=new QLabel;
    this->nums->setText("总数量："+QString::number(this->length));
    this->nums->move(5,0);
    state->addWidget(nums,1);
    state->move(0,540);
    state->resize(1100,25);
    state->show();

    //搜索
    table->connect(searchBytitle,&QPushButton::clicked,[=](){
        searchByCodeEdit->clear();

        QString titleText=searchBytitleEdit->text();
        if(titleText=="");else {
            this->searchByTitle(titleText,parent);
        }
    });

    table->connect(searchByCode,&QPushButton::clicked,[=](){
        searchBytitleEdit->clear();

        QString titleText=searchByCodeEdit->text();
        if(titleText=="");else {
            qDebug()<<titleText;
            this->searchByCode(titleText.toInt(),parent);
        }
    });
    

}

void BookList::insert(Books book)
{
    Node* p=this->head;
    Node *q=new Node(book);
    while(p->next!=NULL)
    {
      p=p->next;
    }
    p->next=q;

    this->length++;
}

void BookList::outFile()
{
    QFile aFile("C:\\Users\\哈默默\\Desktop\\bokData.csv");
    QTextStream out(&aFile);
    if (!aFile.open(QIODevice::WriteOnly | QIODevice::Text));
    Node* p=this->head->next;
    while(p!=NULL)
    {
      QString str1,str2,str3,str4,str5,str6,str7,str8,str;
      str1= QString::number(p->book.getItems().code);
      str2=p->book.getItems().title;
      str3=p->book.getItems().author;
      str4=p->book.getItems().publisHouse;
      str5=p->book.getItems().isbnCode;
      str6=QString::number(p->book.getItems().pageNum);
      str7=p->book.getItems().status;
      str8=p->book.getItems().level;

      str=str1+","+str2+","+str3+","+str4+","+str5+","+str6+","+str7+","+str8+"\r\n";

      out<<str;
      p=p->next;
    }
}

void BookList::render()
{
    table->clearContents();
    table->setRowCount(length);

    QTableWidgetItem *item;
    Attributes bokItem;
    Node *p=head->next;
    for(int j=0;j<this->length;j++)
    {
        bokItem=p->book.getItems();

        for(int i=0;i<9;i++)
        {
            switch (i) {
            case 0:
                item=new QTableWidgetItem(QString::number(bokItem.code));
                item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
                table->setItem(j,i,item);
                break;
            case 1:
                item=new QTableWidgetItem(bokItem.title);
                item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
                table->setItem(j,i,item);
                break;
            case 2:
                item=new QTableWidgetItem(bokItem.author);
                item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
                table->setItem(j,i,item);
                break;
            case 3:
                item=new QTableWidgetItem(bokItem.publisHouse);
                item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
                table->setItem(j,i,item);
                break;
            case 4:
                item=new QTableWidgetItem(bokItem.isbnCode);
                item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
                table->setItem(j,i,item);
                break;
            case 5:
                item=new QTableWidgetItem(QString::number(bokItem.pageNum));
                item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
                table->setItem(j,i,item);
                break;
            case 6:
                item=new QTableWidgetItem(bokItem.status);
                item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
                table->setItem(j,i,item);
                break;
            case 7:
                item=new QTableWidgetItem(bokItem.level);
                item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
                table->setItem(j,i,item);
                break;
            case 8:
            {
                QPushButton *del=new QPushButton(QObject::tr("删除"));
//                del->setStyleSheet("QPushButton {"
//                                   "background-color:rgb(255,69,0);"
//                                 "}");

                QPushButton *lend=new QPushButton(QObject::tr("借阅"));
//                lend->setStyleSheet("QPushButton{background-color:rgb(152, 245, 255)}");

                QPushButton *ret=new QPushButton(QObject::tr("还书"));
//                del->setStyleSheet("QPushButton {"
//                                   "background-color:rgb(255,69,0);"
//                                 "}");

                QPushButton *bor=new QPushButton(QObject::tr("借书"));
//                lend->setStyleSheet("QPushButton{background-color:rgb(152, 245, 255)}");

                //user
                if(bokItem.status=="不可借阅")
                {
                    lend->setEnabled(false);
                    del->setEnabled(false);
                    bor->setEnabled(false);
//                    lend->setStyleSheet("QPushButton{background-color:rgb(240, 255, 255)}");
                }
                else
                {
                    ret->setEnabled(false);
                }
                if(!this->flag)
                {
                    if(this->borNum==0)
                    {
                        bor->setEnabled(false);
                        this->dorNum->setStyleSheet("QLabel{color:red;}");
                    }
                    else
                    {
                        this->dorNum->setStyleSheet("QLabel{color:black;}");
                    }
                }


                QWidget *widget=new QWidget();
                QHBoxLayout *h_box_layout = new QHBoxLayout();

                //user
                if(this->flag)
                {
                    h_box_layout->addStretch();
                    h_box_layout->addWidget(lend);
                    h_box_layout->addWidget(del);
                    h_box_layout->addStretch();
                    h_box_layout->setContentsMargins(0,0, 0, 0);
                    h_box_layout->setSpacing(10);
                }
                else
                {
                    h_box_layout->addStretch();
                    h_box_layout->addWidget(bor);
                    h_box_layout->addWidget(ret);
                    h_box_layout->addStretch();
                    h_box_layout->setContentsMargins(0,0, 0, 0);
                    h_box_layout->setSpacing(10);
                }

                widget->setLayout(h_box_layout);
                table->setCellWidget(j,i,widget);

                //借阅
                table->connect(lend,&QPushButton::clicked,[=](){
                    this->setLend(bokItem.code);
                    this->render();
                });

                //删除
                table->connect(del,&QPushButton::clicked,[=](){
                    this->delItem(bokItem.code);
                    this->render();
                });

                //user
                //bor
                table->connect(bor,&QPushButton::clicked,[=](){
                    this->borBook(bokItem.code);
                    this->render();
                });
                //ret
                table->connect(ret,&QPushButton::clicked,[=](){
                    this->retBook(bokItem.code);
                    this->render();
                });

                break;
            }
            default:
                break;
            }
        }
        p=p->next;
    }
    table->show();
}


//user
void BookList::borBook(int code)
{
    Node *p=head->next;
    while(p!=NULL){
        if(p->book.getItems().code==code)
        {
            p->book.setStatus("不可借阅");

            //user
            this->borNum--;
            this->dorNum->setText(QObject::tr("当前可借本数：")+QString::number(this->borNum));
        }

        p=p->next;
    }
}

void BookList::retBook(int code)
{
    Node *p=head->next;
    while(p!=NULL){
        if(p->book.getItems().code==code)
        {
         p->book.setStatus("可借");

         //user
         this->borNum++;
         this->dorNum->setText(QObject::tr("当前可借本数：")+QString::number(this->borNum));
        }

        p=p->next;
    }
}


void BookList::readFile(QStringList p[])
{
    QFile  aFile("C:\\Users\\哈默默\\Desktop\\BookData.txt");
    int i=0;
    if (aFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        while (!aFile.atEnd())
        {
           QByteArray line = aFile.readLine();
           QString str(line);
           str=str.left(str.size()-1);
           p[i] = str.split(" ");
           i++;
        }
    }
    aFile.close();
}

void BookList::searchByCode(int code,QWidget *parent)
{
    table->clearContents();

    Node *p=head->next;
    QTableWidgetItem *item;
    Attributes bokItem;
    int j=0;
    while(p!=NULL) {
        if(p->book.getItems().code==code)
        {
            bokItem=p->book.getItems();
            for(int i=0;i<9;i++)
            {
                switch (i) {
                case 0:
                    item=new QTableWidgetItem(QString::number(bokItem.code));
                    item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
                    table->setItem(j,i,item);
                    break;
                case 1:
                    item=new QTableWidgetItem(bokItem.title);
                    item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
                    table->setItem(j,i,item);
                    break;
                case 2:
                    item=new QTableWidgetItem(bokItem.author);
                    item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
                    table->setItem(j,i,item);
                    break;
                case 3:
                    item=new QTableWidgetItem(bokItem.publisHouse);
                    item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
                    table->setItem(j,i,item);
                    break;
                case 4:
                    item=new QTableWidgetItem(bokItem.isbnCode);
                    item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
                    table->setItem(j,i,item);
                    break;
                case 5:
                    item=new QTableWidgetItem(QString::number(bokItem.pageNum));
                    item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
                    table->setItem(j,i,item);
                    break;
                case 6:
                    item=new QTableWidgetItem(bokItem.status);
                    item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
                    table->setItem(j,i,item);
                    break;
                case 7:
                    item=new QTableWidgetItem(bokItem.level);
                    item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
                    table->setItem(j,i,item);
                    break;
                case 8:
                {
                    QPushButton *del=new QPushButton(QObject::tr("删除"));
    //                del->setStyleSheet("QPushButton {"
    //                                   "background-color:rgb(255,69,0);"
    //                                 "}");

                    QPushButton *lend=new QPushButton(QObject::tr("借阅"));
    //                lend->setStyleSheet("QPushButton{background-color:rgb(152, 245, 255)}");

                    QPushButton *ret=new QPushButton(QObject::tr("还书"));
    //                del->setStyleSheet("QPushButton {"
    //                                   "background-color:rgb(255,69,0);"
    //                                 "}");

                    QPushButton *bor=new QPushButton(QObject::tr("借书"));
    //                lend->setStyleSheet("QPushButton{background-color:rgb(152, 245, 255)}");

                    //user
                    if(bokItem.status=="不可借阅")
                    {
                        lend->setEnabled(false);
                        del->setEnabled(false);
                        bor->setEnabled(false);
    //                    lend->setStyleSheet("QPushButton{background-color:rgb(240, 255, 255)}");
                    }
                    else
                    {
                        ret->setEnabled(false);
                    }
                    if(!this->flag)
                    {
                        if(this->borNum==0)
                        {
                            bor->setEnabled(false);
                            this->dorNum->setStyleSheet("QLabel{color:red;}");
                        }
                        else
                        {
                            this->dorNum->setStyleSheet("QLabel{color:black;}");
                        }
                    }


                    QWidget *widget=new QWidget();
                    QHBoxLayout *h_box_layout = new QHBoxLayout();

                    //user
                    if(this->flag)
                    {
                        h_box_layout->addStretch();
                        h_box_layout->addWidget(lend);
                        h_box_layout->addWidget(del);
                        h_box_layout->addStretch();
                        h_box_layout->setContentsMargins(0,0, 0, 0);
                        h_box_layout->setSpacing(10);
                    }
                    else
                    {
                        h_box_layout->addStretch();
                        h_box_layout->addWidget(bor);
                        h_box_layout->addWidget(ret);
                        h_box_layout->addStretch();
                        h_box_layout->setContentsMargins(0,0, 0, 0);
                        h_box_layout->setSpacing(10);
                    }

                    widget->setLayout(h_box_layout);
                    table->setCellWidget(j,i,widget);

                    //借阅
                    table->connect(lend,&QPushButton::clicked,[=](){
                        this->setLend(bokItem.code);
                        this->render();
                    });

                    //删除
                    table->connect(del,&QPushButton::clicked,[=](){
                        this->delItem(bokItem.code);
                        this->render();
                    });

                    //user
                    //bor
                    table->connect(bor,&QPushButton::clicked,[=](){
                        this->borBook(bokItem.code);
                        this->render();
                    });
                    //ret
                    table->connect(ret,&QPushButton::clicked,[=](){
                        this->retBook(bokItem.code);
                        this->render();
                    });

                    break;
                }
                default:
                    break;
                }
            }
            j++;
        }
        p=p->next;
    }
    if(j>0)
    {
        table->setRowCount(j);
        table->show();
    }
    else
    {
        QMessageBox::warning(parent,  QObject::tr("警告！"), QObject::tr("内容未找到！"),QMessageBox::Yes);
        this->render();
    }
}

void BookList::searchByTitle(QString title,QWidget *parent)
{
    table->clearContents();

    Node *p=head->next;
    QTableWidgetItem *item;
    Attributes bokItem;
    int j=0;
    while(p!=NULL) {
        if(p->book.getItems().title.contains(title,Qt::CaseInsensitive))
        {
            bokItem=p->book.getItems();
            for(int i=0;i<9;i++)
            {
                switch (i) {
                case 0:
                    item=new QTableWidgetItem(QString::number(bokItem.code));
                    item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
                    table->setItem(j,i,item);
                    break;
                case 1:
                    item=new QTableWidgetItem(bokItem.title);
                    item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
                    table->setItem(j,i,item);
                    break;
                case 2:
                    item=new QTableWidgetItem(bokItem.author);
                    item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
                    table->setItem(j,i,item);
                    break;
                case 3:
                    item=new QTableWidgetItem(bokItem.publisHouse);
                    item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
                    table->setItem(j,i,item);
                    break;
                case 4:
                    item=new QTableWidgetItem(bokItem.isbnCode);
                    item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
                    table->setItem(j,i,item);
                    break;
                case 5:
                    item=new QTableWidgetItem(QString::number(bokItem.pageNum));
                    item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
                    table->setItem(j,i,item);
                    break;
                case 6:
                    item=new QTableWidgetItem(bokItem.status);
                    item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
                    table->setItem(j,i,item);
                    break;
                case 7:
                    item=new QTableWidgetItem(bokItem.level);
                    item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
                    table->setItem(j,i,item);
                    break;
                case 8:
                {
                    QPushButton *del=new QPushButton(QObject::tr("删除"));
    //                del->setStyleSheet("QPushButton {"
    //                                   "background-color:rgb(255,69,0);"
    //                                 "}");

                    QPushButton *lend=new QPushButton(QObject::tr("借阅"));
    //                lend->setStyleSheet("QPushButton{background-color:rgb(152, 245, 255)}");

                    QPushButton *ret=new QPushButton(QObject::tr("还书"));
    //                del->setStyleSheet("QPushButton {"
    //                                   "background-color:rgb(255,69,0);"
    //                                 "}");

                    QPushButton *bor=new QPushButton(QObject::tr("借书"));
    //                lend->setStyleSheet("QPushButton{background-color:rgb(152, 245, 255)}");

                    //user
                    if(bokItem.status=="不可借阅")
                    {
                        lend->setEnabled(false);
                        del->setEnabled(false);
                        bor->setEnabled(false);
    //                    lend->setStyleSheet("QPushButton{background-color:rgb(240, 255, 255)}");
                    }
                    else
                    {
                        ret->setEnabled(false);
                    }
                    if(!this->flag)
                    {
                        if(this->borNum==0)
                        {
                            bor->setEnabled(false);
                            this->dorNum->setStyleSheet("QLabel{color:red;}");
                        }
                        else
                        {
                            this->dorNum->setStyleSheet("QLabel{color:black;}");
                        }
                    }

                    QWidget *widget=new QWidget();
                    QHBoxLayout *h_box_layout = new QHBoxLayout();

                    //user
                    if(this->flag)
                    {
                        h_box_layout->addStretch();
                        h_box_layout->addWidget(lend);
                        h_box_layout->addWidget(del);
                        h_box_layout->addStretch();
                        h_box_layout->setContentsMargins(0,0, 0, 0);
                        h_box_layout->setSpacing(10);
                    }
                    else
                    {
                        h_box_layout->addStretch();
                        h_box_layout->addWidget(bor);
                        h_box_layout->addWidget(ret);
                        h_box_layout->addStretch();
                        h_box_layout->setContentsMargins(0,0, 0, 0);
                        h_box_layout->setSpacing(10);
                    }

                    widget->setLayout(h_box_layout);
                    table->setCellWidget(j,i,widget);

                    //借阅
                    table->connect(lend,&QPushButton::clicked,[=](){
                        this->setLend(bokItem.code);
                        this->render();
                    });

                    //删除
                    table->connect(del,&QPushButton::clicked,[=](){
                        this->delItem(bokItem.code);
                        this->render();
                    });

                    //user
                    //bor
                    table->connect(bor,&QPushButton::clicked,[=](){
                        this->borBook(bokItem.code);
                        this->render();
                    });
                    //ret
                    table->connect(ret,&QPushButton::clicked,[=](){
                        this->retBook(bokItem.code);
                        this->render();
                    });

                    break;
                }
                default:
                    break;
                }
            }
            j++;
        }
        p=p->next;
    }
    if(j>0)
    {
        table->setRowCount(j);
        table->show();
    }
    else
    {
        QMessageBox::warning(parent,  QObject::tr("警告！"), QObject::tr("内容未找到！"),QMessageBox::Yes);
        this->render();
    }
}

void BookList::setLend(int code)
{
    Node *p=head->next;
    while(p!=NULL){
        if(p->book.getItems().code==code)
            p->book.setStatus("不可借阅");
        p=p->next;
    }
}

void BookList::delItem(int code)
{
    Node *p=head->next;
    Node *q;
    while(p->book.getItems().code!=code){
      p=p->next;
    }
    q=p->next;
    if(!q)
    {
        p->next=NULL;
    }
    else
    {
        p->next=q->next;
    }
    this->length--;
    this->nums->setText("总数量："+QString::number(this->length));

    delete q;
}

Node::Node()
{
    this->next=NULL;
}

Node::Node(Books book)
{
    this->book=book;
    this->next=NULL;
}
