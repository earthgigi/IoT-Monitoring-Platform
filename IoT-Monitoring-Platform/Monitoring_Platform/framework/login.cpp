#include "login.h"
#include "ui_login.h"
#include <QMovie>

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    connect(ui->pushButton_login, &QPushButton::clicked, this, &Login::userLogin);
    connect(ui->pushButton_register,&QPushButton::clicked, this, &Login::onRegister);



    connect(ui->pushButton_clear,&QPushButton::clicked,this,[=](){
        ui->lineEdit_account->clear();
        ui->lineEdit_password->clear();
    });


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

    DataBase & dbManager = DataBase::getDatabase();

    //获取输入框的账号密码
    QString useraccount = ui->lineEdit_account->text();
    QString userpassword = ui->lineEdit_password->text();

    QString sql_account = "SELECT username FROM users WHERE username = '"+useraccount+"';";
    QString sql_password = "SELECT password FROM users WHERE username = '"+useraccount+"';";

    QVector<QMap<QString, QString>> results_account = dbManager.fetchResults(sql_account);
    //如果账号不对
        if(results_account.isEmpty()){
            emit checklogin(0);
            return;
        }

    QVector<QMap<QString, QString>> results_password = dbManager.fetchResults(sql_password);
    //如果密码不对
        if(results_password.first().value("password") != userpassword){
            num++;//累计次数
            emit checklogin(1);
            return;
        }
    //两个都对
    emit display(1);
    emit checklogin(2);

}

void Login::onRegister()
{
    emit display(2);
}


Login::~Login()
{
    delete ui;
}


