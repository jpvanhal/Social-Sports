#ifndef GROUP_H
#define GROUP_H

#include <QString>
#include <QMap>
#include "user.h"

class Group
{
public:
    Group();
private:
    QString _name;
    QMap<QString, User> _members;
};

#endif // GROUP_H
