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
    void joinGroup(Group *group);
    void invite(User *user, Group *group);
    bool hasInvitation(Group *group);
    User *getInviter(Group *group);
    void acceptInvitation(Group *group);

private:
    QString _username;
    QMap<QString, Group*> _groups;
    QMap<QString, User*> invitations;
};

#endif // USER_H
