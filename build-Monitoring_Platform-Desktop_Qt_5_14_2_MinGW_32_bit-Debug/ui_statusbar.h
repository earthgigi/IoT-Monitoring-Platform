/********************************************************************************
** Form generated from reading UI file 'statusbar.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATUSBAR_H
#define UI_STATUSBAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StatusBar
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_status;
    QLabel *label_Status;

    void setupUi(QWidget *StatusBar)
    {
        if (StatusBar->objectName().isEmpty())
            StatusBar->setObjectName(QString::fromUtf8("StatusBar"));
        StatusBar->resize(862, 72);
        gridLayout = new QGridLayout(StatusBar);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_status = new QHBoxLayout();
        horizontalLayout_status->setObjectName(QString::fromUtf8("horizontalLayout_status"));
        label_Status = new QLabel(StatusBar);
        label_Status->setObjectName(QString::fromUtf8("label_Status"));
        label_Status->setMinimumSize(QSize(280, 30));
        label_Status->setMaximumSize(QSize(16777215, 30));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        label_Status->setFont(font);
        label_Status->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_status->addWidget(label_Status);


        gridLayout->addLayout(horizontalLayout_status, 0, 0, 1, 1);


        retranslateUi(StatusBar);

        QMetaObject::connectSlotsByName(StatusBar);
    } // setupUi

    void retranslateUi(QWidget *StatusBar)
    {
        StatusBar->setWindowTitle(QCoreApplication::translate("StatusBar", "Form", nullptr));
        label_Status->setText(QCoreApplication::translate("StatusBar", "\346\211\223\345\200\222\344\272\241\347\201\265\351\235\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StatusBar: public Ui_StatusBar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATUSBAR_H
