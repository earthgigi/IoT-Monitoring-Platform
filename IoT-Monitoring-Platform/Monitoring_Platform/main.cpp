#include "widget.h"
#include "DataBase/database.h"
#include <QApplication>
#include <Log/logworker.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DataBase & dbManager = DataBase::getDatabase();
    dbManager.connect();
    Widget w;
    w.show();

    // 创建日志窗口
    LogWorker logWorkerWindow; // 假设 LogWorker 是继承 QWidget 的日志模块
    logWorkerWindow.show();
    return a.exec();
}
