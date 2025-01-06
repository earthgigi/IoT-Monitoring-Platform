/********************************************************************************
** Form generated from reading UI file 'successlogin.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUCCESSLOGIN_H
#define UI_SUCCESSLOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SuccessLogin
{
public:

    void setupUi(QWidget *SuccessLogin)
    {
        if (SuccessLogin->objectName().isEmpty())
            SuccessLogin->setObjectName(QString::fromUtf8("SuccessLogin"));
        SuccessLogin->resize(962, 724);

        retranslateUi(SuccessLogin);

        QMetaObject::connectSlotsByName(SuccessLogin);
    } // setupUi

    void retranslateUi(QWidget *SuccessLogin)
    {
        SuccessLogin->setWindowTitle(QCoreApplication::translate("SuccessLogin", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SuccessLogin: public Ui_SuccessLogin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUCCESSLOGIN_H
