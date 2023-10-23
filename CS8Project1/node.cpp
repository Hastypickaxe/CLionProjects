//
// Created by justd on 9/20/2023.
//

#include "node.h"

node::node() : node(Student()) {

}

const Student node::getData() const {
    return data;
}

void node::setData(const Student &data) {
    node::data = data;
}

node *node::getLink() const {
    return link;
}

void node::setLink(node *link) {
    node::link = link;
}
