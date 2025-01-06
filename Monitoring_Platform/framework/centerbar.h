#ifndef CENTERBAR_H
#define CENTERBAR_H

#include <QWidget>
#include <QStackedLayout>
#include "login.h"
#include "successlogin.h"

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
    QStackedLayout *m_pQStackedLayout;
    Login *m_pLogin;
    SuccessLogin *m_pSuccessLogin;
};

#endif // CENTERBAR_H
