//
// Created by justd on 9/6/2023.
//

#ifndef UNTITLED14_ELECTIVENAMES_H
#define UNTITLED14_ELECTIVENAMES_H
#include <iostream>
#include <vector>
#include "Student.h"

using namespace std;

class ElectiveNames {

public:
    ElectiveNames(){}
    ElectiveNames(string courseName) : courseName(courseName) {}

    string getCourseName();

    void setCourseName(const string &courseName);

    const vector<Student> &getStudents();

    void setStudents(const vector<Student> &students);

    void addStudent(Student);

private:
    string courseName;
    vector<Student> students;
};


#endif //UNTITLED14_ELECTIVENAMES_H
