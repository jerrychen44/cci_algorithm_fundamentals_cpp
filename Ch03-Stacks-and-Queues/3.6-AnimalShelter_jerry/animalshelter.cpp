#include <iostream>
#include "animalshelter.hpp"
//#include <string>






AnimalShelter::AnimalShelter(){

    //this->q1 = nullptr;
    //this->q2 = nullptr;
    this->timestampGlobal = 0;
    this -> q1 = new Queue(&timestampGlobal);
    this -> q2 = new Queue(&timestampGlobal);

}


AnimalShelter::~AnimalShelter(){

    if(q1 != nullptr)
        delete q1;
    if(q2 != nullptr)
        delete q2;

}


void AnimalShelter::enqueue(std::string data){



    if(q1 == nullptr)
        q1 = new Queue(&timestampGlobal);
    if(q2 == nullptr)
        q2 = new Queue(&timestampGlobal);



    if(data == "dog")
        q1->add(1);
    else if (data == "cat")
        q2->add(2);


}

void AnimalShelter::printout(){
    q1->printq();
    q2->printq();
}


bool AnimalShelter::isEmpty(){

    if(q1 == nullptr && q2==nullptr)
        return true;
    return false;
}

int AnimalShelter::dequeueAny(){

    if(isEmpty()){
        std::cout << "AnimalShelter is empty" << std::endl;
        return -1;
    }


    if(q1->peektimestamp() <= q2->peektimestamp())
        return q1->remove();
    else
        return q2->remove();


}


int AnimalShelter::dequeueDog(){

    if(isEmpty()){
        std::cout << "AnimalShelter is empty" << std::endl;
        return -1;
    }



    return q1->remove();

}


int AnimalShelter::dequeueCat(){

    if(isEmpty()){
        std::cout << "AnimalShelter is empty" << std::endl;
        return -1;
    }



    return q2->remove();

}