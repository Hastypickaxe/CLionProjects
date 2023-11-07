#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void findParent(char tree[], const int size) {
    char n, response;

    cout << "Find the parent of a node" << endl;

    do {
        cout << "Enter data : ";
        cin >> n;

        int i = 0;
        bool found = false;

        for (; i < size; ++i) {
            if (tree[i] == n) {
                found = true;
                break;
            }
        }

        if (found) {
            if (i == 0) {
                cout << n << " is root" << endl;
            } else {
                int parent = (i - 1) / 2;
                cout << "The parent of " << n << " is " << tree[parent] << endl;
            }
        } else {
            cout << n << " does not exist in the tree" << endl;
        }

        cout << "more (y/n) ? ";
        cin >> response;
    } while (response == 'y' || response == 'Y');

}

void buildBinaryTree(const string& filename, char tree[], const int size, int & newSize) {
    ifstream inputFile(filename);
    if(!inputFile.is_open()) {
        cout << "Error: Could not open file" << endl;
        return;
    }

    char parentVal, leftVal, rightVal;
    int index = 0;

    while (inputFile >> parentVal >> leftVal >> rightVal) {
        bool found = false;
        for (int i = 0; i < size; ++i) {
            if(tree[i] == parentVal) {
                found = true;

                break;
            }
        }
        if(!found) {
            tree[index++] = parentVal;
        }

        while (tree[index] == 'Z') {
            index++;
        }

        tree[index++] = leftVal;
        tree[index++] = rightVal;

        if (leftVal == 'Z') {
            int leftChild = (index - 2) * 2 + 1;
            int rightChild = leftChild + 1;

            tree[leftChild] = 'Z';
            tree[rightChild] = 'Z';
        }

        if (rightVal == 'Z') {
            int leftChild = (index - 1) * 2 + 1;
            int rightChild = leftChild + 1;

            tree[leftChild] = 'Z';
            tree[rightChild] = 'Z';
        }
    }

    for (int i = 0; i < size; ++i) {
        if (tree[i] == 'Z') {
            tree[i] = '\0';
        }
    }

    newSize = index;
}

void displayTreeInArrayFormat(char tree[], const int size) {
    for (int i = 0; i < size; ++i) {
        cout << i << " | " << tree[i] << endl;
    }
}

int main() {
    const string filename = "tree.txt";

    const int MAX = 100;
    char tree[MAX] = {0};
    int size = 0;

    buildBinaryTree(filename, tree, MAX, size);
    displayTreeInArrayFormat(tree, size);
    findParent(tree, size);

    return 0;
}
