#include "logworker.h"
#include "ui_logworker.h"
#include <QDebug>

LogWorker::LogWorker(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LogWorker) {
    ui->setupUi(this);
    //设置QTabWidget表头，并尝试在数据库中创建日志表
    initTabWidget();

    // 按钮信号连接
    connect(ui->btn_prevPage, &QPushButton::clicked, this, &LogWorker::onPrevPage);
    connect(ui->btn_nextPage, &QPushButton::clicked, this, &LogWorker::onNextPage);
    connect(ui->btn_search,&QPushButton::clicked,this,&LogWorker::onFilterLogs);
    connect(ui->btn_export,&QPushButton::clicked,this,&LogWorker::onExportLog);

    // 初始加载数据
    totalPages = (logData.size() + itemsPerPage - 1) / itemsPerPage; // 计算总页数
    loadLogsForPage(0); // 加载第一页数据

}

void LogWorker::initTabWidget() {
    //获取数据库单例
    DataBase& db = DataBase::getDatabase();

    // 隐藏左侧行号
    ui->tableWidget_log->verticalHeader()->setVisible(false);

    // 设置表头
    ui->tableWidget_log->setColumnCount(7); // 7列
    QStringList headers = {"ID", "时间", "类型", "等级", "内容", "用户ID", "设备ID"};
    ui->tableWidget_log->setHorizontalHeaderLabels(headers);

    // 设置列宽按比例调整
    ui->tableWidget_log->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // 设置表格为只读、禁止编辑
    ui->tableWidget_log->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget_log->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget_log->setSelectionMode(QAbstractItemView::SingleSelection);

    if (!db.connect()) {
        qDebug() << "数据库错误,日志无法连接到数据库!";
        return;
    }
    QString createTableQuery = R"(
        CREATE TABLE IF NOT EXISTS system_logs (
            log_id INTEGER PRIMARY KEY AUTOINCREMENT,
            timestamp DATETIME NOT NULL,
            log_type TEXT NOT NULL,
            log_level TEXT NOT NULL,
            content TEXT NOT NULL,
            user_id INTEGER,
            device_id INTEGER
        );
    )";
    // 执行 SQL 查询（创建表）
    if (db.executeQuery(createTableQuery)) {
        qDebug() << "Table 'system_logs' created successfully!";
    } else {
        qDebug() << "Failed to create table 'system_logs'.";
    }
}

void LogWorker::onFilterLogs() {
    //获取数据库单例
    DataBase& db = DataBase::getDatabase();

    filteredLogData.clear(); // 确保每次搜索时清空过滤后的日志数据

    QString keyword = ui->edit_keyWord->text(); // 获取关键字
    QDateTime startTime = ui->edit_startDate->dateTime(); // 开始时间
    QDateTime endTime = ui->edit_endDate->dateTime(); // 结束时间
    QString logLevel = ui->comboBox_logLevel->currentText(); // 日志等级

    // 清空当前表格内容
    ui->tableWidget_log->setRowCount(0);
    //查询日志数据
    QString sql_logs = "SELECT *FROM system_logs";
    logData = db.fetchResults(sql_logs);
    // 遍历日志数据，根据条件过滤
    for (const auto& log : logData) {
        bool matches = true;

        // 时间范围过滤
        QDateTime logTime = QDateTime::fromString(log.value("timestamp"), "yyyy-MM-dd hh:mm:ss");
        if (logTime < startTime || logTime > endTime) {
            matches = false;
        }

        // 关键字过滤
        if (!keyword.isEmpty() && !log.value("content").contains(keyword, Qt::CaseInsensitive)) {
            matches = false;
        }

        // 日志等级过滤
        if (logLevel != "ALL" && log.value("log_level") != logLevel) {
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

    int start = page * itemsPerPage;                     // 当前页起始索引
    int end = std::min(start + itemsPerPage, filteredLogData.size()); // 当前页结束索引

    for (int i = start; i < end; ++i) {
        const auto& log = filteredLogData[i];
        int row = ui->tableWidget_log->rowCount();
        ui->tableWidget_log->insertRow(row);
        QTableWidgetItem *idItem = new QTableWidgetItem(log.value("log_id"));
        QTableWidgetItem *timeItem = new QTableWidgetItem(log.value("timestamp"));
        QTableWidgetItem *typeItem = new QTableWidgetItem(log.value("log_type"));
        QTableWidgetItem *levelItem = new QTableWidgetItem(log.value("log_level"));
        QTableWidgetItem *contentItem = new QTableWidgetItem(log.value("content"));
        QTableWidgetItem *userIdItem = new QTableWidgetItem(log.value("user_id"));
        QTableWidgetItem *deviceIdItem = new QTableWidgetItem(log.value("device_id"));

        // 根据日志级别设置颜色
        QColor color;
        if (log.value("log_level") == "ERROR") {
            color = Qt::red;
        } else if (log.value("log_level") == "WARNING") {
            color = QColor(255, 165, 0); // 橙色
        } else if (log.value("log_level") == "INFO") {
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
    for (const auto& log : filteredLogData) {
        QStringList rowData;
        rowData << log.value("log_id")
                << log.value("timestamp")
                << log.value("log_type")
                << log.value("log_level")
                << log.value("content")
                << log.value("user_id")
                << log.value("device_id");
        out << rowData.join(isCSV ? "," : "\t") << "\n"; // 用逗号或制表符分隔每行数据
    }
    file.close();
}

bool LogWorker::addLogToDB(QList<QString> newLog) {
    LogFileHandler::addLogToFile(newLog);
    // 检查 newLog 是否包含足够的字段
    if (newLog.size() < 6) {
        qDebug() << "Invalid log data, insertion failed.";
        return false;
    }

    // 构建 SQL 插入语句
    QSqlQuery query;
    query.prepare("INSERT INTO system_logs (timestamp, log_type, log_level, content, user_id, device_id) "
                  "VALUES (:timestamp, :log_type, :log_level, :content, :user_id, :device_id)");

    // 绑定参数
    query.bindValue(":timestamp", newLog[0]);
    query.bindValue(":log_type", newLog[1]);
    query.bindValue(":log_level", newLog[2]);
    query.bindValue(":content", newLog[3]);
    query.bindValue(":user_id", newLog[4].isEmpty() ? QVariant(QVariant::String) : newLog[4]);
    query.bindValue(":device_id", newLog[5].isEmpty() ? QVariant(QVariant::String) : newLog[5]);

    // 执行插入语句
    if (query.exec()) {
        qDebug() << "Log inserted successfully!";
        return true;
    } else {
        qDebug() << "Failed to insert log:" << query.lastError().text();
        return false;
    }
}

LogWorker::~LogWorker() {
    delete ui;
}
