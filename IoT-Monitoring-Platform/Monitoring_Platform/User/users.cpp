#include "users.h"
#include "ui_users.h"

Users::Users(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Users)
{
    ui->setupUi(this);

    // 连接注册按钮的点击事件
    connect(ui->pushButton_register, &QPushButton::clicked, this, &Users::onRegisterClicked);
    connect(ui->pushButton_close, &QPushButton::clicked, this, &Users::onCloseClicked);
}

void Users::onRegisterClicked()
{
    // 获取用户输入的数据
    QString username = ui->usernameLineEdit_2->text();
    QString password = ui->passwordLineEdit_2->text();
    QString email = ui->emailLineEdit_2->text();
    QString phone = ui->phoneLineEdit_2->text();

    // 基本的验证
    if (username.isEmpty() || password.isEmpty() || email.isEmpty() || phone.isEmpty()) {
        QMessageBox::warning(this, "输入错误", "所有字段都不能为空！");
        return;
    }

    // 验证邮箱格式   使用QRegExp来检查一个字符串是否符合某种模式
    QRegExp emailRegex("^[\\w-\\.]+@([\\w-]+\\.)+[\\w-]{2,4}$");
    if (!emailRegex.exactMatch(email)) {
        QMessageBox::warning(this, "输入错误", "请输入有效的邮箱地址！");
        return;
    }

    // 验证手机号格式
    QRegExp phoneRegex("^\\d{11}$");
    if (!phoneRegex.exactMatch(phone)) {
        QMessageBox::warning(this, "输入错误", "请输入有效的手机号！");
        return;
    }

    // 插入到数据库
    DataBase& db = DataBase::getDatabase();
    if (!db.connect()) {
        QMessageBox::critical(this, "数据库错误", "无法连接到数据库！");
        return;
    }

    // 构建 SQL 插入语句
    QSqlQuery query;
    query.prepare("INSERT INTO users (username, password, email, phone, role) "
                  "VALUES (:username, :password, :email, :phone, 0)");
    query.bindValue(":username", username);
    query.bindValue(":password", password);
    query.bindValue(":email", email);
    query.bindValue(":phone", phone);

    if (query.exec()) {
        QMessageBox::information(this, "注册成功", "用户注册成功！");
        emit display(0);
    } else {
        QMessageBox::critical(this, "注册失败", "用户注册失败！");
        ui->usernameLineEdit_2->clear();
        ui->passwordLineEdit_2->clear();
        ui->emailLineEdit_2->clear();
        ui->phoneLineEdit_2->clear();
    }
}

void Users::onCloseClicked()
{
    emit display(0);
}


Users::~Users()
{
    delete ui;
}

