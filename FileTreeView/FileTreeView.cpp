#include "FileTreeView.h"

FileTreeView::FileTreeView(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    connect(ui.OpenDirBtn, SIGNAL(clicked()), this, SLOT(ReadDirectory()));
}

FileTreeView::~FileTreeView()
{
    
}

void FileTreeView::ReadDirectory()
{
    QFileDialog m_Filedialog;
    m_Filedialog.setFileMode(QFileDialog::Directory);
    m_Filedialog.setWindowTitle("请选择你要展示的目录");
    m_Filedialog.exec();
    QDir m_Dir = m_Filedialog.directory();
	if (!m_Dir.exists()) {
        QErrorMessage errorsMsg;
        errorsMsg.showMessage("此路径不存在！\n");
	}
	//取到所有的文件和文件名，但是去掉.和..的文件夹（这是QT默认有的）
	m_Dir.setFilter(QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot);
    addTreeNode(&m_Dir);

}

void FileTreeView::addTreeNode(QDir* pmDir)
{
	QDirIterator dirIterator(*pmDir, QDirIterator::IteratorFlag::Subdirectories);
	
	QTreeWidgetItem* itemsParent = new QTreeWidgetItem(ui.treeWidget);
	itemsParent->setText(0, pmDir->dirName().toUtf8());
	while (dirIterator.hasNext())
	{
		
		QString dirItem(dirIterator.next());
		qDebug() << "正在遍历：" << dirItem << "\n";
		QFileInfo dirItemInfo(dirItem);
		QTreeWidget* ptreeWidget = ui.treeWidget;



		//QTreeWidgetItem* pParentItem1 = new QTreeWidgetItem({"1","2"});
		//QTreeWidgetItem* pChildItem1 = new QTreeWidgetItem({ "3" });
		//pParentItem1->addChild(pChildItem1);
		//ui.treeWidget->addTopLevelItem(pParentItem1);



		if (dirItemInfo.isDir())
		{
			itemsParent = new QTreeWidgetItem(ui.treeWidget);
			itemsParent->setText(0, dirItemInfo.fileName());
			// 为何这样不能访问成员函数
			// ui.treeWidget.addTopLevelItem(itemsParent);
			// 回答，必须使用->进行访问
			// ui.treeWidget->addTopLevelItem(itemsParent);
			QTreeWidgetItem* itemsChild = new QTreeWidgetItem(ui.treeWidget);
			itemsChild->setText(0, dirItemInfo.fileName());
			itemsParent->addChild(itemsChild);
			
		}
		else
		{
			QTreeWidgetItem* itemsChild = new QTreeWidgetItem(ui.treeWidget);
			itemsChild->setText(0, dirItemInfo.fileName());
			// 这里addChild后使用debug查看发现child属性仍然为0，不理解
			itemsParent->addChild(itemsChild);
			ptreeWidget->insertTopLevelItem(0, itemsParent);
		}
		
		
	}
}
