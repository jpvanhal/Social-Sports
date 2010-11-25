#include <QString>
#include <QStringList>
#include <QRegExp>
#include <QMapIterator>

#include "mainwindow.h"
#include "ui_mainwindow.h"

const QString MainWindow::MSG_COMMAND_NOT_RECOGNIZED = QString("Your command was not recognized. Use 'HELP' command to get a list of available commands.");
const QString MainWindow::MSG_REGISTRATION_REQUIRED = QString("You have to register to the service before using this function.");

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->buttonSend, SIGNAL(clicked()), SLOT(sendCommand()));
    connect(ui->lineEditCommand, SIGNAL(returnPressed()), SLOT(sendCommand()));

    this->initRaces();
    this->initHelp();

    this->theUser = 0;
}

void MainWindow::initRaces()
{
    this->races.append(Race("LVJL11", QString::fromUtf8("Länsiväyläjuoksu (long)"), "Espoo", 17400, QDate(2011, 4, 17)));
    this->races.append(Race("LVJS11", QString::fromUtf8("Länsiväyläjuoksu (short)"), "Espoo", 6500, QDate(2011, 4, 17)));
    this->races.append(Race("LVJW11", QString::fromUtf8("Länsiväyläjuoksu (walk)"), "Espoo", 6200, QDate(2011, 4, 17)));
    this->races.append(Race("HCR11", "Helsinki City Run", "Helsinki", 21098, QDate(2011, 5, 7)));
    this->races.append(Race("NK11", "Naisten kymppi", "Helsinki", 10000, QDate(2011, 5, 22)));
    this->races.append(Race("NAKU11", "Nakukymppi", "Padasjoki", 10000, QDate(2011, 6, 17)));
    this->races.append(Race("PNM11", "Paavo Nurmi Marathon", "Turku", 42195, QDate(2011, 7, 2)));
    this->races.append(Race("HKM11", "Helsinki City Marathon", "Helsinki", 42195, QDate(2011, 8, 20)));

    foreach (Race race, this->races) {
        this->raceLookup.insert(race.id(), race);
    }
}

void MainWindow::initHelp()
{
    this->help.insert("HELP", "HELP -- Returns a list of available commands.\nHELP <command> -- Returns help on the specified command.");
    this->help.insert("RACE LIST", "RACE LIST -- Returns a list of upcoming foot races, most recent first.");
    this->help.insert("RACE INFO", "RACE INFO <id> -- Returns detailed information about the race with the given id.");
    this->help.insert("REGISTER", "REGISTER <username> -- Register to the service with the given username.");
    this->help.insert("UNREGISTER", "UNREGISTER -- Unregister from the service.");
    this->help.insert("PERSONAL FITNESS", "PERSONAL FITNESS -- Returns your current personal fitness values and feedback about your training.");
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

QString MainWindow::doHelp(QString command)
{
    QString commandUpper = command.toUpper();
    if (command == "") {
        return "Available commands: " + QStringList(this->help.keys()).join(", ");
    } else if (this->help.contains(commandUpper)) {
        return this->help[commandUpper];
    } else {
        return "No help available on '" + command + "'.";
    }
}

QString MainWindow::doRaceList()
{
    QStringList response;
    foreach (Race race, this->races) {
        response.append(QString("%1: %2").arg(race.id(), race.name()));
    }
    return response.join("\n");
}

QString MainWindow::doRaceInfo(QString id)
{
    QString idUpper = id.toUpper();
    if (this->raceLookup.contains(idUpper)) {
        Race race = this->raceLookup[idUpper];
        return QString("%1 (%2) is %3 m long race organized in %4 on %5.").arg(
                race.name(), race.id(), QString::number(race.distance()),
                race.location(), race.date().toString("dd.MM.yyyy"));
    } else {
        return QString("There is no race with the id '%1'").arg(id);
    }
}

QString MainWindow::doRace(QStringList args)
{
    if (args.length() > 0) {
        QString command = args.takeFirst().toUpper();
        if (command == "LIST") {
            return this->doRaceList();
        } else if (command == "INFO") {
            if (args.length() == 1) {
                return this->doRaceInfo(args[0]);
            } else {
                return this->doHelp("RACE INFO");
            }
        }
    }
    return this->MSG_COMMAND_NOT_RECOGNIZED;
}

QString MainWindow::doRegister(QString username)
{
    if (this->theUser) {
        return QString("You have already registered to the service with username '%0'.").arg(this->theUser->username());
    } else {
        this->theUser = new User(username);
        return QString("You have succesfully registered to the service with username '%0'.").arg(username);
    }
}

QString MainWindow::doUnregister()
{
    if (this->theUser) {
        delete this->theUser;
        this->theUser = 0;
        return QString("You have succesfully unregistered from the service.");
    } else {
        return QString("Cannot unregister you from the service, because you have not registered to the service.");
    }
}

QString MainWindow::doPersonalFitness()
{
    if (!this->theUser) {
        return MSG_REGISTRATION_REQUIRED;
    }
    return "Your endurance is 68/100, strength 45/100 and flexibility 89/100. You have been training hard lately. Maybe you should rest for a change?";
}

void MainWindow::sendCommand()
{
    QString command = this->ui->lineEditCommand->text();
    this->ui->lineEditCommand->clear();

    QStringList args = command.trimmed().split(QRegExp("\\s+"));
    command = args.takeFirst().toUpper();

    QString response;
    if (command == "HELP") {
        response = doHelp(args.join(" "));
    } else if (command == "RACE") {
        response = doRace(args);
    } else if (command == "REGISTER") {
        if (args.length() == 1) {
            response = doRegister(args[0]);
        } else {
            response = doHelp("REGISTER");
        }
    } else if (command == "UNREGISTER") {
        if (args.length() == 0) {
            response = doUnregister();
        } else {
            response = doHelp("UNREGISTER");
        }
    } else if (command == "PERSONAL" && args.length() == 1 && args[0].toUpper() == "FITNESS") {
        response = doPersonalFitness();
    } else {
        response = this->MSG_COMMAND_NOT_RECOGNIZED;
    }

    this->ui->textEditMessageHistory->setPlainText(response);
}
