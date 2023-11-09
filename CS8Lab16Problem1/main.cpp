#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

int main() {
    ifstream infile("data.txt");
    if (!infile.is_open()) {
        cout << "Failed to open file";
        return 1;
    }

    priority_queue<int> priorityQueue;

    int n;
    while (infile >> n) {
        if (n == 0) {
            if (!priorityQueue.empty()) {
                int largest = priorityQueue.top();
                cout << largest << " popped" << endl;
                priorityQueue.pop();

                // Print the new queue
                priority_queue<int> newQueue = priorityQueue;
                while (!newQueue.empty()) {
                    cout << newQueue.top() << " ";
                    newQueue.pop();
                }
                cout << endl;
            }
        } else {
            priorityQueue.push(n);
        }
    }

    infile.close();
    return 0;
}
