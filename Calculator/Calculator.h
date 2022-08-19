#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Calculator.h"

class Calculator : public QMainWindow
{
    Q_OBJECT

public:
    Calculator(QWidget *parent = nullptr);
    ~Calculator();

private:
    Ui::CalculatorClass ui;
    void connectSignalSlot();
 private slots:
    void digit_pressed();
    void on_pushButton_Decimal();
    void unary_operation_pressed();
    void binary_operation_pressed();
    void equal_pressed();
};
