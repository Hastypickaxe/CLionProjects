//
// Created by justd on 9/20/2023.
//


#include "Course.h"


Course::Course() {


}


Course::Course(string code, string title) : code(code), title(title) {
    eList = NULL;
    wList = NULL;
}


string Course::getCode() {
    return code;
}


string Course::getTitle() {
    return title;
}


int Course::getEnrolled() {
    return enrolled;
}


node *Course::getElist() {
    return eList;
}


int Course::getWaitlist() {
    return waitlist;
}


node *Course::getWlist() {
    return wList;
}

void Course::setCode(string _code) {
    code = _code;
}


void Course::setTitle(string _title) {
    title = _title;
}

void Course::addEStudent(node *student) {
    node* iter = eList;

    if (iter == NULL) {
        // If elist is empty, create a new node as the head of the list
//        node* temp = new node(student);
        eList = student;
    } else {
        //Loop until the link is NULL (find the last student)
        while (iter->getLink() != NULL) {
            iter = iter->getLink();
        }

        // Add the new student node to the end of the linked list
        iter->setLink(student);
    }

    enrolled++;
}

void Course::addWStudent(node *student) {
    node* iter = wList;

    if (iter == NULL) {
        // If elist is empty, create a new node as the head of the list
//        node* temp = new node(student);
        wList = student;
    } else {
        //Loop until the link is NULL (find the last student)
        while (iter->getLink() != NULL) {
            iter = iter->getLink();
        }

        // Add the new student node to the end of the linked list
        iter->setLink(student);
    }

    waitlist++;
}

void Course::removeStudentByID(int studentID) {
    // Check if the student is enrolled in the course.
    node* iter = getElist();
    node* previous = nullptr;
    bool found = false;
    bool isElist = true;

    //Finds student by id
    while (iter != nullptr) {
        if (iter->getData().getId() == studentID) {
            found = true;
            cout << getTitle() << " is removed from your course list." << endl;
            break;
        }
        previous = iter;
        iter = iter->getLink();
    }

    // Check if the student is on the waitlist for the course.
    if (!found) {
        iter = getWlist();
        previous = nullptr;
        isElist = false;
        while (iter != nullptr) {
            if (iter->getData().getId() == studentID) {
                found = true;
                cout << "You have been removed from the waitlist of " << getTitle() << endl;
                break;
            }
            previous = iter;
            iter = iter->getLink();
        }
    }

    if (!found) {
        cout << "You are not registered or waitlisted for " << getCode() << " - " << getTitle() << endl;
        return;
    }

    // Remove the student from the list (enrolled or waitlist).
    if (previous == nullptr) {
        if (isElist) {
            setElist(iter->getLink());
        } else {
            setWlist(iter->getLink());
        }
    } else {
        previous->setLink(iter->getLink());

        if (isElist) {
            setEnrolled(getEnrolled() - 1);
        } else {
            setWaitList(getWaitlist() - 1);
        }
    }

    delete iter;

    //For is a student drops a class the student from the waitlist fills the spot
    if (isElist && getWaitlist() > 0) {
        // Check if there are students on the waitlist.
        node* studentFromWaitlist = getWlist();
        if (studentFromWaitlist != nullptr) {
            // Fill the spot with the next student from the waitlist.
            addEStudent(studentFromWaitlist);
            setWlist(studentFromWaitlist->getLink());
            studentFromWaitlist->setLink(NULL);
            cout << "A student from the waitlist has been enrolled in the course." << endl;
        }
    }

}

void Course::setElist(node *_elist) {
    eList = _elist;

    //Counts the number of students
    enrolled = 0;
    node* iter = eList;
    while (iter != nullptr) {
        enrolled++;
        iter = iter->getLink();
    }
}


void Course::setWlist(node *_wlist) {
    //Sets a new head
    wList = _wlist;

    //Counts the number of students in the waitlist
    waitlist = 0;
    node* iter = wList;
    while (iter != nullptr) {
        waitlist++;
        iter = iter->getLink();
    }
}

Course &Course::operator=(Course &rhs) {
    setCode(rhs.code);
    setTitle(rhs.title);
    setWaitList(rhs.waitlist);
    setEnrolled(rhs.enrolled);

    return *this;
}

ostream &operator<<(ostream &os, const Course &course) {
    os << course.code << " " << course.title << " (" << course.enrolled << ") ";

    return os;
}

void Course::setWaitList(int _waitlist) {
    waitlist = _waitlist;
}

void Course::setEnrolled(int _enrolled) {
    enrolled = _enrolled;
}