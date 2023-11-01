#include <iostream>
#include <fstream>

using namespace std;

class TreeNode{
public:
    int key;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int key) {
        this->key = key;
        left = nullptr;
        right = nullptr;
    }
};

class BinarySearchTree {
private:
    TreeNode* root;

    TreeNode* insert(TreeNode* root, int key) {
        if (root == nullptr) {
            return new TreeNode(key);
        }

        if (key < root->key) {
            root->left = insert(root->left, key);
        }
        else if (key > root->key) {
            root->right = insert(root->right, key);
        }

        return root;
    }

    TreeNode* findMin(TreeNode* node) {
        while (node->left != nullptr) {
            node = node->left;
        }

        return node;
    }

    TreeNode* deletion(TreeNode* root, int key) {
        if (root == nullptr) {
            return root;
        }

        if (key < root->key) {
            root->left = deletion(root->left, key);
        } else if (key > root->key) {
            root->right = deletion(root->right, key);
        } else {
            // If the key matches, delete this node
            if (root->left == nullptr) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            // Node with two children: get the inorder successor (smallest in the right subtree)
            TreeNode* temp = findMin(root->right);
            root->key = temp->key;
            root->right = deletion(root->right, temp->key);
        }

        return root;
    }


    void inorderTraversal(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        inorderTraversal(root->left);
        cout << root->key << " ";
        inorderTraversal(root->right);
    }

public:
    BinarySearchTree() {
        root = nullptr;
    }

    void insert(int key) {
        root = insert(root, key);
    }

    void deletion(int key) {
        root = deletion(root, key);
    }

    void display() {
        cout << "BST: ";
        inorderTraversal(root);
        cout << endl;
    }
};

int main() {
    BinarySearchTree bst;

    ifstream infile;
    infile.open("data1.txt");
    int input;

    if (infile.fail()) {
        cout << "Error opening the file data1.txt" << endl;
        return 1;
    }

    while (infile >> input) {
        bst.insert(input);
    }

    infile.close();
    cout << "Original BST: ";
    bst.display();

    do {


        int delete_key;
        cout << "Enter a number to delete (or enter -1 to quit): ";
        cin >> delete_key;

        if (delete_key == -1) {
            break;
        }

        bst.deletion(delete_key);

        cout << "After deleting " << delete_key << " : ";
        cout << endl;
        bst.display();
    } while (true);

    return 0;
}

