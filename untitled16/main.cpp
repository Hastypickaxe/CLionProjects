#include <iostream>
#include "node.h"

using namespace std;

void print(node* ptr){
    node* walk = ptr;
    while(walk != NULL)
    {
        cout << walk->data() << " ";
        walk = walk->link();
    }
}

int main() {
    node* head = NULL;
    node* ptr1 = new node(10, NULL);
    node* ptr2 = new node(20, NULL);
    node* ptr3 = new node(30, NULL);

    head = ptr1;
    ptr1 ->set_link(ptr2);
    ptr2 ->set_link(ptr3);

    print(head);

    return 0;
}
