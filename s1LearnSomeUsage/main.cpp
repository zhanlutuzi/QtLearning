#include "s1LearnSomeUsage.h"
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
// VS2019缺少QLabel的提示，只有.h文件的提示

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    s1LearnSomeUsage w;
    //QLabel mylabel("Hello World");
    //mylabel.setStyleSheet("QLabel:hover { color: rgb(60, 179, 113)}");
    //mylabel.show();
    w.show();
    return a.exec();
}
