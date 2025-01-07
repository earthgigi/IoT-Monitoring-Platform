#ifndef DEVICE_H
#define DEVICE_H

#include <QWidget>

namespace Ui {
class Device;
}

class Device : public QWidget
{
    Q_OBJECT

public:
    explicit Device(QWidget *parent = nullptr);
    ~Device();

public slots:
    void on_addDevice();
    void on_deleteDevice();
    void on_updateDevice();


private:
    Ui::Device *ui;
};

#endif // DEVICE_H
