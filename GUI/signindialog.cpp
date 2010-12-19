#include <QMessageBox>
#include <QInputDialog>

#include "signindialog.h"
#include "ui_signindialog.h"

SignInDialog::SignInDialog(MainWindow *mainwindow, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SignInDialog)
{
    this->mainwindow = mainwindow;
    ui->setupUi(this);

    connect(ui->btnSignIn, SIGNAL(clicked()), SLOT(doSignIn()));
    connect(ui->btnForgotPassword, SIGNAL(clicked()), SLOT(doForgotPassword()));
    connect(ui->btnSignUp, SIGNAL(clicked()), SLOT(doSignUp()));
}

SignInDialog::~SignInDialog()
{
    delete ui;
}

void SignInDialog::doSignIn()
{
    if (validateUserCredentials()) {
        mainwindow->show();
        accept();
    } else {
        QMessageBox::information(this, "Wrong username or password", "The username you entered does not exist, or the username and password do not match. Please try again.");
    }
}

void SignInDialog::doForgotPassword()
{
    QInputDialog::getText(this, "Forgot your password?", "Please enter your email address or phone number below, and we will send you a new password there:");
}

void SignInDialog::doSignUp()
{

}

bool SignInDialog::validateUserCredentials()
{
    QString username = ui->textFieldUsername->text();
    QString password = ui->textFieldPassword->text();
    return (username == "hookie" && password == "hookie");
}

