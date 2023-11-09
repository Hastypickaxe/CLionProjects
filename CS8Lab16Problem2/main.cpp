#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_SIZE = 100;

void insertSorted(vector<int> &sortedArray, int n) {
    if (sortedArray.size() >= MAX_SIZE) {
        cout << "Priority queue is full. Cannot insert " << n << endl;
        return;
    }

    int index = lower_bound(sortedArray.begin(), sortedArray.end(), n) - sortedArray.begin();
    sortedArray.insert(sortedArray.begin() + index, n);
}

void deleteMax(vector<int> &sortedArray) {
    if (!sortedArray.empty()) {
        int largest = sortedArray.back();
        sortedArray.pop_back();
        cout << largest << " popped" << endl;
    } else {
        cout << "Priority queue is empty. Cannot delete." << endl;
    }

    for (int num : sortedArray) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    ifstream infile("data.txt");
    if (!infile.is_open()) {
        cout << "Failed to open file";
        return 1;
    }

    vector<int> priorityQueue;

    int n;
    while (infile >> n) {
        if (n == 0) {
            deleteMax(priorityQueue);
        } else {
            insertSorted(priorityQueue, n);
        }
    }

    infile.close();
    return 0;
}
