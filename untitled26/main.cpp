#include <iostream>
using namespace std;


const int MAX_KEYS = 4;


class BTreeNode {
public:
    int *keys;
    BTreeNode **child_pointers;
    bool is_leaf;
    int key_count;


    BTreeNode() {
        keys = new int[MAX_KEYS];
        child_pointers = new BTreeNode*[MAX_KEYS + 1];
        is_leaf = true;
        key_count = 0;


        for (int i = 0; i < MAX_KEYS + 1; i++) {
            child_pointers[i] = nullptr;
        }
    }


    ~BTreeNode() {
        delete[] keys;
        delete[] child_pointers;
    }
};


class BTree {
private:
    BTreeNode *root;
    BTreeNode *new_node;
    BTreeNode *current_node;


public:
    BTree() : root(nullptr), new_node(nullptr), current_node(nullptr) {}


    BTreeNode* getRoot() {
        return root;
    }


    ~BTree() {
        delete_tree(root);
    }


    void insert(int key) {
        int index, temp;
        current_node = root;


        if (current_node == nullptr) {
            root = initialize_node();
            current_node = root;
        } else {
            if (current_node->is_leaf && current_node->key_count == MAX_KEYS) {
                temp = split_child(current_node, -1);
                current_node = root;


                for (index = 0; index < current_node->key_count; index++) {
                    if ((key > current_node->keys[index]) && (key < current_node->keys[index + 1])) {
                        index++;
                        break;
                    } else if (key < current_node->keys[0]) {
                        break;
                    } else {
                        continue;
                    }
                }


                current_node = current_node->child_pointers[index];
            } else {
                while (!current_node->is_leaf) {
                    for (index = 0; index < current_node->key_count; index++) {
                        if ((key > current_node->keys[index]) && (key < current_node->keys[index + 1])) {
                            index++;
                            break;
                        } else if (key < current_node->keys[0]) {
                            break;
                        } else {
                            continue;
                        }
                    }


                    if (current_node->child_pointers[index]->key_count == MAX_KEYS) {
                        temp = split_child(current_node, index);
                        current_node->keys[current_node->key_count] = temp;
                        current_node->key_count++;
                        sort(current_node->keys, current_node->key_count);
                        continue;
                    } else {
                        current_node = current_node->child_pointers[index];
                    }
                }
            }
        }


        current_node->keys[current_node->key_count] = key;
        current_node->key_count++;
        sort(current_node->keys, current_node->key_count);
    }


    void delete_tree(BTreeNode *node) {
        if (node) {
            if (!node->is_leaf) {
                for (int i = 0; i < node->key_count + 1; i++) {
                    delete_tree(node->child_pointers[i]);
                }
            }
            delete node;
        }
    }


    BTreeNode *initialize_node() {
        new_node = new BTreeNode();
        return new_node;
    }


    void traverse(BTreeNode *node) {
        cout << endl;


        for (int i = 0; i < node->key_count; i++) {
            if (!node->is_leaf) {
                traverse(node->child_pointers[i]);
            }
            cout << " " << node->keys[i];
        }


        if (!node->is_leaf) {
            traverse(node->child_pointers[node->key_count]);
        }


        cout << endl;
    }


    void sort(int *arr, int n) {
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (arr[i] > arr[j]) {
                    swap(arr[i], arr[j]);
                }
            }
        }
    }


    int split_child(BTreeNode *current_node, int index) {
        int j, mid;
        BTreeNode *new_node, *temp_node, *child_node;
        temp_node = initialize_node();
        temp_node->is_leaf = true;


        if (index == -1) {
            mid = current_node->keys[MAX_KEYS / 2];
            current_node->keys[MAX_KEYS / 2] = 0;
            current_node->key_count--;


            new_node = initialize_node();
            new_node->is_leaf = false;
            current_node->is_leaf = true;


            for (j = MAX_KEYS / 2 + 1; j < MAX_KEYS; j++) {
                temp_node->keys[j - (MAX_KEYS / 2 + 1)] = current_node->keys[j];
                temp_node->child_pointers[j - (MAX_KEYS / 2 + 1)] = current_node->child_pointers[j];
                temp_node->key_count++;
                current_node->keys[j] = 0;
                current_node->key_count--;
            }


            for (j = 0; j < MAX_KEYS + 1; j++) {
                current_node->child_pointers[j] = nullptr;
            }


            new_node->keys[0] = mid;
            new_node->child_pointers[new_node->key_count] = current_node;
            new_node->child_pointers[new_node->key_count + 1] = temp_node;
            new_node->key_count++;
            root = new_node;
        } else {
            child_node = current_node->child_pointers[index];
            mid = child_node->keys[MAX_KEYS / 2];
            child_node->keys[MAX_KEYS / 2] = 0;
            child_node->key_count--;


            for (j = MAX_KEYS / 2 + 1; j < MAX_KEYS; j++) {
                temp_node->keys[j - (MAX_KEYS / 2 + 1)] = child_node->keys[j];
                temp_node->key_count++;
                child_node->keys[j] = 0;
                child_node->key_count--;
            }


            current_node->child_pointers[index + 1] = child_node;
            current_node->child_pointers[index + 1] = temp_node;
        }


        return mid;
    }


    // Helper function to find the predecessor of a key in the B-tree
    int get_predecessor(BTreeNode *node) {
        while (!node->is_leaf) {
            node = node->child_pointers[node->key_count];
        }
        return node->keys[node->key_count - 1];
    }


    // Helper function to find the successor of a key in the B-tree
    int get_successor(BTreeNode *node) {
        while (!node->is_leaf) {
            node = node->child_pointers[0];
        }
        return node->keys[0];
    }


    // Helper function to remove a key from a leaf node
    void remove_from_leaf(BTreeNode *node, int index) {
        for (int i = index + 1; i < node->key_count; ++i) {
            node->keys[i - 1] = node->keys[i];
        }
        node->key_count--;
    }


    // Helper function to remove a key from a non-leaf node
    void remove_from_non_leaf(BTreeNode *node, int index) {
        int key = node->keys[index];


        if (node->child_pointers[index]->key_count >= MAX_KEYS / 2 + 1) {
            int predecessor = get_predecessor(node->child_pointers[index]);
            node->keys[index] = predecessor;
            remove(node->child_pointers[index], predecessor);
        } else if (node->child_pointers[index + 1]->key_count >= MAX_KEYS / 2 + 1) {
            int successor = get_successor(node->child_pointers[index + 1]);
            node->keys[index] = successor;
            remove(node->child_pointers[index + 1], successor);
        } else {
            merge(node, index);
            remove(node->child_pointers[index], key);
        }
    }


    // Helper function to merge two nodes
    void merge(BTreeNode *node, int index) {
        BTreeNode *child = node->child_pointers[index];
        BTreeNode *sibling = node->child_pointers[index + 1];


        child->keys[MAX_KEYS / 2] = node->keys[index];


        for (int i = 0; i < sibling->key_count; ++i) {
            child->keys[MAX_KEYS / 2 + 1 + i] = sibling->keys[i];
        }


        for (int i = 0; i <= sibling->key_count; ++i) {
            child->child_pointers[MAX_KEYS / 2 + 1 + i] = sibling->child_pointers[i];
        }


        child->key_count = MAX_KEYS;


        for (int i = index + 1; i < node->key_count; ++i) {
            node->keys[i - 1] = node->keys[i];
        }


        for (int i = index + 2; i <= node->key_count; ++i) {
            node->child_pointers[i - 1] = node->child_pointers[i];
        }


        node->key_count--;


        delete sibling;
    }


    // Function to remove a key from the B-tree
    void remove(int key) {
        remove(root, key);


        if (root->key_count == 0) {
            BTreeNode *temp = root;
            root = root->child_pointers[0];
            delete temp;
        }
    }


    // Recursive function to remove a key from a node
    void remove(BTreeNode *node, int key) {
        int index = 0;


        while (index < node->key_count && key > node->keys[index]) {
            index++;
        }


        if (node->is_leaf) {
            if (index < node->key_count && key == node->keys[index]) {
                remove_from_leaf(node, index);
            }
        } else {
            if (index < node->key_count && key == node->keys[index]) {
                remove_from_non_leaf(node, index);
            } else {
                bool is_last_child = (index == node->key_count);


                if (node->child_pointers[index]->key_count < MAX_KEYS / 2 + 1) {
                    fill(node, index);
                }


                if (is_last_child && index > node->key_count) {
                    remove(node->child_pointers[index - 1], key);
                } else {
                    remove(node->child_pointers[index], key);
                }
            }
        }
    }


    // Helper function to fill the child node with keys from the right sibling
    void fill(BTreeNode *node, int index) {
        if (index != 0 && node->child_pointers[index - 1]->key_count >= MAX_KEYS / 2 + 1) {
            borrow_from_prev(node, index);
        } else if (index != node->key_count && node->child_pointers[index + 1]->key_count >= MAX_KEYS / 2 + 1) {
            borrow_from_next(node, index);
        } else {
            if (index != node->key_count) {
                merge(node, index);
            } else {
                merge(node, index - 1);
            }
        }
    }


    // Helper function to borrow a key from the previous child
    void borrow_from_prev(BTreeNode *node, int index) {
        BTreeNode *child = node->child_pointers[index];
        BTreeNode *sibling = node->child_pointers[index - 1];


        for (int i = child->key_count - 1; i >= 0; --i) {
            child->keys[i + 1] = child->keys[i];
        }


        if (!child->is_leaf) {
            for (int i = child->key_count; i >= 0; --i) {
                child->child_pointers[i + 1] = child->child_pointers[i];
            }
        }


        child->keys[0] = node->keys[index - 1];


        if (!child->is_leaf) {
            child->child_pointers[0] = sibling->child_pointers[sibling->key_count];
        }


        node->keys[index - 1] = sibling->keys[sibling->key_count - 1];


        child->key_count++;
        sibling->key_count--;
    }


    // Helper function to borrow a key from the next child
    void borrow_from_next(BTreeNode *node, int index) {
        BTreeNode *child = node->child_pointers[index];
        BTreeNode *sibling = node->child_pointers[index + 1];


        child->keys[child->key_count] = node->keys[index];


        if (!child->is_leaf) {
            child->child_pointers[child->key_count + 1] = sibling->child_pointers[0];
        }


        node->keys[index] = sibling->keys[0];


        for (int i = 1; i < sibling->key_count; ++i) {
            sibling->keys[i - 1] = sibling->keys[i];
        }


        if (!sibling->is_leaf) {
            for (int i = 1; i <= sibling->key_count; ++i) {
                sibling->child_pointers[i - 1] = sibling->child_pointers[i];
            }
        }


        child->key_count++;
        sibling->key_count--;
    }
};


int main() {
    int index, num_elements, input_key, key_to_delete;
    char continue_deleting;


    cout << "Enter the number of elements to be inserted: ";
    cin >> num_elements;


    BTree btree;


    for (index = 0; index < num_elements; index++) {
        cout << "Enter element #" << index << ": ";
        cin >> input_key;
        btree.insert(input_key);
    }


    cout << "Constructed B-Tree\n";
    btree.traverse(btree.getRoot());


    do {
        cout << "Enter the key to delete: ";
        cin >> key_to_delete;


        btree.remove(key_to_delete);


        cout << "Updated B-Tree after deletion\n";
        btree.traverse(btree.getRoot());


        cout << "Do you want to continue deleting keys? (y/n): ";
        cin >> continue_deleting;
    } while (continue_deleting == 'y' || continue_deleting == 'Y');


    return 0;
}

