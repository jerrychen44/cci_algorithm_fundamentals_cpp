#ifndef STACK_H
#define STACK_H

#include "stacknode.hpp"

class Stack
{
    public:
        Stack();
        ~Stack();

        int pop();
        void push(int value);
        int peek_top();

        bool isEmpty();
        bool isFull();

        int getSize();

        //friend class Setofstack;

    //private:
        int cur_stacksize;
        StackNode *stackhead;
        Stack *nextStack;


};
#endif // STACK_H
