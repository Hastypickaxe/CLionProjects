#include "Student.h"

int getSize(ifstream& f);
Student** readStudent(ifstream& f, int size);
bool isMiddle(Student** s);
bool isHigh(Student** s);

int main() {
    char filename[20];
    cout << "Enter filename" << endl;
    cin >> filename;

    ifstream infile;
    infile.open(filename);
    if (infile.fail()) {
        cout << "Input File Failed!" << endl;
        exit(1);
    }

    int count = getSize(infile);
    cout << "size: " << count << endl;
    Student **st = new Student*[count];
    infile.close();
    infile.open(filename);
    Student** s = readStudent(infile, count);
    cout << "need to be true:" << isMiddle(s) << endl;
    //after you know it is a middle school by check this way. you can use dynamic cast
    const Middle& m = dynamic_cast<Middle&>(*s[0]);
    cout << "i am a middle:" << m.getEnglish();

    infile.close();
    return 0;
}

int getSize(ifstream& f) {
    int count = 0;
    string line;
    while (getline(f, line)) {
        count++;
    }
    return count;
}

Student** readStudent(ifstream& infile, int size) {
    Student** s = new Student * [size];
    int index = 0;
    char type;
    string name;
    int year;
    int math;
    int english;
    string activity;
    while (!infile.eof()) {
        infile >> type;
        if (type == 'M') {
            infile >> name >> year >> math >> english;
            s[index] = new Middle(name, year, english, math);
            cout << type << name << year << math << english << endl;
        }
        if (type == 'H') {
            infile >> name >> year >> activity;
            s[index] = new High(name, year, activity);
            cout << type << name << year << activity << endl;
        }
        index++;
    }
    return s;
}

bool isMiddle(Student** s) {
    cout << typeid(*s[0]).name() << endl;
    return typeid(*s[0]).name() == typeid(Middle).name();
}

bool isHigh(Student** s) {
    return !isMiddle(s);
}