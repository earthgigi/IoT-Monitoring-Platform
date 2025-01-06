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

private:
    Ui::SuccessLogin *ui;
};

#endif // SUCCESSLOGIN_H
