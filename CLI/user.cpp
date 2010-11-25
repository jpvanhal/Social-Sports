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

void User::joinGroup(Group *group)
{
    this->_groups.insert(group->name(), group);
    group->addMember(this);
}

void User::invite(User *user, Group *group)
{
    user->invitations.insert(group->name(), this);
}

bool User::hasInvitation(Group *group)
{
    return this->invitations.contains(group->name());
}

User* User::getInviter(Group *group)
{
    return this->invitations[group->name()];
}

void User::acceptInvitation(Group *group)
{
    if (this->hasInvitation(group))
    {
        this->invitations.remove(group->name());
        this->joinGroup(group);
    }
}