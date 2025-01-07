/********************************************************************************
** Form generated from reading UI file 'titlebar.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TITLEBAR_H
#define UI_TITLEBAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TitleBar
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_title;
    QLabel *label_log;
    QLabel *label_Title;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_Min;
    QPushButton *pushButton_Max;
    QPushButton *pushButton_Close;

    void setupUi(QWidget *TitleBar)
    {
        if (TitleBar->objectName().isEmpty())
            TitleBar->setObjectName(QString::fromUtf8("TitleBar"));
        TitleBar->resize(1025, 289);
        gridLayout = new QGridLayout(TitleBar);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_title = new QHBoxLayout();
        horizontalLayout_title->setObjectName(QString::fromUtf8("horizontalLayout_title"));
        label_log = new QLabel(TitleBar);
        label_log->setObjectName(QString::fromUtf8("label_log"));
        label_log->setMinimumSize(QSize(30, 30));
        label_log->setMaximumSize(QSize(30, 30));
        label_log->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_title->addWidget(label_log);

        label_Title = new QLabel(TitleBar);
        label_Title->setObjectName(QString::fromUtf8("label_Title"));
        label_Title->setMinimumSize(QSize(280, 30));
        label_Title->setMaximumSize(QSize(16777215, 30));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        label_Title->setFont(font);
        label_Title->setStyleSheet(QString::fromUtf8(""));
        label_Title->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_title->addWidget(label_Title);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_title->addItem(horizontalSpacer);

        pushButton_Min = new QPushButton(TitleBar);
        pushButton_Min->setObjectName(QString::fromUtf8("pushButton_Min"));
        pushButton_Min->setMinimumSize(QSize(25, 25));
        pushButton_Min->setMaximumSize(QSize(25, 25));
        pushButton_Min->setStyleSheet(QString::fromUtf8("border-image: url(:/image/minbtn.png);"));

        horizontalLayout_title->addWidget(pushButton_Min);

        pushButton_Max = new QPushButton(TitleBar);
        pushButton_Max->setObjectName(QString::fromUtf8("pushButton_Max"));
        pushButton_Max->setMinimumSize(QSize(25, 25));
        pushButton_Max->setMaximumSize(QSize(25, 25));
        pushButton_Max->setStyleSheet(QString::fromUtf8("border-image: url(:/image/maxbtn.png);"));

        horizontalLayout_title->addWidget(pushButton_Max);

        pushButton_Close = new QPushButton(TitleBar);
        pushButton_Close->setObjectName(QString::fromUtf8("pushButton_Close"));
        pushButton_Close->setMinimumSize(QSize(25, 25));
        pushButton_Close->setMaximumSize(QSize(25, 25));
        pushButton_Close->setStyleSheet(QString::fromUtf8("border-image: url(:/image/closebtn.png);"));

        horizontalLayout_title->addWidget(pushButton_Close);


        gridLayout->addLayout(horizontalLayout_title, 0, 0, 1, 1);


        retranslateUi(TitleBar);

        QMetaObject::connectSlotsByName(TitleBar);
    } // setupUi

    void retranslateUi(QWidget *TitleBar)
    {
        TitleBar->setWindowTitle(QCoreApplication::translate("TitleBar", "Form", nullptr));
        label_log->setText(QString());
        label_Title->setText(QCoreApplication::translate("TitleBar", " \350\217\234\345\235\244\347\211\251\350\201\224\347\275\221\347\233\221\346\216\247\345\271\263\345\217\260", nullptr));
        pushButton_Min->setText(QString());
        pushButton_Max->setText(QString());
        pushButton_Close->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class TitleBar: public Ui_TitleBar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TITLEBAR_H
