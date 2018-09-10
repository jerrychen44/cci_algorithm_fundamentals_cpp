#include <iostream>
#include "node.hpp"

Node::Node(int data, Node *inputnode){
    this->data = data;
    this->prenode = inputnode;
}