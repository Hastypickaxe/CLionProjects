//
// Created by justd on 9/18/2023.
//

#ifndef UNTITLED16_NODE_H
#define UNTITLED16_NODE_H
#include <iostream>

using namespace std;

class node {
public:
    typedef double value_type; // TYPEDEF

// CONSTRUCTOR
    node(const value_type& init_data = value_type(), node* init_link = NULL)
    { data_field = init_data; link_field = init_link; }

// Member functions to set the data and link fields:
    void set_data(const value_type& new_data) { data_field = new_data; }
    void set_link(node* new_link) { link_field = new_link; }

// Constant member function to retrieve the current data:
    value_type data() const { return data_field; }

// Two slightly different member functions to retrieve the current link:
    const node* link() const { return link_field; }
    node* link() { return link_field; }

    value_type getDataField() const;

    void setDataField(value_type dataField);

    node *getLinkField() const;

    void setLinkField(node *linkField);

private:
    value_type data_field;
    node* link_field;
};


#endif //UNTITLED16_NODE_H
