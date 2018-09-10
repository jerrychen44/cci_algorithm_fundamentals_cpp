#include "SetOfStacks.hpp"
#include <iostream>
#include "stacknode.hpp"

SetOfStacks::SetOfStacks(int capcity){
    this->capcity = capcity;
}


SetOfStacks::~SetOfStacks(){

    for(int i=0; i < setofstacks.size(); ++i)
        delete setofstacks[i];
}



Stack* SetOfStacks::getLastStack(){

    Stack *last;
    std::cout << "setofstacks.size() "<< setofstacks.size() << std::endl;

    if(setofstacks.size() > 0){
        std::cout << "setofstacks.size() > 0"<<  std::endl;

        last = setofstacks[setofstacks.size()-1];

    }else{
        std::cout << "setofstacks.size() = 0, new Stack()"<<  std::endl;

        last = new Stack();
        setofstacks.push_back(last);
    }

    return last;
}

void SetOfStacks::push(int v){
    std::cout <<std::endl;

    Stack *last = getLastStack();

    std::cout << "last.cur_stacksize " << last->cur_stacksize << std::endl;

    if( last->cur_stacksize < capcity){
        std::cout << "directly push " << v << std::endl;
        last->push(v);
    }else{
        std::cout << "create new stack and push " << v << std::endl;
        Stack *newstack  = new Stack();
        newstack->push(v);
        setofstacks.push_back(newstack);

    }

}


int SetOfStacks::pop(){

    std::cout <<std::endl;
    int rst;
    std::cout << "setofstacks.size() "<< setofstacks.size() << std::endl;

    if(setofstacks.size() <= 0){
        std::cout << "setofstacks is empty" << std::endl;
        return -1;
    }

    Stack *last = getLastStack();
    std::cout << "last.cur_stacksize " << last->cur_stacksize << std::endl;
    rst = last->pop();
    std::cout << "last.cur_stacksize " << last->cur_stacksize << std::endl;

    if(last->cur_stacksize == 0){
        setofstacks.pop_back();
        std::cout << "remove stack " << std::endl;

    }
    std::cout << "setofstacks.size() "<< setofstacks.size() << std::endl;


    return rst;
}

void SetOfStacks::printSet(){

    std::cout << std::endl;

    for (int i =0; i < setofstacks.size(); ++i){
        StackNode *tmp = setofstacks[i]->stackhead;
        for (int j=0; j < setofstacks[i]->cur_stacksize; ++j){

            std::cout << tmp->data << ", " ;
            tmp = tmp->nextnode;
        }
        std::cout << std::endl;

    }

}




int SetOfStacks::popAt(int pop_idx){

    std::cout <<std::endl;
    int rst=-1;
    if(pop_idx <0 || setofstacks.size() == 0){
        return -1;
    }

    //handle the last stack
    if(pop_idx == setofstacks.size()-1){

        rst = pop();

    }else{

        rst = setofstacks[pop_idx]->pop();
        //
        for (int i = pop_idx; i < setofstacks.size()-1; ++ i ){
            int rstbotm;
            std::cout << "handle stack i = "<< i  <<std::endl;

            rstbotm = setofstacks[i + 1]->popfrombotm();
            setofstacks[i]->push(rstbotm);
        }

    }



    Stack *last = getLastStack();
    if(last->cur_stacksize == 0){
        setofstacks.pop_back();
        std::cout << "remove stack " << std::endl;

    }

    std::cout << "popAt idx: "<< pop_idx<< ", value: " << rst << std::endl;
    return rst;
}




