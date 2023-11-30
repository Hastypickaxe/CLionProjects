//
// Created by justd on 11/13/2023.
//

#ifndef NODE2_H
#define NODE2_H
#include <cstdlib> // Provides NULL and size_t
#include <cassert>

using namespace std;

namespace template_bag4
{
    template <class Item>
    class node
    {
    public:
        node(const Item& init_data = Item(), node* init_link = NULL, node* init_prev = NULL) {
            data_field = init_data;
            next = init_link;
            prev = init_prev;
        }
        Item& data() { return data_field; }
        node* getNext() { return next; }
        node* getPrev() { return prev; }
        void set_data(const Item& new_data) { data_field = new_data; }
        void setNext(node* new_link) { next = new_link; }
        void setPrev(node* new_link) { prev = new_link; }
        const Item& data() const { return data_field; }
        const node* getNext() const { return next; }
        const node* getPrev() const { return prev; }
    private:
        Item data_field;
        node* next;
        node* prev;
    };

    template <class Item>
    void list_clear(node<Item>*& head_ptr);
    template <class Item>
    void list_copy (const node<Item>* source_ptr, node<Item>*& head_ptr, node<Item>*& tail_ptr);template <class Item>
    void list_head_insert(node<Item>*& head_ptr, const Item& entry);
    template <class Item>
    void list_head_remove(node<Item>*& head_ptr);
    template <class Item>
    void list_insert(node<Item>* previous_ptr, const Item& entry);
    template <class Item>
    void list_sort_insert(node<Item>*& head_ptr, const Item& entry);
    template <class Item>
    std::size_t list_length(const node<Item>* head_ptr);
    template <class Item>
    node<Item>* list_locate(node<Item>* head_ptr, int position);
    template <class Item>
    void list_remove(node<Item>* previous_ptr);
    template <class Item>
    node<Item>* list_search(node<Item>* head_ptr, const Item& target);
    template <class Item>
    void list_display(node<Item>* head);

    template <class Item>
    void list_clear(node<Item>*& head_ptr) {
        while (head_ptr != NULL)
            list_head_remove(head_ptr);
    }
    template <class Item>
    void list_copy(const node<Item>* source_ptr, node<Item>*& head_ptr, node<Item>*& tail_ptr) {head_ptr = tail_ptr = NULL;
        if (source_ptr == NULL) return;
// Make the head node for the newly created list, and put data in itlist_head_insert(head_ptr, source_ptr->data());
        tail_ptr = head_ptr;
// Copy rest of the nodes one at a time, adding at the tail of new listsource_ptr = source_ptr->getNext();
        while (source_ptr != NULL)
        {
            list_insert(tail_ptr, source_ptr->data());
            tail_ptr = tail_ptr->getNext();
            source_ptr = source_ptr->getNext();
        }
    }

    template <class Item>
    void list_head_insert(node<Item>*& head_ptr, const Item& entry)
    {
        head_ptr = new node<Item>(entry, head_ptr);
    }
    template <class Item>
    void list_head_remove(node<Item>*& head_ptr)
    {
        node<Item>* remove_ptr;
        remove_ptr = head_ptr;
        head_ptr = head_ptr->getNext();
        delete remove_ptr;
    }
    template <class Item>
    void list_insert(node<Item>* previous_ptr, const Item& entry)
    {
        node<Item>* insert_ptr;
        insert_ptr = new node<Item>(entry, previous_ptr->getNext());
        previous_ptr->setNext(insert_ptr);
        insert_ptr->setPrev(previous_ptr);
    }

    template <class Item>
    void list_sort_insert(node<Item>*& head_ptr, const Item& entry)
    {
        node<Item>* newNode;
        newNode = new node<Item>(entry);

        if (head_ptr->data() >= newNode->data()) {
            newNode->setNext(head_ptr);
            newNode->getNext()->setPrev(newNode);
            head_ptr = newNode;
        } else {
            node<Item>* current = head_ptr;

            while (current->getNext() != NULL && current->getNext()->data() < newNode->data()) {
                current = current->getNext();
            }

            newNode->setNext(current->getNext());

            if (current->getNext() != NULL) {
                newNode->getNext()->setPrev(newNode);
            }

            current->setNext(newNode);
            newNode->setPrev(current);
        }
    }

    template <class Item>
    std::size_t list_length(const node<Item>* head_ptr)
    {
        const node<Item>* cursor;
        std::size_t answer;
        answer = 0;
        for (cursor = head_ptr; cursor != NULL; cursor = cursor->getNext())++answer;
        return answer;
    }
    template <class Item>
    node<Item>* list_locate(node<Item>* head_ptr, int position)
    {
        node<Item>* cursor;
        int i;
        assert(0 < position);
        cursor = head_ptr;
        for (i = 1; (i < position) && (cursor != NULL); ++i)
            cursor = cursor->getNext();
        return cursor;
    }

    template <class Item>
    void list_remove(node<Item>* previous_ptr)
    {
        node<Item>* remove_ptr;
        remove_ptr = previous_ptr->getNext();
        previous_ptr->setNext(remove_ptr->getNext());
        if (previous_ptr->getNext() != NULL) {
            previous_ptr->getNext()->setPrev(previous_ptr);
        }
        delete remove_ptr;
    }
    template <class Item>
    node<Item>* list_search(node<Item>* head_ptr, const Item& target)
    {
        node<Item>* cursor;
        for (cursor = head_ptr; cursor != NULL; cursor = cursor->getNext())if (target == cursor->data())
                return cursor;
        return NULL;
    }

    template <class Item>
    void list_display(node<Item>*& head) {
        node<Item>* cursor = head;

        while (cursor != NULL) {
            cout << cursor->data() << "<->";
            cursor = cursor->getNext();
        }

        cout << "NULL" << endl;
    }

#endif //CS8LAB9_NODE2_H
