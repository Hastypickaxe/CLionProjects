//
// Created by justd on 9/20/2023.
//

#include "Student.h"

Student::Student() {


}

Student::Student(int _id, const string &_name) : id(_id), name(_name){


}

int Student::getId() const {
    return id;
}

string Student::getName() {
    return name;
}

void Student::setId(int _id) {
    id = _id;
}

void Student::setName(string _name) {
    name = _name;
}

ostream &operator<<(ostream &os, Student student) {
    os << student.getId() << "  " << student.getName();

    return os;
}
