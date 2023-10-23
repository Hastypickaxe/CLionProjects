//
// Created by justd on 10/10/2023.
//

#ifndef CS8LAB11_CIRCULAR_QUEUE_H
#define CS8LAB11_CIRCULAR_QUEUE_H
#include <iostream>
#include <cassert>

using namespace std;

template <class Item>
class queue
{
public:
// TYPEDEFS and MEMBER CONSTANTS -- See Appendix E if this fails to compile.
    typedef std::size_t size_type;
    typedef Item value_type;
    static const size_type CAPACITY = 15;
// CONSTRUCTOR
    queue();
// MODIFICATION MEMBER FUNCTIONS
    void pop();
    void push(const Item& entry);
// CONSTANT MEMBER FUNCTIONS
    bool empty() const { return (count == 0); }
    Item front() const;
    size_type size() const { return count; }
private:
    Item data[CAPACITY]; // Circular array
    size_type first; // Index of item at front of the queue
    size_type last; // Index of item at rear of the queue
    size_type count; // Total number of items in the queue
// HELPER MEMBER FUNCTION
    size_type next_index(size_type i) const { return (i + 1) % CAPACITY; }
};
template <class Item>
const typename queue<Item>::size_type queue<Item>::CAPACITY;
template <class Item>
queue<Item>::queue()
{
    count = 0;
    first = 0;
    last = CAPACITY - 1;
}
template <class Item>
Item queue<Item>::front() const
// Library facilities used: cassert
{
    assert(!empty());
    return data[first];
}
template <class Item>
void queue<Item>::pop()
// Library facilities used: cassert
{
    assert(!empty());
    first = next_index(first);
    --count;
}
template <class Item>
void queue<Item>::push(const Item& entry)
// Library facilities used: cassert
{
    assert(size() < CAPACITY);
    last = next_index(last);
    data[last] = entry;
    ++count;
}

#endif //CS8LAB11_CIRCULAR_QUEUE_H
