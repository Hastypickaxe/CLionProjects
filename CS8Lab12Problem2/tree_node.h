#ifndef TREE_CS008_H
#define TREE_CS008_H
#include <iostream>
#include <iomanip>
using namespace std;
template <class Item>
class binary_tree_node
{
public:
    typedef Item value_type;
// constructor
    binary_tree_node(
            const Item& init_data = Item(),
            binary_tree_node* init_left = NULL,
            binary_tree_node* init_right = NULL
    ) {
        data_field = init_data;
        left_field = init_left;
        right_field = init_right;
    }
// modification member functions
    Item& data() { return data_field; }
    binary_tree_node*& left() { return left_field; }
    binary_tree_node*& right() { return right_field; }
    void set_data(const Item& new_data) { data_field = new_data; }
    void set_left(binary_tree_node* new_left) { left_field = new_left; }
    void set_right(binary_tree_node* new_right) { right_field = new_right; }
// constant member functions
    const Item& data() const { return data_field; }
    const binary_tree_node* left() const { return left_field; }
    const binary_tree_node* right() const { return right_field; }
    bool is_leaf() const {
        return (left_field == NULL) && (right_field == NULL);
    }
private:
    Item data_field;
    binary_tree_node* left_field;
    binary_tree_node* right_field;
};
template <class Item>
size_t tree_size(const binary_tree_node<Item>* node_ptr) {
    if (node_ptr == nullptr) {
        return 0;
    } else {
        // Calculate the size recursively by adding the size of the left and right subtrees
        size_t left_size = tree_size(node_ptr->left());
        size_t right_size = tree_size(node_ptr->right());
        return 1 + left_size + right_size; // 1 for the current node
    }
}
#endif
