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

    // Check if the value already exists in the node
    while (i >= 0 && value == node->data[i]) {
        cout << "Key " << value << " already exists in the B-tree. Skipping insertion.\n";
        return;
    }

    if (node->leaf) {
        while (i >= 0 && value < node->data[i]) {
            node->data[i + 1] = node->data[i];
            --i;
        }

        node->data[i + 1] = value;
        ++node->count;
    } else {
        while (i >= 0 && value < node->data[i]) {
            --i;
        }

        ++i;

        if (node->childPtr[i]->count == MAX) {
            splitChild(node, i, node->childPtr[i]);

            if (value > node->data[i])
                ++i;
        }

        insertNonFull(node->childPtr[i], value);
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
            splitChild(newRoot, 0, root->childPtr[0]);
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

            std::cout << node->data[i] << std::endl;
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
