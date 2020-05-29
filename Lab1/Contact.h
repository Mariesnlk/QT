#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <QString>

class Contact {
    public:
    QString firstName;
    QString secondName;
    QString tel;
        Contact(QString firstName, QString secondName, QString tel);
        QString ShowAllContacts();
        QString getFirstName(){return firstName;}
        QString getSecondName(){return secondName;}
        QString getTel(){return tel;}

};

#endif // CONTACT_H
