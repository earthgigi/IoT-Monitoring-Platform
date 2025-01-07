/********************************************************************************
** Form generated from reading UI file 'users.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERS_H
#define UI_USERS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Users
{
public:
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *label_5;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_6;
    QLineEdit *usernameLineEdit_2;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_7;
    QLineEdit *passwordLineEdit_2;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_8;
    QLineEdit *emailLineEdit_2;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_9;
    QLineEdit *phoneLineEdit_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_register;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *pushButton_close;

    void setupUi(QWidget *Users)
    {
        if (Users->objectName().isEmpty())
            Users->setObjectName(QString::fromUtf8("Users"));
        Users->resize(633, 424);
        widget = new QWidget(Users);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(140, 40, 312, 331));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMinimumSize(QSize(290, 50));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(12);
        label_5->setFont(font);
        label_5->setStyleSheet(QString::fromUtf8(""));
        label_5->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_5, 0, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(20);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_6 = new QLabel(widget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMinimumSize(QSize(100, 40));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        label_6->setFont(font1);

        horizontalLayout_5->addWidget(label_6);

        usernameLineEdit_2 = new QLineEdit(widget);
        usernameLineEdit_2->setObjectName(QString::fromUtf8("usernameLineEdit_2"));
        usernameLineEdit_2->setMinimumSize(QSize(200, 40));

        horizontalLayout_5->addWidget(usernameLineEdit_2);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_7 = new QLabel(widget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setMinimumSize(QSize(100, 40));
        label_7->setFont(font1);

        horizontalLayout_6->addWidget(label_7);

        passwordLineEdit_2 = new QLineEdit(widget);
        passwordLineEdit_2->setObjectName(QString::fromUtf8("passwordLineEdit_2"));
        passwordLineEdit_2->setMinimumSize(QSize(200, 40));

        horizontalLayout_6->addWidget(passwordLineEdit_2);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_8 = new QLabel(widget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setMinimumSize(QSize(100, 40));
        label_8->setFont(font1);

        horizontalLayout_7->addWidget(label_8);

        emailLineEdit_2 = new QLineEdit(widget);
        emailLineEdit_2->setObjectName(QString::fromUtf8("emailLineEdit_2"));
        emailLineEdit_2->setMinimumSize(QSize(200, 40));

        horizontalLayout_7->addWidget(emailLineEdit_2);


        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_9 = new QLabel(widget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setMinimumSize(QSize(100, 40));
        label_9->setFont(font1);

        horizontalLayout_8->addWidget(label_9);

        phoneLineEdit_2 = new QLineEdit(widget);
        phoneLineEdit_2->setObjectName(QString::fromUtf8("phoneLineEdit_2"));
        phoneLineEdit_2->setMinimumSize(QSize(200, 40));

        horizontalLayout_8->addWidget(phoneLineEdit_2);


        verticalLayout_2->addLayout(horizontalLayout_8);


        gridLayout->addLayout(verticalLayout_2, 1, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton_register = new QPushButton(widget);
        pushButton_register->setObjectName(QString::fromUtf8("pushButton_register"));
        pushButton_register->setMinimumSize(QSize(100, 35));

        horizontalLayout->addWidget(pushButton_register);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        pushButton_close = new QPushButton(widget);
        pushButton_close->setObjectName(QString::fromUtf8("pushButton_close"));
        pushButton_close->setMinimumSize(QSize(100, 35));

        horizontalLayout->addWidget(pushButton_close);


        gridLayout->addLayout(horizontalLayout, 2, 0, 1, 1);


        retranslateUi(Users);

        QMetaObject::connectSlotsByName(Users);
    } // setupUi

    void retranslateUi(QWidget *Users)
    {
        Users->setWindowTitle(QCoreApplication::translate("Users", "Form", nullptr));
        label_5->setText(QCoreApplication::translate("Users", "\345\277\253\346\235\245\345\212\240\345\205\245\350\217\234\347\213\227\350\201\224\347\233\237\357\274\201", nullptr));
        label_6->setText(QCoreApplication::translate("Users", "\347\224\250\346\210\267\345\220\215:    ", nullptr));
        label_7->setText(QCoreApplication::translate("Users", "\345\257\206\347\240\201:     ", nullptr));
        label_8->setText(QCoreApplication::translate("Users", "\347\224\265\345\255\220\351\202\256\347\256\261:  ", nullptr));
        label_9->setText(QCoreApplication::translate("Users", "\346\211\213\346\234\272\345\217\267:    ", nullptr));
        pushButton_register->setText(QCoreApplication::translate("Users", "\346\263\250\345\206\214", nullptr));
        pushButton_close->setText(QCoreApplication::translate("Users", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Users: public Ui_Users {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERS_H
