#ifndef GROUP_H
#define GROUP_H

#include <QString>
#include <QMap>

class User;

class Group
{
public:
    Group();
    Group(QString name);
    QString name();
    void addMember(User *user);
    void removeMember(User user);
    void invite(User *user);
    QList<User *> getMembers();
private:
    QString _name;
    QMap<QString, User *> _members;
};

#endif // GROUP_H
