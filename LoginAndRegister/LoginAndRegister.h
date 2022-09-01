#pragma once

#include <QtWidgets/QWidget>
#include "ui_LoginAndRegister.h"
#include <QMessageBox>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>

class LoginAndRegister : public QWidget
{
    Q_OBJECT

public:
    LoginAndRegister(QWidget *parent = nullptr);
    ~LoginAndRegister();

private:
    Ui::LoginAndRegisterClass ui;
    QSqlDatabase database;
    QSqlDatabase db;
private slots:
    void RegisterAUser();
    void UserLogin();
};
