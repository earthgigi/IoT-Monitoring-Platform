#ifndef LOGWORKER_H
#define LOGWORKER_H

#include <QWidget>

#include <QString>
#include <QList>
#include <QFile>
#include <QFileInfo>
#include <QFileDialog>
#include <QDate>
#include <QTextStream>
#include <QDir>
struct LogEntry {
    int log_id;          // 日志ID
    QString timestamp;   // 日志时间
    QString log_type;    // 日志类型
    QString log_level;   // 日志等级
    QString content;     // 日志内容
    QString user_id;     // 用户ID（可选）
    QString device_id;   // 设备ID（可选）
};

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

private:
    Ui::LogWorker *ui;
    QList<LogEntry> logData;
    QList<LogEntry> filteredLogData; // 搜索结果数据

    const int itemsPerPage = 10;  // 每页显示的日志数
    int currentPage = 0;         // 当前页码
    int totalPages = 0;          // 总页数

};

#endif // LOGWORKER_H
