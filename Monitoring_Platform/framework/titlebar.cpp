#include "titlebar.h"
#include "ui_titlebar.h"

TitleBar::TitleBar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TitleBar)
{
    ui->setupUi(this);
    //parentWidget()找到当前界面的父界面
    connect(ui->pushButton_Min,&QPushButton::clicked,this,[=](){parentWidget()->showMinimized();});
    connect(ui->pushButton_Max,&QPushButton::clicked,this,[=](){
        if(parentWidget()->isMaximized()){
            parentWidget()->showNormal();
            return;
        }
        parentWidget()->showMaximized();
    });
    connect(ui->pushButton_Close,&QPushButton::clicked,this,[=](){parentWidget()->close();});
}

TitleBar::~TitleBar()
{
    delete ui;
}
