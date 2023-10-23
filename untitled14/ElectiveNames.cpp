//
// Created by justd on 9/6/2023.
//

#include "ElectiveNames.h"

string ElectiveNames::getCourseName()
{
    return courseName;
}

void ElectiveNames::setCourseName(const string &courseName) {
    ElectiveNames::courseName = courseName;
}

//const vector<Student> &getStudents() {
//    return students;
//}

void ElectiveNames::setStudents(const vector<Student> &students) {
    ElectiveNames::students = students;
}

const vector<Student> &ElectiveNames::getStudents() {
    return students;
}

void ElectiveNames::addStudent(Student student) {
    students.push_back(student);
}
