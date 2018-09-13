#ifndef STACK_H
#define STACK_H

#include "node.hpp"


class Queue{


public:
    Queue();
    ~Queue();

    void add(int data);
    int remove();
    int peek();

    bool isEmpty();
    void printq();


    Node *firstnode;
    Node *lastnode;
    int cur_queuesize;
    int timestampGlobal;


};



#endif