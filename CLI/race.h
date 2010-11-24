#ifndef RACE_H
#define RACE_H

#include <QString>
#include <QDate>

class Race
{
public:
    Race(QString name, QString location, int distance, QDate date);
    QString name();
    QString location();
    int distance();
    QDate date();

private:
    QString _name;
    QString _location;
    int _distance;
    QDate _date;
};

#endif // RACE_H
