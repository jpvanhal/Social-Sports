#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QHash>
#include <QMap>
#include <QList>

#include "race.h"
#include "user.h"
#include "group.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void changeEvent(QEvent *e);

private:
    QMap<QString, Race *> raceLookup;
    QList<Race *> races;
    QMap<QString, QString> help;
    User *theUser;
    QMap<QString, User*> users;
    QMap<QString, Group*> groups;

    Ui::MainWindow *ui;

    void initRaces();
    void initHelp();
    void initGroupsAndUsers();
    Group* createGroup(QString name);
    User* createUser(QString username);
    QString doHelp(QString command);
    QString doGroup(QStringList args);
    QString doGroupMembers(QString groupName);
    QString doGroupJoin(QString groupName);
    QString doGroupLeave(QString groupName);
    QString doGroupCreate(QString groupName, QStringList usernames);
    QString doGroupInvite(QString groupName, QStringList usernames);
    QString doGroupFitness(QString groupName);
    QString doRace(QStringList args);
    QString doRaceInfo(QString id);
    QString doRaceList();
    QString doRaceJoin(QString raceId, QString groupName);
    QString doRaceLeave(QString raceId, QString groupName);
    QString doRacePrerank(QString raceId, QString groupName);
    QString doRegister(QString username);
    QString doUnregister();
    QString doMy(QStringList args);
    QString doMyFitness();
    QString doMyInvitations();
    QString doNews();
    void receiveMessage(QString message);

    static const QString MSG_COMMAND_NOT_RECOGNIZED;
    static const QString MSG_REGISTRATION_REQUIRED;

private slots:
    void sendCommand();
    void simulateInvitation();
};

#endif // MAINWINDOW_H
