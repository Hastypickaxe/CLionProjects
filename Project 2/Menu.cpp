//
// Created by justd on 4/12/2023.
//


#include "Menu.h"


void Menu::menu0() {
    cout << "1. Search a book"<<endl;
    cout << "2. Rent a book"<<endl;
    cout << "3. Return a book"<<endl;
    cout << "4. Show my information"<<endl;
    cout << "5. Show all books"<<endl;
    cout << "6. Exit"<<endl;
}


void Menu::menu1() {
    int codeInput;
    string title;


    cout << "Enter Code : " << endl;
    cin >> codeInput;
    cout << "Enter title : " << endl;
    cin >> title;


    cout << endl;


    bool found = false;


    for(int i = 0; i < librarySize; i++){
        Book* b = library[i];
        int code = b->getCode();


        if (codeInput != code || title != b->getTitle()) {
            continue;
        }


        found = true;


        cout << b->getTitle() << "(" << code << ") exists." << endl;


        cout << "Category : " << b->getCategory() << endl;


        if (code >= 1001 && code <= 2000)
        {
            ChildrenBook* book = (ChildrenBook*)b;
            cout << "Age : " << book->getAge() << endl;
        } else if (code >= 2001 && code <= 3000)
        {
            ComputerBook* book = (ComputerBook*)b;
            cout << "Publisher : " << book->getPublisher() << endl;
        } else if (code >= 3001 && code <= 4000)
        {
            Novel* book = (Novel*)b;
            cout << "Publish Date :" << book->getPublishDate() << endl;
        }


        cout << b->getAvailable() << " available, " << b->getRented() << " rented" << endl;
    }


    if (!found) {
        cout << "No match (code and title do not match)" << endl;
    }


    cout << endl;
}


void Menu::menu2() {
    int personID;
    string title;
    string name;
    char input;


    cout << "Enter your personID : " << endl;
    cin >> personID;
    cout << "Enter book title : " << endl;
    cin >> title;


    bool isPersonFound = false;


    for (int i = 0; i < peopleSize; i++) {
        Person* p = people[i];




        if (personID != p->getId()) {
            continue;
        }


        isPersonFound = true;


        // search for books like menu1 in here.
        if(personID >= 1 && personID <= 100){
            Teacher* person = (Teacher*)p;
            cout << "You are " << person->getName() << ". You have rented " << p->getCount() << " book(s)." << endl;
            cout<<"Do you want to rent " << title << " (y/n)?";
            cin >> input;
            if(p->isFull()){
                cout<<"You have rented the maximum amount of books"<<endl;
            }
            else {
                int bookIndex = getBookIndexByTitle(title);


                if (bookIndex > -1) {
                    Book* b = library[i];


                    person->getBookArray()[person->getCount()] = b->getCode();
                    person->setCount(person->getCount() + 1);
                    cout<<"*****Rent succeed. Check you info!"<<endl;
                } else {
                    cout << "Book not found" << endl;
                }


            }
        }
        else if(personID >= 101 && personID <= 300){
            Student* person = (Student*)p;
            cout << "You are " << person ->getName() << ". You have rented " << person->getCount() << " book." << endl;
            cout<<"Do you want to rent " << title << " (y/n)?";
            cin >> input;
            if(p->isFull()){
                cout<<"You have rented the maximum amount of books"<<endl;
            }
            else {
                int bookIndex = getBookIndexByTitle(title);


                if (bookIndex > -1) {
                    Book* b = library[i];


                    person->getBookArray()[person->getCount()] = b->getCode();
                    person->setCount(person->getCount() + 1);
                    cout<<"*****Rent succeed. Check you info!"<<endl;
                } else {
                    cout << "Book not found" << endl;
                }


            }
        } else {
            cout << "ID not found" << endl;
        }
    }


    if (!isPersonFound) {
        cout << "Person not found" << endl;
    }
}


void Menu::menu3() {
    int personID;
    int code;
    string title;
    string name;
    char input;


    cout << "Enter your personID : "<<endl;
    cin >> personID;
    cout << "Enter the book code to return : "<<endl;
    cin >> code;


    bool isPersonFound = false;


    for (int i = 0; i < peopleSize; i++) {
        Person* p = people[i];
        //Book* b = library[i];


        if (personID != p->getId()) {
            continue;
        }


        isPersonFound = true;


        int bookIndex = getBookIndexByCode(code);


        if (bookIndex == -1) {
            cout << "Book not found" << endl;
            return; // back to main menu
        }


        Book* b = library[bookIndex];


        cout << "Do you want to return " << b->getTitle() << " (y/n)?" << endl;
        cin >> input;


        if (input == 'N' || input == 'n') {
            return;
        }


        if(personID >= 1 && personID <= 100) {
            Teacher* person = (Teacher*)p;




            bool foundBook = false;
            for (int j = 0; j < person->getCount(); j++) {
                int personCode = person->getBookArray()[j];


                if (personCode == code) {
                    foundBook = true;
                    person->getBookArray()[j] = 0;
                    int count = person->getCount();


                    // looping through your person's book to push all data up
                    sortPeopleBook(person->getBookArray(), count);




                    person->setCount(count - 1);


                    cout << "****Return succeed. Check your info!" << endl;
                    break;
                }
            }


            if(!foundBook){
                cout<<"You did not rent this book"<<endl;
                return;
            }


        } else if(personID >= 101 && personID <= 300) {
            Student *person = (Student *) p;


            bool foundBook = false;
            for (int j = 0; j < person->getCount(); j++) {
                int personCode = person->getBookArray()[j];


                if (personCode == code) {
                    foundBook = true;
                    person->getBookArray()[j] = 0;
                    int count = person->getCount();


                    // looping through your person's book to push all data up
                    sortPeopleBook(person->getBookArray(), count);




                    person->setCount(count - 1);


                    cout << "****Return succeed. Check your info!" << endl;
                    break;
                }
            }


            if(!foundBook){
                cout<<"You did not rent this book"<<endl;
                return;
            }
        }


        break; // found the person by this point no need to check loop
    }
}


// personBooks = [100, 200];
// personBooks[0] = -1;
// personBooks[1] = 200;


// personBooks = [];


void Menu::menu4() {
    int personID;
    string name;
    string title;


    cout<<"Enter your id :" << endl;
    cin >> personID;
    cout<<"Enter your name : " << endl;
    cin >> name;


    bool isPersonFound = false;
    for (int i = 0; i < peopleSize; i++) {
        Person *p = people[i];
        //Book* b = library[i];


        if (personID != p->getId()) {
            continue;
        }


        isPersonFound = true;


        if (personID >= 1 && personID <= 100) {
            Teacher *person = (Teacher *) p;
            cout << "You are " << person->getName() << ". You have rented " << p->getCount() << " book(s)." << endl << endl;


            for (int j = 0; j < person->getCount(); j++) {
                int code = person->getBookArray()[j];


                if (code <= 0) {
                    continue;
                }


                int bookIndex = getBookIndexByCode(code);


                Book* b = library[bookIndex];
                cout << b->getTitle() << endl;
            }
        } else if (personID >= 101 && personID <= 300) {
            Student *person = (Student *) p;
            cout << "You are " << person->getName() << ". You have rented " << person->getCount() << " book(s)." << endl << endl;


            for (int j = 0; j < person->getCount(); j++) {
                int code = person->getBookArray()[j];


                if (code <= 0) {
                    continue;
                }


                int bookIndex = getBookIndexByCode(code);


                Book* b = library[bookIndex];
                cout << b->getTitle() << endl;
            }
        }
    }
}


void Menu::menu5() {
//    cout << "===================================" << endl;
//    cout << "         Children Books            " << endl;
//    cout << "===================================" << endl;
//
//
//    cout << "===================================" << endl;
//    cout << "         Computer Books            " << endl;
//    cout << "===================================" << endl;
//
//
//    cout << "===================================" << endl;
//    cout << "              Novels               " << endl;
//    cout << "===================================" << endl;
    printChildBook();
    printCompBook();
    printNovel();
}


void Menu::menu6() {
    exit(1);
    //break;
}


int Menu::getBookIndexByTitle(const string &title) {
    for (int i = 0; i < librarySize; i++){
        if(library[i]->getTitle() == title) {
            return i; // found book
        }
    }


    return -1; // no book found
}


int Menu::getBookIndexByCode(const int &code) {
    for (int i = 0; i < librarySize; i++){
        if(library[i]->getCode() == code) {
            return i; // found book
        }
    }


    return -1; // no book found
}


void Menu::sortPeopleBook(int arr[], int size) {
    for (int i =0; i < size - 1; i++){
        for(int j = 0; j < size - i - 1; j++){
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


Menu::Menu() {
    readBooks("book.txt", library, librarySize);
    readPeople("person.txt", people, peopleSize);
}


void Menu::run() {
    string inputStr;


    while (true) {


        menu0();
        cout << "Selection (1~6) : " << endl;


        cin >> inputStr;


        int input = stoi(inputStr);


        if (input == 1) {
            menu1();
        }
        else if(input == 2){
            menu2();
        }
        else if(input == 3){
            menu3();
        }
        else if(input == 4){
            menu4();
        }
        else if(input == 5){
            menu5();
        }
        else if (input == 6) {
            menu6();
        } else {
            cout << "Invalid input" << endl;
        }
    }


}


Book **&Menu::getLibrary() {
    return library;
}


Person **&Menu::getPeople() {
    return people;
}


int Menu::getLibrarySize() {
    return librarySize;
}


int Menu::getPeopleSize() {
    return peopleSize;
}


void Menu::readBooks(const string& fileName, Book** &library, int &librarySize)
{
    ifstream infile(fileName);
    countLines(fileName, librarySize);


    library = new Book*[librarySize];


    if (infile.fail())
    {
        cout<<"Input File Failed: " << fileName << endl;
        exit(1);
    }


    int counter = 0;


    while(!infile.eof())
    {
        int code;
        string title;
        int available;
        int rented;


        infile>>code>>title;


        if(code >= 1001 && code <= 2000)
        {
            int age;
            ChildrenBook* book = new ChildrenBook;
            infile>>age>>available>>rented;


            book->setCode(code);
            book->setTitle(title);
            book->setAge(age);
            book->setAvailable(available);
            book->setRented(rented);


            library[counter] = book;
        } else if(code >= 2001 && code <= 3000)
        {
            string publisher;
            ComputerBook* book = new ComputerBook;
            infile>>publisher>>available>>rented;


            book->setCode(code);
            book->setTitle(title);
            book->setPublisher(publisher);
            book->setAvailable(available);
            book->setRented(rented);


            library[counter] = book;
        } else if(code >= 3001 && code <= 4000)
        {
            int published_date;
            Novel* book = new Novel;
            infile>>published_date>>available>>rented;


            book->setCode(code);
            book->setTitle(title);
            book->setPublishDate(published_date);
            book->setAvailable(available);
            book->setRented(rented);


            library[counter] = book;
        }
        counter++;
    }
    infile.close();
}


void Menu::readPeople(const string& fileName, Person** &people, int &peopleSize)
{
    ifstream infile(fileName);
    countLines(fileName, peopleSize);


    people = new Person*[peopleSize];


    if (infile.fail())
    {
        cout<<"Input File Failed: " << fileName << endl;
        exit(1);
    }


    int counter = 0;


    while(!infile.eof())
    {
        int id;
        string name;
        int count;


        int code;


        infile>>id>>name>>count;


        if(id >= 1 && id <= 100)
        {
            Teacher* person = new Teacher;


            person->setId(id);
            person->setName(name);
            person->setCount(count);


            for(int i = 0; i < count; i++) {
                infile >> code;
                person->getBookArray()[i] = code;
            }


            people[counter] = person;
        } else if (id >= 101 && id <= 300)
        {
            Student* person = new Student;


            person->setId(id);
            person->setName(name);
            person->setCount(count);


            for(int i = 0; i < count; i++) {
                infile >> code;
                person->getBookArray()[i] = code;
            }


            people[counter] = person;
        }


        counter++;
    }
    infile.close();
}


void Menu::countLines(const string& fileName, int &size)
{
    ifstream infile(fileName);


    if (infile.fail())
    {
        cout<<"Input File Failed: " << fileName << endl;
        exit(1);
    }


    string line;


    size = 0;


    while(getline(infile, line))
    {
        if (!line.empty()) {
            size++;
        }
    }


    infile.close();
}


void Menu::printChildBook() {
    printBorder(60, 0);
    cout << endl;
    cout << setw(20) << "Children Books\n";
    printBorder(60, 0);
    cout << endl;
    cout << "code" << setw(20) << "title" << setw(20) << "age" << setw(13) << "available" << setw(10) << "rented\n";
    printBorder(60, 1);
    cout << endl;
    for (int i = 0; i < librarySize; i++) {
        Book *b = library[i];
        int code = b->getCode();
        if (code >= 1001 && code <= 2000) {
            ChildrenBook *cb = (ChildrenBook *) b;
            cout << cb->getCode() << setw(30) << cb->getTitle() << setw(8) << cb->getAge() << setw(12) << cb->getAvailable() << setw(10) << cb->getRented() << endl;
        }
    }
    cout << endl;

}

void Menu::printCompBook() {

}

void Menu::printNovel() {

}

void Menu::printBorder(int length, int borderType) {
    if (borderType == 0) {
        for (int i = 0; i < length; i++) {
            cout << "=";
        }
    } else {
        for (int i = 0; i < length; i++) {
            cout << "-";
        }
    }
}
