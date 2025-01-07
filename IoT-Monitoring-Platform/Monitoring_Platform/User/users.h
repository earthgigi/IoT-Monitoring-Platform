#ifndef USERS_H
#define USERS_H

#include <QWidget>
#include <QMessageBox>
#include "DataBase/database.h"

namespace Ui {
class Users;
}

class Users : public QWidget
{
    Q_OBJECT

public:
    explicit Users(QWidget *parent = nullptr);
    ~Users();

signals:
    void display(int);

public slots:
    void onRegisterClicked();
    void onCloseClicked();

private:
    Ui::Users *ui;
};

#endif // USERS_H
