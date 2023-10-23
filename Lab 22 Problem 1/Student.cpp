//
// Created by justd on 4/11/2023.
//

#include "Student.h"

Student::Student() {}

const string &Student::getName() const {
    return name;
}

void Student::setName(const string &name) {
    Student::name = name;
}

int Student::getYear() const {
    return year;
}

void Student::setYear(int year) {
    Student::year = year;
}

Middle::Middle() {}

int Middle::getEnglish() const {
    return english;
}

void Middle::setEnglish(int english) {
    Middle::english = english;
}

int Middle::getMath() const {
    return math;
}

void Middle::setMath(int math) {
    Middle::math = math;
}

High::High() {}

const string &High::getActivity() const {
    return activity;
}

void High::setActivity(const string &activity) {
    High::activity = activity;
}

High::High(const string &n, int y, const string &a): Student(n, y), activity(a) {

}

void Middle::print() {

}

void High::print() {

}
