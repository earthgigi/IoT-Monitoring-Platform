#include "centerbar.h"
#include "ui_centerbar.h"

CenterBar::CenterBar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CenterBar)
{
    ui->setupUi(this);
    m_QStackedLayout = new QStackedLayout(this);
}

CenterBar::~CenterBar()
{
    delete ui;
}
