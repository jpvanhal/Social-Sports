#include "user.h"
#include "group.h"

User::User()
{
}

User::User(QString username)
{
    this->_username = username;
}

QString User::username()
{
    return this->_username;
}

void User::join(Group *group)
{
    this->_groups.insert(group->name(), group);
    group->addMember(this);
}

void User::leave(Group *group)
{
    this->_groups.remove(group->name());
    group->removeMember(this);
}

bool User::isMemberOf(Group *group)
{
    return this->_groups.contains(group->name());
}

void User::invite(User *user, Group *group)
{
    user->invitations.insert(group->name(), this);
}

bool User::hasInvitation(Group *group)
{
    return this->invitations.contains(group->name());
}

QList<QString> User::getInvitations()
{
    return this->invitations.keys();
}

User* User::getInviter(Group *group)
{
    return this->invitations[group->name()];
}

QList<QString> User::getGroups()
{
    return this->_groups.keys();
}

void User::acceptInvitation(Group *group)
{
    if (this->hasInvitation(group))
    {
        this->invitations.remove(group->name());
        this->join(group);
    }
}
