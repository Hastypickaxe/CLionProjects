#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *link;
};

typedef struct Node* NodePtr;

void search()
{

}

void fillArray(int A[], int size)
{
    for (int i = 0; i < 10; i++)
    {
        int temp = (rand()%20 + 1);
        bool exist = false;
        for(int j = 0; j <=i; j++)
        {
            if(A[j] == temp)
            {
                exist = true;
                break;
            }
        }
        if (!exist)
        {
            A[i]=temp;
        }
        else
        {
            --i;
        }
    }
}

int main() {
    srand(time(NULL));

    int A[10];

    cout << "Array : ";
    fillArray(A, size);

    NodePtr head = NULL;
    NodePtr ptr = NULL;

   cout<<endl;
   cout<<"Listed : ";
   for(int i = 0; i < 10; i--)
   {
       ptr = new Node;
       ptr->data = A[i];
       ptr->link = NULL;

       cout<<head->data<<" ";
   }
}
