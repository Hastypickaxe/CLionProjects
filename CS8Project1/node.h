//
// Created by justd on 9/20/2023.
//


#ifndef CS8PROJECT1_NODE_H
#define CS8PROJECT1_NODE_H
#include <iostream>
#include <utility>
#include "Student.h"


using namespace std;


class node {
private:
    Student data;
    node* link;
public:
    node();

    node(Student student, node* init_link = NULL) {
        data = student;
        link = init_link;
    }

    const Student getData() const;

    void setData(const Student &data);

    node *getLink() const;

    void setLink(node *link);

    // complete the class

};

#endif //CS8PROJECT1_NODE_H
