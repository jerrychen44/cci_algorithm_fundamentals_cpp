#ifndef STACK_H
#define STACK_H

#include "node.hpp"


class Queue{


public:

    Queue(int *timestampGlobal);
    ~Queue();

    void add(int data);
    int remove();
    int peek();
    int peektimestamp();

    bool isEmpty();
    void printq();


    Node *firstnode;
    Node *lastnode;
    int cur_queuesize;
    int *timestampGlobal;


};



#endif