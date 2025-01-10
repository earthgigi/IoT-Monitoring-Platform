#ifndef LOGFILEHANDLER_H
#define LOGFILEHANDLER_H

#include <QList>

class LogFileHandler {
public:
    LogFileHandler();
    static void addLogToFile(const QList<QString> &log);

private:
    static QString getLogFilePath();
    static void rotateLogFile();
};

#endif // LOGFILEHANDLER_H
