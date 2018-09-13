#include <iostream>
#include "node.hpp"

Node::Node(int data){
    this->data = data;
    this->nextnode = nullptr;
    this->timestampNode =-1;
}