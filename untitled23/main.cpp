#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct TreeNode {
    int key;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : key(val), left(nullptr), right(nullptr) {}
};

class binarySearchTree {
public:
    TreeNode* root;

    binarySearchTree() : root(nullptr) {}

    void insert(int key) {
        root =insertRecursive(root, key);
    }

    TreeNode* insertRecursive(TreeNode* node, int key) {
        if (node == nullptr) {
            return new TreeNode(key);
        }

        if (key < node->key) {
            node->left = insertRecursive(node->left, key);
        }
        else if (key > node->key) {
            node->right = insertRecursive(node->right, key);
        }

        return node;
    }

    TreeNode* findparent(int key, TreeNode* node, TreeNode* parent) {
        if (node == nullptr) {
            return nullptr;
        }

        if (node->key == key) {
            return parent;
        }
        else if (key < node->key) {
            return findparent(key, node->left, node);
        }
        else {
            return findparent(key, node->right, node);
        }
    }

    TreeNode* findSibling(int key, TreeNode* node) {
        TreeNode* parent = findparent(key, root, nullptr);

        if (parent == nullptr) {
            return nullptr;
        }

        if (parent->left && parent->left->key == key) {
            return parent->right;
        }
        else if (parent->right && parent->right->key == key) {
            return parent->left;
        }

        return nullptr;
    }

    void inorderPrint(TreeNode* node) {
        if (node == nullptr) {
            return;
        }

        inorderPrint(node->left);
        cout << node->key << " ";
        inorderPrint(node->right);
    }
};

int main() {
    string filename;

    cout << "Enter filename : ";
    cin >> filename;

    binarySearchTree bst;
    ifstream infile(filename);
    int key;

    if (infile.fail()) {
        cout << "File failed to open";
        return 1;
    }

    while (infile >> key) {
        bst.insert(key);
    }

    cout << "BST: ";
    bst.inorderPrint(bst.root);
    cout << endl;

    char choice;
    do {
        int found;
        cout << "Enter data to search : ";
        cin >> found;

        TreeNode* parent = bst.findparent(found, bst.root, nullptr);
        TreeNode* sibling = bst.findSibling(found, bst.root);

        cout << "Parent of " << found << " is ";
        if (parent) {
            cout << parent->key;
        } else {
            cout << "No parent found (root)";
        }

        cout << ", sibling is ";
        if (sibling) {
            cout << sibling->key;
        } else {
            cout << " no sibling";
        }

        cout << endl;

        cout << "more (y/n) ? : ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    return 0;
}
