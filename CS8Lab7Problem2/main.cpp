#include <iostream>
#include "node.h"

using namespace std;

node* createUniqueList(int); // sorted list that has unique values
node* mergeTwoLists(node*, node*);
void printList(node*);

int main()
{
    node* head1, * head2, * head;
    head1 = head2 = head = NULL;
    int count1, count2;
    cout << "Enter the number of input for list1 : ";
    cin >> count1;
    head1 = createUniqueList(count1);
    printList(head1);
    cout << "Enter the number of input for list2 : ";
    cin >> count2;
    head2 = createUniqueList(count2);
    printList(head2);
    head = mergeTwoLists(head1, head2);
    cout << "<< Merged list >>";
    printList(head);
}

node* createUniqueList(int count)
{
    node* head = nullptr;

    cout << "Enter a number: ";
    if(count > 0)
    {
        int number;
        cin >> number;
        node* newNode = new node(number);
        head = newNode;
        node* current = head;
        for(int i = 1; i < count; i++)
        {
            cout << "Enter a number: " << endl;
            cin >> number;
            if(number != current -> data())
            {
                newNode = new node(number);
                current ->set_link(newNode);
                current = newNode;
            }
        }
    }
    return head;
}

node* mergeTwoLists(node* head1, node* head2)
{
    node* mergedHead = nullptr;
    node* current1 = head1;
    node* current2 = head2;

    while(current1 != nullptr && current2 != nullptr)
    {
        if(current1 -> data() < current2 ->data())
        {
            node* newNode = new node(current1 -> data());
            if(mergedHead == nullptr)
            {
                mergedHead = newNode;
            }
            else
            {
                node* temp = mergedHead;
                while(temp -> link() != nullptr)
                {
                    temp = temp -> link();
                }
                temp -> set_link(newNode);
            }
            current1 = current1 -> link();
        }
        else if(current1 -> data() > current2 -> data())
        {
            node* newNode = new node(current2 -> data());
            if(mergedHead == nullptr)
            {
                mergedHead = newNode;
            }
            else
            {
                node* temp = mergedHead;
                while(temp -> link() != nullptr)
                {
                    temp = temp -> link();
                }
                temp -> set_link(newNode);
            }
            current2 = current2 -> link();
        }
        else
        {
            current1 = current1 -> link();
            current2 = current2 -> link();
        }
    }

    while (current1 != nullptr)
    {
        node* newNode = new node(current1 ->data());
        if(mergedHead == nullptr)
        {
            mergedHead = newNode;
        }
        else
        {
            node* temp = mergedHead;
            while(temp -> link() != nullptr)
            {
                temp = temp -> link();
            }
            temp ->set_link(newNode);
        }
        current1 = current1 -> link();
    }

    while (current2 != nullptr)
    {
        node* newNode = new node(current2 -> data());
        if(mergedHead == nullptr)
        {
            mergedHead = newNode;
        }
        else
        {
            node* temp = mergedHead;
            while(temp -> link() != nullptr)
            {
                temp = temp -> link();
            }
            temp -> set_link(newNode);
        }
        current2 = current2 -> link();
    }

    return mergedHead;
}

void printList(node* head)
{
    cout << "Linked List: ";
    const node* current = head;
    while (current != nullptr)
    {
        cout << current ->data();
        if(current -> link() != nullptr)
        {
            cout << " -> ";
        }
        current = current -> link();
    }
    cout << endl;
}
