
#include "node.h"
using namespace CodingTest1;
template <class Item>
class node_iterator {
public:
    node_iterator(node<Item>* initial = NULL)
    {
        current = initial;
    }
    Item& operator *() const
    {
        return current->data();
    }
    node_iterator& operator ++() { // Prefix ++
        current = current->link();
        return *this;
    }
    node_iterator operator ++(int) { // Postfix ++
        node_iterator original(current);
        current = current->link();
        return original;
    }
    bool operator ==(const node_iterator other) const
    {
        return current == other.current;
    }
    bool operator !=(const node_iterator other) const
    {
        return current != other.current;
    }
private:
    node<Item>* current;
};

