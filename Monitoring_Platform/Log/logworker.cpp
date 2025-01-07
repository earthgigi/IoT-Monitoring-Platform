#include "logworker.h"
#include "ui_logworker.h"
#include <QDebug>

LogWorker::LogWorker(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LogWorker) {
    ui->setupUi(this);
    // 设置表格为只读、禁止编辑
    ui->tableWidget_log->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget_log->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget_log->setSelectionMode(QAbstractItemView::SingleSelection);

    // 按钮信号连接
    connect(ui->btn_prevPage, &QPushButton::clicked, this, &LogWorker::onPrevPage);
    connect(ui->btn_nextPage, &QPushButton::clicked, this, &LogWorker::onNextPage);
    connect(ui->btn_search,&QPushButton::clicked,this,&LogWorker::onFilterLogs);
    connect(ui->btn_export,&QPushButton::clicked,this,&LogWorker::onExportLog);

    logData.append({1, "2015-01-06 10:00:00", "system", "INFO", "系统启动成功", "user123", "device456"});
    logData.append({2, "2016-01-06 10:05:00", "operation", "WARNING", "操作超时警告", "user123", "device789"});
    logData.append({3, "2017-01-06 10:10:00", "alarm", "ERROR", "设备连接失败", "user456", "device123"});
    logData.append({4, "2018-01-06 10:15:00", "system", "CRITICAL", "系统内存溢出", "user789", "device654"});
    logData.append({5, "2019-01-06 10:20:00", "operation", "INFO", "用户登录成功", "user001", "device789"});
    logData.append({6, "2020-01-06 10:25:00", "alarm", "WARNING", "温度接近上限", "user123", "device456"});
    logData.append({7, "2021-01-06 10:30:00", "exception", "ERROR", "数据库连接失败", "user999", "device321"});
    logData.append({8, "2022-01-06 10:35:00", "system", "INFO", "服务正常运行", "user456", "device654"});
    logData.append({9, "2023-01-06 10:40:00", "operation", "CRITICAL", "非法操作检测", "user888", "device123"});
    logData.append({10, "2024-01-06 10:45:00", "alarm", "CRITICAL", "设备掉电告警", "user777", "device000"});
    logData.append({11, "2025-01-06 10:50:00", "system", "INFO", "日志清理完成", "user555", "device789"});
    logData.append({12, "2025-02-06 10:55:00", "exception", "WARNING", "配置文件格式异常", "user333", "device123"});
    logData.append({13, "2025-03-06 11:00:00", "alarm", "ERROR", "风扇运行异常", "user111", "device456"});
    logData.append({14, "2025-04-06 11:05:00", "operation", "INFO", "任务执行完成", "user222", "device999"});
    logData.append({15, "2025-05-06 11:10:00", "system", "CRITICAL", "磁盘空间不足", "user000", "device888"});

    initTabWidget();

    // 初始加载数据
    totalPages = (logData.size() + itemsPerPage - 1) / itemsPerPage; // 计算总页数
    loadLogsForPage(0); // 加载第一页数据

//    writeLogToFile(logData);
}

void LogWorker::initTabWidget() {
    // 隐藏左侧行号
    ui->tableWidget_log->verticalHeader()->setVisible(false);

    // 设置表头
    ui->tableWidget_log->setColumnCount(7); // 7列
    QStringList headers = {"ID", "时间", "类型", "等级", "内容", "用户ID", "设备ID"};
    ui->tableWidget_log->setHorizontalHeaderLabels(headers);

    // 设置列宽按比例调整
    ui->tableWidget_log->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void LogWorker::onFilterLogs() {
    filteredLogData.clear(); // 确保每次搜索时清空过滤后的日志数据

    QString keyword = ui->edit_keyWord->text(); // 获取关键字
    QDateTime startTime = ui->edit_startDate->dateTime(); // 开始时间
    QDateTime endTime = ui->edit_endDate->dateTime(); // 结束时间
    QString logLevel = ui->comboBox_logLevel->currentText(); // 日志等级

    // 清空当前表格内容
    ui->tableWidget_log->setRowCount(0);

    // 遍历日志数据，根据条件过滤
    for (const LogEntry &log : logData) {
        bool matches = true;

        // 时间范围过滤
        QDateTime logTime = QDateTime::fromString(log.timestamp, "yyyy-MM-dd hh:mm:ss");
        if (logTime < startTime || logTime > endTime) {
            matches = false;
        }

        // 关键字过滤
        if (!keyword.isEmpty() && !log.content.contains(keyword, Qt::CaseInsensitive)) {
            matches = false;
        }

        // 日志等级过滤
        if (logLevel != "ALL" && log.log_level != logLevel) {
            matches = false;
        }

        // 如果匹配条件，将日志添加到表格
        if (matches) {
            filteredLogData.append(log);
        }
    }
    // 更新分页数据
    totalPages = (filteredLogData.size() + itemsPerPage - 1) / itemsPerPage; // 计算总页数
    loadLogsForPage(0); // 加载第一页搜索结果
}

void LogWorker::onNextPage() {
    if (currentPage < totalPages - 1) {
        loadLogsForPage(currentPage + 1);
    }
}

void LogWorker::onPrevPage() {
    if (currentPage > 0) {
        loadLogsForPage(currentPage - 1);
    }
}

void LogWorker::updatePagination() {
    // 更新页码标签
    ui->label_pageInfo->setText(QString("页码: %1 / %2").arg(currentPage + 1).arg(totalPages));

    // 控制按钮可用状态
    ui->btn_prevPage->setEnabled(currentPage > 0);
    ui->btn_nextPage->setEnabled(currentPage < totalPages - 1);
}

void LogWorker::loadLogsForPage(int page) {
    if (page < 0 || page >= totalPages) return; // 防止越界

    currentPage = page;
    ui->tableWidget_log->setRowCount(0); // 清空表格

    const QList<LogEntry> &dataSource = filteredLogData;  // 使用过滤后的数据

    int start = page * itemsPerPage;                     // 当前页起始索引
    int end = std::min(start + itemsPerPage, dataSource.size()); // 当前页结束索引

    for (int i = start; i < end; ++i) {
        const LogEntry &log = dataSource[i];
        int row = ui->tableWidget_log->rowCount();
        ui->tableWidget_log->insertRow(row);
        QTableWidgetItem *idItem = new QTableWidgetItem(QString::number(log.log_id));
        QTableWidgetItem *timeItem = new QTableWidgetItem(log.timestamp);
        QTableWidgetItem *typeItem = new QTableWidgetItem(log.log_type);
        QTableWidgetItem *levelItem = new QTableWidgetItem(log.log_level);
        QTableWidgetItem *contentItem = new QTableWidgetItem(log.content);
        QTableWidgetItem *userIdItem = new QTableWidgetItem(log.user_id);
        QTableWidgetItem *deviceIdItem = new QTableWidgetItem(log.device_id);

        // 根据日志级别设置颜色
        QColor color;
        if (log.log_level == "ERROR") {
            color = Qt::red;
        } else if (log.log_level == "WARNING") {
            color = QColor(255, 165, 0); // 橙色
        } else if (log.log_level == "INFO") {
            color = Qt::blue;
        } else {
            color = Qt::black; // 默认颜色
        }

        // 设置颜色到每个单元格
        idItem->setForeground(color);
        timeItem->setForeground(color);
        typeItem->setForeground(color);
        levelItem->setForeground(color);
        contentItem->setForeground(color);
        userIdItem->setForeground(color);
        deviceIdItem->setForeground(color);

        // 将单元格添加到表格
        ui->tableWidget_log->setItem(i - start, 0, idItem);
        ui->tableWidget_log->setItem(i - start, 1, timeItem);
        ui->tableWidget_log->setItem(i - start, 2, typeItem);
        ui->tableWidget_log->setItem(i - start, 3, levelItem);
        ui->tableWidget_log->setItem(i - start, 4, contentItem);
        ui->tableWidget_log->setItem(i - start, 5, userIdItem);
        ui->tableWidget_log->setItem(i - start, 6, deviceIdItem);
    }
    // 更新分页信息
    updatePagination();
}

void LogWorker::onExportLog() {
    // 打开文件对话框，让用户选择文件保存路径
    QString filePath = QFileDialog::getSaveFileName(
        this,
        tr("导出日志文件"),
        "",
        tr("文本文件 (*.txt);;CSV文件 (*.csv)")
    );

    // 如果用户未选择路径，直接返回
    if (filePath.isEmpty()) {
        return;
    }

    // 判断是文本文件还是 CSV 文件
    bool isCSV = filePath.endsWith(".csv");

    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        // 打开文件失败
        qDebug() << "无法打开文件进行写入：" << filePath;
        return;
    }

    QTextStream out(&file);
    out.setCodec("UTF-8"); // 设置编码为 UTF-8，确保中文正常显示

    // 写入表头
    QStringList headers;
    for (int col = 0; col < ui->tableWidget_log->columnCount(); ++col) {
        headers << ui->tableWidget_log->horizontalHeaderItem(col)->text();
    }
    out << headers.join(isCSV ? "," : "\t") << "\n"; // 用逗号或制表符分隔表头

    // 遍历搜索的日志数据并写入文件
    for (const LogEntry &log : filteredLogData) {
        QStringList rowData;
        rowData << QString::number(log.log_id) // 转为字符串
                << log.timestamp
                << log.log_type
                << log.log_level
                << log.content
                << log.user_id
                << log.device_id;
        out << rowData.join(isCSV ? "," : "\t") << "\n"; // 用逗号或制表符分隔每行数据
    }
    file.close();
}

LogWorker::~LogWorker() {
    delete ui;
}
