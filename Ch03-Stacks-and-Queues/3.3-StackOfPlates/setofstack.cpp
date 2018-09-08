#include "setofstack.hpp"
#include <iostream>

Setofstack::Setofstack(int capacity){
    this->cur_sof_stackhead = nullptr;
    this->cur_sof_stacknum = 0;
    this->capacity = capacity;

}

/*
Setofstack::~Setofstack(){

    Stack *discardstack;
    while(cur_sof_stackhead  !=nullptr){
        discardstack = cur_sof_stackhead;
        cur_sof_stackhead = cur_sof_stackhead->nextStack;
        delete discardstack;
    }
}
*/
bool Setofstack::isEmpty()
{
  return (cur_sof_stacknum == 0 || cur_sof_stackhead == nullptr);
}

void Setofstack::push(int value){
    std::cout << "push"<<std::endl;
    std::cout << "  push value = " << value << std::endl;


    if (isEmpty()){
        std::cout << "  Setofstack is Empty " << std::endl;
        cur_sof_stackhead = new Stack();
        cur_sof_stackhead -> push(value);
        //cur_sof_stackhead->cur_stacksize ++;
        cur_sof_stacknum++;

    }else if(cur_sof_stackhead->cur_stacksize < capacity ){
        std::cout << "  keep push " << std::endl;
        cur_sof_stackhead -> push(value);
        //cur_sof_stackhead->cur_stacksize++;

    }else{
        std::cout << "  create new stack, push " << std::endl;

        Stack *tmp = cur_sof_stackhead;
        cur_sof_stackhead = new Stack();
        cur_sof_stackhead-> nextStack = tmp;
        cur_sof_stackhead -> push(value);
        //cur_sof_stackhead->cur_stacksize ++;
        cur_sof_stacknum++;
        //push_times=0;
    }

    std::cout << "  cur_sof_stacknum = " << cur_sof_stacknum << std::endl;
    std::cout << "  cur_stacksize " << cur_sof_stackhead->cur_stacksize << std::endl;
}


int Setofstack::pop()
{
  std::cout << "pop"<<std::endl;

  if(cur_sof_stacknum == 0 || cur_sof_stackhead == nullptr){
    std::cout << "Setofstack is empty"<< std::endl;

    return -1;
  }


  int popresult;

  if(cur_sof_stackhead->cur_stacksize >0){

    popresult = cur_sof_stackhead -> pop();

    std::cout << "    cur_stacksize " << cur_sof_stackhead->cur_stacksize << std::endl;
    std::cout << "    cur_sof_stacknum = " << cur_sof_stacknum << std::endl;
  }

  if (cur_sof_stackhead->cur_stacksize == 0){
    Stack *discard = cur_sof_stackhead;
    cur_sof_stackhead = cur_sof_stackhead->nextStack;
    delete discard;
    cur_sof_stacknum--;


  }


  return popresult;


}






