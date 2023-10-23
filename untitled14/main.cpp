#include <iostream>
#include <vector>
#include <set>
#include "Student.h"
#include "ElectiveNames.h"

using namespace std;

ElectiveNames* locate(vector<ElectiveNames*>& electives, const string& courseName);

int main() {
    vector<Student> students;

    // Vector of courses and names in each course
    vector<ElectiveNames *> electives;
    // pair<courseName, studentNames>

    string filename;

    filename = "student.txt";
    //cin >> filename;

    ifstream infile;

    infile.open(filename);
    if(infile.fail())
    {
        cout << "File has failed to open";
        exit(1);
    }

    if(infile.is_open())
    {
        string line;
        while(!infile.eof())
        {
            string name;

            infile >> name;
//            cout << "NAME:" << name << " ";

            string course;

            getline(infile, line);
            istringstream ss(line);

            vector<string> courseList;

            while (ss >> course) {
                courseList.push_back(course);

            }

            Student student(name, courseList);

            ElectiveNames* electiveList = locate(electives, course);
            electiveList->addStudent(student);
            students.push_back(student);
        }

    }

    infile.close();

    return 0;
}

ElectiveNames* locate(vector<ElectiveNames*>& electives, const string& courseName)
{
    for(auto course : electives) {
        if (course->getCourseName() == courseName) {
            return course;
        }
    }
    ElectiveNames* en = new ElectiveNames(courseName);
    electives.push_back(en);

    return en;
}