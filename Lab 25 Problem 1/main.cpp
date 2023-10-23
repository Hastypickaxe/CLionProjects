#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <string>

using namespace std;

class  Student{
public:
    Student();

    Student(int ID, string n, int s) : id(ID), name(n), score(s){}

    int getId() const {
        return id;
    }

    void setId(int id) {
        Student::id = id;
    }

    const string &getName() const {
        return name;
    }

    void setName(const string &name) {
        Student::name = name;
    }

    int getScore() const {
        return score;
    }

    void setScore(int score) {
        Student::score = score;
    }

    friend ostream& operator<<(ostream& os, const Student& student){
        os << student.id << " " << student.name << " " << student.score;
        return os;
    }

private:
    int id;
    string name;
    int score;
};

vector<Student>* readFile(const string& filename){
    vector<Student>* section = new vector<Student>();
    ifstream infile(filename);
    int id;
    string name;
    int score;
    infile.open(filename);
    while(infile >> id >> name >> score){
            Student student(id, name, score);
            section->push_back(student);
    }
    infile.close();
    return section;
}

void print(vector<Student>* section){
    vector<Student>::iterator iter;
    for(iter = section->begin(); iter != section->end(); iter++){
        cout << *iter << endl;
    }
}

int main()
{
    vector<Student> *section1, *section2;
    string filename1, filename2;
    int count1, count2;
    cout << "Enter filename1 : ";
    cin >> filename1;
    section1 = readFile(filename1);
    cout << "Enter filename2 : ";
    cin >> filename2;
    section2 = readFile(filename2);
    cout << "\n < section1 >" << endl;
    cout << "-------------------" << endl;
    print(section1);
    cout << "\n < section2 >" << endl;
    cout << "-------------------" << endl;
    print(section2);
/*
// sort the section1 vector
    sort(section1->begin(), section1->end());
    cout << "\n<< section1 after sorting >>" << endl;
    print(section1);
// sort the section2 vector
    sort(section2->begin(), section2->end());
    cout << "\n<< section2 after sorting >>" << endl;
    print(section2);
// merge section1 and section2
    vector<Student> section(section1->size() + section2->size());
    merge(section1->begin(), section1->end(), section2->begin(), section2->end(), section.begin());
    cout << "\n<< After merging two vectors >>" << endl;
    print(&section);
    return 0;
*/
}
