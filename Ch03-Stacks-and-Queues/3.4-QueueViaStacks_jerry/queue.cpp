#include <iostream>
#include "stack.hpp"
#include "queue.hpp"



QueueviaStack::QueueviaStack(){
    this->inputstack = new Stack();
    this->outputstack = new Stack();
}

void QueueviaStack::add(int data){
    std::cout << "add: " << data << std::endl;
    inputstack->push(data);
}

int QueueviaStack::remove(){

    if(inputstack->cur_stacksize==0 && outputstack->cur_stacksize ==0){
        std::cout << "Queue is empty" << std::endl;
        return -1;
    }


    if(outputstack->cur_stacksize ==0){
        //pop out the input to outputstack
        while(inputstack->cur_stacksize != 0){
            int tmp = inputstack->pop();
            outputstack->push(tmp);
        }
    }

    int rst = outputstack->pop();
    std::cout << "remove: " << rst << std::endl;
    return rst;
}