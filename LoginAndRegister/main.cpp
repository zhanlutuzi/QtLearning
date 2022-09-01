#include "LoginAndRegister.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginAndRegister w;
    w.show();
    return a.exec();
}
