//
// Created by justd on 8/31/2023.
//

#ifndef UNTITLED14_STUDENT_H
#define UNTITLED14_STUDENT_H
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Student
{
private:
    string name;
    vector<string>electiveList;
public:
    Student() { }
    Student(const string &name, const vector<string> &electiveList);

    string getName(){
        return name;
    }

    const vector<string> &getElectiveList() const
    {
        return electiveList;
    }

    void setName(const string &name)
    {
        Student::name = name;
    }

    void setElectiveList(const vector<string> &electiveList)
    {
        Student::electiveList = electiveList;
    }

};

Student::Student(const string &name, const vector<string> &electiveList) : name(name), electiveList(electiveList)
{

}


#endif //UNTITLED14_STUDENT_H
