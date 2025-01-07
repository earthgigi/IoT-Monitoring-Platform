/********************************************************************************
** Form generated from reading UI file 'centerbar.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CENTERBAR_H
#define UI_CENTERBAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CenterBar
{
public:

    void setupUi(QWidget *CenterBar)
    {
        if (CenterBar->objectName().isEmpty())
            CenterBar->setObjectName(QString::fromUtf8("CenterBar"));
        CenterBar->resize(1020, 535);

        retranslateUi(CenterBar);

        QMetaObject::connectSlotsByName(CenterBar);
    } // setupUi

    void retranslateUi(QWidget *CenterBar)
    {
        CenterBar->setWindowTitle(QCoreApplication::translate("CenterBar", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CenterBar: public Ui_CenterBar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CENTERBAR_H
