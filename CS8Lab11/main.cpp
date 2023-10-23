#include <iostream>
#include <fstream>
#include "circular_queue.h"

using namespace std;

int main() {
    queue<string> enrolled;
    queue<string> waitlisted;

    ifstream infile;
    infile.open("list.txt");
    if (infile.fail()) {
        cout << "Failed to open file" << endl;
        return 1;
    }

    string line;

    while (getline(infile, line)) {
        if (line.substr(0, 4) == "push") {
            string name = line.substr(5);
            if (enrolled.size() < queue<string>::CAPACITY) {
                enrolled.push(name);
            } else {
                waitlisted.push(name);
            }
        } else if (line == "pop") {
            if (!enrolled.empty()) {
                enrolled.pop();
                if (!waitlisted.empty()) {
                    string name = waitlisted.front();
                    enrolled.push(name);
                    waitlisted.pop();
                }
            }
        }

        // Print the status of the queues without clearing them
        cout << "Enroll: ";
        queue<string> enrolledCopy = enrolled; // Copy printing
        while (!enrolledCopy.empty()) {
            cout << enrolledCopy.front() << " ";
            enrolledCopy.pop();
        }
        cout << endl;

        cout << "Waitlist: ";
        if (waitlisted.empty()) {
            cout << "empty";
        } else {
            queue<string> waitlistedCopy = waitlisted; // Copy printing
            while (!waitlistedCopy.empty()) {
                cout << waitlistedCopy.front() << " ";
                waitlistedCopy.pop();
            }
        }
        cout << endl;

        cout << "--------------------------------" << endl;
    }

    infile.close();

    return 0;
}
