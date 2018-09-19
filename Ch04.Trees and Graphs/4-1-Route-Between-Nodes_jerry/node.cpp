#include <iostream>
#include "node.hpp"



Node::Node(int data){
    this->data = data;
    this->visiting_state = 0;
    this->nextNode = nullptr;
}