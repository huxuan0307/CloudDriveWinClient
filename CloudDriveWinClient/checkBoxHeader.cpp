#include "checkBoxHeader.h"

checkBoxHeader::checkBoxHeader (Qt::Orientation orientation, QWidget* parent) : QHeaderView (orientation, parent), isOn (false)
{ }

inline checkBoxHeader::~checkBoxHeader () { }

inline void checkBoxHeader::paintSection (QPainter* painter, const QRect& rect, int logicalIndex) const
{
	painter->save ();
	QHeaderView::paintSection (painter, rect, logicalIndex);
	painter->restore ();
	if (logicalIndex == 0) {
		QStyleOptionButton option;
		option.rect = QRect (10, 10, 10, 10);
		if (isOn)
			option.state = QStyle::State_On;
		else
			option.state = QStyle::State_Off;
		this->style ()->drawPrimitive (QStyle::PE_IndicatorCheckBox, &option, painter);
	}

}

inline void checkBoxHeader::mousePressEvent (QMouseEvent* event)
{
	if (isOn)
		isOn = false;
	else
		isOn = true;
	this->update ();
	QHeaderView::mousePressEvent (event);
}
