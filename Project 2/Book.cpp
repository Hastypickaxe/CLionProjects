//
// Created by justd on 4/12/2023.
//


#include "Book.h"


Book::Book() {}


int Book::getCode() const {
    return code;
}


void Book::setCode(int code) {
    Book::code = code;
}


const string &Book::getTitle() const {
    return title;
}


void Book::setTitle(const string &title) {
    Book::title = title;
}


int Book::getAvailable() const {
    return available;
}


void Book::setAvailable(int available) {
    Book::available = available;
}


int Book::getRented() const {
    return rented;
}


void Book::setRented(int rented) {
    Book::rented = rented;
}


ChildrenBook::ChildrenBook() {}


int ChildrenBook::getAge() const {
    return age;
}


void ChildrenBook::setAge(int age) {
    ChildrenBook::age = age;
}


string ChildrenBook::getCategory() {
    return "Children";
}


void ChildrenBook::print() {
    cout<<getTitle()<< "(" << getCode() << ") exist" << endl;
    cout<<"Category : "<<getCategory() << endl;
    cout<<"Age : "<<getAge()<<endl;
    cout<<getAvailable()<<" Available, " << getRented() << " rented"<<endl;
}


/*void ChildrenBook::setCode(int code) {
   if(code >= 1001 && code <= 2000){
       Book::setCode(code);
   }
}*/


ComputerBook::ComputerBook() {}


const string &ComputerBook::getPublisher() const {
    return publisher;
}


void ComputerBook::setPublisher(const string &publisher) {
    ComputerBook::publisher = publisher;
}


string ComputerBook::getCategory() {
    return "Computer";
}


void ComputerBook::print() {
    cout << getTitle() << "(" << getCode() << ") exist" << endl;
    cout << "Category : " << getCategory() << endl;
    cout << "Publisher : " << getPublisher() << endl;
    cout << getAvailable() << " Available, " << getRented() << " rented"<<endl;
}


/*void ComputerBook::setCode(int code) {
   if(code >= 2001 && code <= 3000){
       Book::setCode(code);
   }
}*/


Novel::Novel() {}


int Novel::getPublishDate() const {
    return publish_date;
}


void Novel::setPublishDate(int publishDate) {
    publish_date = publishDate;
}


string Novel::getCategory() {
    return "Novel";
}


void Novel::print() {
    cout << getTitle() << "(" << getCode() << ") exist" << endl;
    cout << "Category : " << getCategory() << endl;
    cout << "Publish Date : " << getPublishDate() << endl;
    cout << getAvailable() << " Available, " << getRented() << " rented"<<endl;
}


/*void Novel::setCode(int code) {
   if(code >= 3001 && code <= 4000){
       Book::setCode(code);
   }
}*/


