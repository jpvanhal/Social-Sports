#include "eventdelegate.h"

#include<QPalette>

EventDelegate::EventDelegate(QObject *parent)
    : QItemDelegate(parent)
{

}


void EventDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    painter->save();

    this->drawBackground(painter, option, index);

    QVariant decoration = index.data(Qt::DecorationRole);
    if (decoration.isValid()) {
        QIcon icon = qvariant_cast<QIcon>(decoration);
        QPixmap pixmap = icon.pixmap(option.decorationSize);
        QRect rect;
        rect.setX(option.rect.x());
        rect.setY(option.rect.y());
        rect.setSize(option.decorationSize);
        this->drawDecoration(painter, option, rect, pixmap);
    }

    if (option.state & QStyle::State_Selected) {
        painter->setPen(option.palette.color(QPalette::HighlightedText));
    } else {
        painter->setPen(option.palette.color(QPalette::Text));
    }

    QRect textRect = QRect(option.rect);
    textRect.setX(option.decorationSize.width() + 5);

    QVariant title = index.data(Qt::DisplayRole);
    if (title.isValid()) {
        QString text = title.toString();
        painter->drawText(textRect, Qt::AlignLeft | Qt::AlignTop, text);
    }

    QVariant subtitle = index.data(Qt::UserRole);
    if (subtitle.isValid()) {
        QString text = subtitle.toString();
        painter->drawText(textRect, Qt::AlignLeft | Qt::AlignBottom, text);
    }


    painter->restore();
}


