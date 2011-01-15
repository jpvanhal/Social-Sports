#ifndef SIGNINDIALOG_H
#define SIGNINDIALOG_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
    class SignInDialog;
}

class SignInDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SignInDialog(MainWindow *mainwindow, QWidget *parent = 0);
    ~SignInDialog();

private:
    Ui::SignInDialog *ui;
    MainWindow *mainwindow;
    bool validateUserCredentials();

private slots:
    void doSignIn();
    void doForgotPassword();
    void doSignUp();
};

#endif // SIGNINDIALOG_H
