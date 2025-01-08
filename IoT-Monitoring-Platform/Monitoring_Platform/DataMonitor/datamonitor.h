#ifndef DATAMONITOR_H
#define DATAMONITOR_H

#include <QWidget>
#include <Log/logworker.h>

namespace Ui {
class DataMonitor;
}

class DataMonitor : public QWidget {
    Q_OBJECT

public:
    explicit DataMonitor(QWidget *parent = nullptr);
    ~DataMonitor();

public slots:
    void onFilterData();

    void onNextPage();           // 下一页
    void onPrevPage();           // 上一页

    void onExportData();

    void onChart();

public:
    void initTabWidget();

    void updatePagination();     // 更新分页显示
    void loadDataForPage(int page); // 加载指定页的日志
    bool addDataToDB(QList<QString> newLog);

private:
    Ui::DataMonitor *ui;
    QVector<QMap<QString, QString>> logData; // 使用数据库查询的结果直接存储日志数据
    QVector<QMap<QString, QString>> filteredLogData; // 筛选后的日志数据

    const int itemsPerPage = 10;  // 每页显示的日志数
    int currentPage = 0;         // 当前页码
    int totalPages = 0;          // 总页数

};

#endif // DATAMONITOR_H
