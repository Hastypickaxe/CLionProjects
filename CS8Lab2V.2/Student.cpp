//
// Created by justd on 9/11/2023.
//

#include "Student.h"

Student::Student() {

}

Student::Student(string _name, string e1, string e2, string e3) {
    name = _name;
    electiveList.push_back(e1);
    electiveList.push_back(e2);
    electiveList.push_back(e3);
}

string Student::getName() {
    return name;
}

string Student::getElective(int i) {
    return electiveList[i];
}

void Student::setName(string _name) {
    name = _name;
}

void Student::setElective(vector<string> courses) {
    electiveList = courses;
}
