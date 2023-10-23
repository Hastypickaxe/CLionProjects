#include <iostream>

using namespace std;

class node {

public:
    typedef int value_type;
    node(const value_type& init_data = value_type(), node* init_link = NULL)
    {
        data_field = init_data; link_field = init_link;
    }
    void set_data(const value_type& new_data) { data_field = new_data; }
    void set_link(node* new_link) { link_field = new_link; }
    value_type data() const { return data_field; }
    const node* link() const { return link_field; }
    node* link() { return link_field; }

private:
    value_type data_field;
    node* link_field;
};

void insertSort(node*& head, const node::value_type& data)
{
    node* newNode = new node(data);

    if(head == nullptr || head -> data() >= data)
    {
        newNode ->set_link(head);
        head = newNode;
    }
    else
    {
        node* current = head;
        while(current -> link() != nullptr && current -> link() -> data() <  data)
        {
            current = current -> link();
        }
        newNode -> set_link(current -> link());
        current -> set_link(newNode);
    }
}

node* createSortedList(int count)
{
    node* head = nullptr;

    cout << "Enter " << count << " numbers: ";
    for(int i = 1; i <= count; i++)
    {
        int number;
        cout << endl;
        cout << "Enter a number " << i << " : ";
        cin >> number;
        node* newNode = new node(number);
        insertSort(head, number);
    }
    return head;
}

void printList(node* head)
{
    cout << "Sorted linked list: ";
    while(head != nullptr)
    {
        cout << head -> data();
        if(head -> link() != nullptr)
        {
            cout << "->";
        }
        else {
            cout << "-> NULL";
        }
        head = head -> link();
    }
    cout << endl;
}

int main() {
    node* head = NULL;

    int count;
    cout << "Enter the number of input: ";
    cin >> count;

    head = createSortedList(count);
    printList(head);

    return 0;
}
