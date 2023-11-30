#include <iostream>
#include "iterator.h"
#include "node2.h"

using namespace std;

int main() {
    int n;
    node<int>* head = nullptr;
    node<int>* current = nullptr; // New pointer to keep track of the current node

    // 4 7 2 4 1 5 0

    do {
        cout << "Enter a number: ";
        cin >> n;

        if (head == nullptr) {
            template_bag4::list_head_insert(head, n);
            current = head; // Set current to the head in the first iteration
        } else if (n != 0){
            template_bag4::list_sort_insert(head, n);
//            current = current->getNext(); // Move current to the new node
        }

    } while (n != 0);

//    node_iterator<int> iter(head);

    template_bag4::list_display(head);

    return 0;
}