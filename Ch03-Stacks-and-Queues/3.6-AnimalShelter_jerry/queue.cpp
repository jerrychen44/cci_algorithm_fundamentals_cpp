#include <iostream>
#include "queue.hpp"
#include "node.hpp"



Queue:: Queue(int *timestampGlobal){
    this->firstnode = nullptr;
    this->lastnode = nullptr;
    this->cur_queuesize = 0;
    this->timestampGlobal = timestampGlobal;
}


Queue::~Queue(){

    while(firstnode != nullptr){
        Node *discard = firstnode;
        firstnode = firstnode ->nextnode;
        discard = nullptr;
        delete discard;
    }


    while(lastnode != nullptr){
        Node *discard = lastnode;
        lastnode = lastnode ->nextnode;
        discard = nullptr;
        delete discard;
    }
}


void Queue::add(int data){

    //queue is empty
    if(firstnode == nullptr && lastnode==nullptr){
        firstnode = new Node(data);
        firstnode->timestampNode = *timestampGlobal;
        lastnode = firstnode;
    }else{
        Node *newnode = new Node(data);
        newnode->timestampNode = *timestampGlobal;
        lastnode->nextnode = newnode;
        lastnode = newnode;

    }

    cur_queuesize++;
    (*timestampGlobal)++;
    std::cout << "add: " << data << std::endl;
    std::cout << "cur_queuesize " << cur_queuesize << std::endl;
    std::cout << "timestampGlobal " << *timestampGlobal << std::endl;


}

bool Queue::isEmpty(){

    if( (firstnode == nullptr && lastnode==nullptr) && cur_queuesize == 0){
        std::cout << "queue is empty " << std::endl;
        return true;
    }
    return false;
}


int Queue::remove(){

    if( isEmpty() ){
        std::cout << "queue is empty " << std::endl;
        return -1;
    }



    int rst=-1;
    rst = firstnode->data;
    Node *discard;
    discard = firstnode;
    firstnode = firstnode->nextnode;
    discard = nullptr;
    delete discard;
    cur_queuesize--;


    std::cout << "remove: " << rst << std::endl;
    std::cout << "cur_queuesize " << cur_queuesize << std::endl;

    if(cur_queuesize == 0){
        firstnode = nullptr;
        lastnode = nullptr;
    }



    return rst;
}

void Queue::printq(){


    std::cout << " ==== print queue ====  " << std::endl;

    if(isEmpty() ){
        return;
    }


    Node *tmp = firstnode;


    while(tmp !=nullptr){
        std::cout << tmp->data <<"(t:" << tmp->timestampNode<<"), ";
        tmp = tmp->nextnode;
    }

    std::cout << std::endl;
    std::cout << "cur_queuesize " << cur_queuesize << std::endl;
    std::cout << "firstnode->data " << firstnode->data << std::endl;
    std::cout << "lastnode->data " << lastnode->data << std::endl;
    std::cout << "timestampGlobal " << *timestampGlobal << std::endl;
    std::cout << std::endl;

}


int Queue::peek(){

    if( isEmpty() ){
        std::cout << "queue is empty " << std::endl;
        return -1;
    }
    std::cout << "peek: " << firstnode->data << std::endl;


    return firstnode->data;
}

int Queue::peektimestamp(){

    if( isEmpty() ){
        std::cout << "queue is empty, return peektimestamp = 9999 " << std::endl;
        return 9999;
    }
    std::cout << "peek timestampNode: " << firstnode->timestampNode << std::endl;


    return firstnode->timestampNode;
}














