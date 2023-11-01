#include <iostream>
#include <fstream>
#include <map>

using namespace std;

const int MAX = 100;

// Define the TreeNode structure
struct TreeNode {
    char data;
    int index; // Index in the array
};

// Function to create a binary tree from the data using an array
TreeNode* createBinaryTreeFromArray(const map<char, pair<char, char>>& treeMap, char rootData, TreeNode* array) {
    if (rootData == 'Z') {
        return nullptr; // Empty node
    }

    TreeNode* root = &array[rootData - 'A'];
    root->data = rootData;

    string leftChildStr = treeMap.at(rootData).first;
    string rightChildStr = treeMap.at(rootData).second;

    char leftChild = (leftChildStr.empty()) ? 'Z' : leftChildStr[0];
    char rightChild = (rightChildStr.empty()) ? 'Z' : rightChildStr[0];

    root->index = rootData - 'A';

    if (leftChild != 'Z') {
        root->left = createBinaryTreeFromArray(treeMap, leftChild, array);
    }

    if (rightChild != 'Z') {
        root->right = createBinaryTreeFromArray(treeMap, rightChild, array);
    }

    return root;
}

// Function to find the parent of a node
TreeNode* findParent(TreeNode* root, char targetData) {
    if (!root) {
        return nullptr;
    }

    if ((root->left && root->left->data == targetData) || (root->right && root->right->data == targetData)) {
        return root;
    }

    TreeNode* leftResult = findParent(root->left, targetData);
    if (leftResult) {
        return leftResult;
    }

    return findParent(root->right, targetData);
}

int main() {
    ifstream inputFile("tree.txt");
    map<char, pair<char, char>> treeMap;

    if (inputFile.is_open()) {
        char parent;
        string left, right;
        while (inputFile >> parent >> left >> right) {
            treeMap[parent] = make_pair(left, right);
        }

        inputFile.close();
    } else {
        cerr << "Unable to open the input file." << endl;
        return 1;
    }

    TreeNode array[MAX];
    char rootData = 'G'; // Assuming 'G' is the root node.
    TreeNode* root = createBinaryTreeFromArray(treeMap, rootData, array);

    cout << "<Binary tree in array" << endl;
    for (int i = 0; i < MAX; i++) {
        if (array[i].data != 0) {
            cout << i << " | " << array[i].data << endl;
        } else {
            cout << i << " | " << endl;
        }
    }

    char more;
    do {
        char searchData;
        cout << "\nFind the parent of a node" << endl;
        cout << "Enter data: ";
        cin >> searchData;
        TreeNode* parent = findParent(root, searchData);
        if (parent) {
            cout << "The parent of " << searchData << " is " << parent->data << endl;
        } else {
            cout << "Node not found." << endl;
        }

        cout << "More(y/n)? : ";
        cin >> more;
    } while (more == 'y' || more == 'Y');

    return 0;
}
