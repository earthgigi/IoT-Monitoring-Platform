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
    m_pStatusBar = new StatusBar(this);

    m_pUsers = new Users(this);


    //添加登陆界面和登陆成功界面进入center
    m_pQStackedLayout->addWidget(m_pLogin);          //0
    m_pQStackedLayout->addWidget(m_pSuccessLogin);   //1
    m_pQStackedLayout->addWidget(m_pUsers);          //2

    //收到display信号来切换页面
    connect(m_pLogin,&Login::display,m_pQStackedLayout,&QStackedLayout::setCurrentIndex);
    connect(m_pSuccessLogin,&SuccessLogin::display,m_pQStackedLayout,&QStackedLayout::setCurrentIndex);
    connect(m_pUsers,&Users::display,m_pQStackedLayout,&QStackedLayout::setCurrentIndex);


    connect(m_pLogin, &Login::checklogin,m_pStatusBar,&StatusBar::onshowStatus);



}



CenterBar::~CenterBar()
{
    delete ui;
}

