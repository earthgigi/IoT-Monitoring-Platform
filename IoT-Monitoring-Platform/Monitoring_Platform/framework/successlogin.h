#ifndef SUCCESSLOGIN_H
#define SUCCESSLOGIN_H

#include <QWidget>

namespace Ui {
class SuccessLogin;
}

class SuccessLogin : public QWidget
{
    Q_OBJECT

public:
    explicit SuccessLogin(QWidget *parent = nullptr);
    ~SuccessLogin();

signals:
    //切换界面回登陆界面用
    void display(int);

private:
    Ui::SuccessLogin *ui;
};

#endif // SUCCESSLOGIN_H
