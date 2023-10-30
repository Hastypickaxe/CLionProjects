#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <map>
#include <fstream>

using namespace std;

class TreeNode {
public:
    string value;
    TreeNode* left_child;
    TreeNode* right_child;

    TreeNode(string val) : value(val), left_child(nullptr), right_child(nullptr) {}
};

void buildBinaryTree(const string& filename, char tree[], const int size) {
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

        tree[index++] = leftVal;
        tree[index++] = rightVal;
    }
}

TreeNode* buildBinaryTree(const string& filename, map<string, TreeNode*>& nodeMap) {
    ifstream inputFile(filename);
    if(!inputFile.is_open()) {
        cout << "Error: Could not open file" << endl;
        return nullptr;
    }

    string parentVal, leftVal, rightVal;
    TreeNode* root = nullptr;

    while (inputFile >> parentVal >> leftVal >> rightVal) {
        TreeNode* parentNode;
        if (nodeMap.find(parentVal) == nodeMap.end()) {
            parentNode = new TreeNode(parentVal);
            nodeMap[parentVal] = parentNode;
        } else {
            parentNode = nodeMap[parentVal];
        }

        if (leftVal != "Z" ) {
            TreeNode* leftNode;
            if (nodeMap.find(leftVal) == nodeMap.end()) {
                leftNode = new TreeNode(leftVal);
                nodeMap[leftVal] = leftNode;
            }
            parentNode->left_child = leftNode;
        }

        if (rightVal != "Z" ) {
            TreeNode* rightNode;
            if (nodeMap.find(rightVal) == nodeMap.end()) {
                rightNode = new TreeNode(rightVal);
                nodeMap[rightVal] = rightNode;
            } else {
                rightNode = nodeMap[rightVal];
            }
            parentNode->right_child = rightNode;
        }

        if (root == nullptr) {
            root = parentNode;
        }
    }

    inputFile.close();
    return root;
}

string findParent(const map<string, TreeNode*>& nodeMap, const string& target) {
    for (const auto& entry : nodeMap) {
        if (entry.second->left_child && entry.second->left_child->value == target) {
            return entry.first;
        }
        if (entry.second->right_child && entry.second->right_child->value == target) {
            return entry.first;
        }
    }
    return "Not Found";
}

void displayTreeInArrayFormat(char tree[], const int size) {
    for (int i = 0; i < size; ++i) {
        cout << i << " | " << tree[i] << endl;
    }
}
void displayTreeInArrayFormat(const map<string, TreeNode*>& nodeMap, TreeNode* node, int depth, vector<string>& output) {
    if (node == NULL) {
        return;
    }
    string line = to_string(depth) + " | " + node->value;
    output.push_back(line);

    cout << depth << " | " << node->value << endl;
    displayTreeInArrayFormat(nodeMap, node->left_child, depth + 1, output);
    displayTreeInArrayFormat(nodeMap, node->right_child, depth + 1, output);

}

int main() {
    const string filename = "tree.txt";
    map<string, TreeNode*> nodeMap;
    TreeNode* root = buildBinaryTree(filename, nodeMap);

    const int MAX = 100;
    char tree[MAX] = {0};

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

    return 0;
}
