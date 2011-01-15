#include <QMessageBox>
#include <QPushButton>

#include "newgroupdialog.h"
#include "ui_newgroupdialog.h"

NewGroupDialog::NewGroupDialog(QStringList *groupNames, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewGroupDialog)
{
    ui->setupUi(this);

    connect(ui->buttonBox, SIGNAL(accepted()), SLOT(validate()));
    connect(ui->lineEdit, SIGNAL(textEdited(QString)), SLOT(groupNameEdited()));

    this->groupNameEdited();
    this->groupNames = groupNames;

    QRegExp re("[A-Z0-9]+", Qt::CaseInsensitive);
    QRegExpValidator *validator = new QRegExpValidator;
    validator->setRegExp(re);
    ui->lineEdit->setValidator(validator);
}

NewGroupDialog::~NewGroupDialog()
{
    delete ui;
}

void NewGroupDialog::groupNameEdited()
{
    QPushButton *btnOk = ui->buttonBox->button(QDialogButtonBox::Ok);
    btnOk->setEnabled(ui->lineEdit->text().length() > 0);
}

void NewGroupDialog::validate()
{
    QString name = ui->lineEdit->text();
    if (groupNames->contains(name, Qt::CaseInsensitive)) {
        QMessageBox mbox(QMessageBox::Warning, "Group name already taken.",
                         "The group name you chose has already been taken.",
                         QMessageBox::Ok);
        mbox.setInformativeText("Please choose another name and try again.");
        mbox.exec();
    } else {
        accept();
    }
}

QString NewGroupDialog::groupName()
{
    return ui->lineEdit->text();
}
