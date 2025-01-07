/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_Title;
    QVBoxLayout *verticalLayout_Center;
    QVBoxLayout *verticalLayout_Status;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(800, 600);
        gridLayout = new QGridLayout(Widget);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_Title = new QVBoxLayout();
        verticalLayout_Title->setObjectName(QString::fromUtf8("verticalLayout_Title"));

        gridLayout->addLayout(verticalLayout_Title, 0, 0, 1, 1);

        verticalLayout_Center = new QVBoxLayout();
        verticalLayout_Center->setObjectName(QString::fromUtf8("verticalLayout_Center"));

        gridLayout->addLayout(verticalLayout_Center, 1, 0, 1, 1);

        verticalLayout_Status = new QVBoxLayout();
        verticalLayout_Status->setObjectName(QString::fromUtf8("verticalLayout_Status"));

        gridLayout->addLayout(verticalLayout_Status, 2, 0, 1, 1);

        gridLayout->setRowStretch(0, 1);
        gridLayout->setRowStretch(1, 15);
        gridLayout->setRowStretch(2, 1);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
