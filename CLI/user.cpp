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

void User::addGroup(Group *group)
{
    this->_groups.insert(group->name(), group);
}
