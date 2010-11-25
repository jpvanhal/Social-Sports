#ifndef USER_H
#define USER_H

#include <QString>
#include <QMap>

class User
{
public:
    User();
    User(QString username);
    QString username();
private:
    QString _username;
};

#endif // USER_H
