#include "titlebar.h"
#include "ui_titlebar.h"
#include <QMovie>

TitleBar::TitleBar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TitleBar)
{
    ui->setupUi(this);

    //log展示
    QMovie *longmovie =new QMovie(":/beautityResources/caigou.gif");
    ui->label_log->setMovie(longmovie);
    longmovie->setSpeed(150);
    longmovie->start();
    // 设置QLabel的缩放内容属性
    ui->label_log->setScaledContents(true);

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
