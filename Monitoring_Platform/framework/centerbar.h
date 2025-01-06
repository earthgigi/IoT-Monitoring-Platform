#ifndef CENTERBAR_H
#define CENTERBAR_H

#include <QWidget>
#include <QStackedLayout>

namespace Ui {
class CenterBar;
}

class CenterBar : public QWidget
{
    Q_OBJECT

public:
    explicit CenterBar(QWidget *parent = nullptr);
    ~CenterBar();

private:
    Ui::CenterBar *ui;
    QStackedLayout *m_QStackedLayout;
};

#endif // CENTERBAR_H
