#include <iostream>
#include "queue.hpp"


myQueue::myQueue(){
    this->cur_queuesize = 0;
    this->head = nullptr;
    this->tail = nullptr;

}

myQueue::~myQueue(){

    while(head != nullptr){
        Node *discard;
        discard = head;
        head = head ->nextNode;
        delete discard;
        discard = nullptr;
    }
}


void myQueue::add(int data){

    Node *newnode = new Node(data);

    if(cur_queuesize ==0 ){
        head = newnode;
        tail = head;
    }else{
        tail->nextNode = newnode;
        tail = newnode;
    }

    cur_queuesize++;

}


int myQueue::remove(){

    if(cur_queuesize == 0){
        return -1;
    }

    int rst = head->data;


    Node * discard;
    discard = head;
    head = head->nextNode;
    delete discard;
    discard = nullptr;

    cur_queuesize--;



    return rst;
}

int myQueue::peekhead(){
    return head->data;
}

bool myQueue :: isEmpty(){
    return head == nullptr;
}
void myQueue::printQ(){



    if(cur_queuesize == 0){
        return ;
    }

    Node *tmp = head;

    std::cout << std::endl;
    while(tmp != nullptr){
        std::cout << tmp->data << ", ";
        tmp = tmp->nextNode;
    }
    std::cout << std::endl;


}


