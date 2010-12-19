#ifndef SIGNUPDIALOG_H
#define SIGNUPDIALOG_H

#include <QDialog>

namespace Ui {
    class SignUpDialog;
}

class SignUpDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SignUpDialog(QWidget *parent = 0);
    ~SignUpDialog();

private:
    Ui::SignUpDialog *ui;
    bool isUsernameValid;
    bool isPasswordValid;
    bool isPasswordConfirmationValid;
    bool isEmailValid;
    bool validate();

private slots:
    void validateUsername();
    void validatePassword();
    void validatePasswordConfirmation();
    void validateEmail();
    void doSignUp();
};

#endif // SIGNUPDIALOG_H
