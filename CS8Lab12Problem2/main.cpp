#include "tree_node.h" // Include the tree_node.h header

int main() {
    // Create nodes for the binary tree
    binary_tree_node<int>* root = new binary_tree_node<int>(1);
    binary_tree_node<int>* leftChild = new binary_tree_node<int>(2);
    binary_tree_node<int>* rightChild = new binary_tree_node<int>(3);

    // Link the nodes to form a binary tree
    root->set_left(leftChild);
    root->set_right(rightChild);

    binary_tree_node<int>* leftChildLeft = new binary_tree_node<int>(4);
    binary_tree_node<int>* leftChildRight = new binary_tree_node<int>(5);

    leftChild->set_left(leftChildLeft);
    leftChild->set_right(leftChildRight);

    // Display the structure of the binary tree
    cout << "Binary Tree Structure:" << endl;
    cout << "root data     : " << root->data() << endl;
    cout << "root->left : " << leftChild->data() << endl;
    cout << "root->right : " << rightChild->data() << endl;
    cout << "root->left->left : " << leftChildLeft->data() << endl;
    cout << "root->left->right : " << leftChildRight->data() << endl;

    // Calculate and display the size of the binary tree using the tree_size function
    size_t size = tree_size(root);
    cout << "Tree size : " << size << endl;

    // Don't forget to deallocate memory for the nodes when done
    delete root;
    delete leftChild;
    delete rightChild;
    delete leftChildLeft;
    delete leftChildRight;

    return 0;
}
