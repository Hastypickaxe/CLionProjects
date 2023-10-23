//
// Created by justd on 9/20/2023.
//

#ifndef CS8PROJECT1_STUDENT_H
#define CS8PROJECT1_STUDENT_H
#include <iostream>

using namespace std;

class Student {
private:
    int id;
    string name;


public:
    Student();
    Student(int _id, const string &_name);


    int getId() const;
    string getName();


    void setId(int _id);
    void setName(string _name);

    friend ostream& operator<<(ostream& os, Student student);
};

#endif //CS8PROJECT1_STUDENT_H
