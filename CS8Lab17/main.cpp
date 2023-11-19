#include <iostream>
#include <vector>
#include <algorithm>

class BTreeNode {
public:
    std::vector<int> keys;
    std::vector<BTreeNode*> children;
};

BTreeNode* createNode(int key, BTreeNode* left = nullptr, BTreeNode* right = nullptr) {
    BTreeNode* node = new BTreeNode();
    node->keys.push_back(key);
    node->children.push_back(left);
    node->children.push_back(right);
    return node;
}

BTreeNode* insert(BTreeNode* root, int key);

void displayBTree(const BTreeNode* node, int level = 0);

int main() {
    BTreeNode* root = nullptr;

    int numElements;
    std::cout << "Enter the number of elements: ";
    std::cin >> numElements;

    for (int i = 0; i < numElements; ++i) {
        int element;
        std::cout << "Enter the element " << i + 1 << " : ";
        std::cin >> element;
        root = insert(root, element);
    }

    std::cout << "\nConstructed B-tree:\n";
    displayBTree(root);

    return 0;
}

BTreeNode* insert(BTreeNode* root, int key) {
    if (!root) {
        return createNode(key);
    }

    // Find the child to insert into
    auto it = std::lower_bound(root->keys.begin(), root->keys.end(), key);
    size_t index = std::distance(root->keys.begin(), it);
    BTreeNode* child = root->children[index];

    // Recursively insert into the child
    root->children[index] = insert(child, key);

    // Split if necessary
    if (root->keys.size() == 5) {
        BTreeNode* newRoot = createNode(root->keys[2], createNode(root->keys[0], root->children[0], root->children[1]),
                                        createNode(root->keys[4], root->children[3], root->children[4]));
        root->keys = {root->keys[1], root->keys[3]};
        root->children = {root->children[2], newRoot};
        return root;
    }

    return root;
}

void displayBTree(const BTreeNode* node, int level) {
    if (node) {
        for (int i = 0; i < level; ++i) {
            std::cout << "  ";
        }
        for (int key : node->keys) {
            std::cout << key << " ";
        }
        std::cout << "\n";

        for (const BTreeNode* child : node->children) {
            displayBTree(child, level + 1);
        }
    }
}
