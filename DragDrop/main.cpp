#include "DragDrop.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DragDrop w;
    w.show();
    return a.exec();
}
