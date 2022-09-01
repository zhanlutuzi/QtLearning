#pragma once

#include <QtWidgets/QMainWindow>
#include <QFileDialog>
#include <QDebug>
#include <QErrorMessage>
#include <QDirIterator>
#include "ui_FileTreeView.h"

class FileTreeView : public QMainWindow
{
    Q_OBJECT

public:
    FileTreeView(QWidget *parent = nullptr);
    ~FileTreeView();

private slots:
    void ReadDirectory();
private:
    Ui::FileTreeViewClass ui;
    void addTreeNode(QDir* mDir);
    bool IsADir = false;
    //QTreeWidgetItem* itemsParent;
    //QTreeWidgetItem* itemsChild;
    //QDirIterator m_DirIterator;
};
