#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QHash>
#include <QMap>
#include <QList>

#include "race.h"
#include "user.h"

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
    QMap<QString, Race> raceLookup;
    QList<Race> races;
    QMap<QString, QString> help;
    User *theUser;

    Ui::MainWindow *ui;

    void initRaces();
    void initHelp();
    QString doHelp(QString command);
    QString doRace(QStringList args);
    QString doRaceInfo(QString id);
    QString doRaceList();
    QString doRegister(QString username);

    static const QString MSG_COMMAND_NOT_RECOGNIZED;

private slots:
    void sendCommand();
};

#endif // MAINWINDOW_H
