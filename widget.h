#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "QString"
#include <QPushButton>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    void userLogin();
    void adminLogin();
    void onUserLoginEd(QString name);
    void onAdminLoginEd(QString name);

    ~Widget();

private:
    Ui::Widget *ui;
    QPushButton *user;
    QPushButton *admin;
};

#endif // WIDGET_H
