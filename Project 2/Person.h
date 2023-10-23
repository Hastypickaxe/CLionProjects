//
// Created by justd on 4/11/2023.
//


#ifndef PROJECT_2_V2_PERSON_H
#define PROJECT_2_V2_PERSON_H
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <string>


using namespace std;


class Person {
public:
    Person();


    int getId() const;


    void setId(int id);


    const string &getName() const;


    void setName(const string &name);


    int getCount() const;


    void setCount(int count);


    // void setCode(int code);


    virtual void print() = 0;


    virtual bool isFull() = 0;


private:
    int id;
    string name;
    int count;
};


class Student : public Person
{
public:
    Student();


    int *getBookArray();


    void print() override;


    bool isFull() override;


private:
    int code[2] = {0};
};


class Teacher : public Person
{
public:
    Teacher();


    int *getBookArray();


    void print() override;


    bool isFull() override;


private:
    int code[3] = {0};
};


#endif //PROJECT_2_V2_PERSON_H


