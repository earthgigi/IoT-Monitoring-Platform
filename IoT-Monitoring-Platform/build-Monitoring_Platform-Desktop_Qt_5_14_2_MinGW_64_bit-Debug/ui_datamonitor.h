/********************************************************************************
** Form generated from reading UI file 'datamonitor.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATAMONITOR_H
#define UI_DATAMONITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DataMonitor
{
public:
    QGridLayout *gridLayout_4;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QDateTimeEdit *edit_startDate;
    QLabel *label_2;
    QDateTimeEdit *edit_endDate;
    QLabel *label_3;
    QLineEdit *edit_deviceName;
    QLabel *label_4;
    QComboBox *comboBox_deviceType;
    QPushButton *btn_search;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QTableWidget *tableWidget_deviceData;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btn_chart;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_prevPage;
    QPushButton *label_pageInfo;
    QPushButton *btn_nextPage;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btn_export;

    void setupUi(QWidget *DataMonitor)
    {
        if (DataMonitor->objectName().isEmpty())
            DataMonitor->setObjectName(QString::fromUtf8("DataMonitor"));
        DataMonitor->resize(1168, 863);
        gridLayout_4 = new QGridLayout(DataMonitor);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        groupBox = new QGroupBox(DataMonitor);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        edit_startDate = new QDateTimeEdit(groupBox);
        edit_startDate->setObjectName(QString::fromUtf8("edit_startDate"));

        horizontalLayout->addWidget(edit_startDate);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        edit_endDate = new QDateTimeEdit(groupBox);
        edit_endDate->setObjectName(QString::fromUtf8("edit_endDate"));

        horizontalLayout->addWidget(edit_endDate);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        edit_deviceName = new QLineEdit(groupBox);
        edit_deviceName->setObjectName(QString::fromUtf8("edit_deviceName"));

        horizontalLayout->addWidget(edit_deviceName);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout->addWidget(label_4);

        comboBox_deviceType = new QComboBox(groupBox);
        comboBox_deviceType->addItem(QString());
        comboBox_deviceType->addItem(QString());
        comboBox_deviceType->addItem(QString());
        comboBox_deviceType->addItem(QString());
        comboBox_deviceType->setObjectName(QString::fromUtf8("comboBox_deviceType"));

        horizontalLayout->addWidget(comboBox_deviceType);

        btn_search = new QPushButton(groupBox);
        btn_search->setObjectName(QString::fromUtf8("btn_search"));

        horizontalLayout->addWidget(btn_search);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);


        gridLayout_4->addWidget(groupBox, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(DataMonitor);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        tableWidget_deviceData = new QTableWidget(groupBox_2);
        tableWidget_deviceData->setObjectName(QString::fromUtf8("tableWidget_deviceData"));

        gridLayout_3->addWidget(tableWidget_deviceData, 0, 0, 1, 1);


        gridLayout_4->addWidget(groupBox_2, 1, 0, 1, 1);

        groupBox_3 = new QGroupBox(DataMonitor);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        gridLayout_2 = new QGridLayout(groupBox_3);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        btn_chart = new QPushButton(groupBox_3);
        btn_chart->setObjectName(QString::fromUtf8("btn_chart"));

        horizontalLayout_2->addWidget(btn_chart);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        btn_prevPage = new QPushButton(groupBox_3);
        btn_prevPage->setObjectName(QString::fromUtf8("btn_prevPage"));

        horizontalLayout_2->addWidget(btn_prevPage);

        label_pageInfo = new QPushButton(groupBox_3);
        label_pageInfo->setObjectName(QString::fromUtf8("label_pageInfo"));

        horizontalLayout_2->addWidget(label_pageInfo);

        btn_nextPage = new QPushButton(groupBox_3);
        btn_nextPage->setObjectName(QString::fromUtf8("btn_nextPage"));

        horizontalLayout_2->addWidget(btn_nextPage);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        btn_export = new QPushButton(groupBox_3);
        btn_export->setObjectName(QString::fromUtf8("btn_export"));

        horizontalLayout_2->addWidget(btn_export);


        gridLayout_2->addLayout(horizontalLayout_2, 0, 0, 1, 1);


        gridLayout_4->addWidget(groupBox_3, 2, 0, 1, 1);


        retranslateUi(DataMonitor);

        QMetaObject::connectSlotsByName(DataMonitor);
    } // setupUi

    void retranslateUi(QWidget *DataMonitor)
    {
        DataMonitor->setWindowTitle(QCoreApplication::translate("DataMonitor", "Form", nullptr));
        groupBox->setTitle(QCoreApplication::translate("DataMonitor", "\346\237\245\350\257\242\346\235\241\344\273\266", nullptr));
        label->setText(QCoreApplication::translate("DataMonitor", "\345\274\200\345\247\213\346\227\266\351\227\264", nullptr));
        label_2->setText(QCoreApplication::translate("DataMonitor", "\347\273\223\346\235\237\346\227\266\351\227\264", nullptr));
        label_3->setText(QCoreApplication::translate("DataMonitor", "\350\256\276\345\244\207\345\220\215", nullptr));
        label_4->setText(QCoreApplication::translate("DataMonitor", "\350\256\276\345\244\207\347\261\273\345\236\213", nullptr));
        comboBox_deviceType->setItemText(0, QCoreApplication::translate("DataMonitor", "ALL", nullptr));
        comboBox_deviceType->setItemText(1, QCoreApplication::translate("DataMonitor", "temperature", nullptr));
        comboBox_deviceType->setItemText(2, QCoreApplication::translate("DataMonitor", "humidity", nullptr));
        comboBox_deviceType->setItemText(3, QCoreApplication::translate("DataMonitor", "light", nullptr));

        btn_search->setText(QCoreApplication::translate("DataMonitor", "\346\237\245\350\257\242", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("DataMonitor", "\346\225\260\346\215\256\346\230\276\347\244\272", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("DataMonitor", "\346\223\215\344\275\234", nullptr));
        btn_chart->setText(QCoreApplication::translate("DataMonitor", "\345\233\276", nullptr));
        btn_prevPage->setText(QCoreApplication::translate("DataMonitor", "\344\270\212\344\270\200\351\241\265", nullptr));
        label_pageInfo->setText(QCoreApplication::translate("DataMonitor", "\347\254\254x\351\241\265", nullptr));
        btn_nextPage->setText(QCoreApplication::translate("DataMonitor", "\344\270\213\344\270\200\351\241\265", nullptr));
        btn_export->setText(QCoreApplication::translate("DataMonitor", "\345\257\274\345\207\272\346\227\245\345\277\227", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DataMonitor: public Ui_DataMonitor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATAMONITOR_H
