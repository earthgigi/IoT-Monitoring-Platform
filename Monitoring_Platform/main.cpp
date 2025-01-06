#include "widget.h"
#include "DataBase/database.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DataBase & dbManager = DataBase::getDatabase();
    dbManager.connect();
    Widget w;
    w.show();
    return a.exec();
}
