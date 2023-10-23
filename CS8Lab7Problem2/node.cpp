//
// Created by justd on 9/19/2023.
//

#include "node.h"

node::node(node::value_type dataField, node *linkField) : data_field(dataField), link_field(linkField) {}

node::value_type node::getDataField() const {
    return data_field;
}

void node::setDataField(node::value_type dataField) {
    data_field = dataField;
}

node *node::getLinkField() const {
    return link_field;
}

void node::setLinkField(node *linkField) {
    link_field = linkField;
}
