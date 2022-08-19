#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_s1LearnSomeUsage.h"

class s1LearnSomeUsage : public QMainWindow
{
    Q_OBJECT

public:
    s1LearnSomeUsage(QWidget *parent = nullptr);
    ~s1LearnSomeUsage();

private:
    Ui::s1LearnSomeUsageClass ui;
};
