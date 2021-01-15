#include "login.h"
#include <QMessageBox>
#include <QString>
#include <windows.h>

Login::Login(QString type,QWidget *parent) :
    QWidget(parent)
{
    //设置窗体标题
    QIcon title(":/new/prefix1/title.png");
    this->setWindowIcon(title);
    this->setWindowTitle(type+tr("登录"));

//    QFont font;


    //用户名Label
    userNameLbl = new QLabel(this);   //new一个标签对象
    userNameLbl->move(80,80);         //移动到(70,80)位置(Label左上角坐标，相对于父窗体)
    userNameLbl->setText(tr("账号:"));   //设置标签文本

    //用户名输入框
    userNameLEd = new QLineEdit(this);
    userNameLEd->move(120,80);
    userNameLEd->setPlaceholderText(tr("请输入账号！"));//占位符

    //密码Label
    pwdLbl = new QLabel(this);
//    font=pwdLbl->font();
//    font.setPointSize(14);
//    pwdLbl->setFont(font);
    pwdLbl->move(80,130);
    pwdLbl->setText("密码:");

    //密码输入框
    pwdLEd = new QLineEdit(this);
//    pwdLEd->resize(200,30);
//    font=pwdLEd->font();
//    font.setPointSize(16);
//    pwdLEd->setFont(font);
    pwdLEd->move(120,130);
    pwdLEd->setPlaceholderText("请输入密码!");
    pwdLEd->setEchoMode(QLineEdit::Password);//输入的密码以圆点显示

    //登录按钮
    loginBtn = new QPushButton(this);
    loginBtn->move(80,200);
    loginBtn->setText("登录");

    //退出按钮
    exitBtn = new QPushButton(this);
    exitBtn->move(175,200);
    exitBtn->setText("退出");

    this->setWindowFlags(windowFlags() | Qt::WindowStaysOnTopHint);

    // 设置固定大小
    setFixedSize(350,290);

    //单击登录按钮时 执行 Login::login 槽函数(自定义)；单击退出按钮时 执行 Login::close 槽函数(窗体的关闭函数，不用自己写)
    connect(loginBtn,&QPushButton::clicked,this,&Login::login);
    connect(exitBtn,&QPushButton::clicked,this,&Login::close);
}

void Login::login()
{
    //获得userNameLEd输入框的文本：userNameLEd->text()；
    //trimmed()去掉前后空格
    //tr()函数，防止设置中文时乱码
    if(userNameLEd->text().trimmed() == tr("hamomo") && pwdLEd->text() == tr("123456"))
    {
       emit logInSuccess(tr("hamomo"));
       this->close();
    }
    else
    {
       QMessageBox::warning(this, tr("警告！"),tr("用户名或密码错误！"),QMessageBox::Yes);

    // 清空输入框内容
       userNameLEd->clear();
       pwdLEd->clear();

    //光标定位
       userNameLEd->setFocus();
    }
}
