#include "datamonitor.h"
#include "ui_datamonitor.h"

DataBase& db = DataBase::getDatabase();

DataMonitor::DataMonitor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DataMonitor) {
    ui->setupUi(this);
}

void DataMonitor::initTabWidget() {
//    // 隐藏左侧行号
//    ui->tableWidget_deviceData->verticalHeader()->setVisible(false);

//    // 设置表头
//    ui->tableWidget_deviceData->setColumnCount(8); // 8列
//    QStringList headers = {"数据ID", "设备ID", "设备名", "设备类型", "时间", "温度", "湿度", "光照强度"};
//    ui->tableWidget_deviceData->setHorizontalHeaderLabels(headers);

//    // 设置列宽按比例调整
//    ui->tableWidget_deviceData->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);


//    if (!db.connect()) {
//        qDebug() << "数据库错误,日志无法连接到数据库!";
//        return;
//    }
//    QString createTableQuery = R"(
//        CREATE TABLE IF NOT EXISTS device_data (
//            log_id INTEGER PRIMARY KEY AUTOINCREMENT,
//            timestamp DATETIME NOT NULL,
//            log_type TEXT NOT NULL,
//            log_level TEXT NOT NULL,
//            content TEXT NOT NULL,
//            user_id INTEGER,
//            device_id INTEGER
//        );
//    )";
//    // 执行 SQL 查询（创建表）
//    if (db.executeQuery(createTableQuery)) {
//        qDebug() << "Table 'system_logs' created successfully!";
//    } else {
//        qDebug() << "Failed to create table 'system_logs'.";
//    }
}

void DataMonitor::updatePagination() {

}

void DataMonitor::loadDataForPage(int page) {

}

bool DataMonitor::addDataToDB(QList<QString> newLog) {

}


void DataMonitor::onFilterData() {

}

void DataMonitor::onNextPage() {

}

void DataMonitor::onPrevPage() {

}

void DataMonitor::onExportData() {

}

void DataMonitor::onChart() {

}

DataMonitor::~DataMonitor() {
    delete ui;
}
