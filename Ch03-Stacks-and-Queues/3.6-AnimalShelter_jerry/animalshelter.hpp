#ifndef ANIMALSHELTER_H
#define ANIMALSHELTER_H

#include "queue.hpp"
//#include <string>


class AnimalShelter{


    public:

        AnimalShelter();
        ~AnimalShelter();



        bool isEmpty();

        void enqueue(std::string input);

        int dequeueAny();
        int dequeueDog();
        int dequeueCat();




        void printout();

        Queue *q1;//dog
        Queue *q2;//cat
        int timestampGlobal;

};





#endif