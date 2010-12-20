#ifndef NEWGROUPDIALOG_H
#define NEWGROUPDIALOG_H

#include <QDialog>

namespace Ui {
    class NewGroupDialog;
}

class NewGroupDialog : public QDialog
{
    Q_OBJECT

public:
    NewGroupDialog(QStringList *groupNames, QWidget *parent = 0);
    ~NewGroupDialog();
    QString groupName();

private:
    Ui::NewGroupDialog *ui;
    QStringList *groupNames;

private slots:
    void validate();
    void groupNameEdited();
};

#endif // NEWGROUPDIALOG_H
