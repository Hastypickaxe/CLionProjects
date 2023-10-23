#include <iostream>

using namespace std;

/*
int findMax(int nums[], int start, int end);

int main()
{
    int nums[] = { 8, 7, 9, 2, 11, 3, 3, 7, 6, 1 };
    int size = sizeof(nums) / sizeof(nums[0]);
    cout << "Array elements: " << endl;
    for (size_t i = 0; i < size; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    int max = findMax(nums, 0, size - 1);
    cout << "Maximum element: " << max << endl;
    return 0;
}

int findMax(int nums[], int start, int end)
{
    if(start == end) {
        return nums[start];
    } else {
        int mid = (start + end) / 2;
        int leftMax = findMax(nums, start, mid);
        int rightMax = findMax(nums, mid + 1, end);

        return max(leftMax, rightMax);
    }
}




class node
{
public:
    int data;
    node* link;
};

int getCount(node* p);

int main() {
    node* head = NULL;
    int input;
    while (1) {
        cin >> input;
        if (input == 0) break;
        if (!head) {
            head = new node;
            head->data = input; head->link = NULL;
            continue;
        }
        node* ptr = new node;
        ptr->data = input; ptr->link = head;
        head = ptr;
    }
    cout << "List : ";
    for (node* ptr = head; ptr; ptr = ptr->link)
        cout << ptr->data << " ";
    cout << endl;
    cout << "Count : " << getCount(head) << endl;
    return 0;
}

int getCount(node* p)
{
    if(!p) return 0;
    return 1 + getCount(p->link);
}


node* search(node* h, int value);

int main() {
    node* head = NULL;
    int input;
    while (1) {
        cin >> input;
        if (input == 0) break;
        if (!head) {
            head = new node;
            head->data = input; head->link = NULL;
            continue;
        }
        node* ptr = new node;
        ptr->data = input; ptr->link = head; head = ptr;
    }
    int num;
    cout << "\nEnter a number to search : ";
    cin >> num;
    node* ptr = search(head, num);
    if (!ptr) cout << "There is no " << num << " in the list" << endl;
    else cout << num << " exists in the list" << endl;
}

node* search(node* h, int value) {
    if(!h) {
        return NULL;
    }

    if (h->data == value) {
        return h;
    }

    return search(h->link, value);
}
*/

/*
int func(int nums[], int size, int element);

int main() {
    int nums[] = { 3, 4, 4, 4, 5, 5, 3, 3, 3, 7, 6, 7, 7, 4 };
    int size = sizeof(nums) / sizeof(nums[0]);
    cout << "Array elements: " << endl;
    for (int i = 0; i < size; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    int element;
    cout << "\nInput an element: ";
    cin >> element;
    int count = func(nums, size, element);
    cout << "Number of occurrences of " << element << ": " << count << endl;
    return 0;
}

int func(int nums[], int size, int element) {
    if(size == 0)
        return 0;

    if(nums[0] == element)
        return 1 + func(nums + 1, size - 1, element);
    else
        return func(nums + 1, size - 1, element);
}
*/

int multiply(int x, int y);

int main() {
    int n1, n2;
    cout << "Input two numbers : ";
    cin >> n1 >> n2;
    int result = multiply(n1, n2);
    cout << n1 << " * " << n2 << " = " << result << endl;
    return 0;
}

int multiply(int x, int y){
if(x == 0||y == 0) {
    return  0;
}

if(y > 0) {
    return x + multiply(x, y - 1);
}
else {
    return -x + multiply(x, y + 1);
}
}