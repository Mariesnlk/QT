//#include <QCoreApplication>
//#include <QCoreApplication>
//#include <QMap>
//#include <QDebug>
//#include <QTextStream>


//QTextStream cout(stdout);
//QTextStream cin(stdin);

//QString name;
//QString tel;

//QMultiMap<QString, QString> mapPhonebook;

//void addContact(){
//        cout<<"Enter name"<<endl;
//        cin>>name<<endl;
//        cout<<"Entered name is " << name<<endl;

//        cout<<"Enter tel"<<endl;
//        cin>>tel<<endl;
//        cout<<"Entered tel is " << tel<<endl;

//        if(mapPhonebook.keys().contains(name) && mapPhonebook.values().contains(tel)){
//            cout<< "This contact exist!" <<endl;
//        } else{
//            mapPhonebook.insert(name, tel);
//        }

//}

//void showAllContacts(){
//        for (auto itr = mapPhonebook.begin(); itr != mapPhonebook.end(); ++itr) {
//         cout << "Name: " << itr.key() << "  Phone:  " << itr.value() << endl;
//         }
//}


//void  deleteContactByName(){
//    if(!mapPhonebook.isEmpty()){
//        cout << "Enter name to delete (First letter should be capital)" << endl;
//        cin >> name << endl;
//        if(!mapPhonebook.keys().contains(name)){
//            cout<< "You can`t delete this contact! " << endl;
//        } else{
//            mapPhonebook.remove(name);
//        }
//      } else{
//         cout<< "You can`t delete this contact! Phone book is empty! " << endl;
//     }
//}


//void findByName(){
//    cout << "Enter name to find (First letter should be capital): " << endl;
//    cin >> name << endl;
//    if(mapPhonebook.keys().contains(name)){
//    for (auto itr = mapPhonebook.begin(); itr != mapPhonebook.end(); itr++)
//        if (itr.key() == name)
//            cout << "Name: " << itr.key() << "  Phone: " << itr.value()<< endl;
//    } else{
//        cout<<"This name doesn`t exist!"<<endl;
//    }
//}

//void findByTel(){
//    cout << "Enter tel to find: " << endl;
//    cin >> tel << endl;
//    if(mapPhonebook.values().contains(tel)){
//    for (auto itr = mapPhonebook.begin(); itr != mapPhonebook.end(); itr++)
//        if (itr.value() == tel)
//            cout << "Name: " << itr.key() << "  Phone: " << itr.value()<< endl;
//    }else{
//        cout<<"This tel doesn`t exist!"<<endl;
//    }
//}

//int main(int argc, char *argv[])
//{
//    QCoreApplication a(argc, argv);

//    mapPhonebook.insert("Piggy", "+49631322187");
//    mapPhonebook.insert("Kermit", "+49631322181");
//    mapPhonebook.insert("Gonzo", "+49631322000");
//    mapPhonebook.insert("Gonzo", "+49631322010");
//    mapPhonebook.insert("Piggy", "+49631322999");
//    mapPhonebook.insert("Peppa", "+49631322889");
//    mapPhonebook.insert("Gonzo", "+49631322186");



//    cout << "Type yes to start: " << endl;
//    QString st = cin.readLine();

//    while(st.contains("yes")){
//        cout << "Choice option: 1 - add(name and tel), 2 - delete(name and tel), 3 - show all telephonebook,"
//                " 4 - find contact by name, "
//                " 5 - find contact by tel, " << endl;
//        int s;
//        cin >> s;

//        switch (s) {
//            case 1:
//              addContact();
//              break;
//            case 2:
//              deleteContactByName();
//              showAllContacts();
//              break;
//            case 3:
//              showAllContacts();
//              break;
//            case 4:
//              findByName();
//              break;
//            case 5:
//              findByTel();
//              break;

//        }

////        cout << "Type yes to go on: " << endl;
////        st = cin.readLine();
//    }
//    cout << "Type yes to go on: " << endl;
//    st = cin.readLine();

//    return a.exec();
//}
