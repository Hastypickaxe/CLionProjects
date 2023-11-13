#include <iostream>
#include "iterator.h"
#include "node2.h"

using namespace std;

int main() {
    int n;
    node<int>* head = nullptr;
    node<int>* current = nullptr; // New pointer to keep track of the current node

    do {
        cout << "Enter a number: ";
        cin >> n;

        if (head == nullptr) {
            list_head_insert(head, n);
            current = head; // Set current to the head in the first iteration
        } else if (n != 0){
            list_insert(current, n);
            current = current->getNext(); // Move current to the new node
        }

    } while (n != 0);

    node_iterator<int> iter(head);

    cout << "";

    return 0;
}
