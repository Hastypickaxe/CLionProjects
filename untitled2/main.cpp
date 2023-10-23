#include <iostream>




using namespace std;




struct Node
{
public:
    int data;
    Node* link;
};




typedef Node* NodePtr;




NodePtr createList(int);
NodePtr mergeTwoList(NodePtr, NodePtr);
void printList(NodePtr);




NodePtr createList(int size) {
    int n;
    NodePtr ptr, head, prev;
    for (int i = 1; i <= size; i++) {
        cout << "Enter the " << i << " element of linked list";
        cin >> n;




        ptr = new Node;
        ptr->data = n;
        ptr->link = NULL;




        if (head == NULL)
        {
            head = ptr;
        }
        else
        {
            if ((head->data) > (ptr->data)) {
                ptr->link = head;
                head = ptr;
            }
            else {




                prev = head;
                while (prev->link != NULL && (prev->link->data) < ptr->data) {
                    prev = prev->link;
                }
                ptr->link = prev->link;
                prev->link = ptr;




            }
        }
    }
    return head;
}




NodePtr mergeTwoList(NodePtr head1, NodePtr head2)
{
    NodePtr merged = NULL;
    NodePtr tail = NULL;


    NodePtr move1 = head1;
    NodePtr move2 = head2;


    while(move1 != NULL && move2 != NULL) {
        if (move1->data <= move2->data) {
            if (merged == NULL) {
                merged = new Node;
                merged->data = move1->data;
                tail = merged;


                //move1 = move1->link; // this broke it more
                continue;
            }
            NodePtr temp = new Node;
            temp->data = move1->data;


            tail->link = temp;
            tail = temp;


            move1 = move1->link;
        } else {
            if (merged == NULL) {
                merged = new Node;
                merged->data = move2->data;
                tail = merged;


                //move2 = move2->link; // this broke it more
                continue;
            }
            NodePtr temp = new Node;
            temp->data = move2->data;


            tail->link = temp;
            tail = temp;


            move2 = move2->link;
        }
    }




    return merged;
}




void printList(NodePtr head)
{
    for (NodePtr ptr = head; ptr != NULL; ptr = ptr->link)
        cout << ptr->data << " ";
    cout << endl;
}




int main()
{
    NodePtr head1=NULL, head2=NULL, head3=NULL;




    int size1, size2;




    cout << "Enter Number of Elements in First Linked List: ";
    cin>>size1;
    head1 = createList(size1);




    cout << "Enter Number of Elements in Second Linked List: ";
    cin>>size2;
    head2 = createList(size2);




    cout<<"The First Linked List is Shown as: ";
    printList(head1);
    cout<<"The Second Linked List is Shown as: ";
    printList(head2);




    head3 = mergeTwoList(head1, head2);
    cout<<"Merged Linked List is: ";
    printList(head3);
}
