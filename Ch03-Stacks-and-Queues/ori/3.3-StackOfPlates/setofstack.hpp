#ifndef SETOFSTACK_H
#define SETOFSTACK_H
#include "stack.hpp"



class Setofstack
{
    public:

        Setofstack(int capacity);
        //~Setofstack();

        int pop();
        void push(int value);

        bool isEmpty();

    //private:
        int cur_sof_stacknum;
        Stack *cur_sof_stackhead;

        int capacity;
        int push_times;
};
#endif // SETOFSTACK_H
