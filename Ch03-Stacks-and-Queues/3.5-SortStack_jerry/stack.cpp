#include <iostream>
#include "stack.hpp"
#include "node.hpp"



Stack::Stack(){

    this->nodehead = nullptr;
    this->cur_stacksize = 0;
}

Stack::~Stack(){

    if(nodehead == nullptr)
        return;

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


bool Stack::isEmpty(){

    return cur_stacksize == 0;
}

int Stack::peek(){

    if(nodehead == nullptr || cur_stacksize ==0){
        std::cout << "stack is empty"<< std::endl;
        return -1;
    }
    return nodehead->data;
}

void Stack::printStack(){

    if(isEmpty()){
        std::cout << "stack is empty"<< std::endl;
        return;
    }

    Node *tmp;
    tmp = nodehead;

    while(tmp != nullptr){
        std::cout << tmp->data ;
        tmp = tmp->prenode;

        if(tmp == nullptr)
            std::cout <<"|" << std::endl;
        else
            std::cout <<", ";

    }

}

void Stack::sortStack(){

    Stack hlperstack = Stack();

    while(cur_stacksize !=0){
    int tmp = pop();

        if(hlperstack.cur_stacksize ==0){
            hlperstack.push(tmp);
        }else{

                while(hlperstack.peek() <= tmp){

                    int htmp = hlperstack.pop();
                    if (htmp < 0)
                        break;
                    else
                        push(htmp);

                }

                hlperstack.push(tmp);

        }
    }

    hlperstack.printStack();

    /////////////////////////////////
    //can push back to original stack in reverse order
    ////////////////////////////////
    while(hlperstack.cur_stacksize!=0){
        push(hlperstack.pop());
    }
    printStack();

}



























