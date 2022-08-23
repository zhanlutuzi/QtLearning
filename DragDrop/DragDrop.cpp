#include "DragDrop.h"

DragDrop::DragDrop(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    connect(ui.droparea, SIGNAL(changed()), this, SLOT(GetMIMEChanged()));
    //下面这样写就不能正常连接
    //connect(ui.droparea, SIGNAL(droparea->changed()), this, SLOT(this->GetMIMEChanged()));
}

DragDrop::~DragDrop()
{
}

void DragDrop::GetMIMEChanged()
{
    QString thisPath = ui.droparea->getURLText();
    QString filetype, filePath, fileName = "";
    QStringList splitOne = thisPath.split("///");
    QStringList splitTwo = splitOne[1].split(".");
    QStringList splitThr = splitTwo[0].split("/");
    for (int i = 0; i < splitThr.size() - 1; ++i)
        filePath.append(splitThr[i]);
    filetype = splitTwo.last();
	fileName = splitThr.last();

    ui.FileNameText->setText(fileName);
    ui.FilePathText->setText(filePath);
    ui.FileTypeText->setText(filetype);

}

void DragDrop::dragEnterEvent(QDragEnterEvent* event)
{

}

void DragDrop::dropEvent(QDropEvent* event)
{
    QByteArray mimedataArray = event->mimeData()->data("URL");
    QString URLstr = QString(mimedataArray);
    //qDebug(URLstr);
    qDebug()<<URLstr<<"/n";
}
