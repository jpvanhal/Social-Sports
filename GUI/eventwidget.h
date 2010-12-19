#ifndef EVENTWIDGET_H
#define EVENTWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>

namespace Ui {
    class Form;
}

class EventWidget : public QWidget
{
    Q_OBJECT
public:
    explicit EventWidget(QString title, QString subtitle, QWidget *parent = 0);

private:
    Ui::Form *ui;

    QLabel *_labelAvatar;
    QLabel *_labelTitle;
    QLabel *_labelSubtitle;
    QHBoxLayout *_hbox;
    QVBoxLayout *_vbox;

signals:

public slots:

};

#endif // EVENTWIDGET_H
