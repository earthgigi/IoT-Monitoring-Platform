#include "widget.h"
#include "ui_widget.h"
#include <QMenu>
#include <QAction>
#include <QMouseEvent>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 去除窗口的边框和标题栏，使用无边框窗口
    setWindowFlag(Qt::FramelessWindowHint);

    m_titleBar = new TitleBar(this);
    m_statusBar = new StatusBar(this);
    m_centerBar = new CenterBar(this);

    ui->verticalLayout_Title->addWidget(m_titleBar);
    ui->verticalLayout_Status->addWidget(m_statusBar);
    ui->verticalLayout_Center->addWidget(m_centerBar);

    // 初始化拖动状态
    isPressed = false;

    // 安装事件过滤器，用于处理窗口的鼠标事件（拖动等）
    this->installEventFilter(this);

//    // 连接中心区域发送消息的信号到状态栏更新消息的槽
//    connect(m_centerWidget, &centerWidget::sendMessageByCenter, m_statusBar, &statusBar::onSendMessageByStatusBar);
}

bool Widget::eventFilter(QObject *watched, QEvent *event) {
    // 处理鼠标按下事件（左键）
    if (watched == this && event->type() == QEvent::MouseButtonPress) {
        QMouseEvent *m_event = dynamic_cast<QMouseEvent *>(event);
        if (m_event->buttons() & Qt::LeftButton) {
            // 记录鼠标按下的位置与窗口位置的偏移量，用于拖动
            m_point = m_event->globalPos() - this->pos();
            isPressed = true;
        }
        return true;  // 事件已处理，不传递给其他控件
    }

    // 处理鼠标释放事件
    if (watched == this && event->type() == QEvent::MouseButtonRelease) {
        isPressed = false;  // 释放鼠标后，不再进行拖动
        return true;  // 事件已处理
    }

    // 处理鼠标移动事件
    if (watched == this && event->type() == QEvent::MouseMove) {
        QMouseEvent *m_event = dynamic_cast<QMouseEvent *>(event);
        if (isPressed) {
            // 如果窗口正在被拖动，更新窗口的位置
            this->move(m_event->globalPos() - m_point);
        }
        return true;  // 事件已处理
    }

    // 如果事件未处理，返回 false 交给其他控件处理
    return false;
}

Widget::~Widget() {
    // 析构函数，销毁动态分配的资源
    delete ui;
    delete m_titleBar;
    delete m_statusBar;
    delete m_centerBar;
}
