#ifndef NODE_H
#define NODE_H
#include <cstdlib>

namespace CodingTest1
{
    template <class Item>
    class node
    {
    public:
        node(const Item& init_data = Item(), node* init_link = NULL) {
            data_field = init_data; link_field = init_link;
        }

        Item& data() { return data_field; }
        node* link() { return link_field; }
        void set_data(const Item& new_data) { data_field = new_data; }
        void set_link(node* new_link) { link_field = new_link; }

        const Item& data() const { return data_field; }
        const node* link() const { return link_field; }
    private:
        Item data_field;
        node* link_field;
    };

    template <class Item>
    void list_head_insert(node<Item>*& head_ptr, const Item& entry)
    {
        head_ptr = new node<Item>(entry, head_ptr);
    }

    template <class Item>
    void list_insert(node<Item>* previous_ptr, const Item& entry)
    {
        node<Item>* insert_ptr;

        insert_ptr = new node<Item>(entry, previous_ptr->link());
        previous_ptr->set_link(insert_ptr);
    }
}
#endif

