//
// Created by justd on 9/19/2023.
//

#ifndef CS8LAB7PROBLEM2_NODE_H
#define CS8LAB7PROBLEM2_NODE_H
#include <iostream>

using namespace std;

class node {
public:
    typedef int value_type;
    node(const value_type& init_data = value_type(), node* init_link = NULL)
    {
        data_field = init_data; link_field = init_link;
    }

    node(value_type dataField, node *linkField);

    void set_data(const value_type& new_data) { data_field = new_data; }
    void set_link(node* new_link) { link_field = new_link; }
    value_type data() const { return data_field; }
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

#endif //CS8LAB7PROBLEM2_NODE_H
