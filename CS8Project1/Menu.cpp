//
// Created by Kevin on 9/25/2023.
//

#include "Menu.h"

Menu::Menu() {
    string filenameCourse = "courses.txt";
    string filenameEnrollment = "enrollment.txt";

    // Open and read course data from the courses.txt file
    ifstream courseFile(filenameCourse);
    if (!courseFile) {
        cout << "Error: Unable to open the course file." << endl;
        exit(1);
    }

    string courseCode, courseTitle;
    int enrolledCount, waitlistCount;

    //Retrieves the data from each line
    while (courseFile >> courseCode >> courseTitle >> enrolledCount >> waitlistCount) {
        Course course(courseCode, courseTitle);
        courses[coursesSize++] = course;
    }

    courseFile.close();

    // Open and read student enrollment data from the enrollment.txt file
    ifstream enrollmentFile(filenameEnrollment);
    if (!enrollmentFile) {
        cout << "Error: Unable to open the enrollment file." << endl;
        exit(1);
    }

    int studentID, enrolledCourses, waitlistedCourses;
    string studentName, enrolledCourseCode;

    while (enrollmentFile >> studentID >> studentName >> enrolledCourses) {
        Student student(studentID, studentName);

        for (int i = 0; i < enrolledCourses; i++) {
            enrollmentFile >> enrolledCourseCode;

            for (int j = 0; j < coursesSize; j++) {
                if (courses[j].getCode() == enrolledCourseCode) {
                    courses[j].addEStudent(new node(student));
//                    courses[j].setEnrolled(courses[j].getEnrolled() + 1);
                    break;
                }
            }
        }

        //Peeks into the next character to check if there is a waitlist
        if (enrollmentFile.peek() != '\n' && enrollmentFile.peek() != ifstream::traits_type::eof()) {
            enrollmentFile >> waitlistedCourses;

            for (int i = 0; i < waitlistedCourses; i++) {
                enrollmentFile >> enrolledCourseCode;

                for (int j = 0; j < coursesSize; j++) {
                    if (courses[j].getCode() == enrolledCourseCode) {
                        courses[j].addWStudent(new node(student));
//                        courses[j].setWaitList(courses[j].getWaitlist() + 1);
                        break;
                    }
                }
            }
        }
    }

    enrollmentFile.close();
}

void Menu::run() {
    string inputStr;

    while (true) {

        menu0();
        cout << "Selection (1~5) : " << endl;

        cin >> inputStr;

        int input = stoi(inputStr);

        if (input == 1) {
            menu1();
        }
        else if(input == 2){
            menu2();
        }
        else if(input == 3){
            menu3();
        }
        else if(input == 4){
            menu4();
        }
        else if(input == 5){
            menu5();
        }
        else {
            cout << "Invalid input" << endl;
        }
    }
}

void Menu::menu0() {
    cout << "===============Menu===============" << endl;
    cout << "1. View your registration" <<endl;
    cout << "2. Course registration"<<endl;
    cout << "3. Course cancellation"<<endl;
    cout << "4. Print enrollment list including wait-list"<<endl;
    cout << "5. Exit"<<endl;
}

void Menu::menu1() {
    int id;
    string name;

    cout << "Enter your ID: ";
    cin >> id;

    cout << "Enter your name: ";
    cin >> name;

    // Find the student in the list of students (you should have a list of students)
    // and print the courses they are registered for and waitlisted for.
    bool found = false;

    for (int i = 0; i < coursesSize; i++) {
        node* enrolledList = courses[i].getElist();
        node* waitList = courses[i].getWlist();

        //Loops through the enroll list first if student not found then loops waitlist
        while (enrolledList != NULL || waitList != NULL) {
            if (enrolledList != NULL && enrolledList->getData().getId() == id) {
                cout << "(R) " << courses[i].getCode() << " - " << courses[i].getTitle() << endl;
                found = true;
            }
            if (waitList != NULL && waitList->getData().getId() == id) {
                cout << "(W) " << courses[i].getCode() << " - " << courses[i].getTitle() << endl;
                found = true;
            }

            if (enrolledList != NULL) {
                enrolledList = enrolledList->getLink();
            }
            if (waitList != NULL) {
                waitList = waitList->getLink();
            }
        }
    }

    if (!found) {
        cout << "You are not registered for any courses." << endl;
    }
}

void Menu::menu2() {
    int id;
    string name;
    string courseCode;
    string courseTitle;

    cout << "Enter your ID: ";
    cin >> id;
    cout << "Enter your name: ";
    cin >> name;
    cout << "Enter course code: ";
    cin >> courseCode;
    cout << "Enter course title: ";
    cin >> courseTitle;

    // Search for the course based on courseCode in the courses array.
    Course* course = getCourseByCode(courseCode);

    if (course == nullptr) {
        cout << "Course not found. Please check the course code." << endl;
        return;
    }

    // Check if the course is full or not and add the student to the appropriate list.
    node* studentNode = new node(Student(id, name));

    if (course->getEnrolled() < 10) {
        course->addEStudent(studentNode);
        cout << "You have been enrolled in " << course->getCode() << " - " << course->getTitle() << endl;
    } else {
        course->addWStudent(studentNode);
        cout << "You have been waitlisted for " << course->getCode() << " - " << course->getTitle() << endl;
    }
}

void Menu::menu3() {
    int id;
    string name;
    string courseCode;
    string courseTitle;

    cout << "Enter your ID: ";
    cin >> id;
    cout << "Enter your name: ";
    cin >> name;
    cout << "Enter the course code you want to cancel registration for: ";
    cin >> courseCode;

    // Search for the course based on courseCode in the courses array.
    Course* course = getCourseByCode(courseCode);

    if (course == nullptr) {
        cout << "Course not found. Please check the course code." << endl;
        return;
    }

    course->removeStudentByID(id);
}

void Menu::menu4() {
    for (int i = 0; i < coursesSize; i++) {
        cout << courses[i] << endl;

        node* it = courses[i].getElist();

        while (it != NULL) {
            cout << it->getData() << endl;

            it = it->getLink();
        }
        if(courses[i].getWaitlist() > 0) {
            cout << "< Waitlist (" << courses[i].getWaitlist() << ") >" << endl;

            it = courses[i].getWlist();
            while (it != NULL) {
                cout << it->getData() << endl;

                it = it->getLink();
            }
        }

        cout << endl;
    }
}

void Menu::menu5() {
    exit(1);
}

Course *Menu::getCourseByCode(const string &code) {
    Course* course = nullptr;

    //Searching through each course by its code
    for (int i = 0; i < coursesSize; i++) {
        if (courses[i].getCode() == code) {
            course = &courses[i];
            break;
        }
    }

    return course;
}
