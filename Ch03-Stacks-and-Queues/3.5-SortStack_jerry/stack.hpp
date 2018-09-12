#ifndef STACK_H
#define STACK_H

#include "node.hpp"


class Stack{


public:
    Stack();
    ~Stack();


    void push(int data);
    int pop();

    bool isEmpty();
    int peek();

    void printStack();


    void sortStack();

    int cur_stacksize;
    Node *nodehead;


};



#endif