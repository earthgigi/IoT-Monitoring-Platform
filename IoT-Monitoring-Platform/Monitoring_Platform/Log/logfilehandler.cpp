#include "logfilehandler.h"
#include <QDebug>
#include <QFile>
#include <QDir>
#include <QDateTime>
#include <QCoreApplication>

LogFileHandler::LogFileHandler() {

}

void LogFileHandler::addLogToFile(const QList<QString> &log) {
    QString logFilePath = getLogFilePath();
    rotateLogFile();

    QFile logFile(logFilePath);
    if (logFile.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream stream(&logFile);
        stream << log.join(" ") << "\n"; // 使用空格分隔日志字段
        logFile.close();
    } else {
        qWarning() << "Failed to open log file for writing!";
    }
}

QString LogFileHandler::getLogFilePath() {
    // 当前文件路径：可执行文件目录 + "logs" 文件夹
    QDir logDir(QCoreApplication::applicationDirPath() + "/../logs");
    if (!logDir.exists()) {
        logDir.mkpath(".");
    }
    return logDir.filePath("system_log.txt");
}

void LogFileHandler::rotateLogFile() {
    QString logFilePath = getLogFilePath();
    QFile logFile(logFilePath);

    if (logFile.size() > 1 * 1024) { // 10 MB
        QString backupFileName = QString("system_log_%1.txt")
                                     .arg(QDateTime::currentDateTime().toString("yyyyMMdd_HHmmss"));
        QString backupFilePath = QCoreApplication::applicationDirPath() + "/../logs/" + backupFileName;
        qDebug() << QCoreApplication::applicationDirPath();
        qDebug() << "Original log file path:" << logFilePath;
        qDebug() << "Backup log file path:" << backupFilePath;
        if (!logFile.rename(backupFilePath)) {
            qWarning() << "Failed to rotate log file!";
        }
    }
}
