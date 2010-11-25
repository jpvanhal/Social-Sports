#include "user.h"

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
