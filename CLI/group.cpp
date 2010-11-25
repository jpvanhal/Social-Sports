#include "group.h"
#include "user.h"

Group::Group()
{
}

Group::Group(QString name) {
    this->_name = name;
}

QString Group::name()
{
    return this->_name;
}

void Group::addMember(User* user)
{
    this->_members.insert(user->username(), user);
    user->addGroup(this);
}

QList<User *> Group::getMembers()
{
    return this->_members.values();
}
