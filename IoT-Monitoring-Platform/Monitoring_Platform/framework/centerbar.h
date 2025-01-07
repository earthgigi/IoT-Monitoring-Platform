#ifndef CENTERBAR_H
#define CENTERBAR_H

#include <QWidget>
#include <QStackedLayout>
#include "login.h"
#include "successlogin.h"
#include "statusbar.h"
#include "User/users.h"


namespace Ui {
class CenterBar;
}

class CenterBar : public QWidget
{
    Q_OBJECT
public:
    explicit CenterBar(QWidget *parent = nullptr);
    ~CenterBar();


signals:
   void checklogin(int);//账号错误0，密码错误，1，登陆成功2；

private:
    Ui::CenterBar *ui;
    QStackedLayout *m_pQStackedLayout;
    Login *m_pLogin;
    SuccessLogin *m_pSuccessLogin;
    StatusBar *m_pStatusBar;
    Users *m_pUsers;
};

#endif // CENTERBAR_H
