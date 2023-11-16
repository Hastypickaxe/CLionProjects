#include <iostream>

using namespace std;

const int MAX = 4;

class BTreeNode {
private:
    int data[MAX]; // static array
    BTreeNode* childPtr[MAX + 1];
    bool leaf;
    int count; // number of data in a node

public:
    BTreeNode() : leaf(true), count(0) {
        for (int i = 0; i <= MAX; ++i) {
            childPtr[i] = nullptr;
        }
    }

    int getCount() const {
        return count;
    }

    int getData(int index) const {
        return data[index];
    }

    bool isLeaf() const {
        return leaf;
    }

    BTreeNode* getChildPtr(int index) const {
        return childPtr[index];
    }


    friend class BTree;
};

class BTree {
private:
    BTreeNode* root;

    bool existsInNode(BTreeNode* node, int value);
    int findKeyPosition(BTreeNode* node, int key);

    void insertNonFull(BTreeNode* node, int key);
    bool searchKey(BTreeNode* node, int key);

public:
    BTree() : root(nullptr) {}

    void insert(int key);
    void constructTree();
    void display(BTreeNode* root, int level);
    void splitChild(BTreeNode* parent, int index, BTreeNode* child);

    BTreeNode* getRoot() const {
        return root;
    }

    void display() {
        display(getRoot(), 0);
    }

    bool search(int key);
};

bool BTree::existsInNode(BTreeNode* node, int value) {
    for (int i = 0; i < node->count; ++i) {
        if (node->data[i] == value) {
            return true; // Duplicate found
        }
    }
    return false; // No duplicate found
}

int BTree::findKeyPosition(BTreeNode* node, int key) {
    int i = 0;
    while (i < node->count && key > node->data[i]) {
        ++i;
    }
    return i;
}

void BTree::splitChild(BTreeNode* parent, int index, BTreeNode* child) {
    BTreeNode* newChild = new BTreeNode();
    newChild->leaf = child->leaf;
    newChild->count = MAX / 2;

    for (int j = 0; j < MAX / 2; ++j) {
        newChild->data[j] = child->data[j + MAX / 2];
    }

    if (!child->leaf) {
        for (int j = 0; j <= MAX / 2; ++j) {
            newChild->childPtr[j] = child->childPtr[j + MAX / 2];
        }
    }

    child->count = MAX / 2;

    // Check if the middle element already exists in the parent
    bool middleElementExists = false;
    for (int j = 0; j < parent->count; ++j) {
        if (parent->data[j] == child->data[MAX / 2]) {
            middleElementExists = true;
            break;
        }
    }

    // Insert the middle element into the parent only if it doesn't already exist
    if (!middleElementExists) {
        for (int j = parent->count; j > index; --j) {
            parent->childPtr[j + 1] = parent->childPtr[j];
        }

        parent->childPtr[index + 1] = newChild;

        for (int j = parent->count - 1; j >= index; --j) {
            parent->data[j + 1] = parent->data[j];
        }

        parent->data[index] = child->data[MAX / 2];
        ++parent->count;
    }
}


void BTree::insertNonFull(BTreeNode* node, int value) {
    int i = node->count - 1;

    parent->data[index] = child->data[MAX / 2 - 1];
    ++parent->count;
}

void BTree::insertNonFull(BTreeNode* node, int key) {
    int index = findKeyPosition(node, key);


    // Check if the value already exists in the node
    while (i >= 0 && value == node->data[i]) {
        cout << "Key " << value << " already exists in the B-tree. Skipping insertion.\n";
        return;
    }

    if (node->leaf) {
        // Check for duplicates in the current node
        if (existsInNode(node, key)) {
            return; // Duplicate, do nothing
        }

        // Shift elements to make space for the new key
        for (int i = node->count - 1; i >= index; --i) {
            node->data[i + 1] = node->data[i];
        }

        // Insert the new key
        node->data[index] = key;
        ++node->count;
    } else {
        // Check for duplicates in the current node before traversing
        if (index < node->count && key == node->data[index]) {
            return; // Duplicate, do nothing
        }

        // Ensure we don't go beyond the maximum count
        if (node->childPtr[index]->count == MAX) {
            splitChild(node, index, node->childPtr[index]);

            // Determine which of the two children to descend to
            if (key > node->data[index]) {
                ++index;
            }
        }

        insertNonFull(node->childPtr[index], key);
    }
}


bool BTree::search(int key) {
    return searchKey(root, key);
}

bool BTree::searchKey(BTreeNode* node, int key) {
    int i = 0;
    while (i < node->count && key > node->data[i]) {
        i++;
    }

    if (i < node->count && key == node->data[i]) {
        return true;
    } else if (node->leaf) {
        return false;
    } else {
        return searchKey(node->childPtr[i], key);
    }
}

void BTree::insert(int key) {
    if (root == nullptr) {
        // If the tree is empty, create a new root with the key
        root = new BTreeNode();
        root->data[0] = key;
        root->count = 1;
    } else {
        // Check if the key already exists in the tree
        if (search(key)) {
            cout << "Key " << key << " already exists in the B-tree. Skipping insertion.\n";
            return;
        }

        // If the root is full, split it and create a new root
        if (root->count == MAX) {
            BTreeNode* newRoot = new BTreeNode();
            newRoot->childPtr[0] = root;
            root = newRoot;
            splitChild(newRoot, 0, newRoot->childPtr[0]);
            insertNonFull(newRoot, key);
        } else {
            // If the root is not full, insert the key
            insertNonFull(root, key);
        }
    }
}

void BTree::constructTree() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int element;
        cout << "Enter the element " << i + 1 << ": ";
        cin >> element;
        insert(element);
    }
}

void BTree::display(BTreeNode* node, int level) {
    if (node != nullptr) {
        for (int i = node->count - 1; i >= 0; --i) {
            display(node->childPtr[i + 1], level + 1);

            for (int j = 0; j < level; ++j)
                std::cout << "    ";

            std::cout << node->data[i] << " ";
        }
        display(node->childPtr[0], level + 1);
    }
}

int main() {
    BTree btree;
    btree.constructTree();

    cout << "\nConstructed B-tree : \n";
    btree.display();

    return 0;
}
