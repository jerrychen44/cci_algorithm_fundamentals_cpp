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

int Stack::popfrombotm(){

  if(cur_stacksize == 0 || stackhead == nullptr)
    return  -1;

  int rest;

  StackNode *tmp = stackhead;
  //fist move
  int predata = tmp->data;
  //tmp = tmp->nextnode;

  for (int i = 0; i < cur_stacksize ; ++i){

    //for the last node in stack
    //we return the data directly
    if(tmp->nextnode == nullptr){
      rest = tmp->data;
      break;
    }

    //move
    std::cout << "move B tmp->data " << tmp->data <<std::endl;

    tmp = tmp->nextnode;
    std::cout << "move A tmp->data " << tmp->data <<std::endl;

    int curdata = tmp->data;


    tmp->data = predata;
    std::cout << "move A SET tmp->data " << tmp->data <<std::endl;

    std::cout << "predata " << predata <<std::endl;
    std::cout << "curdata " << curdata <<std::endl;

    predata = curdata;
    rest = curdata;

    // to stop the tmp shift
    if(tmp->nextnode == nullptr)
      break;

  }

  StackNode *dic = stackhead;
  stackhead = stackhead ->nextnode;
  delete dic;
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