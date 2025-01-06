#ifndef STATUSBAR_H
#define STATUSBAR_H

#include <QWidget>
#include <QTimer>

namespace Ui {
class StatusBar;
}

class StatusBar : public QWidget
{
    Q_OBJECT

public:
    explicit StatusBar(QWidget *parent = nullptr);
    ~StatusBar();

private:
    Ui::StatusBar *ui;
    QTimer *m_timer;
};

#endif // STATUSBAR_H
