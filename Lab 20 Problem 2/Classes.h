//
// Created by justd on 3/30/2023.
//

#ifndef LAB_20_PROBLEM_2_CLASSES_H
#define LAB_20_PROBLEM_2_CLASSES_H

#include <iostream>

using namespace std;

class Student
{
private:
    string name;
    int year;
public:
    Student() {};
    Student(const string &name, int year) : name(name), year(year) {}

    const string &getName() const {
        return name;
    }

    void setName(const string &name) {
        Student::name = name;
    }

    int getYear() const {
        return year;
    }

    void setYear(int year) {
        Student::year = year;
    }

};

class HS_Student:public Student
{
private:
    string activities;
public:
    HS_Student(): Student() {}
   HS_Student(const string& name, int year, const string &activities)
   : Student(name, year), activities(activities) {}

    const string &getActivities() const {
        return activities;
    }

    void setActivities(const string &activities) {
        HS_Student::activities = activities;
    }

    const static int NUM_GRADE = 4;
};

class MS_Student:public Student
{
private:
    int mathScore;
    int scienceScore;
public:
    MS_Student(): Student(){};
    MS_Student(const string& name, int year, int mathScore, int scienceScore)
            : Student(name, year), mathScore(mathScore), scienceScore(scienceScore) {}

    int getMathScore() const {
        return mathScore;
    }

    void setMathScore(int mathScore) {
        MS_Student::mathScore = mathScore;
    }

    int getScienceScore() const {
        return scienceScore;
    }

    void setScienceScore(int scienceScore) {
        MS_Student::scienceScore = scienceScore;
    }
};

#endif //LAB_20_PROBLEM_2_CLASSES_H
