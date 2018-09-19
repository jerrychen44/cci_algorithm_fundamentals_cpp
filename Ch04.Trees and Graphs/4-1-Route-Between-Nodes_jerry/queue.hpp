#ifndef QUEUE_H
#define QUEUE_H
#include "node.hpp"


class myQueue{

public:
    myQueue();
    ~myQueue();


    void add(int data);
    int remove();

    int peekhead();
    //int peektail();

    void printQ();

    bool isEmpty();



    int cur_queuesize;
    Node *head;
    Node *tail;

};




#endif