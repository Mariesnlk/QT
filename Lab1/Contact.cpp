#include "Contact.h"
#include <QTextStream>


Contact::Contact(QString firstName, QString secondName, QString tel)
{
    this->firstName = firstName;
    this->secondName = secondName;
    this->tel = tel;
}

QString Contact::ShowAllContacts()
{
    return "Contact: " + firstName + " " + secondName + " tel: " + tel;
}
