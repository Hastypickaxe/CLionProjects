#include <iostream>
#include "tree_node.h"

int main() {
    binary_tree_node<int> *root = new binary_tree_node<int>(10);

    root->set_left(new binary_tree_node<int> (20));
    root->set_right(new binary_tree_node<int> (30));

    binary_tree_node<int> * left = root->left();
    left->set_left(new binary_tree_node<int> (40));
    left->set_right(new binary_tree_node<int> (50));



    return 0;
}
