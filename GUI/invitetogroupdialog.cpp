#include <QStandardItemModel>

#include "invitetogroupdialog.h"
#include "ui_invitetogroupdialog.h"

InviteToGroupDialog::InviteToGroupDialog(QString groupName, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InviteToGroupDialog)
{
    ui->setupUi(this);
    ui->label->setText(QString("Choose the users to be invited to the group %0 from the list below:").arg(groupName));

    QStandardItemModel *model = new QStandardItemModel;

    QStringList users;
    users.append("AlexGreen");
    users.append("AnneNorthern");
    users.append("AnneWhite");
    users.append("FastRunner");
    users.append("JamesJones");
    users.append("JamesSmith");
    users.append("Jane");
    users.append("JohnBlack");
    users.append("LauraGreen");
    users.append("Mark");
    users.append("MatthewWalsh");
    users.append("Peter");

    foreach(QString username, users) {
        QStandardItem *item = new QStandardItem(QIcon(":/gfx/avatar.jpg"), username);
        item->setCheckable(true);
        model->appendRow(item);
    }

    ui->listView->setModel(model);
    ui->listView->setIconSize(QSize(32, 32));
}

InviteToGroupDialog::~InviteToGroupDialog()
{
    delete ui;
}
