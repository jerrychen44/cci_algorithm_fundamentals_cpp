#ifndef J_STACKNODE_H
#define J_STACKNODE_H

class Stack;

class StackNode
{
public:
  //we set Stack class as our (StackNode) friend,
  //which means , stack class can access the private data in StackNode
  friend class Stack;
  StackNode(int data, StackNode *next);

private:
  int data;
  StackNode *next;
  StackNode *minimum;
};

#endif // J_STACKNODE_H
