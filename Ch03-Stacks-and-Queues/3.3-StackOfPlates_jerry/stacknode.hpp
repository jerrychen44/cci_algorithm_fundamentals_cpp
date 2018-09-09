#ifndef STACKNODE_H
#define STACKNODE_H


class StackNode
{
    public:
        StackNode(int data, StackNode *nextnode);
        friend class Stack;
    //private:
        int data;
        StackNode *nextnode;

};
#endif // STACKNODE_H
