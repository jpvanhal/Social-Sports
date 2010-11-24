#include <QString>
#include <QStringList>
#include <QRegExp>
#include <QMapIterator>

#include "mainwindow.h"
#include "ui_mainwindow.h"

const QString MainWindow::MSG_COMMAND_NOT_RECOGNIZED = QString("Your command was not recognized. Use 'HELP' command to get a list of available commands.");

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->buttonSend, SIGNAL(clicked()), SLOT(sendCommand()));
    connect(ui->lineEditCommand, SIGNAL(returnPressed()), SLOT(sendCommand()));

    this->races.insert("LVJL11", Race(QString::fromUtf8("Länsiväyläjuoksu (long)"), "Espoo", 17400, QDate(2011, 4, 17)));
    this->races.insert("LVJS11", Race(QString::fromUtf8("Länsiväyläjuoksu (short)"), "Espoo", 6500, QDate(2011, 4, 17)));
    this->races.insert("LVJW11", Race(QString::fromUtf8("Länsiväyläjuoksu (walk)"), "Espoo", 6200, QDate(2011, 4, 17)));
    this->races.insert("HCR11", Race("Helsinki City Run", "Helsinki", 21098, QDate(2011, 5, 7)));
    this->races.insert("NK11", Race("Naisten kymppi", "Helsinki", 10000, QDate(2011, 5, 22)));
    this->races.insert("NAKU11", Race("Nakukymppi", "Padasjoki", 10000, QDate(2011, 6, 17)));
    this->races.insert("PNM11", Race("Paavo Nurmi Marathon", "Turku", 42195, QDate(2011, 7, 2)));
    this->races.insert("HKM11", Race("Helsinki City Marathon", "Helsinki", 42195, QDate(2011, 8, 20)));
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
        return "Available commands: HELP, RACE LIST";
    } else {
        QString command1 = args[0].toUpper();
        if (command1 == "HELP" && args.length() == 1) {
            return "HELP -- Returns a list of available commands.\nHELP <command> -- Returns help on the specified command.";
        } else if (command1 == "RACE" && args.length() == 2) {
            QString command2 = args[1].toUpper();
            if (command2 == "LIST") {
                return "RACE LIST -- Returns a list of upcoming foot races, most recent first.";
            }
        }
        return "No help available on '" + args.join(" ") + "'.";
    }
}

QString MainWindow::doRaceList()
{
    QStringList response;
    QMapIterator<QString, Race> i(this->races);
     while (i.hasNext()) {
         i.next();
         QString id = i.key();
         Race race = i.value();
         response.append(QString("%1: %2 (%3 m) on %4 at %5").arg(id, race.name(), QString::number(race.distance()), race.date().toString("dd.MM.yyyy"), race.location()));
     }
     return response.join(";\n");
}

QString MainWindow::doRace(QStringList args)
{
    if (args.length() > 0) {
        QString command = args.takeFirst().toUpper();
        if (command == "LIST") {
            return this->doRaceList();
        }
    }
    return this->MSG_COMMAND_NOT_RECOGNIZED;
}

void MainWindow::sendCommand()
{
    QString command = this->ui->lineEditCommand->text();
    this->ui->lineEditCommand->clear();

    QStringList args = command.trimmed().split(QRegExp("\\s+"));
    command = args.takeFirst().toUpper();

    QString response;
    if (command == "HELP") {
        response = doHelp(args);
    } else if (command == "RACE") {
        response = doRace(args);
    } else {
        response = this->MSG_COMMAND_NOT_RECOGNIZED;
    }

    this->ui->textEditMessageHistory->setPlainText(response);
}
