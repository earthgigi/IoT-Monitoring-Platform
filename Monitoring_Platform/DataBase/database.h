#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QMap>
#include <QString>
#include <QDebug>
#include <QVector>

class DataBase : public QObject
{
    Q_OBJECT
public:
    //单例模式
    static DataBase& getDatabase();
    ~DataBase()
    {
        m_db.close();
    }
    bool connect();                            //连接数据库
    bool disconnect();                         //关闭数据库
    bool executeQuery(const QString& query);   //数据库查询执行  INSERT、UPDATE、DELETE只检查执行成功与否
    QVector<QMap<QString, QString>> fetchResults(const QString &query);  // 返回SELECT查询结果


private:
    DataBase(QObject *parent = nullptr);
    DataBase(const DataBase&) = delete;
    DataBase&operator=(const DataBase&) = delete;
    QSqlDatabase  m_db;

};

#endif // DATABASE_H
