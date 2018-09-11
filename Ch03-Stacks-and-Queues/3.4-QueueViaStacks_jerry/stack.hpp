#ifndef STACK_H
#define STACK_H

#include "node.hpp"


class Stack{


public:
    Stack();
    ~Stack();


    void push(int data);
    int pop();


    int cur_stacksize;
    Node *nodehead;


};



#endif