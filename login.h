#ifndef LOGIN_H
#define LOGIN_H


#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QString>

class Login:public QWidget
{
    Q_OBJECT
public:
    explicit Login(QString type,QWidget *parent=0);
signals:
    void logInSuccess(QString);
public slots:
    void login();//点击登录按钮执行的槽函数
private:
    QLabel *userNameLbl;         //"用户名"标签
    QLabel *pwdLbl;              //"密码"标签
    QLineEdit *userNameLEd;      //用户名编辑行
    QLineEdit *pwdLEd;           //密码编辑行
    QPushButton *loginBtn;       //登录按钮
    QPushButton *exitBtn;        //退出按钮
};

#endif // LOGIN_H
