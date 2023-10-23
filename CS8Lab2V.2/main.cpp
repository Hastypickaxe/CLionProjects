#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <iomanip>
#include "Student.h"

using namespace std;

vector<Student> readFile(string filename, set<string>& classes) {

    ifstream infile;
    infile.open(filename);

    if (infile.fail()) {
        cout << "File opening failed!";
        exit(1);
    }

    string name, e1, e2, e3;


    vector<Student> s;

    while (infile >> name >> e1 >> e2 >> e3) {

        cout << setw(13) << name << setw(13) << e1 << setw(13) << e2 << setw(13) << e3 << endl;
        s.push_back(Student(name, e1, e2, e3));


        for (int i = 0; i < s.size(); i++) {
            for (int j = 0; j < 3; j++) {
                string t = s[i].getElective(j);
                classes.insert(t);
            }
        }
    }

    infile.close();
    return s;
}

void printElectives(vector<Student> students, set<string> classes) {

    set<string>::iterator itr;

    for (itr = classes.begin(); itr != classes.end(); itr++) {
        string electiveName = *itr;

        cout << "[ " << electiveName << " ] ";

        for (auto & student : students) {
            if (electiveName == student.getElective(0) || electiveName == student.getElective(1) || electiveName == student.getElective(2)) {
                cout << student.getName() << " ";
            }

        }
        cout << endl;
    }
}

int main()
{
    set<string> classes;
    string filename;

    cout << "Enter filename : ";
    cin >> filename;

    cout << "============================== Student List ==============================" << endl;
    cout << "--------------------------------------------------------------------------" << endl;
    vector<Student> students = readFile(filename, classes);

    cout << "\n============================== Elective List ==============================" << endl;
    cout << "--------------------------------------------------------------------------" << endl;
    printElectives(students, classes);

    return 0;
}

