#include "database.h"

DataBase::DataBase(QObject *parent) : QObject(parent) {}

//单例模式
DataBase &DataBase::getDatabase()
{
    static DataBase Databaseinstance;
    return Databaseinstance;
}


//连接数据库
bool DataBase::connect()
{
    // 连接到 SQLite 数据库
    m_db = QSqlDatabase::addDatabase("QSQLITE");

    //换成自己的数据库路径
    m_db.setDatabaseName("E:/code/01aaaaaaaaaaaxiangmu/IoT-Monitoring-Platform/Monitoring_Platform/platform.db");
    if (m_db.open()) {
        qDebug() << "成功连接到数据库";
        return true;
    } else {
        qCritical() << "无法连接到数据库：" << m_db.lastError().text();
        return false;
    }
}

//断开数据库连接
bool DataBase::disconnect()
{
    if (m_db.isOpen()) {
        m_db.close();
        qDebug() << "数据库连接已关闭";
        return true;
    } else {
        qDebug() << "关闭数据库连接失败：" << m_db.lastError().text();
        return false;
    }
}

//执行查询
bool DataBase::executeQuery(const QString &query)
{
    QSqlQuery sqlQuery(query, m_db);
    if (sqlQuery.exec()) {
        qDebug() << "SQL 操作成功：" << query;
        return true;
    } else {
        qDebug() << "SQL 操作失败：" << sqlQuery.lastError().text();
        return false;
    }
}

//获取查询结果
QVector<QMap<QString, QString>> DataBase::fetchResults(const QString &query)
{
    //创建一个 QVector<QMap<QString, QString>> 类型的变量 results，用于存储查询的结果
    QVector<QMap<QString, QString>> results;
    QSqlQuery sqlQuery(query, m_db);
    if (sqlQuery.exec()) {
        while (sqlQuery.next()) {
            QMap<QString, QString> row;
            for (int i = 0; i < sqlQuery.record().count(); ++i) {
                row.insert(sqlQuery.record().fieldName(i), sqlQuery.value(i).toString());
            }
            results.append(row);
        }
    } else {
        qCritical() << "查询失败：" << sqlQuery.lastError().text();
    }
    return results;
}
