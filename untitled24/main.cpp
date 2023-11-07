#include <iostream>
#include <fstream>

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BST {
private:
    TreeNode* root;

    // Function to insert a value into the BST and balance it
    TreeNode* insert(TreeNode* node, int value) {
        if (node == nullptr) {
            return new TreeNode(value);
        }

        if (value < node->data) {
            node->left = insert(node->left, value);
        } else if (value > node->data) {
            node->right = insert(node->right, value);
        }

        // Balance the tree using AVL balancing
        int balance = getBalance(node);

        // Left heavy
        if (balance > 1 && value < node->left->data) {
            return rightRotate(node);
        }
        // Right heavy
        if (balance < -1 && value > node->right->data) {
            return leftRotate(node);
        }
        // Left-Right case
        if (balance > 1 && value > node->left->data) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        // Right-Left case
        if (balance < -1 && value < node->right->data) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    // Helper function to perform a right rotation
    TreeNode* rightRotate(TreeNode* y) {
        TreeNode* x = y->left;
        TreeNode* T2 = x->right;

        x->right = y;
        y->left = T2;

        return x;
    }

    // Helper function to perform a left rotation
    TreeNode* leftRotate(TreeNode* x) {
        TreeNode* y = x->right;
        TreeNode* T2 = y->left;

        y->left = x;
        x->right = T2;

        return y;
    }

    // Helper function to get the balance factor of a node
    int getBalance(TreeNode* node) {
        if (node == nullptr)
            return 0;
        return getHeight(node->left) - getHeight(node->right);
    }

    // Helper function to get the height of a node
    int getHeight(TreeNode* node) {
        if (node == nullptr)
            return 0;
        return 1 + std::max(getHeight(node->left), getHeight(node->right));
    }

public:
    BST() : root(nullptr) {}

    // Function to insert a value into the BST
    void insert(int value) {
        root = insert(root, value);
    }

    // Function to perform in-order traversal and print sorted values
    void inOrderTraversal(TreeNode* node) {
        if (node == nullptr) return;
        inOrderTraversal(node->left);
        std::cout << node->data << std::endl;
        inOrderTraversal(node->right);
    }

    // Public function to perform in-order traversal
    void inOrderTraversal() {
        inOrderTraversal(root);
    }
};

int main() {
    std::ifstream inputFile("data1.txt");

    if (!inputFile) {
        std::cerr << "Failed to open input file." << std::endl;
        return 1;
    }

    BST bst;

    int n, num;
    inputFile >> n;

    for (int i = 0; i < n; i++) {
        inputFile >> num;
        bst.insert(num);
    }

    bst.inOrderTraversal();

    inputFile.close();

    return 0;
}
