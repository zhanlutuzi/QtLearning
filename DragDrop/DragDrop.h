#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_DragDrop.h"
#include<QDragEnterEvent>
#include<QMimeData>
#include<QDropEvent>
#include<QUrl>
#include<QString>
#include<QDebug>
#include "DragDrop.h"

class DragDrop : public QMainWindow
{
    Q_OBJECT

public:
    DragDrop(QWidget *parent = nullptr);
    ~DragDrop();

private slots:
    void GetMIMEChanged();
private:
    Ui::DragDropClass ui;

protected:
	void dragEnterEvent(QDragEnterEvent* event) override;//拖动进入事件
	void dropEvent(QDropEvent* event) override;
};
