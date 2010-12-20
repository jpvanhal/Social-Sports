#include "eventwidget.h"
#include "ui_eventwidget.h"

EventWidget::EventWidget(QString title, QString subtitle, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);

    ui->labelAvatar->setText("<img src=':/gfx/avatar.jpg' width=32 height=32>");
    ui->labelTitle->setText(title);
    ui->labelSubtitle->setText(subtitle);
}
