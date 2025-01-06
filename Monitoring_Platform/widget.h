#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <framework/centerbar.h>
#include <framework/statusbar.h>
#include <framework/titlebar.h>
#include <QSystemTrayIcon>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    //重载鼠标事件（按下移动）
    bool eventFilter(QObject *watched, QEvent *event) override;

private:
    Ui::Widget *ui;

    TitleBar *m_titleBar;
    StatusBar *m_statusBar;
    CenterBar *m_centerBar;

    QPoint m_point;
    bool isPressed;


};
#endif // WIDGET_H
