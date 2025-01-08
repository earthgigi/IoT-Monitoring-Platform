#include "widget.h"
#include "DataBase/database.h"
#include <QApplication>
#include <Log/logworker.h>
#include <DataMonitor/datamonitor.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DataBase & dbManager = DataBase::getDatabase();
    dbManager.connect();
//    Widget w;
//    w.show();

//    // 创建日志窗口
//    LogWorker logWorkerWindow; // 假设 LogWorker 是继承 QWidget 的日志模块
//    logWorkerWindow.show();

    // 创建数据监控窗口
    DataMonitor dataMonitorWindow; // 假设 LogWorker 是继承 QWidget 的日志模块
    dataMonitorWindow.show();

    return a.exec();
}
