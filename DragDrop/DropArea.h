#pragma once
#include <QLabel>
#include <QDebug>
QT_BEGIN_NAMESPACE
class QMimeData;
QT_END_NAMESPACE

class DropArea : public QLabel
{
	Q_OBJECT

public:
	explicit DropArea(QWidget* parent = nullptr);
	QString getURLText();
public slots:
	void clear();

signals:
	void changed();
	//! [DropArea header part1]

	//! [DropArea header part2]
protected:
	void dragEnterEvent(QDragEnterEvent* event) override;
	void dragMoveEvent(QDragMoveEvent* event) override;
	void dragLeaveEvent(QDragLeaveEvent* event) override;
	void dropEvent(QDropEvent* event) override;
	

private:
	QLabel* label;
	QString URLText;
};

