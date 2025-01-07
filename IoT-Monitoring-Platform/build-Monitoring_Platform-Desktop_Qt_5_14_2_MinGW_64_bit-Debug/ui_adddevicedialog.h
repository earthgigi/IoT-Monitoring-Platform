/********************************************************************************
** Form generated from reading UI file 'adddevicedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDDEVICEDIALOG_H
#define UI_ADDDEVICEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>

QT_BEGIN_NAMESPACE

class Ui_AddDeviceDialog
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *AddDeviceDialog)
    {
        if (AddDeviceDialog->objectName().isEmpty())
            AddDeviceDialog->setObjectName(QString::fromUtf8("AddDeviceDialog"));
        AddDeviceDialog->resize(843, 580);
        buttonBox = new QDialogButtonBox(AddDeviceDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(480, 520, 321, 31));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(AddDeviceDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), AddDeviceDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), AddDeviceDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(AddDeviceDialog);
    } // setupUi

    void retranslateUi(QDialog *AddDeviceDialog)
    {
        AddDeviceDialog->setWindowTitle(QCoreApplication::translate("AddDeviceDialog", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddDeviceDialog: public Ui_AddDeviceDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDDEVICEDIALOG_H
