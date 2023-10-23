//
// Created by justd on 9/20/2023.
//


#ifndef CS8PROJECT1_COURSE_H
#define CS8PROJECT1_COURSE_H
#include <iostream>
#include "node.h"


using namespace std;


class Course {
private:
    string code;
    string title;
    int enrolled = 0;
    node* eList = NULL;
    int waitlist = 0;
    node* wList = NULL;


public:
    Course();


    Course(string code, string title);


    string getCode();
    string getTitle();
    int getEnrolled();
    node* getElist();
    int getWaitlist();
    node* getWlist();


    void setCode(string _code);
    void setTitle(string _title);


    void addEStudent(node* student);
    void addWStudent(node* student);

    void removeStudentByID(int studentID);


    void setElist(node* _elist);
    void setWlist(node* _wlist);

    Course& operator=(Course& rhs);

    friend ostream& operator<<(ostream& os, const Course& course);
// complete the class

    void setEnrolled(int _enrolled);
    void setWaitList(int _waitlist);
};


#endif //CS8PROJECT1_COURSE_H
