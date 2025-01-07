#include "successlogin.h"
#include "ui_successlogin.h"

SuccessLogin::SuccessLogin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SuccessLogin)
{
    ui->setupUi(this);
    connect(ui->pushButton_logout,&QPushButton::clicked,this,[=](){emit display(0);});
}

SuccessLogin::~SuccessLogin()
{
    delete ui;
}
