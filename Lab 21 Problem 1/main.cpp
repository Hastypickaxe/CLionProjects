#include <iostream>

using namespace std;

class Person
{
public:
// add constructors, copy constructor, destructor, operator=
Person(){ }
Person(string n, int c, string* h):name(n), count(c) {
    hobbies = new string[count];
    for(int i = 0; i < count; i++)
    {
        hobbies[i] = h[i];
    }
}
Person(const Person& p):name(p.name), count(p.count)
{
    hobbies = new string[count];
    for(int i = 0; i < count; i++)
    {
        hobbies[i]=p.hobbies[i];
    }
}
~Person(){delete[] hobbies;}

Person& operator= (const Person& p)
{
    name = p.name;
    count = p.count;
    hobbies = new string[count];
    for(int i = 0; i < count; i++)
    hobbies[i]=p.hobbies[i];
    return *this;
}
void show() {
        cout << "I am " << name << " and love ";
        for (int i = 0; i < count - 1; i++)
            cout << hobbies[i] << ", ";
        cout << hobbies[count - 1] << ".";
        cout << endl;
}
private:
    string name; // person name
    int count; // number of hobbies
    string* hobbies; // list of hobbies
};

class Student : public Person
{
public:
// add constructor, copy constructor, destructor, operator =
Student(){}
Student(string n, int cnt, string* h, int y, int num, string* c):Person(n, cnt, h), year(y), numOfCourses(num), courses(c){
    courses = new string[numOfCourses];
    for(int  i = 0; i < numOfCourses; i++)
    {
        courses[i] = c[i];
    }

}
Student(const string n, int cnt, string* h, Student& s):Person(n, cnt, h), year(s.year), numOfCourses(s.numOfCourses), courses(s.courses)
{
    delete[] courses;
    courses = new string[numOfCourses];
    for(int i = 0; i < numOfCourses; i++)
    {
        courses[i] = s.courses[i];
    }
}
~Student(){delete[] courses;}

Student& operator= (const Student& s)
{
    Person::operator=(s);
    year = s.year;
    numOfCourses = s.numOfCourses;
    courses = new string[numOfCourses];
    for(int i = 0; i < numOfCourses; i++)
        courses[i] = s.courses[i];
    return *this;
}

    void show() {
        Person::show();
        cout << "My year is " << year << " and have taken " << numOfCourses << " courses." << endl;
        cout << "Courses : ";
        for (int i = 0; i < numOfCourses - 1; i++)
            cout << courses[i] << ", ";
        cout << courses[numOfCourses - 1] << "." << endl;
    }
private:
    int year; // year at college
    int numOfCourses; // number of courses that a student has taken
    string* courses; // course list that a student has taken
};

int main()
{
    string hbs_alice[4] = {"reading", "drawing", "swimming", "movies"};
    string hbs_bob[3] = { "swimming", "running", "singing" };
    string cs_alice[6] = { "C++", "Java", "Python", "DS", "Algorithms", "Database" };
    string cs_bob[7] = { "Java", "DS", "OS", "Network", "Windows", "Linux", "AI" };
    Student alice("Alice", 4, hbs_alice, 2, 6, cs_alice);
    Student bob("Bob", 3, hbs_bob, 3, 7, cs_bob);
    alice.show();
    cout << "------------------------------------------------------------" << endl;
    bob.show();
    cout << "\n************************************************************" << endl;
    cout << "Creating two more objects using copy constructor" << endl;
    Student alice2 = alice;
    alice2.show();
    cout << "------------------------------------------------------------" << endl;
    Student bob2 = bob;
    bob2.show();
    cout << "\n************************************************************" << endl;
    cout << "operator = testing" << endl;
    Student alice3;
    alice3 = alice2;
    alice3.show();
    cout << "------------------------------------------------------------" << endl;
    Student bob3;
    bob3 = bob;
    bob3.show();
}
