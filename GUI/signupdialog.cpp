#include <QMessageBox>
#include "signupdialog.h"
#include "ui_signupdialog.h"

SignUpDialog::SignUpDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SignUpDialog)
{
    ui->setupUi(this);

    ui->labelUsernameMessages->hide();
    ui->labelPasswordMessages->hide();
    ui->labelPasswordConfirmationMessages->hide();
    ui->labelEmailMessages->hide();
    update();

    isUsernameValid = false;
    isPasswordValid = false;
    isPasswordConfirmationValid = false;
    isEmailValid = false;

    connect(ui->textFieldUsername, SIGNAL(editingFinished()), SLOT(validateUsername()));
    connect(ui->textFieldEmail, SIGNAL(editingFinished()), SLOT(validateEmail()));
    connect(ui->textFieldPassword, SIGNAL(editingFinished()), SLOT(validatePassword()));
    connect(ui->textFieldPasswordConfirmation, SIGNAL(editingFinished()), SLOT(validatePasswordConfirmation()));
    connect(ui->btnSignUp, SIGNAL(clicked()), SLOT(doSignUp()));
    connect(ui->btnCancel, SIGNAL(clicked()), SLOT(reject()));
}

void SignUpDialog::validateUsername()
{
    if (ui->textFieldUsername->text().length() == 0) {
        ui->labelUsernameMessages->setText("You need to provide a username");
        isUsernameValid = false;
    } else if (ui->textFieldUsername->text() == "hookie") {
        ui->labelUsernameMessages->setText("The username has already been taken");
        isUsernameValid = false;
    } else if (!QRegExp("[A-Z0-9]+", Qt::CaseInsensitive).exactMatch(ui->textFieldUsername->text())) {
        ui->labelUsernameMessages->setText("The username can only contain letters and numbers");
        isUsernameValid = false;
    } else {
        isUsernameValid = true;
    }

    if (isUsernameValid) {
        ui->labelUsernameMessages->hide();
    } else {
        ui->labelUsernameMessages->show();
    }
    this->update();
}

void SignUpDialog::validateEmail()
{
    if (ui->textFieldEmail->text().length() == 0) {
        ui->labelEmailMessages->setText("You need to provide an email");
        isEmailValid = false;
        ui->labelEmailMessages->show();
    } else if (!QRegExp("[A-Z0-9._%+-]+@[A-Z0-9.-]+\\.[A-Z]{2,4}", Qt::CaseInsensitive).exactMatch(ui->textFieldEmail->text())) {
        ui->labelEmailMessages->setText("The email is not valid. An example of valid email address is: firstname.lastname@domain.org");
        isEmailValid = false;
        ui->labelEmailMessages->show();
    } else {
        isEmailValid = true;
    }
    if (isEmailValid) {
        ui->labelEmailMessages->hide();
    } else {
        ui->labelEmailMessages->show();
    }
    this->update();
}

void SignUpDialog::validatePassword()
{
    if (ui->textFieldPassword->text().length() == 0) {
        ui->labelPasswordMessages->setText("You need to provide a password.");
        isPasswordValid = false;
    } else if (ui->textFieldPassword->text().length() < 6) {
        ui->labelPasswordMessages->setText("Password should be at least 6 characters long.");
        isPasswordValid = false;
    } else {
        isPasswordValid = true;
    }

    if (isPasswordValid) {
        ui->labelPasswordMessages->hide();
    } else {
        ui->labelPasswordMessages->show();
    }

    this->update();
}

void SignUpDialog::validatePasswordConfirmation()
{
    if (ui->textFieldPassword->text() != ui->textFieldPasswordConfirmation->text()) {
        ui->labelPasswordConfirmationMessages->setText("The passwords did not match.");
        isPasswordConfirmationValid = false;
    } else {
        isPasswordConfirmationValid = true;
    }

    if (isPasswordConfirmationValid) {
        ui->labelPasswordConfirmationMessages->hide();
    } else {
        ui->labelPasswordConfirmationMessages->show();
    }

    this->update();
}

bool SignUpDialog::validate()
{
    validateUsername();
    validateEmail();
    validatePassword();
    validatePasswordConfirmation();
    return isUsernameValid && isPasswordValid && isPasswordConfirmationValid && isEmailValid;
}

void SignUpDialog::doSignUp()
{
    if (validate()) {
        accept();
    } else {
        QMessageBox mbox(QMessageBox::Warning, "Sign Up",
                         "Signing up could not be completed, because some of the data you entered was not valid.",
                         QMessageBox::Ok, this);
        mbox.setInformativeText("Please check the messages below input fields for more information about the problems. Try to fix those and the try to sign up again.");
        mbox.exec();
    }
}

SignUpDialog::~SignUpDialog()
{
    delete ui;
}
