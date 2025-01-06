#include "centerbar.h"
#include "ui_centerbar.h"

CenterBar::CenterBar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CenterBar)
{
    ui->setupUi(this);
    m_pQStackedLayout = new QStackedLayout(this);
    m_pLogin = new Login(this);
    m_pSuccessLogin = new SuccessLogin(this);


    //添加登陆界面和登陆成功界面进入center
    m_pQStackedLayout->addWidget(m_pLogin);
    m_pQStackedLayout->addWidget(m_pSuccessLogin);



}

CenterBar::~CenterBar()
{
    delete ui;
}
