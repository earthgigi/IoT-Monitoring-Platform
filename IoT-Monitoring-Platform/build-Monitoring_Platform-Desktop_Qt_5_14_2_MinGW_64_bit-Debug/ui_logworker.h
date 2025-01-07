/********************************************************************************
** Form generated from reading UI file 'logworker.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGWORKER_H
#define UI_LOGWORKER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
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

class Ui_LogWorker
{
public:
    QGridLayout *gridLayout_3;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QDateEdit *edit_startDate;
    QLabel *label_2;
    QDateEdit *edit_endDate;
    QLabel *label_3;
    QLineEdit *edit_keyWord;
    QLabel *label_4;
    QComboBox *comboBox_logLevel;
    QPushButton *btn_search;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout;
    QTableWidget *tableWidget_log;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_prevPage;
    QPushButton *label_pageInfo;
    QPushButton *btn_nextPage;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btn_export;

    void setupUi(QWidget *LogWorker)
    {
        if (LogWorker->objectName().isEmpty())
            LogWorker->setObjectName(QString::fromUtf8("LogWorker"));
        LogWorker->resize(1125, 784);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(9);
        LogWorker->setFont(font);
        gridLayout_3 = new QGridLayout(LogWorker);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        groupBox = new QGroupBox(LogWorker);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        edit_startDate = new QDateEdit(groupBox);
        edit_startDate->setObjectName(QString::fromUtf8("edit_startDate"));
        edit_startDate->setMinimumSize(QSize(120, 0));
        edit_startDate->setMaximumSize(QSize(120, 16777215));

        horizontalLayout->addWidget(edit_startDate);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        edit_endDate = new QDateEdit(groupBox);
        edit_endDate->setObjectName(QString::fromUtf8("edit_endDate"));
        edit_endDate->setMinimumSize(QSize(120, 0));
        edit_endDate->setMaximumSize(QSize(120, 16777215));

        horizontalLayout->addWidget(edit_endDate);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        edit_keyWord = new QLineEdit(groupBox);
        edit_keyWord->setObjectName(QString::fromUtf8("edit_keyWord"));

        horizontalLayout->addWidget(edit_keyWord);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout->addWidget(label_4);

        comboBox_logLevel = new QComboBox(groupBox);
        comboBox_logLevel->addItem(QString());
        comboBox_logLevel->addItem(QString());
        comboBox_logLevel->addItem(QString());
        comboBox_logLevel->addItem(QString());
        comboBox_logLevel->addItem(QString());
        comboBox_logLevel->setObjectName(QString::fromUtf8("comboBox_logLevel"));

        horizontalLayout->addWidget(comboBox_logLevel);

        btn_search = new QPushButton(groupBox);
        btn_search->setObjectName(QString::fromUtf8("btn_search"));

        horizontalLayout->addWidget(btn_search);


        gridLayout_3->addWidget(groupBox, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(LogWorker);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout = new QGridLayout(groupBox_2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tableWidget_log = new QTableWidget(groupBox_2);
        tableWidget_log->setObjectName(QString::fromUtf8("tableWidget_log"));

        gridLayout->addWidget(tableWidget_log, 0, 0, 1, 1);


        gridLayout_3->addWidget(groupBox_2, 1, 0, 1, 1);

        groupBox_3 = new QGroupBox(LogWorker);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        gridLayout_2 = new QGridLayout(groupBox_3);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
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


        gridLayout_3->addWidget(groupBox_3, 2, 0, 1, 1);


        retranslateUi(LogWorker);

        QMetaObject::connectSlotsByName(LogWorker);
    } // setupUi

    void retranslateUi(QWidget *LogWorker)
    {
        LogWorker->setWindowTitle(QCoreApplication::translate("LogWorker", "Form", nullptr));
        groupBox->setTitle(QCoreApplication::translate("LogWorker", "\346\237\245\350\257\242\346\235\241\344\273\266", nullptr));
        label->setText(QCoreApplication::translate("LogWorker", "\345\274\200\345\247\213\346\227\266\351\227\264", nullptr));
        label_2->setText(QCoreApplication::translate("LogWorker", "\347\273\223\346\235\237\346\227\266\351\227\264", nullptr));
        label_3->setText(QCoreApplication::translate("LogWorker", "\345\205\263\351\224\256\345\255\227", nullptr));
        label_4->setText(QCoreApplication::translate("LogWorker", "\346\227\245\345\277\227\347\255\211\347\272\247", nullptr));
        comboBox_logLevel->setItemText(0, QCoreApplication::translate("LogWorker", "ALL", nullptr));
        comboBox_logLevel->setItemText(1, QCoreApplication::translate("LogWorker", "INFO", nullptr));
        comboBox_logLevel->setItemText(2, QCoreApplication::translate("LogWorker", "WARNING", nullptr));
        comboBox_logLevel->setItemText(3, QCoreApplication::translate("LogWorker", "ERROR", nullptr));
        comboBox_logLevel->setItemText(4, QCoreApplication::translate("LogWorker", "CRITICAL", nullptr));

        btn_search->setText(QCoreApplication::translate("LogWorker", "\346\237\245\350\257\242", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("LogWorker", "\346\227\245\345\277\227\346\230\276\347\244\272", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("LogWorker", "\346\223\215\344\275\234", nullptr));
        btn_prevPage->setText(QCoreApplication::translate("LogWorker", "\344\270\212\344\270\200\351\241\265", nullptr));
        label_pageInfo->setText(QCoreApplication::translate("LogWorker", "\347\254\254x\351\241\265", nullptr));
        btn_nextPage->setText(QCoreApplication::translate("LogWorker", "\344\270\213\344\270\200\351\241\265", nullptr));
        btn_export->setText(QCoreApplication::translate("LogWorker", "\345\257\274\345\207\272\346\227\245\345\277\227", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LogWorker: public Ui_LogWorker {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGWORKER_H
