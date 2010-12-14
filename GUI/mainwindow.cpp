#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QStandardItemModel>
#include <QStandardItem>
#include <QDebug>
#include <QResource>

#include "eventdelegate.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->connect(ui->listViewNews, SIGNAL(clicked(QModelIndex)), SLOT(newsItemActivated(QModelIndex)));
    this->connect(ui->listViewNews, SIGNAL(activated(QModelIndex)), SLOT(newsItemActivated(QModelIndex)));

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

void MainWindow::newsItemActivated(QModelIndex index)
{
    QStandardItemModel *model = (QStandardItemModel *) ui->listViewNews->model();
    QStandardItem *item = model->itemFromIndex(index);

    QString title = item->data(Qt::DisplayRole).toString();
    QString time = item->data(Qt::UserRole).toString();

    QString html = "";
    html += "<div><img src=':/icons/avatar.jpg' style='float: left; margin-right: 10px;'>";
    html += "<p style='margin: 0; font-size: large;'>&nbsp;&nbsp;%0</p>";
    html += "<p style='margin: 10;'>&nbsp;&nbsp;&nbsp;%1</p></div>";
    html += "<p>More details about the update...</p><p>Lorem ipsum dolor sit amet, consectetur adipiscing elit. Mauris nec magna ligula. Sed facilisis leo non diam aliquam rhoncus volutpat ut libero. Donec vitae sem ac felis adipiscing molestie eu quis arcu. Quisque et lacus a libero blandit facilisis in quis leo.</p>";
    html += "<hr><p><img src=':/icons/thumbs_up.png'>&nbsp;&nbsp;<strong>Mark</strong> and <strong>Jane</strong> likes this.</p>";
    html += "<hr><p><img src=':/icons/avatar.jpg' width='32' height='32' style='float: left'>&nbsp;&nbsp;<strong>Jane</strong>: Great job, James!<br>&nbsp;&nbsp;5 minutes ago</p>";

    ui->textEditNewsItem->setHtml(html.arg(title, time));
}
