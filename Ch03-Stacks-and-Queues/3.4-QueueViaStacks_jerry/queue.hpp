#ifndef QUEUE_H
#define QUEUE_H
#include "stack.hpp"

class QueueviaStack{

public:

    QueueviaStack();
    //~Queue();

    void add(int data);
    int remove();


    Stack *inputstack;
    Stack *outputstack;

};


#endif