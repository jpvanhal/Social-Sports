#ifndef RACE_H
#define RACE_H

#include <QString>
#include <QDate>
#include <QHash>

#include "group.h"

class Race
{
public:
    Race();
    Race(QString id, QString name, QString location, int distance, QDate date);
    QString id();
    QString name();
    QString location();
    int distance();
    QDate date();
    void join(Group *group);
    void leave(Group *group);
    bool isEnrolled(Group *group);

private:
    QString _id;
    QString _name;
    QString _location;
    int _distance;
    QDate _date;
    QHash<QString, Group *> enrollments;
};

#endif // RACE_H
