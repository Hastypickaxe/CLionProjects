#include "node2.h"
using namespace template_bag4;
template <class Item>
class node_iterator {
public:
    node_iterator(node<Item>* initial = NULL)
    { current = initial; }
    Item& operator *() const
    { return current->data(); }
    node_iterator& operator ++() { // Prefix ++
        current = current->getNext();
        return *this;
    }
    node_iterator operator ++(int) { // Postfix ++
        node_iterator original(current);
        current = current->getNext();
        return original;
    }

    node_iterator& operator --() { // Prefix --
        current = current->getPrev();
        return *this;
    }
    node_iterator operator --(int) { // Postfix --
        node_iterator original(current);
        current = current->getPrev();
        return original;
    }

    bool operator ==(const node_iterator other) const
    { return current == other.current; }
    bool operator !=(const node_iterator other) const
    { return current != other.current; }
private:
    node<Item>* current;
};