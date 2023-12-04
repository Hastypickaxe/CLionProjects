#include <iostream>
#include <fstream>

using namespace std;

class MaxHeap {
private:
    int* elements;
    int size;
    int capacity;

public:
    MaxHeap(int initialCapacity = 10) {
        capacity = initialCapacity;
        elements = new int[capacity];
        size = 0;
    }

    ~MaxHeap() {
        delete[] elements;
    }

    void push(int value) {
        if (size == capacity) {
            resize();
        }

        int currentIndex = size;
        elements[size++] = value;

        while (currentIndex > 0) {
            int parentIndex = (currentIndex - 1) / 2;
            if (elements[currentIndex] > elements[parentIndex]) {
                swap(elements[currentIndex], elements[parentIndex]);
                currentIndex = parentIndex;
            } else {
                break;
            }
        }
    }

    void pop() {
        if (size == 0) {
            return;
        }

        elements[0] = elements[--size];
        heapifyDown(0);
    }

    bool empty() const {
        return size == 0;
    }

    int top() const {
        return size > 0 ? elements[0] : -1; // Assuming -1 as an invalid value for an empty heap
    }

    // Added a function to get the array size
    int getSize() const {
        return size;
    }

    // Added a function to get the array elements
    const int* getElements() const {
        return elements;
    }

private:
    void resize() {
        capacity *= 2;
        int* newElements = new int[capacity];
        for (int i = 0; i < size; ++i) {
            newElements[i] = elements[i];
        }
        delete[] elements;
        elements = newElements;
    }

    void heapifyDown(int index) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int largest = index;

        if (leftChild < size && elements[leftChild] > elements[largest]) {
            largest = leftChild;
        }

        if (rightChild < size && elements[rightChild] > elements[largest]) {
            largest = rightChild;
        }

        if (largest != index) {
            swap(elements[index], elements[largest]);
            heapifyDown(largest);
        }
    }
};

int main() {
    ifstream infile("data.txt");
    if (!infile.is_open()) {
        cout << "Failed to open file";
        return 1;
    }

    MaxHeap maxHeap;

    int n;
    while (infile >> n) {
        if (n == 0) {
            if (!maxHeap.empty()) {
                int largest = maxHeap.top();
                cout << largest << " popped" << endl;
                maxHeap.pop();

                // Print the new heap
                const int* heapElements = maxHeap.getElements();
                for (int i = 0; i < maxHeap.getSize(); ++i) {
                    cout << heapElements[i] << " ";
                }
                cout << endl;
            }
        } else {
            maxHeap.push(n);
        }
    }

    infile.close();
    return 0;
}
