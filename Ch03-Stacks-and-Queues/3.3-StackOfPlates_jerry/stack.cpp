#include "stack.hpp"

#include <iostream>

Stack::Stack(){
    this->stackhead = nullptr;
    this->cur_stacksize = 0;
}


Stack::~Stack(){

    StackNode *discard;
    while(stackhead !=nullptr){
        discard = stackhead;
        stackhead = stackhead->nextnode;
        delete discard;
    }
}


void Stack::push(int item)
{
  if(isEmpty())
  {
    stackhead = new StackNode(item, nullptr);

  }else
  {
    stackhead = new StackNode(item, stackhead);
  }

  cur_stacksize++;
}

int Stack::pop()
{
  if(cur_stacksize == 0 || stackhead == nullptr)
    return  -1;

  int rest;
  rest = stackhead->data;
  std::cout << "    pop " << stackhead->data<<std::endl;
  StackNode *discard = stackhead;
  stackhead = stackhead->nextnode;
  delete discard;
  cur_stacksize--;

  return rest;
}

bool Stack::isEmpty()
{
  return (cur_stacksize == 0 || stackhead == nullptr);
}

int Stack::getSize()
{
  return cur_stacksize;
}