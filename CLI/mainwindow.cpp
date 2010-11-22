#include <QString>
#include <QStringList>
#include <QRegExp>

#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->buttonSend, SIGNAL(clicked()), SLOT(sendCommand()));
    connect(ui->lineEditCommand, SIGNAL(returnPressed()), SLOT(sendCommand()));
    ui->lineEditCommand->setFocus(Qt::OtherFocusReason);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

QString MainWindow::doHelp(QStringList args)
{
    if (args.length() == 0) {
        return "Available commands: HELP";
    } else {
        return "No help available on '" + args.join(" ") + "'.";
    }
}

void MainWindow::sendCommand()
{
    QString command = this->ui->lineEditCommand->text();
    this->ui->lineEditCommand->clear();
    this->ui->textEditMessageHistory->append("> " + command);

    QStringList args = command.trimmed().split(QRegExp("\\s+"));
    command = args.takeFirst().toUpper();

    QString response;
    if (command == "HELP") {
        response = doHelp(args);
    } else {
        response = "Your command was not recognized. Use 'HELP' command to get a list of available commands.";
    }

    this->ui->textEditMessageHistory->append(response);
}
