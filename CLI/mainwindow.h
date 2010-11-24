#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMap>

#include "race.h"

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
    QMap<QString, Race> races;
    Ui::MainWindow *ui;
    QString doHelp(QStringList args);
    QString doRace(QStringList args);
    QString doRaceList();

    static const QString MSG_COMMAND_NOT_RECOGNIZED;

private slots:
    void sendCommand();
};

#endif // MAINWINDOW_H
