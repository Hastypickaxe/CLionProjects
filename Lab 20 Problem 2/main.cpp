#include <iostream>
#include "Classes.h"
#include "Count.h"
#include "fstream"
#include "MSScoreCalc.h"

int getFileSize(std::fstream& in);
HS_Student* readHSStudent(std::fstream& in, int size);
MS_Student* readMSStudent(std::fstream& in, int size);
//Return an array points to different activity count based on the grades
//For example, index 0 points to grade 9, index 1 points to grade 10, and so on
ActivityCount* countActivity(HS_Student* hsStudentAry, int size);
// transform student's year to the index of the array we need to use
int yearToIndex(int year);
MSScoreCalc getMSScore(MS_Student* msStudentAry, int size);

int main() {
    std::fstream inMS("MS.txt");
    std::fstream inHS("HS.txt");
    int arySizeMS = getFileSize(inMS);
    int arySizeHS = getFileSize(inHS);
    inMS.close();
    inHS.close();
    inMS.open("MS.txt");
    inHS.open("HS.txt");
    HS_Student* hsStudentAry =  readHSStudent(inHS, arySizeHS);
    MS_Student* msStudentAry = readMSStudent(inMS, arySizeMS);
    ActivityCount* count = countActivity(hsStudentAry, arySizeHS);
    MSScoreCalc msScoreCalc = getMSScore(msStudentAry, arySizeMS);
    cout << "  High School Students\n";
    cout << "-------------------------------------\n";
    for (int i = 0; i < 4; i++) {
        count[i].print(i + 9);
    }
    cout << msScoreCalc << endl;
}

int getFileSize(std::fstream& in) {
    int count = 0;
    std::string tmp;
    while (std::getline(in, tmp)) {
        count++;
    }
    return count;
}

HS_Student* readHSStudent(std::fstream& in, int size) {
    HS_Student* hsStudentAry = new HS_Student[size];
    string name;
    int year;
    string activity;
    int index = 0;
    while (in >> name >> year >> activity) {
        hsStudentAry[index].setName(name);
        hsStudentAry[index].setYear(year);
        hsStudentAry[index].setActivities(activity);
        index++;
    }
    return hsStudentAry;
}

MS_Student* readMSStudent(std::fstream& in, int size) {
    MS_Student* msStudentAry = new MS_Student[size];
    string name;
    int year;
    int mathScore, scienceScore;
    int index = 0;
    while (in >> name >> year >> mathScore>> scienceScore) {
        msStudentAry[index].setName(name);
        msStudentAry[index].setYear(year);
        msStudentAry[index].setMathScore(mathScore);
        msStudentAry[index].setScienceScore(scienceScore);
        index++;
    }
    return msStudentAry;
}

ActivityCount* countActivity(HS_Student* hsStudentAry, int size) {
    ActivityCount* count = new ActivityCount[HS_Student::NUM_GRADE];
    for (int i = 0; i < size; i++) {
        count[yearToIndex(hsStudentAry[i].getYear())].updateCount(hsStudentAry[i].getActivities());
    }
    return count;
}

int yearToIndex(int year) {
    return year - 9;
}

MSScoreCalc getMSScore(MS_Student* msStudentAry, int size) {
    MSScoreCalc calc;
    for (int i = 0; i < size; i++) {
        int year = msStudentAry[i].getYear();
        calc.updateMath(msStudentAry[i].getMathScore(), year);
        calc.updateScience(msStudentAry[i].getScienceScore(), year);
    }
    return calc;
}
