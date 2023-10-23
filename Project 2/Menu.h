//
// Created by justd on 4/12/2023.
//


#ifndef PROJECT_2_V2_MENU_H
#define PROJECT_2_V2_MENU_H


#include <iostream>
#include <fstream>
#include "Person.h"
#include "Book.h"


using namespace std;




class Menu {
private:
    Book** library = nullptr;
    int librarySize = 0;


    Person** people = nullptr;
    int peopleSize = -1;


    void menu0();
    void menu1();
    void menu2();
    void menu3();
    void menu4();
    void menu5();
    void menu6();


    void sortPeopleBook(int arr[], int size);


    int getBookIndexByTitle(const string& title);
    int getBookIndexByCode(const int& code);


    void countLines(const string& fileName, int &size);
    void readBooks(const string& fileName, Book** &library, int &librarySize);
    void readPeople(const string& fileName, Person** &people, int &peopleSize);

    //helper functions for menu5
    void printChildBook();
    void printCompBook();
    void printNovel();
    /**
     * @param length
     * @param borderType : 0 for =, 1 for -
     */
    void printBorder(int length, int borderType);
public:
    Menu();


    Book**& getLibrary();
    Person**& getPeople();


    int getLibrarySize();
    int getPeopleSize();




    void run();
};




#endif //PROJECT_2_V2_MENU_H


