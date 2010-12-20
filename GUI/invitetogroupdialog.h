#ifndef INVITETOGROUPDIALOG_H
#define INVITETOGROUPDIALOG_H

#include <QDialog>

namespace Ui {
    class InviteToGroupDialog;
}

class InviteToGroupDialog : public QDialog
{
    Q_OBJECT

public:
    explicit InviteToGroupDialog(QString groupName, QWidget *parent = 0);
    ~InviteToGroupDialog();

private:
    Ui::InviteToGroupDialog *ui;
};

#endif // INVITETOGROUPDIALOG_H
