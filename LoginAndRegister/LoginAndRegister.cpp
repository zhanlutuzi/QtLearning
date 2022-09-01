#include "LoginAndRegister.h"

LoginAndRegister::LoginAndRegister(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
    connect(ui.RegBtn, SIGNAL(clicked()), this, SLOT(RegisterAUser()));
    connect(ui.LogBtn, SIGNAL(clicked()), this, SLOT(UserLogin()));
}

LoginAndRegister::~LoginAndRegister()
{
}

void LoginAndRegister::RegisterAUser()
{


    // 链接数据库

	database = QSqlDatabase::addDatabase("QMYSQL","addData");
	database.setHostName("localhost");
	database.setUserName("root");
	database.setPassword("");
	database.setDatabaseName("qt5resgister");

    if (database.open())
    {
		QString username = ui.Regusername->text();
		QString password = ui.Regpassword->text();
		QString email = ui.Regemail->text();
		QString phone = ui.Regphone->text();
        //QMessageBox::information(this, "Connected!", "Successfully connect to the Database");

        // 运行插入语句
        QSqlQuery qry(QSqlDatabase::database("addData"));
        qry.prepare("INSERT INTO user (username, password, email, phone)"
                    "VALUES (:username, :password, :email, :phone)");
        qry.bindValue(":username", username);
        qry.bindValue(":password", password);
        qry.bindValue(":email", email);
        qry.bindValue(":phone", phone);

        if (qry.exec())
        {
            QMessageBox::information(this, "Register Successfully!", "Congratulation,you have successfully register.");
        }
        else
        {
            QMessageBox::information(this, "Register Error!", "Sorry your register is unsuccessful.");
        }
        
    }
    else
    {
        QMessageBox::information(this, "Not Connect", "Database connect error,Plese try again later.");
    }

}

void LoginAndRegister::UserLogin()
{

	// 链接数据库

	db = QSqlDatabase::addDatabase("QMYSQL","LoginConnect");
	db.setHostName("localhost");
	db.setUserName("root");
	db.setPassword("");
	db.setDatabaseName("qt5resgister");

    if (db.open())
    {
        QString username = ui.Logusername->text();
        QString password = ui.Logpassword->text();
        //QMessageBox::information(this, "Connected!", "Successfully connect to the Database");
        QSqlQuery query(QSqlDatabase::database("LoginConnect"));
        query.prepare("SELECT * FROM user WHERE username = :username AND password = :password");
        query.bindValue(":username", username);
        query.bindValue(":password", password);

        if (query.exec())
        {
            while (query.next())
            {
				QString DBusername = query.value(1).toString();
				QString DBpassword = query.value(2).toString();
				if (DBpassword == password && DBusername == username)
				{
					QMessageBox::information(this, "SUCCESSFULLY LOGIN", "Congratulation you have already login.");
				}
            }
        }
        else
        {
            QMessageBox::information(this, "Log Error",  "Something goes wrong,You can't LogIn.Check Your username or password");
        }
    }
    else
    {
        QMessageBox::information(this, "Not Connect", "Database connect error,Plese try again later.");
    }
}
