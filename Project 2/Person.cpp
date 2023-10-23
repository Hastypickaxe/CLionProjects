//
// Created by justd on 4/11/2023.
//


#include "Person.h"


Person::Person() {


}




int Person::getId() const {
    return id;
}


void Person::setId(int id) {
    Person::id = id;
}


const string &Person::getName() const {
    return name;
}


void Person::setName(const string &name) {
    Person::name = name;
}


int Person::getCount() const {
    return count;
}


void Person::setCount(int count) {
    Person::count = count;
}


Student::Student() {}


int *Student::getBookArray() {
    return code;
}


void Student::print() {
    cout << "You rented " << getCount() << " books"<<endl;
    cout<<getId();
}


bool Student::isFull() {
    return getCount() == 2;
}


Teacher::Teacher() {}


int *Teacher::getBookArray() {
    return code;
}


void Teacher::print() {
    cout << "You rented " << getCount() << " books"<<endl;
    cout<<getId();
}


bool Teacher::isFull() {
    return getCount() == 3;
}


