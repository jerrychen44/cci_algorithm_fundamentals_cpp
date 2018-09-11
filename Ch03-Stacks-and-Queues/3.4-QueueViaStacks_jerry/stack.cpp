#include <iostream>
#include "stack.hpp"
#include "node.hpp"



Stack::Stack(){

    this->nodehead = nullptr;
    this->cur_stacksize = 0;
}

Stack::~Stack(){

    while(nodehead->prenode !=nullptr){
        Node *discard = nodehead;
        nodehead = nodehead ->prenode;
        delete discard;
    }

}


void Stack::push(int data){


    if (cur_stacksize == 0){

        nodehead = new Node(data,nullptr);
    }else{
        nodehead = new Node(data,nodehead);
    }


    cur_stacksize++;

}

int Stack::pop(){

    if(nodehead == nullptr || cur_stacksize ==0){
        std::cout << "stack is empty"<< std::endl;
        return -1;
    }

    int rst;
    rst = nodehead->data;
    Node *discard;
    discard = nodehead;
    nodehead = nodehead->prenode;
    delete discard;
    cur_stacksize--;
    return rst;

}






