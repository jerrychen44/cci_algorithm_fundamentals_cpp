#ifndef J_STACK_H
#define J_STACK_H

#include "j_StackNode.h"
#include <iostream>
#include <cstdlib>
//stack build in linked list
class Stack
{
public:
  Stack();
  virtual ~Stack();
  void push(int item);
  void pop();
  int top() const;
  int getMinimum() const;

  bool isEmpty() const;
  int getSize() const;

private:
  StackNode *head;
  int stackSize;
};

#endif // J_STACK_H
