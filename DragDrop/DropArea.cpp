#include "DropArea.h"

#include <QDragEnterEvent>
#include <QMimeData>

//! [DropArea constructor]
DropArea::DropArea(QWidget* parent)
	: QLabel(parent)
{
	setMinimumSize(200, 200);
	setFrameStyle(QFrame::Sunken | QFrame::StyledPanel);
	setAlignment(Qt::AlignCenter);
	setAcceptDrops(true);
	setAutoFillBackground(true);
	clear();
}
//! [DropArea constructor]

//! [dragEnterEvent() function]
void DropArea::dragEnterEvent(QDragEnterEvent* event)
{
	setText(tr("<drop content>"));
	setBackgroundRole(QPalette::Highlight);

	event->acceptProposedAction();
	//emit changed(event->mimeData());
}
//! [dragEnterEvent() function]

//! [dragMoveEvent() function]
void DropArea::dragMoveEvent(QDragMoveEvent* event)
{
	event->acceptProposedAction();
}
//! [dragMoveEvent() function]

//! [dropEvent() function part1]
void DropArea::dropEvent(QDropEvent* event)
{
	
	const QMimeData* mimeData = event->mimeData();
	//! [dropEvent() function part1]

	//! [dropEvent() function part2]
	if (mimeData->hasImage()) {
		setPixmap(qvariant_cast<QPixmap>(mimeData->imageData()));
		qDebug() << "Image Change Emit\n";
		qDebug() << "---------------------------------------------------------\n";
	}
	else if (mimeData->hasFormat(QLatin1String("text/markdown"))) {
		setText(QString::fromUtf8(mimeData->data(QLatin1String("text/markdown"))));
		setTextFormat(Qt::MarkdownText);
		qDebug() << "Markdown Change Emit\n";
		qDebug() << "---------------------------------------------------------\n";
	}
	else if (mimeData->hasHtml()) {
		setText(mimeData->html());
		setTextFormat(Qt::RichText);
		qDebug() << "RichText Change Emit\n";
		qDebug() << "---------------------------------------------------------\n";
	}
	else if (mimeData->hasText()) {
		//setText(mimeData->text());
		//setTextFormat(Qt::PlainText);
		URLText = mimeData->text();
		emit changed();
		qDebug() << "Text Change Emit\n";
		qDebug() << "---------------------------------------------------------\n";
	}
	else if (mimeData->hasUrls()) {
		QList<QUrl> urlList = mimeData->urls();
		QString text;
		for (int i = 0; i < urlList.size() && i < 32; ++i)
			text += urlList.at(i).path() + QLatin1Char('\n');
		URLText = text;
		emit changed();
		qDebug() << "URL Change Emit\n";
		qDebug() << "---------------------------------------------------------\n";
	}
	else {
		setText(tr("Cannot display data"));
	}
	//! [dropEvent() function part2]

	//! [dropEvent() function part3]
	setBackgroundRole(QPalette::Dark);
	event->acceptProposedAction();
}



QString DropArea::getURLText()
{
	return URLText;
}

//! [dropEvent() function part3]

//! [dragLeaveEvent() function]
void DropArea::dragLeaveEvent(QDragLeaveEvent* event)
{
	clear();
	event->accept();
}
//! [dragLeaveEvent() function]

//! [clear() function]
void DropArea::clear()
{
	setText(tr("<drop content>"));
	setBackgroundRole(QPalette::Dark);

	
}
//! [clear() function]