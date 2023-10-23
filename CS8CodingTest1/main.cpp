#include <iostream>
#include "iterator.h"

using namespace CodingTest1;
using namespace std;

node<int>* createList()
{
    node<int>* head = NULL, * prev = NULL;
    int input = 0;
    while (1) {
        cout << "Enter a number : ";
        cin >> input;
        if (input == 0) break;
        if (!head) {
            list_head_insert(head, input);
            prev = head;
        }
        else {
            list_insert(prev, input);
            prev = prev->link();
        }
    }
    return head;
}
node<int>* reverseList(node<int>* head)
{
    if (head == NULL || head->link() == NULL)
        return head;

    node<int>* prev = NULL;
    node<int>* newHead= head;
    node<int>* link = NULL;

    while (newHead != NULL) {
        link = newHead->link();
        newHead->set_link(prev);
        prev = newHead;
        newHead = link;
    }

    return prev;
}


void print(node<int>* head)
{
    node_iterator<int> iter = head;
    while (iter != NULL)
    {
        cout << *iter << " ";
        iter++;
    }
    cout << endl;
}

node<int>* concatenate(node<int>* ptr1, node<int>* ptr2)
{
    if (ptr1 == NULL) {
        return ptr2;
    }
    node<int>* newPtr = ptr1;
    while (newPtr->link() != NULL) {
        newPtr = newPtr->link();
    }

    newPtr->set_link(ptr2);

    return ptr1;
}

int main()
{
    node<int>* head1 = NULL;
    head1 = createList();
    cout << "List 1 : ";
    print(head1);
    cout << "---------------------" << endl;
    node<int>* head2 = NULL;
    head2 = createList();
    cout << "List 2 : ";
    print(head2);
    cout << "---------------------" << endl;
    node<int>* head3 = concatenate(head1, head2);
    cout << "List 1 + List 2 : ";
    print(head3);
    cout << "---------------------" << endl;
    node<int>* reversed_head = reverseList(head3);
    cout << "Reversed List : ";
    print(reversed_head);
    return 0;
}