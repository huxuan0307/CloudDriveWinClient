#pragma once
#include <QtGui>
#include <QHeaderView>
class checkBoxHeader :public QHeaderView
{
public:
	checkBoxHeader (Qt::Orientation orientation, QWidget* parent = 0);
	~checkBoxHeader ();;
protected:
	void paintSection (QPainter* painter, const QRect& rect, int logicalIndex) const;
	void mousePressEvent (QMouseEvent* event);
private:
	bool isOn;
};
