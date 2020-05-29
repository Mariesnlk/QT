#include <QCoreApplication>
#include <QCoreApplication>
#include <QTextStream>
#include <Contact.h>

QTextStream cout(stdout);
QTextStream cin(stdin);

QString firstName;
QString secondName;
QString tel;
int position;

//example
void exampleContacts( QVector<Contact>& contacts){
        contacts = {
            Contact("Carl", "Kafka", "380665790506"),
            Contact("Abdo", "Abby", "380678130506"),
            Contact("Andrew", "Zale", "380668190900/380954207819"),
            Contact("Zak", "Zale", "380965790506"),
            Contact("Pablo", "Sabo", "3806615790506"),
            Contact("Andrew", "Syne", "380669791011/380674435671")
        };

}

void showListOfContacts( QVector<Contact>& contacts){
    int it = 1;
    for (auto element : contacts)
        cout << it++ << ". " <<element.ShowAllContacts() << endl;
    cout << endl;
}

void sortingBySecondName( QVector<Contact>& contacts){
    std::sort(contacts.begin(), contacts.end(), [](Contact &c1, Contact &c2){
           return c1.secondName < c2.secondName;
      });
    cout << endl;
}

void findByFirstName( QVector<Contact>& contacts, QString &firstName){
    for(auto element: contacts){
        if(element.getFirstName().contains(firstName)){
             cout << element.ShowAllContacts() << endl;
        }
    }
}


void findBySecondName( QVector<Contact>& contacts, QString &secondName){
    for(auto element: contacts){
        if(element.getSecondName().contains(secondName)){
             cout << element.ShowAllContacts() << endl;
        }
    }
}

void findByTel( QVector<Contact>& contacts, QString &tel){
    for(auto element: contacts){
        if(element.getTel().contains(tel)){
             cout << element.ShowAllContacts() << endl;
        }
    }
}


void deleteContact(QVector<Contact>& contacts, int pos){
    contacts.removeAt(pos-1);
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QVector<Contact> contacts;

    exampleContacts(contacts);

//example unsorted phonebook
    cout << "Phonebook" << endl << endl;
    showListOfContacts(contacts);

//sorting by secondName
    sortingBySecondName(contacts);

//example sorted by seconName
    cout << "Sorted Phonebook" << endl << endl;
    showListOfContacts(contacts);

    cout << "Type yes to start: " << endl;
    QString st = cin.readLine();

    while(st.contains("yes")){
        cout << "Choice option: 1 - add(name and tel), 2 - delete(name and tel), 3 - show all telephonebook,"
                " 4 - find contact by first name, "
                " 5 - find contact by second name, "
                " 6 - find contact be tel " << endl;
        int s;
        cin >> s;

        switch (s) {
            case 1:
            cout<<"Enter first name"<<endl;
            cin>>firstName<<endl;

            cout<<"Enter second name"<<endl;
            cin>>secondName<<endl;

            cout<<"Enter tel"<<endl;
            cin>>tel<<endl;

              contacts.push_back(Contact(firstName, secondName, tel));
              sortingBySecondName(contacts);
              showListOfContacts(contacts);
              cout << endl;
              break;
            case 2:
                cout<<"Enter position of contact you want to delete: "<<endl;
                cin>>position<<endl;
                if(!contacts.empty()){
                showListOfContacts(contacts);
                deleteContact(contacts, position);
                showListOfContacts(contacts);
                cout << endl;
                }
              break;
            case 3:
                sortingBySecondName(contacts);
                showListOfContacts(contacts);
                cout << endl;
              break;
            case 4:
                cout<<"Enter first name"<<endl;
                cin>>firstName<<endl;
                findByFirstName(contacts, firstName);
                cout << endl;
              break;
            case 5:
                cout<<"Enter second name"<<endl;
                cin>>secondName<<endl;
                findBySecondName(contacts, secondName);
                cout << endl;
              break;
            case 6:
                cout<<"Enter tel"<<endl;
                cin>>tel<<endl;
                findByTel(contacts, tel);
                cout << endl;
              break;

        }
    }
    cout << "Type yes to go on: " << endl;
    st = cin.readLine();

    return a.exec();
}
