#pragma once

#include <QtWidgets/QWidget>
#include <QTimer>
#include <QTime>
#include <QPainter>
#include <QDebug>
#include "ui_AnalogClock.h"

class AnalogClock : public QWidget
{
    Q_OBJECT

public:
    AnalogClock(QWidget *parent = nullptr);
    ~AnalogClock();

protected:
    void paintEvent(QPaintEvent* event) override;
    int Mycountnum = 0;
private:
    Ui::AnalogClockClass ui;
};
