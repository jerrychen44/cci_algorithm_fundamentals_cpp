#include "SetOfStacks.hpp"
#include <iostream>

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






