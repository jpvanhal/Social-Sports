#ifndef EVENTDELEGATE_H
#define EVENTDELEGATE_H

#include <QItemDelegate>
#include <QPainter>

class EventDelegate : public QItemDelegate
{
public:
    EventDelegate(QObject *parent = 0);
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
};

#endif // EVENTDELEGATE_H
