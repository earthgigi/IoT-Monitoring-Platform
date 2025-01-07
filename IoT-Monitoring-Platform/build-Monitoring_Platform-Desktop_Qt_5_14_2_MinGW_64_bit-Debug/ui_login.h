/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_nochange1;
    QLineEdit *lineEdit_account;
    QPushButton *pushButton_login;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_nochange2;
    QLineEdit *lineEdit_password;
    QPushButton *pushButton_clear;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_forgetPassword;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_register;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_left;
    QLabel *label_2;
    QLabel *label_right;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QString::fromUtf8("Login"));
        Login->resize(891, 525);
        gridLayout = new QGridLayout(Login);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_nochange1 = new QLabel(Login);
        label_nochange1->setObjectName(QString::fromUtf8("label_nochange1"));
        label_nochange1->setMinimumSize(QSize(70, 40));
        label_nochange1->setMaximumSize(QSize(70, 40));
        label_nochange1->setSizeIncrement(QSize(100, 40));
        label_nochange1->setBaseSize(QSize(100, 0));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(12);
        label_nochange1->setFont(font);

        horizontalLayout->addWidget(label_nochange1);

        lineEdit_account = new QLineEdit(Login);
        lineEdit_account->setObjectName(QString::fromUtf8("lineEdit_account"));
        lineEdit_account->setMinimumSize(QSize(300, 35));
        lineEdit_account->setMaximumSize(QSize(300, 35));

        horizontalLayout->addWidget(lineEdit_account);

        pushButton_login = new QPushButton(Login);
        pushButton_login->setObjectName(QString::fromUtf8("pushButton_login"));
        pushButton_login->setMinimumSize(QSize(100, 40));
        pushButton_login->setMaximumSize(QSize(100, 40));
        pushButton_login->setFont(font);

        horizontalLayout->addWidget(pushButton_login);


        gridLayout->addLayout(horizontalLayout, 2, 0, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 108, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_4, 7, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_nochange2 = new QLabel(Login);
        label_nochange2->setObjectName(QString::fromUtf8("label_nochange2"));
        label_nochange2->setMinimumSize(QSize(70, 40));
        label_nochange2->setMaximumSize(QSize(70, 40));
        label_nochange2->setSizeIncrement(QSize(100, 40));
        label_nochange2->setBaseSize(QSize(100, 0));
        label_nochange2->setFont(font);

        horizontalLayout_2->addWidget(label_nochange2);

        lineEdit_password = new QLineEdit(Login);
        lineEdit_password->setObjectName(QString::fromUtf8("lineEdit_password"));
        lineEdit_password->setMinimumSize(QSize(300, 35));
        lineEdit_password->setMaximumSize(QSize(300, 35));

        horizontalLayout_2->addWidget(lineEdit_password);

        pushButton_clear = new QPushButton(Login);
        pushButton_clear->setObjectName(QString::fromUtf8("pushButton_clear"));
        pushButton_clear->setMinimumSize(QSize(100, 40));
        pushButton_clear->setMaximumSize(QSize(100, 40));
        pushButton_clear->setFont(font);

        horizontalLayout_2->addWidget(pushButton_clear);


        gridLayout->addLayout(horizontalLayout_2, 4, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        pushButton_forgetPassword = new QPushButton(Login);
        pushButton_forgetPassword->setObjectName(QString::fromUtf8("pushButton_forgetPassword"));
        pushButton_forgetPassword->setMinimumSize(QSize(100, 40));
        pushButton_forgetPassword->setMaximumSize(QSize(100, 40));
        pushButton_forgetPassword->setFont(font);

        horizontalLayout_3->addWidget(pushButton_forgetPassword);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        pushButton_register = new QPushButton(Login);
        pushButton_register->setObjectName(QString::fromUtf8("pushButton_register"));
        pushButton_register->setMinimumSize(QSize(100, 40));
        pushButton_register->setMaximumSize(QSize(100, 40));
        pushButton_register->setFont(font);

        horizontalLayout_3->addWidget(pushButton_register);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);


        gridLayout->addLayout(horizontalLayout_3, 6, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_left = new QLabel(Login);
        label_left->setObjectName(QString::fromUtf8("label_left"));
        label_left->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 255, 127);"));

        horizontalLayout_4->addWidget(label_left);

        label_2 = new QLabel(Login);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 255, 127);"));

        horizontalLayout_4->addWidget(label_2);

        label_right = new QLabel(Login);
        label_right->setObjectName(QString::fromUtf8("label_right"));
        label_right->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 255, 127);"));

        horizontalLayout_4->addWidget(label_right);

        horizontalLayout_4->setStretch(0, 3);
        horizontalLayout_4->setStretch(1, 5);
        horizontalLayout_4->setStretch(2, 3);

        gridLayout->addLayout(horizontalLayout_4, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 109, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 3, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 1, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 108, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 5, 0, 1, 1);

        gridLayout->setRowStretch(0, 10);
        gridLayout->setRowStretch(1, 1);
        gridLayout->setRowStretch(2, 1);
        gridLayout->setRowStretch(3, 1);
        gridLayout->setRowStretch(4, 1);
        gridLayout->setRowStretch(5, 1);
        gridLayout->setRowStretch(6, 1);
        gridLayout->setRowStretch(7, 1);

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QWidget *Login)
    {
        Login->setWindowTitle(QCoreApplication::translate("Login", "Form", nullptr));
        label_nochange1->setText(QCoreApplication::translate("Login", "\347\224\250\346\210\267\345\247\223\345\220\215", nullptr));
        pushButton_login->setText(QCoreApplication::translate("Login", "\347\231\273\345\275\225", nullptr));
        label_nochange2->setText(QCoreApplication::translate("Login", "\347\224\250\346\210\267\345\257\206\347\240\201", nullptr));
        pushButton_clear->setText(QCoreApplication::translate("Login", "\346\270\205\347\251\272", nullptr));
        pushButton_forgetPassword->setText(QCoreApplication::translate("Login", "\345\277\230\350\256\260\345\257\206\347\240\201", nullptr));
        pushButton_register->setText(QCoreApplication::translate("Login", "\346\263\250\345\206\214", nullptr));
        label_left->setText(QString());
        label_2->setText(QString());
        label_right->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
