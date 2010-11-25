#ifndef USER_H
#define USER_H

#include <QString>
#include <QMap>

class Group;

class User
{
public:
    User();
    User(QString username);
    QString username();
    void addGroup(Group *group);
private:
    QString _username;
    QMap<QString, Group*> _groups;
};

#endif // USER_H
