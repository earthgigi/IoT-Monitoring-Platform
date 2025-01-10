#ifndef LOGWORKER_H
#define LOGWORKER_H

#include <QWidget>
#include <DataBase/database.h>
#include <Log/logfilehandler.h>
#include <QString>
#include <QList>
#include <QFile>
#include <QFileDialog>
#include <QDate>
#include <QTextStream>
#include <QDir>
#include <QDateTime>

namespace Ui {
class LogWorker;
}

class LogWorker : public QWidget {
    Q_OBJECT

public:
    explicit LogWorker(QWidget *parent = nullptr);
    ~LogWorker();

public slots:
    void onFilterLogs();

    void onNextPage();           // 下一页
    void onPrevPage();           // 上一页

    void onExportLog();

public:
    void initTabWidget();

    void updatePagination();     // 更新分页显示
    void loadLogsForPage(int page); // 加载指定页的日志
    static bool addLogToDB(QList<QString> newLog);

private:
    Ui::LogWorker *ui;
    QVector<QMap<QString, QString>> logData; // 使用数据库查询的结果直接存储日志数据
    QVector<QMap<QString, QString>> filteredLogData; // 筛选后的日志数据

    const int itemsPerPage = 10;  // 每页显示的日志数
    int currentPage = 0;         // 当前页码
    int totalPages = 0;          // 总页数

};

#endif // LOGWORKER_H
