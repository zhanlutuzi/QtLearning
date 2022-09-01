#include "FileTreeView.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FileTreeView w;
    w.show();
    return a.exec();
}
