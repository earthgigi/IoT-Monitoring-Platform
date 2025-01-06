#include "login.h"
#include "ui_login.h"
#include <QMovie>

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    connect(ui->pushButton_login, &QPushButton::clicked, this, &Login::userLogin);

    //左右动图
    QMovie *longmovie_left =new QMovie(":/beautityResources/caigou_left.gif");
    QMovie *longmovie_right =new QMovie(":/beautityResources/caigou_right.gif");
    ui->label_left->setMovie(longmovie_left);
    longmovie_left->setSpeed(100);
    longmovie_left->start();
    ui->label_right->setMovie(longmovie_right);
    longmovie_right->setSpeed(100);
    longmovie_right->start();
    // 设置QLabel的缩放内容属性
    ui->label_left->setScaledContents(true);
    ui->label_right->setScaledContents(true);

}

void Login::userLogin()
{
    static int num = 0;
    if(num>=3){
        parentWidget()->parentWidget()->close();//关闭整个页面
    }


//数据库单例模式调用
//    DatabaseManager & dbManager = DatabaseManager::getDatabase();

//    dbManager.openDatabase();
//    dbManager.createUserTable();


    //获取输入框的账号密码
    QString useraccount = ui->lineEdit_account->text();
    QString userpassword = ui->lineEdit_password->text();

    //如果账号不对
//    if(!dbManager.findAccount(useraccount)){
//        emit checklogin(0);
//        return;
//    }
    //如果密码不对
//    if(!dbManager.findPassword(useraccount,userpassword)){
//        num++;累计次数
//        emit checklogin(1);
//        return;
//    }
    //两个都对
    emit display(1);
    emit checklogin(2);

}


Login::~Login()
{
    delete ui;
}


