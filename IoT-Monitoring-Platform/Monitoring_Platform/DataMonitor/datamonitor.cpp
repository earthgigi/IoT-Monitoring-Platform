#include "datamonitor.h"
#include "ui_datamonitor.h"

#include <QMessageBox>

DataMonitor::DataMonitor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DataMonitor) {
    ui->setupUi(this);
    m_qTimer = new QTimer(this);

    initTabWidget();

    // 按钮信号连接
    connect(ui->btn_prevPage, &QPushButton::clicked, this, &DataMonitor::onPrevPage);
    connect(ui->btn_nextPage, &QPushButton::clicked, this, &DataMonitor::onNextPage);
    connect(ui->btn_search,&QPushButton::clicked,this,&DataMonitor::onFilterData);
    connect(ui->btn_export,&QPushButton::clicked,this,&DataMonitor::onExportData);
    connect(ui->btn_chart,&QPushButton::clicked,this,&DataMonitor::onChart);
    connect(m_qTimer, &QTimer::timeout, this, &DataMonitor::onInsertRandomData);
    m_qTimer->start(6000); // 每隔6秒执行一次
    // 初始加载数据
    totalPages = (deviceData.size() + itemsPerPage - 1) / itemsPerPage; // 计算总页数
    loadDataForPage(0); // 加载第一页数据
}

void DataMonitor::initTabWidget() {
    //获取数据库单例
    DataBase& db = DataBase::getDatabase();

    //初始化结束时间为当前时间
    ui->edit_endDate->setDateTime(QDateTime::currentDateTime());

    // 隐藏左侧行号
    ui->tableWidget_deviceData->verticalHeader()->setVisible(false);

    // 设置表头
    ui->tableWidget_deviceData->setColumnCount(8); // 8列
    QStringList headers = {"数据ID", "设备ID", "设备名", "设备类型", "时间", "温度", "湿度", "光照强度"};
    ui->tableWidget_deviceData->setHorizontalHeaderLabels(headers);

    // 设置列宽按比例调整
    ui->tableWidget_deviceData->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // 设置表格为只读、禁止编辑
    ui->tableWidget_deviceData->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget_deviceData->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget_deviceData->setSelectionMode(QAbstractItemView::SingleSelection);

    if (!db.connect()) {
        qDebug() << "数据库错误,日志无法连接到数据库!";
        return;
    }
    QString createTableQuery = R"(
        CREATE TABLE IF NOT EXISTS device_data (
            data_id INTEGER PRIMARY KEY AUTOINCREMENT,  -- 数据ID，自增主键
            device_id INTEGER NOT NULL,                 -- 设备ID，外键，非空
            timestamp DATETIME NOT NULL,                -- 时间戳，非空
            temperature REAL,                           -- 温度，可空
            humidity REAL,                              -- 湿度，可空
            light REAL,                                 -- 光照强度，可空
            FOREIGN KEY (device_id) REFERENCES device(device_id) -- 外键约束，关联设备表
            ON DELETE CASCADE                            --指定级联删除
        );
    )";
    // 执行 SQL 查询（创建表）
    if (db.executeQuery(createTableQuery)) {
        qDebug() << "Table 'device_data' created successfully!";
    } else {
        qDebug() << "Failed to create table 'device_data'.";
    }

    //查询两表数据，准备导入展示
    QString query = R"(
                    SELECT dd.data_id, d.device_id, d.name, d.type, dd.timestamp, dd.temperature, dd.humidity, dd.light
                    FROM device AS d
                    JOIN device_data AS dd
                    ON d.device_id = dd.device_id;
    )";
    deviceData = db.fetchResults(query);
}

void DataMonitor::updatePagination() {
    // 更新页码标签
    ui->label_pageInfo->setText(QString("页码: %1 / %2").arg(currentPage + 1).arg(totalPages));

    // 控制按钮可用状态
    ui->btn_prevPage->setEnabled(currentPage > 0);
    ui->btn_nextPage->setEnabled(currentPage < totalPages - 1);
}

void DataMonitor::loadDataForPage(int page) {
    if (page < 0 || page >= totalPages) return; // 防止越界
    currentPage = page;
    ui->tableWidget_deviceData->setRowCount(0); // 清空表格

    int start = page * itemsPerPage;                     // 当前页起始索引
    int end = std::min(start + itemsPerPage, filteredDeviceData.size()); // 当前页结束索引

    for (int i = start; i < end; ++i) {
        const auto& log = filteredDeviceData[i];
        int row = ui->tableWidget_deviceData->rowCount();
        ui->tableWidget_deviceData->insertRow(row);
        QTableWidgetItem *data_idItem = new QTableWidgetItem(log.value("data_id"));
        QTableWidgetItem *device_idItem = new QTableWidgetItem(log.value("device_id"));
        QTableWidgetItem *nameItem = new QTableWidgetItem(log.value("name"));
        QTableWidgetItem *typeItem = new QTableWidgetItem(log.value("type"));
        QTableWidgetItem *timestampItem = new QTableWidgetItem(log.value("timestamp"));
        QTableWidgetItem *temperatureIdItem = new QTableWidgetItem(log.value("temperature"));
        QTableWidgetItem *humidityItem = new QTableWidgetItem(log.value("humidity"));
        QTableWidgetItem *lightItem = new QTableWidgetItem(log.value("light"));

        // 将单元格添加到表格
        ui->tableWidget_deviceData->setItem(i - start, 0, data_idItem);
        ui->tableWidget_deviceData->setItem(i - start, 1, device_idItem);
        ui->tableWidget_deviceData->setItem(i - start, 2, nameItem);
        ui->tableWidget_deviceData->setItem(i - start, 3, typeItem);
        ui->tableWidget_deviceData->setItem(i - start, 4, timestampItem);
        ui->tableWidget_deviceData->setItem(i - start, 5, temperatureIdItem);
        ui->tableWidget_deviceData->setItem(i - start, 6, humidityItem);
        ui->tableWidget_deviceData->setItem(i - start, 7, lightItem);
    }
    // 更新分页信息
    updatePagination();
}

void DataMonitor::onFilterData() {
    filteredDeviceData.clear(); // 确保每次搜索时清空过滤后的日志数据

    QString deviceName = ui->edit_deviceName->text(); // 获取设备名
    QDateTime startTime = ui->edit_startDate->dateTime(); // 开始时间
    QDateTime endTime = ui->edit_endDate->dateTime(); // 结束时间
    QString deviceType = ui->comboBox_deviceType->currentText(); // 设备类型

    // 遍历日志数据，根据条件过滤
    for (const auto& log : deviceData) {
        bool matches = true;

        // 时间范围过滤
        QDateTime logTime = QDateTime::fromString(log.value("timestamp"), "yyyy-MM-dd hh:mm:ss");
        if (logTime < startTime || logTime > endTime) {
            matches = false;
        }

        // 设备名过滤
        if (!deviceName.isEmpty() && !log.value("name").contains(deviceName, Qt::CaseInsensitive)) {
            matches = false;
        }

        // 设备类型过滤
        if (deviceType != "ALL" && log.value("type") != deviceType) {
            matches = false;
        }

        // 如果匹配条件，将设备数据添加到表格
        if (matches) {
            filteredDeviceData.append(log);
        }
    }

    QList<QString> newLog = {QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")
                             ,"operation"
                             ,"INFO"
                             ,"筛选设备数据"
                             ,""
                             ,""};
    LogWorker::addLogToDB(newLog);

    // 更新分页数据
    totalPages = (filteredDeviceData.size() + itemsPerPage - 1) / itemsPerPage; // 计算总页数
    loadDataForPage(0); // 加载第一页搜索结果
}

void DataMonitor::onNextPage() {
    if (currentPage < totalPages - 1) {
        loadDataForPage(currentPage + 1);
    }
}

void DataMonitor::onPrevPage() {
    if (currentPage > 0) {
        loadDataForPage(currentPage - 1);
    }
}

void DataMonitor::onExportData() {
    // 打开文件对话框，让用户选择保存路径
    QString filePath = QFileDialog::getSaveFileName(
        this,
        tr("导出数据"),
        "",
        tr("CSV 文件 (*.csv);;Excel 文件 (*.xlsx)")
    );

    // 如果用户未选择路径，直接返回
    if (filePath.isEmpty()) {
        return;
    }

    // 判断文件格式
    bool isCSV = filePath.endsWith(".csv");

    // 创建文件
    if (isCSV) {
        QFile file(filePath);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            qDebug() << "无法打开文件进行写入: " << filePath;
            return;
        }

        QTextStream out(&file);
        out.setCodec("UTF-8"); // 设置编码为 UTF-8，确保中文正常显示

        // 写入表头
        QStringList headers;
        for (int col = 0; col < ui->tableWidget_deviceData->columnCount(); ++col) {
            headers << ui->tableWidget_deviceData->horizontalHeaderItem(col)->text();
        }
        out << headers.join(",") << "\n";

        // 写入当前过滤后的数据
        for (const auto &row : filteredDeviceData) { // 假设 filteredData 存储当前筛选结果
            QStringList rowData;
            rowData << row.value("data_id");
            rowData << row.value("device_id");
            rowData << row.value("name");
            rowData << row.value("type");
            rowData << row.value("timestamp");
            rowData << row.value("temperature");
            rowData << row.value("humidity");
            rowData << row.value("light");
            out << rowData.join(",") << "\n";
        }

        file.close();
    } else {
        // 使用 QAxObject 导出 Excel
        QAxObject *excel = new QAxObject("Excel.Application");
        if (!excel) {
            QMessageBox::warning(this, tr("错误"), tr("无法启动 Excel，请确保已正确安装 Microsoft Excel"));
            return;
        }

        excel->dynamicCall("SetVisible(bool Visible)", false); // 隐藏 Excel 窗口
        QAxObject *workbooks = excel->querySubObject("Workbooks");
        QAxObject *workbook = workbooks->querySubObject("Add()");
        QAxObject *sheet = workbook->querySubObject("Worksheets(int)", 1);

        // 写入表头
        for (int col = 0; col < ui->tableWidget_deviceData->columnCount(); ++col) {
            QAxObject *cell = sheet->querySubObject("Cells(int,int)", 1, col + 1);
            QString header = ui->tableWidget_deviceData->horizontalHeaderItem(col)->text();
            cell->dynamicCall("SetValue(const QVariant&)", header);
        }

        // 写入数据
        int rowIndex = 2; // 从第2行开始写数据
        for (const auto &row : filteredDeviceData) { // filteredDeviceData 存储当前筛选结果
            sheet->querySubObject("Cells(int,int)", rowIndex, 1)->dynamicCall("SetValue(const QVariant&)", row.value("data_id"));
            sheet->querySubObject("Cells(int,int)", rowIndex, 2)->dynamicCall("SetValue(const QVariant&)", row.value("device_id"));
            sheet->querySubObject("Cells(int,int)", rowIndex, 3)->dynamicCall("SetValue(const QVariant&)", row.value("name"));
            sheet->querySubObject("Cells(int,int)", rowIndex, 4)->dynamicCall("SetValue(const QVariant&)", row.value("type"));
            sheet->querySubObject("Cells(int,int)", rowIndex, 5)->dynamicCall("SetValue(const QVariant&)", row.value("timestamp"));
            sheet->querySubObject("Cells(int,int)", rowIndex, 6)->dynamicCall("SetValue(const QVariant&)", row.value("temperature"));
            sheet->querySubObject("Cells(int,int)", rowIndex, 7)->dynamicCall("SetValue(const QVariant&)", row.value("humidity"));
            sheet->querySubObject("Cells(int,int)", rowIndex, 8)->dynamicCall("SetValue(const QVariant&)", row.value("light"));
            rowIndex++;
        }

        // 保存 Excel 文件
        workbook->dynamicCall("SaveAs(const QString&)", QDir::toNativeSeparators(filePath));
        workbook->dynamicCall("Close()");
        excel->dynamicCall("Quit()");
        qDebug() << "导出excel成功";
        delete excel;
    }
    QList<QString> newLog = {QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")
                             ,"operation"
                             ,"INFO"
                             ,"导出设备数据"
                             ,""
                             ,""};
    LogWorker::addLogToDB(newLog);
}

void DataMonitor::onChart() {
    using namespace QtCharts;

    // 创建弹窗
    QDialog *dialog = new QDialog(this);
    dialog->setWindowTitle("设备数据图表");
    dialog->resize(1400, 900); // 设置弹窗大小

    // 创建 QChart 和 QLineSeries
    QChart *chart = new QChart();
    QLineSeries *series = new QLineSeries();
    // 存储当前选择的设备类型
    QString deviceType;
    // 遍历表格，提取数据
    for (int row = 0; row < ui->tableWidget_deviceData->rowCount(); ++row) {
        QTableWidgetItem *timeItem = ui->tableWidget_deviceData->item(row, 4); // 时间列
        QTableWidgetItem *typeItem = ui->tableWidget_deviceData->item(row, 3); // 设备类型列
        QTableWidgetItem *valueItem = nullptr; // 温度/湿度/光照列

        if (timeItem && !timeItem->text().isEmpty()) {
            QDateTime time = QDateTime::fromString(timeItem->text(), "yyyy-MM-dd HH:mm:ss");
            if (!time.isValid()) {
                qDebug() << "时间格式错误";
                continue;
            }

            // 获取设备类型
            if (typeItem && !typeItem->text().isEmpty()) {
                deviceType = typeItem->text(); // 假设设备类型是温度/湿度/光照
            }

            // 根据设备类型选择相应的数值列
            if (deviceType == "temperature") {
                valueItem = ui->tableWidget_deviceData->item(row, 5); // 温度列
            } else if (deviceType == "humidity") {
                valueItem = ui->tableWidget_deviceData->item(row, 6); // 湿度列
            } else if (deviceType == "light") {
                valueItem = ui->tableWidget_deviceData->item(row, 7); // 光照强度列
            }

            // 检查值是否有效并添加到图表
            if (valueItem && !valueItem->text().isEmpty()) {
                double value = valueItem->text().toDouble();
                series->append(time.toMSecsSinceEpoch(), value);
            }
        }
    }
    // 将 series 添加到 chart
    chart->addSeries(series);

    // 创建 X 轴（时间轴）
    QDateTimeAxis *axisX = new QDateTimeAxis();
    axisX->setFormat("yyyy-MM-dd HH:mm:ss");
    axisX->setTitleText("时间");
    axisX->setTickCount(10);  // 强制设置10个刻度
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);


    // 创建 Y 轴（数值轴）
    QValueAxis *axisY = new QValueAxis();
    if (deviceType == "temperature") {
        axisY->setTitleText("温度");
    } else if (deviceType == "humidity") {
        axisY->setTitleText("湿度");
    } else if (deviceType == "light") {
        axisY->setTitleText("光照强度");
    }
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    // 设置 chart 标题
    chart->setTitle("设备数据变化图");
    chart->legend()->hide(); // 隐藏图例（如果不需要）

    // 创建 QChartView 并设置抗锯齿
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // 将 QChartView 添加到弹窗布局
    QVBoxLayout *layout = new QVBoxLayout(dialog);
    layout->addWidget(chartView);

    QList<QString> newLog = {QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")
                             ,"operation"
                             ,"INFO"
                             ,"数据生成折线图"
                             ,""
                             ,""};
    LogWorker::addLogToDB(newLog);

    // 显示弹窗
    dialog->exec();
}

void DataMonitor::onInsertRandomData() {
    //获取数据库单例
    DataBase& db = DataBase::getDatabase();

    // 定义设备数据范围
    QMap<QString, QPair<double, double>> ranges = {
        {"temperature", {20.0, 30.0}}, // 温度范围：20 ~ 30
        {"humidity", {30.0, 60.0}},    // 湿度范围：30 ~ 60
        {"light", {100.0, 500.0}}      // 光强范围：100 ~ 500
    };

    // 获取所有设备信息，设备的类型（如温度、湿度、光强）以及设备ID
    QSqlQuery deviceQuery("SELECT device_id, type FROM device");
    if (!deviceQuery.exec()) {
        qDebug() << "Failed to fetch device information:" << deviceQuery.lastError();
        return;
    }

    // 插入随机数据
    QSqlQuery query;
    while (deviceQuery.next()) {
        int deviceId = deviceQuery.value("device_id").toInt();
        QString deviceType = deviceQuery.value("type").toString();

        // 根据设备类型选择随机值的范围
        double minValue = 0.0, maxValue = 0.0;
        if (ranges.contains(deviceType)) {
            minValue = ranges[deviceType].first;
            maxValue = ranges[deviceType].second;
        } else {
            qDebug() << "Unknown device type:" << deviceType;
            continue;  // 如果设备类型未定义，跳过该设备
        }

        // 生成随机值
        double value = minValue + QRandomGenerator::global()->bounded(static_cast<float>(maxValue - minValue));
        value = qRound(value * 10) / 10.0; // 保留一位小数

        // 插入随机值到数据库
        query.prepare("INSERT INTO device_data (device_id, timestamp, temperature, humidity, light) "
                      "VALUES (:device_id, :timestamp, :temperature, :humidity, :light)");
        query.bindValue(":device_id", deviceId);
        query.bindValue(":timestamp", QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));

        // 根据设备类型设置相应数据
        if (deviceType == "temperature") {
            query.bindValue(":temperature", value);
            query.bindValue(":humidity", QVariant());
            query.bindValue(":light", QVariant());
        } else if (deviceType == "humidity") {
            query.bindValue(":temperature", QVariant());
            query.bindValue(":humidity", value);
            query.bindValue(":light", QVariant());
        } else if (deviceType == "light") {
            query.bindValue(":temperature", QVariant());
            query.bindValue(":humidity", QVariant());
            query.bindValue(":light", value);
        }

        // 执行插入
        if (!query.exec()) {
            qDebug() << "Failed to insert random data:" << query.lastError();
        } else {
            qDebug() << "Inserted random data for device_id" << deviceId;
        }
        //查询两表数据，准备导入展示
        QString query = R"(
                        SELECT dd.data_id, d.device_id, d.name, d.type, dd.timestamp, dd.temperature, dd.humidity, dd.light
                        FROM device AS d
                        JOIN device_data AS dd
                        ON d.device_id = dd.device_id;
        )";
        deviceData = db.fetchResults(query);
    }
}

DataMonitor::~DataMonitor() {
    delete ui;
}
