#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QStandardItemModel>
#include <QStandardItem>

#include "eventdelegate.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);



    QStandardItemModel *model = new QStandardItemModel;
    ui->listViewNews->setIconSize(QSize(32, 32));
    ui->listViewNews->setModel(model);
    ui->listViewNews->setItemDelegate(new EventDelegate());

    this->addNewsItem("James reached a new record!", "2 hours ago");
    this->addNewsItem("Mark jogged 10 km in one hour.", "yesterday");
    this->addNewsItem("TKK_Runners signed up for Helsinki City Run", "3 weeks ago");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addNewsItem(QString title, QString time)
{
    QStandardItem *item = new QStandardItem(QIcon(":/icons/avatar.jpg"), title);
    item->setData(time, Qt::UserRole);
    QStandardItemModel *model = (QStandardItemModel *) ui->listViewNews->model();
    model->appendRow(item);
}

