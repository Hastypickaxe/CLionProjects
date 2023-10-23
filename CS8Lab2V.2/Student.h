//
// Created by justd on 9/11/2023.
//

#ifndef CS8LAB2V_2_STUDENT_H
#define CS8LAB2V_2_STUDENT_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Student {

private:
    string name;
    vector<string> electiveList;

public:
    Student();
    Student(string _name, string e1, string e2, string e3);

    string getName();
    string getElective(int i);

    void setName(string _name);
    void setElective(vector<string> courses);

};


#endif //CS8LAB2V_2_STUDENT_H
