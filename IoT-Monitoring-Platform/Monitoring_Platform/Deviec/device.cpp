#include "device.h"
#include "ui_device.h"

Device::Device(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Device)
{
    ui->setupUi(this);
}

void Device::on_addDevice()
{

}

void Device::on_deleteDevice()
{

}

void Device::on_updateDevice()
{

}

Device::~Device()
{
    delete ui;
}

