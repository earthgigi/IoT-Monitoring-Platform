#include "successlogin.h"
#include "ui_successlogin.h"

SuccessLogin::SuccessLogin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SuccessLogin)
{
    ui->setupUi(this);
}

SuccessLogin::~SuccessLogin()
{
    delete ui;
}
