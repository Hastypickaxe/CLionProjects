//
// Created by Kevin on 9/25/2023.
//

#ifndef CS8PROJECT1_MENU_H
#define CS8PROJECT1_MENU_H
#include <iostream>
#include <fstream>
#include "Student.h"
#include "Course.h"

using namespace std;

class Menu {

private:
    Course courses[11];
    int coursesSize = 0;

    Course* getCourseByCode(const string& code);
public:
    Menu();

    void run();
    void menu0();
    void menu1();
    void menu2();
    void menu3();
    void menu4();
    void menu5();
};

#endif //CS8PROJECT1_MENU_H
