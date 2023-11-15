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

    friend class BTree;
};

class BTree {
private:
    BTreeNode* root;

    void insertNonFull(BTreeNode* node, int key);

public:
    BTree() : root(nullptr) {}

    void insert(int key);
    void constructTree();
    void display(BTreeNode* root, int level);

    BTreeNode* getRoot() const {
        return root;
    }

    void display() {
        display(getRoot(), 0);
    }
};

void BTree::insertNonFull(BTreeNode* node, int key) {
    int i = node->count;

    if (node->leaf) {
        while (i > 0 && key < node->data[i - 1]) {
            node->data[i] = node->data[i - 1];
            i--;
        }

        node->data[i] = key;
        node->count++;
    } else {
        while (i > 0 && key < node->data[i - 1]) {
            i--;
        }

        if (node->childPtr[i]->count == MAX) {
            insertNonFull(node->childPtr[i], key);
        } else {
            for (int j = node->childPtr[i]->count; j > 0; --j) {
                node->childPtr[i]->data[j] = node->childPtr[i]->data[j - 1];
            }

            node->childPtr[i]->data[0] = node->data[i];
            node->childPtr[i]->count++;

            node->data[i] = node->childPtr[i]->data[0];
            node->count++;
        }
    }
}

void BTree::insert(int key) {
    if (root == nullptr) {
        root = new BTreeNode();
        root->data[0] = key;
        root->count = 1;
    } else {
        if (root->count == MAX) {
            BTreeNode* newRoot = new BTreeNode();
            newRoot->childPtr[0] = root;
            root = newRoot;
        }

        insertNonFull(root, key);
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

void BTree::display(BTreeNode* root, int level) {
    if (root != nullptr) {
        for (int i = root->count; i > 0; --i) {
            for (int j = 0; j < level; ++j) {
                cout << "    ";
            }

            cout << root->data[i - 1] << endl;
            display(root->childPtr[i - 1], level + 1);
        }

        display(root->childPtr[MAX], level + 1);
    }
}

int main() {
    BTree btree;
    btree.constructTree();

    cout << "\nConstructed B-tree : \n";
    btree.display();

    return 0;
}
