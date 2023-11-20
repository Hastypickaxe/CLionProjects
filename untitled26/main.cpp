#include <iostream>
using namespace std;

const int MAX = 5;

class BTreeNode {
public:
    int *data;
    BTreeNode **child_ptr;
    bool leaf;
    int n;

    BTreeNode() {
        data = new int[MAX];
        child_ptr = new BTreeNode*[MAX + 1];
        leaf = true;
        n = 0;

        for (int i = 0; i < MAX + 1; i++) {
            child_ptr[i] = nullptr;
        }
    }

    ~BTreeNode() {
        delete[] data;
        delete[] child_ptr;
    }
};

class BTree {
private:
    BTreeNode *root;
    BTreeNode *np;
    BTreeNode *x;

public:
    BTree() : root(nullptr), np(nullptr), x(nullptr) {}

    BTreeNode* getRoot() {
        return root;
    }

    ~BTree() {
        delete_tree(root);
    }

    void delete_tree(BTreeNode *p) {
        if (p) {
            if (!p->leaf) {
                for (int i = 0; i < p->n + 1; i++) {
                    delete_tree(p->child_ptr[i]);
                }
            }
            delete p;
        }
    }

    BTreeNode *init() {
        np = new BTreeNode();
        return np;
    }

    void traverse(BTreeNode *p) {
        cout << endl;

        for (int i = 0; i < p->n; i++) {
            if (!p->leaf) {
                traverse(p->child_ptr[i]);
            }
            cout << " " << p->data[i];
        }

        if (!p->leaf) {
            traverse(p->child_ptr[p->n]);
        }

        cout << endl;
    }

    void sort(int *p, int n) {
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (p[i] > p[j]) {
                    swap(p[i], p[j]);
                }
            }
        }
    }

    int split_child(BTreeNode *x, int i) {
        int j, mid;
        BTreeNode *np1, *np3, *y;
        np3 = init();
        np3->leaf = true;

        if (i == -1) {
            mid = x->data[MAX / 2];
            x->data[MAX / 2] = 0;
            x->n--;

            np1 = init();
            np1->leaf = false;
            x->leaf = true;

            for (j = MAX / 2 + 1; j < MAX; j++) {
                np3->data[j - (MAX / 2 + 1)] = x->data[j];
                np3->child_ptr[j - (MAX / 2 + 1)] = x->child_ptr[j];
                np3->n++;
                x->data[j] = 0;
                x->n--;
            }

            for (j = 0; j < MAX + 1; j++) {
                x->child_ptr[j] = nullptr;
            }

            np1->data[0] = mid;
            np1->child_ptr[np1->n] = x;
            np1->child_ptr[np1->n + 1] = np3;
            np1->n++;
            root = np1;
        } else {
            y = x->child_ptr[i];
            mid = y->data[MAX / 2];
            y->data[MAX / 2] = 0;
            y->n--;

            for (j = MAX / 2 + 1; j < MAX; j++) {
                np3->data[j - (MAX / 2 + 1)] = y->data[j];
                np3->n++;
                y->data[j] = 0;
                y->n--;
            }

            x->child_ptr[i + 1] = y;
            x->child_ptr[i + 1] = np3;
        }

        return mid;
    }

    void insert(int a) {
        int i, temp;
        x = root;

        if (x == nullptr) {
            root = init();
            x = root;
        } else {
            if (x->leaf && x->n == MAX) {
                temp = split_child(x, -1);
                x = root;

                for (i = 0; i < x->n; i++) {
                    if ((a > x->data[i]) && (a < x->data[i + 1])) {
                        i++;
                        break;
                    } else if (a < x->data[0]) {
                        break;
                    } else {
                        continue;
                    }
                }

                x = x->child_ptr[i];
            } else {
                while (!x->leaf) {
                    for (i = 0; i < x->n; i++) {
                        if ((a > x->data[i]) && (a < x->data[i + 1])) {
                            i++;
                            break;
                        } else if (a < x->data[0]) {
                            break;
                        } else {
                            continue;
                        }
                    }

                    if (x->child_ptr[i]->n == MAX) {
                        temp = split_child(x, i);
                        x->data[x->n] = temp;
                        x->n++;
                        continue;
                    } else {
                        x = x->child_ptr[i];
                    }
                }
            }
        }

        x->data[x->n] = a;
        sort(x->data, x->n);
        x->n++;
    }
};

int main() {
    int i, n, t;
    cout << "enter the no of elements to be inserted\n";
    cin >> n;

    BTree btree;

    for (i = 0; i < n; i++) {
        cout << "enter the element\n";
        cin >> t;
        btree.insert(t);
    }

    cout << "traversal of constructed tree\n";
    btree.traverse(btree.getRoot());

    return 0;
}
