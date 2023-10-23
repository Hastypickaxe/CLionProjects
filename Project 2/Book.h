//
// Created by justd on 4/12/2023.
//


#ifndef PROJECT_2_V2_BOOK_H
#define PROJECT_2_V2_BOOK_H
#include <iostream>


using namespace std;


class Book
{
public:
    Book();


    int getCode() const;


    void setCode(int code);


    const string &getTitle() const;


    void setTitle(const string &title);


    int getAvailable() const;


    void setAvailable(int available);


    int getRented() const;


    void setRented(int rented);


    virtual void print() = 0;


    virtual string getCategory() = 0;


private:
    int code;
    string title;
    int available;
    int rented;
};


class ChildrenBook : public Book
{
public:
    ChildrenBook();


    int getAge() const;


    void setAge(int age);


    //void setCode(int code);


    void print() override;


    string getCategory() override;


private:
    int age;
};


class ComputerBook : public Book
{
public:
    ComputerBook();


    const string &getPublisher() const;


    void setPublisher(const string &publisher);


    // void setCode(int code);


    void print() override;


    string getCategory() override;
private:
    string publisher;
};


class Novel : public Book
{
public:
    Novel();


    int getPublishDate() const;


    void setPublishDate(int publishDate);


    // void setCode(int code);


    void print() override;


    string getCategory() override;
private:
    int publish_date;
};




#endif //PROJECT_2_V2_BOOK_H
