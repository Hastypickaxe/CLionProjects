#include <iostream>
#include <fstream>
#include "tree_node.h"

using namespace std;

template <class Item>
class binary_search_tree {
public:
    binary_search_tree() : root(nullptr) {}

    void insert(const Item& value) {
        insert(root, value);
    }

    void inorder_traversal() const {
        inorder_traversal(root);
    }

    void preorder_traversal() const {
        preorder_traversal(root);
    }

    void postorder_traversal() const {
        postorder_traversal(root);
    }

    int height() const {
        if (root == NULL) {
            return 0;
        }

        return height(root) - 1;
    }

    int size() const {
        return size(root);
    }

    int search(const Item& value) const {
        int level = 1;  // Initialize level to 1
        return search(root, value, level) - 1;
    }

private:
    binary_tree_node<Item>* root;

    void insert(binary_tree_node<Item>*& node, const Item& value) {
        if (node == nullptr) {
            node = new binary_tree_node<Item>(value);
        } else if (value < node->data()) {
            insert(node->left(), value);
        } else {
            insert(node->right(), value);
        }
    }

    void inorder_traversal(const binary_tree_node<Item>* node) const {
        if (node != nullptr) {
            inorder_traversal(node->left());
            cout << node->data() << " ";
            inorder_traversal(node->right());
        }
    }

    void preorder_traversal(const binary_tree_node<Item>* node) const {
        if (node != nullptr) {
            cout << node->data() << " ";
            preorder_traversal(node->left());
            preorder_traversal(node->right());
        }
    }

    void postorder_traversal(const binary_tree_node<Item>* node) const {
        if (node != nullptr) {
            postorder_traversal(node->left());
            postorder_traversal(node->right());
            cout << node->data() << " ";
        }
    }

    int height(const binary_tree_node<Item>* node) const {
        if (node == nullptr) {
            return 0;
        }
        int left_height = height(node->left());
        int right_height = height(node->right());
        return max(left_height, right_height) + 1;
    }

    int size(const binary_tree_node<Item>* node) const {
        if (node == nullptr) {
            return 0;
        }
        return 1 + size(node->left()) + size(node->right());
    }

    int search(const binary_tree_node<Item>* node, const Item& value, int& level) const {
        if (node == nullptr) {
            return -1;  // Value not found
        }
        if (value == node->data()) {
            level--;

            cout << value << " is at level " << level;

            if (node->is_leaf()) {
                cout << " and " << value << " is a leaf node";
            }

            cout << endl;

            return level;  // Value found at this level
        }
        if (value < node->data()) {
            return search(node->left(), value, ++level);
        } else {
            return search(node->right(), value, ++level);
        }
    }
};

int main() {
    binary_search_tree<int> bst;
    ifstream inputFile("data1.txt");

    if (inputFile.is_open()) {
        int value;
        while (inputFile >> value) {
            bst.insert(value);
        }
        inputFile.close();

        cout << "The traversal results" << endl;

        cout << "Preorder Traversal  : ";
        bst.preorder_traversal();
        cout << endl;

        cout << "Inorder Traversal   : ";
        bst.inorder_traversal();
        cout << endl;

        cout << "Postorder Traversal : ";
        bst.postorder_traversal();
        cout << endl;

        cout << endl;

        cout << "Height of the tree: " << bst.height() << endl;
        cout << "Size of the tree: " << bst.size() << endl;

        cout << endl;

        while (true) {
            int search_value;
            cout << "Enter data to search: ";
            cin >> search_value;

            int level = bst.search(search_value);

            char choice;
            cout << "More (y/n): ";
            cin >> choice;
            if (choice != 'y' && choice != 'Y') {
                break;
            }
        }
    } else {
        cout << "Failed to open the file" << endl;
    }

    return 0;
}
