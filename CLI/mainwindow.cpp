#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->buttonSend, SIGNAL(clicked()), SLOT(sendCommand()));
    connect(ui->lineEditCommand, SIGNAL(returnPressed()), SLOT(sendCommand()));
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

void MainWindow::sendCommand()
{
    QString command = this->ui->lineEditCommand->text();
    this->ui->textEditMessageHistory->append(command);
}
