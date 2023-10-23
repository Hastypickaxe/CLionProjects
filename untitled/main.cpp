#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *link;
};
typedef Node *NodePtr;

void printList(NodePtr head) {
    for (NodePtr ptr = head; ptr != NULL; ptr = ptr->link) {
        cout << ptr->data << " ";
    }
    cout << endl;
}

int main() {
    int A[10] = {4, 3, 6, 1, 10, 9, 5, 8, 7, 2};

    NodePtr head = NULL;
    NodePtr ptr = NULL;
    NodePtr prev = NULL;

    for (int i = 0; i < 10; i++) {
        ptr = new Node;
        ptr->data = A[i];
        ptr->link = NULL;


        if (head == NULL) {
            head = ptr;
        } else {
            if ((head->data) > (ptr->data)) {
                ptr->link = head;
                head = ptr;
            } else {
                if ((head->data) > (ptr->data)) {
                    ptr->link = head;
                    head = ptr;
                } else {
                    prev = head;
                    while (prev->link != NULL && (prev->link->data) < ptr->data) {
                        prev = prev->link;
                    }
                    ptr->link = prev->link;
                    prev->link = ptr;
                }
            }
        }

        printList(head);
    }


    cout << endl;
    return 0;
}