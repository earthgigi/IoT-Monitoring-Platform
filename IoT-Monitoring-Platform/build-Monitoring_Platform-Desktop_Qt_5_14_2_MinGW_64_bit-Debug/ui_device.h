/********************************************************************************
** Form generated from reading UI file 'device.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEVICE_H
#define UI_DEVICE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Device
{
public:
    QGridLayout *gridLayout;
    QTableWidget *tableWidget_show;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_addDevice;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_deleteDevice;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_updateDevice;
    QSpacerItem *horizontalSpacer_4;

    void setupUi(QWidget *Device)
    {
        if (Device->objectName().isEmpty())
            Device->setObjectName(QString::fromUtf8("Device"));
        Device->resize(795, 579);
        gridLayout = new QGridLayout(Device);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tableWidget_show = new QTableWidget(Device);
        tableWidget_show->setObjectName(QString::fromUtf8("tableWidget_show"));

        gridLayout->addWidget(tableWidget_show, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_addDevice = new QPushButton(Device);
        pushButton_addDevice->setObjectName(QString::fromUtf8("pushButton_addDevice"));
        pushButton_addDevice->setMinimumSize(QSize(100, 30));

        horizontalLayout->addWidget(pushButton_addDevice);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        pushButton_deleteDevice = new QPushButton(Device);
        pushButton_deleteDevice->setObjectName(QString::fromUtf8("pushButton_deleteDevice"));
        pushButton_deleteDevice->setMinimumSize(QSize(100, 30));

        horizontalLayout->addWidget(pushButton_deleteDevice);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        pushButton_updateDevice = new QPushButton(Device);
        pushButton_updateDevice->setObjectName(QString::fromUtf8("pushButton_updateDevice"));
        pushButton_updateDevice->setMinimumSize(QSize(100, 30));

        horizontalLayout->addWidget(pushButton_updateDevice);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);

        gridLayout->setRowStretch(0, 10);
        gridLayout->setRowStretch(1, 1);

        retranslateUi(Device);

        QMetaObject::connectSlotsByName(Device);
    } // setupUi

    void retranslateUi(QWidget *Device)
    {
        Device->setWindowTitle(QCoreApplication::translate("Device", "Form", nullptr));
        pushButton_addDevice->setText(QCoreApplication::translate("Device", "\346\267\273\345\212\240\350\256\276\345\244\207", nullptr));
        pushButton_deleteDevice->setText(QCoreApplication::translate("Device", "\345\210\240\351\231\244\350\256\276\345\244\207", nullptr));
        pushButton_updateDevice->setText(QCoreApplication::translate("Device", "\346\233\264\346\226\260\344\270\200\344\270\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Device: public Ui_Device {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEVICE_H
