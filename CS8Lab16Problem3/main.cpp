#include <iostream>
#include <fstream>

using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class PriorityQueue {
private:
    Node* head;

public:
    PriorityQueue() : head(nullptr) {}

    void insert(int n) {
        Node* newNode = new Node(n);
        newNode->next = head;
        head = newNode;
    }

    void deleteMax() {
        if (!head) {
            cout << "Priority queue is empty. Cannot delete." << endl;
            return;
        }

        int largest = head->data;
        Node* prev = nullptr;
        Node* current = head;
        Node* maxPrev = nullptr;

        while (current) {
            if (current->data > largest) {
                largest = current->data;
                maxPrev = prev;
            }
            prev = current;
            current = current->next;
        }

        if (maxPrev) {
            Node* temp = maxPrev->next;
            maxPrev->next = maxPrev->next->next;
            delete temp;
        } else {
            Node* temp = head;
            head = head->next;
            delete temp;
        }

        cout << largest << " popped" << endl;
        print();
    }

    void print() {
        Node* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    ifstream infile("data.txt");
    if (!infile.is_open()) {
        cout << "Failed to open file";
        return 1;
    }

    PriorityQueue priorityQueue;

    int n;
    while (infile >> n) {
        if (n == 0) {
            priorityQueue.deleteMax();
        } else {
            priorityQueue.insert(n);
        }
    }

    infile.close();
    return 0;
}
