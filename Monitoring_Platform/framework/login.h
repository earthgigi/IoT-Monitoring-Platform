#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>

namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();


signals:
    //进入登陆成功的主页面（页面跳转）
    void display(int);
    //检查账号密码是否正确
    void checklogin(int);//账号错误0，密码错误，1，登陆成功2；

public slots:
    //用户登录函数，用于判断账号密码和页面跳转
    void userLogin();

private:
    Ui::Login *ui;
};

#endif // LOGIN_H
