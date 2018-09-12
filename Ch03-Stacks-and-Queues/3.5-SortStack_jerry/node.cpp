#include <iostream>
#include "node.hpp"

Node::Node(int data, Node *prenode){
    this->data = data;
    this->prenode = prenode;
}