#include <iostream>
using namespace std;

const int MAX_KEYS = 4;

// Class representing a node in the B-tree
class BTreeNode {
public:
    int *keys;                    // Array to store keys
    BTreeNode **child_pointers;   // Array to store pointers to child nodes
    bool is_leaf;                 // Flag to indicate if the node is a leaf
    int key_count;                // Number of keys currently in the node

    BTreeNode() {
        keys = new int[MAX_KEYS];                    // Allocate memory for keys
        child_pointers = new BTreeNode*[MAX_KEYS + 1];  // Allocate memory for child pointers
        is_leaf = true;                              // Initialize as leaf node
        key_count = 0;                               // Initialize key count

        for (int i = 0; i < MAX_KEYS + 1; i++) {
            child_pointers[i] = nullptr;            // Initialize child pointers to null
        }
    }

    ~BTreeNode() {
        delete[] keys;                               // Free memory for keys
        delete[] child_pointers;                     // Free memory for child pointers
    }
};

// Class representing the B-tree itself
class BTree {
private:
    BTreeNode *root;          // Pointer to the root node of the tree
    BTreeNode *new_node;      // Pointer to a new node during node splitting
    BTreeNode *current_node;  // Pointer to the current node during tree traversal

public:
    BTree() : root(nullptr), new_node(nullptr), current_node(nullptr) {}

    // Function to get the root of the tree
    BTreeNode* getRoot() {
        return root;
    }

    // Destructor to delete the entire tree
    ~BTree() {
        delete_tree(root);
    }

    // Recursive function to delete the tree
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

    // Function to initialize a new node
    BTreeNode *initialize_node() {
        new_node = new BTreeNode();
        return new_node;
    }

    // Function to traverse the tree and print its contents
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

    // Function to sort an array of keys
    void sort(int *arr, int n) {
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (arr[i] > arr[j]) {
                    swap(arr[i], arr[j]);
                }
            }
        }
    }

    // Function to split a child node during insertion
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
            new_node->child_pointers[new_node->key_count] = temp_node;
            new_node->child_pointers[new_node->key_count + 1] = current_node;
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

            current_node->key_count++;
            for (j = current_node->key_count - 1; j > index; j--) {
                current_node->keys[j] = current_node->keys[j - 1];
                current_node->child_pointers[j + 1] = current_node->child_pointers[j];
            }

            current_node->keys[index] = mid;
            current_node->child_pointers[index + 1] = temp_node;
        }

        return mid;
    }


    // Function to insert a key into the B-tree
    void insert(int key) {
        int index, temp;
        current_node = root;

        if (current_node == nullptr) {
            root = initialize_node();
            current_node = root;
        } else {
            if (current_node->is_leaf && current_node->key_count == MAX_KEYS) {
                temp = split_child(current_node, -1);

                // Create a new root
                BTreeNode* new_root = initialize_node();
                new_root->is_leaf = false;
                new_root->child_pointers[0] = root;
                new_root->keys[0] = temp;
                new_root->child_pointers[1] = new_node;
                new_root->key_count = 1;
                root = new_root;

                current_node = root->child_pointers[0];
            }

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

        current_node->keys[current_node->key_count] = key;
        current_node->key_count++;
        sort(current_node->keys, current_node->key_count);
    }
};

// Main function for testing the B-tree
int main() {
    int index, num_elements, input_key;
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

    return 0;
}