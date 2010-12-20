#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QStandardItemModel>
#include <QStandardItem>
#include <QDebug>
#include <QResource>

#include "eventdelegate.h"
#include "eventwidget.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->btnComment, SIGNAL(clicked()), SLOT(commentNewsItem()));
    connect(ui->btnLike, SIGNAL(clicked()), SLOT(likeNewsItem()));

    initNews();
    initFitness();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initNews()
{
    QStandardItemModel *model = new QStandardItemModel;
    ui->listViewNews->setIconSize(QSize(32, 32));
    ui->listViewNews->setModel(model);
    ui->listViewNews->setItemDelegate(new EventDelegate());

    this->addNewsItem("James reached a new record!", "2 hours ago");
    this->addNewsItem("Mark jogged 10 km in one hour.", "yesterday");
    this->addNewsItem("TKK_Runners signed up for Helsinki City Run", "3 weeks ago");

    QVBoxLayout *commentLayout = new QVBoxLayout;
    commentLayout->setContentsMargins(0, 0, 0, 0);
    ui->widgetComments->setLayout(commentLayout);

    clearNewsItemComments();
    connect(ui->listViewNews->selectionModel(),
            SIGNAL(selectionChanged(QItemSelection,QItemSelection)),
            SLOT(newsItemSelectionChanged(QItemSelection, QItemSelection)));

    ui->listViewNews->setCurrentIndex(model->index(0, 0));
}

void MainWindow::initFitness()
{
    QStandardItemModel *model = new QStandardItemModel;
    ui->listViewFitnessGroups->setIconSize(QSize(32, 32));
    ui->listViewFitnessGroups->setModel(model);
    ui->listViewFitnessGroups->setItemDelegate(new EventDelegate());

    model->appendRow(new QStandardItem(QIcon(":/gfx/avatar.jpg"), "Me"));
    model->appendRow(new QStandardItem(QIcon(":/gfx/avatar.jpg"), "Mark"));
    model->appendRow(new QStandardItem(QIcon(":/gfx/avatar.jpg"), "Jane"));
    model->appendRow(new QStandardItem(QIcon(":/gfx/avatar.jpg"), "TKKRunners"));
    model->appendRow(new QStandardItem(QIcon(":/gfx/avatar.jpg"), "NakedJoggers"));

    ui->listViewFitnessGroups->setCurrentIndex(model->index(0, 0));
}

void MainWindow::addNewsItem(QString title, QString time)
{
    QStandardItem *item = new QStandardItem(QIcon(":/gfx/avatar.jpg"), title);
    item->setData(time, Qt::UserRole);
    QStandardItemModel *model = (QStandardItemModel *) ui->listViewNews->model();
    model->appendRow(item);
}

void MainWindow::addNewsItemComment(QString name, QString comment, QString time)
{
    QString title = QString("<b>%0:</b> %1").arg(name, comment);
    EventWidget *widgetComment = new EventWidget(title, time);
    QVBoxLayout *container = (QVBoxLayout *) ui->widgetComments->layout();
    int pos = container->count() - 1;
    container->insertWidget(pos, widgetComment);
}

void MainWindow::clearNewsItemComments()
{
    QVBoxLayout *commentLayout = (QVBoxLayout *) ui->widgetComments->layout();
    QLayoutItem *child;
    while ((child = commentLayout->takeAt(0)) != 0) {
        if (child->widget() != 0) {
            child->widget()->hide();
        }
        delete child;
    }
    commentLayout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding));
}

void MainWindow::newsItemSelectionChanged(const QItemSelection &selected, const QItemSelection &deselected)
{
    QModelIndex index = selected.indexes().first();
    QStandardItemModel *model = (QStandardItemModel *) ui->listViewNews->model();
    QStandardItem *item = model->itemFromIndex(index);

    QString title = item->data(Qt::DisplayRole).toString();
    QString time = item->data(Qt::UserRole).toString();

    ui->labelNewsItemHeading->setText(title);
    ui->labelNewsItemTime->setText(time);
    theUserLikes = false;
    updateLikings();

    clearNewsItemComments();
    addNewsItemComment("Jane", "Great job, James!", "5 minutes ago");
}

void MainWindow::updateLikings()
{
    if (theUserLikes) {
        ui->btnLike->setText("Don't Like");
        ui->labelNewsItemLike->setText("<b>You</b>, <b>Mark</b> and <b>Jane</b> like this.");
    } else {
        ui->btnLike->setText("Like");
        ui->labelNewsItemLike->setText("<b>Mark</b> and <b>Jane</b> like this.");
    }
}

void MainWindow::commentNewsItem()
{
    QString comment = ui->textEditComment->toPlainText();
    ui->textEditComment->clear();
    addNewsItemComment("You", comment, "just now");
}

void MainWindow::likeNewsItem()
{
    theUserLikes = !theUserLikes;
    updateLikings();
}
