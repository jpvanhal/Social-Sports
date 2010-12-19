#include <QMessageBox>

#include "signindialog.h"
#include "ui_signindialog.h"

SignInDialog::SignInDialog(MainWindow *mainwindow, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SignInDialog)
{
    this->mainwindow = mainwindow;
    ui->setupUi(this);

    connect(ui->btnSignIn, SIGNAL(clicked()), SLOT(doSignIn()));
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

bool SignInDialog::validateUserCredentials()
{
    QString username = ui->textFieldUsername->text();
    QString password = ui->textFieldPassword->text();
    return (username == "hookie" && password == "hookie");
}

