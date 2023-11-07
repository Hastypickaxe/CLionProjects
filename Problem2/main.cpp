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
private:
    TreeNode* root;

    TreeNode* insert(TreeNode* node, int value) {
        if (node == nullptr) {
            return new TreeNode(value);
        }

        if (value < node->key) {
            node->left = insert(node->left, value);
        } else if (value > node->key) {
            node->right = insert(node->right, value);
        }

        int balance = getBalance(node);

        if (balance > 1 && value > node->left->key) {
            return rightRotate(node);
        }

        if (balance < -1 && value > node->right->key) {
            return leftRotate(node);
        }

        if (balance > 1 && value < node->left->key) {  // Changed > to < here
            node->left = leftRotate(node->left);  // Changed == to =
            return rightRotate(node);
        }

        if (balance < -1 && value < node->right->key) {  // Changed > to < here
            node->right = rightRotate(node->right);  // Changed == to =
            return leftRotate(node);
        }

        return node;
    }

    TreeNode* rightRotate(TreeNode* y) {
        TreeNode* x = y->left;
        TreeNode* T2 = x->right;

        x->right = y;
        y->left = T2;

        return x;
    }

    TreeNode* leftRotate(TreeNode* x) {
        TreeNode* y = x->right;
        TreeNode* T2 = y->left;

        y->left = x;
        x->right = T2;

        return y;
    }

    int getBalance(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }
        return getHeight(node->left) - getHeight(node->right);
    }

    int getHeight(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }
        return 1 + max(getHeight(node->left), getHeight(node->right));
    }

public:
    binarySearchTree() : root(nullptr) {}

    void insert(int value) {
        root = insert(root, value);
    }

    void inorderTraversal(TreeNode* node) {
        if (node == nullptr) return;
        inorderTraversal(node->left);
        cout << node->key << endl;
        inorderTraversal(node->right);
    }
};

int main() {
    ifstream infile("data1.txt");

    if (!infile) {
        cout << "File failed to open" << endl;
        return 1;
    }

    binarySearchTree bst;

    int n, num;
    infile >> n;

    for (int i = 0; i < n; ++i) {
        infile >> num;
        bst.insert(num);
    }

    bst.inorderTraversal(bst.root);  // Pass the root node to the traversal function

    infile.close();

    return 0;
}
