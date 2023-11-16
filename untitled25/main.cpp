#include <iostream>
using namespace std;

const int MAX = 4;

class BTreeNode
{
private:
    int data[MAX];                   // Static array to store keys
    BTreeNode *childPtr[MAX + 1];    // Pointers to child nodes
    bool leaf;                       // Indicates whether the node is a leaf
    int count;                       // Number of keys in the node

public:
    BTreeNode()
    {
        // Constructor to initialize the node
        for (int i = 0; i <= MAX; i++)
        {
            data[i] = 0;             // Initialize keys to 0
            childPtr[i] = nullptr;   // Initialize child pointers to null
        }
        childPtr[MAX] = nullptr;      // Initialize the last child pointer to null
        leaf = true;                  // By default, a newly created node is a leaf
        count = 0;                    // Initialize the number of keys to 0
    }


    friend class BTree;
};

class BTree
{
private:
    BTreeNode *root;                  // Pointer to the root of the B-tree
    void insertNonFull(BTreeNode *x, int k);  // Helper function for insertion
    void splitChild(BTreeNode *x, int i, BTreeNode *y);  // Helper function for splitting a child
    void printBTree(BTreeNode *root, int depth);

public:
    BTree()
    {
        // Constructor to initialize the B-tree
        root = nullptr;                // Initially, the tree is empty
    }

    void insert(int k);                // Function to insert a key into the B-tree
    void constructBTree();            // Function to construct the B-tree by taking user input
    void printTree();                  // Function to print the entire B-tree
};

void BTree::insert(int k)
{
    // Function to insert a key into the B-tree
    if (root == nullptr)
    {
        // If the tree is empty, create a new root node
        root = new BTreeNode;
        root->data[0] = k;
        root->count = 1;
    }
    else
    {
        if (root->count == MAX)
        {
            // If the root is full, create a new root and split the old root
            BTreeNode *s = new BTreeNode;
            s->childPtr[0] = root;
            splitChild(s, 0, root);
            root = s;
        }
        else
        {
            insertNonFull(root, k);
        }
    }
}

void BTree::insertNonFull(BTreeNode *x, int k)
{
    // Helper function to insert a key into a non-full node
    int i = x->count - 1;

    if (x->leaf)
    {
        // if x is a leaf node, insert k into x
        // this works only when x is not full
        // If the node is a leaf, insert the key in sorted order
        while (i >= 0 && k < x->data[i])
        {
            x->data[i + 1] = x->data[i];
            i--;
        }
        x->data[i + 1] = k;
        x->count++;
    }
    else
    {
        // If the node is not a leaf, find the child to insert into
        while (i >= 0 && k < x->data[i])
        {
            i--;
        }
        i++;
        if (x->childPtr[i]->count == MAX)
        {
            // If the child is full, split it
            splitChild(x, i, x->childPtr[i]);
            if (k > x->data[i])
            {
                i++;
            }
        }
        // Recursively insert into the appropriate child
        insertNonFull(x->childPtr[i], k);
    }
}

void BTree::splitChild(BTreeNode *parent, int index, BTreeNode *child)
{
    // Helper function to split a full child of a node
    BTreeNode *newChild = new BTreeNode;
    newChild->leaf = child->leaf;
    newChild->count = MAX / 2;

    for (int i = 0; i < MAX / 2; i++)
    {
        // Move the second half of keys from child to newChild
        newChild->data[i] = child->data[i + MAX / 2 + 1];
    }

    if (!child->leaf)
    {
        for (int i = 0; i < MAX / 2 + 1; i++)
        {
            // Move the second half of child pointers from child to newChild
            newChild->childPtr[i] = child->childPtr[i + MAX / 2 + 1];
        }
    }

    child->count = MAX / 2;

    for (int i = parent->count; i > index; i--)
    {
        // Adjust child pointers in the parent node
        parent->childPtr[i + 1] = parent->childPtr[i];
    }

    parent->childPtr[index + 1] = newChild;

    for (int i = parent->count - 1; i >= index; i--)
    {
        // Move the median key from child to the parent node
        parent->data[i + 1] = parent->data[i];
    }

    parent->data[index] = child->data[MAX / 2];
    parent->count++;
}

void BTree::constructBTree()
{
    // Function to construct the B-tree by taking user input
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int element;
        cout << "Enter the element " << i + 1 << " : ";
        cin >> element;
        insert(element);
    }
}

void BTree::printBTree(BTreeNode *root, int depth)
{
    if (root == nullptr)
    {
        return;
    }

    for (int i = root->count - 1; i >= 0; i--)
    {
        printBTree(root->childPtr[i + 1], depth + 1);

        for (int j = 0; j < depth; j++)
        {
            cout << "    ";
        }

        cout << root->data[i];
        if (i > 0)
        {
            cout << " ";
        }
        else
        {
            cout << endl;
        }
    }

    printBTree(root->childPtr[0], depth + 1);
}

void BTree::printTree()
{
    // Function to print the entire B-tree
    constructBTree();  // Call constructBTree before printing

    cout << "Constructed B-tree:" << endl;
    printBTree(root, 0);
    cout << endl;
}
int main()
{
    BTree btree;
    btree.printTree();
    return 0;
}
