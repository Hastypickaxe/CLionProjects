#include <iostream>
#include <fstream>

using namespace std;

class SortedArray {
private:
    int* elements;
    int size;
    int capacity;

public:
    SortedArray(int initialCapacity = 100) {
        capacity = initialCapacity;
        elements = new int[capacity];
        size = 0;
    }

    ~SortedArray() {
        delete[] elements;
    }

    void insert(int value) {
        if (size == capacity) {
            cout << "Array is full. Cannot insert more elements." << endl;
            return;
        }

        int i = size - 1;
        while (i >= 0 && elements[i] > value) {
            elements[i + 1] = elements[i];
            i--;
        }

        elements[i + 1] = value;
        size++;
    }

    void removeTop() {
        if (size > 0) {
            cout << elements[size - 1] << " removed" << endl;
            size--;
        } else {
            cout << "Array is empty. Cannot remove elements." << endl;
        }
    }

    bool empty() const {
        return size == 0;
    }

    int top() const {
        return size > 0 ? elements[size - 1] : -1; // Assuming -1 as an invalid value for an empty array
    }

    int getSize() const {
        return size;
    }

    const int* getElements() const {
        return elements;
    }
};

int main() {
    ifstream infile("data.txt");
    if (!infile.is_open()) {
        cout << "Failed to open file";
        return 1;
    }

    SortedArray sortedArray;

    int n;
    while (infile >> n) {
        if (n == 0) {
            if (!sortedArray.empty()) {
                sortedArray.removeTop();

                // Print the new array
                const int* arrayElements = sortedArray.getElements();
                for (int i = 0; i < sortedArray.getSize(); ++i) {
                    cout << arrayElements[i] << " ";
                }
                cout << endl;
            }
        } else {
            sortedArray.insert(n);
        }
    }

    infile.close();
    return 0;
}
