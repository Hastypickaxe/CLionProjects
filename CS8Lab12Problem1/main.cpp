#include <iostream>
<<<<<<< HEAD
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <iomanip>

const int MAX = 100;  // Maximum number of nodes

using namespace std;

class TreeNode {
public:
    string value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(string val) : value(val), left(nullptr), right(nullptr) {}
};

<<<<<<< Updated upstream
void buildBinaryTree(const string& filename, char tree[], const int size) {
=======
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
>>>>>>> 9cbaefa43765d8448e57a98233bfc159a521ec1c
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

<<<<<<< HEAD
TreeNode* buildBinaryTree(const string& filename, map<string, TreeNode*>& nodeMap) {
=======
// Function to build a binary tree from the data in a file
TreeNode* buildBinaryTreeFromFile(const string& filename, map<string, TreeNode*>& nodeMap) {
>>>>>>> Stashed changes
    ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "Error: Could not open the file." << endl;
        return nullptr;
    }
=======
        if (leftVal == 'Z') {
            int leftChild = (index - 2) * 2 + 1;
            int rightChild = leftChild + 1;
>>>>>>> 9cbaefa43765d8448e57a98233bfc159a521ec1c

            tree[leftChild] = 'Z';
            tree[rightChild] = 'Z';
        }

<<<<<<< HEAD
        if (leftVal != "Z") {
            TreeNode* leftNode;
            if (nodeMap.find(leftVal) == nodeMap.end()) {
                leftNode = new TreeNode(leftVal);
                nodeMap[leftVal] = leftNode;
            } else {
                leftNode = nodeMap[leftVal];
            }
            parentNode->left = leftNode;
        }

        if (rightVal != "Z") {
            TreeNode* rightNode;
            if (nodeMap.find(rightVal) == nodeMap.end()) {
                rightNode = new TreeNode(rightVal);
                nodeMap[rightVal] = rightNode;
            } else {
                rightNode = nodeMap[rightVal];
            }
            parentNode->right = rightNode;
        }

        if (root == nullptr) {
            root = parentNode;
        }
    }

    inputFile.close();
    return root;
}

// Function to find the parent of a given node
string findParent(const map<string, TreeNode*>& nodeMap, const string& target) {
    for (const auto& entry : nodeMap) {
        TreeNode* current = entry.second;
        if (current->left && current->left->value == target) {
            return entry.first;
        }
        if (current->right && current->right->value == target) {
            return entry.first;
        }
    }
    return "Not found";
=======
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
>>>>>>> 9cbaefa43765d8448e57a98233bfc159a521ec1c
}

<<<<<<< Updated upstream
void displayTreeInArrayFormat(char tree[], const int size) {
    for (int i = 0; i < size; ++i) {
        cout << i << " | " << tree[i] << endl;
    }
}
<<<<<<< HEAD
void displayTreeInArrayFormat(const map<string, TreeNode*>& nodeMap, TreeNode* node, int depth, vector<string>& output) {
    if (node == NULL) {
        return;
=======
// Function to display the binary tree in the desired format
void displayTreeInArrayFormat(TreeNode* root, map<string, TreeNode*>& nodeMap) {
    if (!root) return;

    cout << "<Binary tree in array>" << endl;

    vector<TreeNode*> currentLevel;
    vector<TreeNode*> nextLevel;
    currentLevel.push_back(root);

    int arrayIndex = 0;

    while (!currentLevel.empty()) {
        cout << setw(2) << arrayIndex << " | ";
        for (TreeNode* node : currentLevel) {
            if (node) {
                cout << node->value << endl;
                nextLevel.push_back(nodeMap[node->left->value]);
                nextLevel.push_back(nodeMap[node->right->value]);
            }
        }

        cout << setw(2) << "  | " << string(20, '-') << endl;
        currentLevel = nextLevel;
        nextLevel.clear();
        arrayIndex++;
>>>>>>> Stashed changes
    }
}

int main() {
    const string filename = "tree.txt";
    map<string, TreeNode*> nodeMap;
    TreeNode* root = buildBinaryTreeFromFile(filename, nodeMap);
=======

int main() {
    const string filename = "tree.txt";
>>>>>>> 9cbaefa43765d8448e57a98233bfc159a521ec1c

<<<<<<< Updated upstream
    const int MAX = 100;
    char tree[MAX] = {0};
    int size = 0;

<<<<<<< HEAD
    buildBinaryTree(filename, tree, MAX);
    displayTreeInArrayFormat(tree, MAX);

//    if (root) {
//        vector<string> treeOutput;
//        displayTreeInArrayFormat(nodeMap, root, 0, treeOutput);
//
//        size_t maxWidth = 0;
//        for (const string &line: treeOutput) {
//            maxWidth = max(maxWidth, line.length());
//        }
//
////        cout << "<Binary tree in array>" << endl;
////        for (size_t i = 0; i < treeOutput.size(); i++) {
////            cout << setw(maxWidth) << right << treeOutput[i] << endl;
////        }
//
//        char more;
//        do {
//            cout << "Find the parent of the node" << endl;
//            cout << "Enter data: ";
//            string data;
//            cin >> data;
//
//            string parent = findParent(nodeMap, data);
//            cout << "The parent of " << data << " is " << parent << endl;
//
//            cout << "More(y/n)? : ";
//            cin >> more;
//        } while (more == 'y' || more == 'Y');
//    }else {
//        cout << "Failed to create the binary tree." << endl;
//    }
//
//    for (auto& entry : nodeMap) {
//        delete entry.second;
//    }
=======
    if (root) {
        displayTreeInArrayFormat(root, nodeMap);

        char more;
        do {
            cout << "Find the parent of a node" << endl;
            cout << "Enter data: ";
            string target;
            cin >> target;

            string parent = findParent(nodeMap, target);
            if (parent != "Not found") {
                cout << "The parent of " << target << " is " << parent << endl;
            } else {
                cout << "Node not found." << endl;
            }

            cout << "More(y/n)? : ";
            cin >> more;
        } while (more == 'y' || more == 'Y');
    } else {
        cout << "Failed to create the binary tree." << endl;
    }

    // Clean up memory by deleting the nodes
    for (auto& entry : nodeMap) {
        delete entry.second;
    }
>>>>>>> Stashed changes
=======
    buildBinaryTree(filename, tree, MAX, size);
    displayTreeInArrayFormat(tree, size);
    findParent(tree, size);
>>>>>>> 9cbaefa43765d8448e57a98233bfc159a521ec1c

    return 0;
}
