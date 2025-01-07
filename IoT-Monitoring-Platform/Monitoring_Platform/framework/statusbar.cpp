#include "statusbar.h"
#include "ui_statusbar.h"


StatusBar::StatusBar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StatusBar)
{
    ui->setupUi(this);
    m_ptimer = new QTimer(this);
    connect(m_ptimer,&QTimer::timeout,this,[=](){
        ui->label_Status->clear();});

}

void StatusBar::onshowStatus(int index)
{
    switch (index) {
    case 0:ui->label_Status->setText("账号错误，请重新输入");
        m_ptimer->start(2000);
        break;
    case 1:ui->label_Status->setText("密码错误，请重新输入");
        m_ptimer->start(2000);
        break;
    case 2:ui->label_Status->setText("登陆成功！！！");
        m_ptimer->start(2000);
        break;
    }
}


StatusBar::~StatusBar()
{
    delete ui;
}
