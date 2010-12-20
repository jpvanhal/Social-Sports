#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QStandardItemModel>
#include <QStandardItem>
#include <QDebug>
#include <QResource>
#include <QMessageBox>

#include "eventdelegate.h"
#include "eventwidget.h"
#include "newgroupdialog.h"
#include "invitetogroupdialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->btnComment, SIGNAL(clicked()), SLOT(commentNewsItem()));
    connect(ui->btnLike, SIGNAL(clicked()), SLOT(likeNewsItem()));

    for (int i = 0; i < ui->treeWidgetRaces->columnCount(); i++) {
        ui->treeWidgetRaces->resizeColumnToContents(i);
    }

    initNews();
    initFitness();
    initGroups();
    initInvitations();
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
    ui->treeWidgetFitnessGroups->setColumnCount(1);
    ui->treeWidgetFitnessGroups->setIconSize(QSize(32, 32));

    QTreeWidgetItem *tkkRunners = addGroup(ui->treeWidgetFitnessGroups, "TKKRunners");
    addUserToGroup(tkkRunners, "You");
    addUserToGroup(tkkRunners, "JamesJones");
    addUserToGroup(tkkRunners, "FastRunner");
    addUserToGroup(tkkRunners, "AnneWhite");
    addUserToGroup(tkkRunners, "LauraGreen");

    QTreeWidgetItem *nakedJoggers = addGroup(ui->treeWidgetFitnessGroups, "NakedJoggers");
    addUserToGroup(nakedJoggers, "Mark");
    addUserToGroup(nakedJoggers, "Jane");
    addUserToGroup(nakedJoggers, "Peter");
}

void MainWindow::initInvitations()
{
    connect(ui->btnAcceptInvitation, SIGNAL(clicked()), SLOT(acceptInvitation()));
    connect(ui->btnDeclineInvitation, SIGNAL(clicked()), SLOT(declineInvitation()));

    QStandardItemModel *model = new QStandardItemModel;
    ui->listViewInvitations->setIconSize(QSize(32, 32));
    ui->listViewInvitations->setModel(model);
    ui->listViewInvitations->setItemDelegate(new EventDelegate());

    QStandardItem *item = new QStandardItem(QIcon(":/gfx/group_avatar.png"), "NakedJoggers");
    item->setData("Invited by Mark an hour ago", Qt::UserRole);
    model->appendRow(item);

    connect(ui->listViewInvitations->selectionModel(),
            SIGNAL(selectionChanged(QItemSelection,QItemSelection)),
            SLOT(invitationItemSelectionChanged(QItemSelection,QItemSelection)));
}

void MainWindow::initGroups()
{
    connect(ui->treeWidgetGroups, SIGNAL(itemSelectionChanged()), SLOT(groupSelectionChanged()));
    connect(ui->btnCreateGroup, SIGNAL(clicked()), SLOT(createGroup()));
    connect(ui->btnInviteToGroup, SIGNAL(clicked()), SLOT(inviteToGroup()));
    connect(ui->btnLeaveGroup, SIGNAL(clicked()), SLOT(leaveGroup()));

    groupNames.append("TKKRunners");
    groupNames.append("NakedJoggers");

    ui->treeWidgetGroups->setColumnCount(1);
    ui->treeWidgetGroups->setIconSize(QSize(32, 32));

    QTreeWidgetItem *tkkRunners = addGroup(ui->treeWidgetGroups, "TKKRunners");
    addUserToGroup(tkkRunners, "You");
    addUserToGroup(tkkRunners, "JamesJones");
    addUserToGroup(tkkRunners, "FastRunner");
    addUserToGroup(tkkRunners, "AnneWhite");
    addUserToGroup(tkkRunners, "LauraGreen");
}

void MainWindow::createGroup()
{
    NewGroupDialog dlg(&groupNames);
    if (dlg.exec() == QDialog::Accepted) {
        QString groupName = dlg.groupName();
        groupNames.append(groupName);
        QTreeWidgetItem *group = addGroup(ui->treeWidgetGroups, groupName);
        addUserToGroup(group, "You");
    }
}

void MainWindow::inviteToGroup()
{
    QTreeWidgetItem *treeitem = ui->treeWidgetGroups->currentItem();
    QString groupName = treeitem->text(0);
    InviteToGroupDialog dlg(groupName);
    if (dlg.exec() == QDialog::Accepted) {
        QMessageBox mbox(QMessageBox::Information, "Invitations Sent",
            QString("You have succesfully sent invitations to the selected users to join the group %0.").arg(groupName));
        mbox.setInformativeText("The invited users will have to accept the invitation before they become members of the group.");
        mbox.exec();
    }
}

QTreeWidgetItem *MainWindow::addGroup(QTreeWidget *tree, QString groupName)
{
    QTreeWidgetItem *group = new QTreeWidgetItem(tree);
    group->setText(0, groupName);
    group->setIcon(0, QIcon(":/gfx/group_avatar.png"));
    return group;
}

void MainWindow::addUserToGroup(QTreeWidgetItem *group, QString username)
{
    QTreeWidgetItem *user = new QTreeWidgetItem(group);
    user->setText(0, username);
    user->setIcon(0, QIcon(":/gfx/avatar.jpg"));
}

void MainWindow::groupSelectionChanged()
{
    QTreeWidgetItem *selection = ui->treeWidgetGroups->currentItem();
    bool isGroup = (selection && selection->childCount() > 0);
    ui->btnLeaveGroup->setEnabled(isGroup);
    ui->btnInviteToGroup->setEnabled(isGroup);
}

void MainWindow::leaveGroup()
{
    int index = ui->treeWidgetGroups->currentIndex().row();
    ui->treeWidgetGroups->takeTopLevelItem(index);
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

void MainWindow::invitationItemSelectionChanged(const QItemSelection &selected, const QItemSelection &deselected)
{
    bool isInvitationSelected = selected.count() > 0;
    ui->btnAcceptInvitation->setEnabled(isInvitationSelected);
    ui->btnDeclineInvitation->setEnabled(isInvitationSelected);
}

void MainWindow::acceptInvitation()
{
    QModelIndex index = ui->listViewInvitations->currentIndex();
    ui->listViewInvitations->model()->removeRow(index.row());
    QTreeWidgetItem *nakedJoggers = addGroup(ui->treeWidgetGroups, "NakedJoggers");
    addUserToGroup(nakedJoggers, "You");
    addUserToGroup(nakedJoggers, "Mark");
    addUserToGroup(nakedJoggers, "Jane");
    addUserToGroup(nakedJoggers, "Peter");
}

void MainWindow::declineInvitation()
{
    QModelIndex index = ui->listViewInvitations->currentIndex();
    ui->listViewInvitations->model()->removeRow(index.row());
}
