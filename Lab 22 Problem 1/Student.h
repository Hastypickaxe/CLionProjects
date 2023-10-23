//
// Created by justd on 4/11/2023.
//

#ifndef LAB_22_PROBLEM_1_STUDENT_H
#define LAB_22_PROBLEM_1_STUDENT_H
#include <iomanip>
#include <iostream>
#include <fstream>

using namespace std;

class Student {
private:
    string name;
    int year;
public:
    Student();
    Student(const string& n, int y):name(n),year(y){ }
    const string &getName() const;

    void setName(const string &name);

    int getYear() const;

    void setYear(int year);

    virtual void print() = 0;
};

class Middle : public Student
{
private:
    int english;
    int math;
public:
    Middle();
    Middle(const string& n, int y, int e, int m):Student(n ,y), english(e), math(m){ }
    void print();

    int getEnglish() const;

    void setEnglish(int english);

    int getMath() const;

    void setMath(int math);
};

class High : public Student
{
private:
    string activity;
public:
    High();
    High(const string& n, int y, const string& a);
    void print();

    const string &getActivity() const;

    void setActivity(const string &activity);
};

#endif //LAB_22_PROBLEM_1_STUDENT_H
