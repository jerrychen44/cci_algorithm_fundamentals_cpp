#include <iostream>
#include "queue.hpp"
#include "node.hpp"
#include "animalshelter.hpp"
#include <string>


int main(){


    /*
    Queue myq = Queue();

    myq.add(1);
    myq.add(2);
    myq.add(3);

    myq.add(4);

    myq.printq();

    myq.remove();

    myq.printq();

    myq.peek();
    */


    AnimalShelter myshelter = AnimalShelter();

    myshelter.printout();

    myshelter.enqueue("dog");

    myshelter.printout();


    myshelter.enqueue("dog");

    myshelter.printout();


    myshelter.enqueue("cat");

    myshelter.printout();


    myshelter.enqueue("dog");

    myshelter.printout();

    myshelter.enqueue("cat");

    myshelter.printout();

    myshelter.enqueue("cat");

    myshelter.printout();

    myshelter.enqueue("dog");

    myshelter.printout();



    myshelter.dequeueAny();

    myshelter.printout();

    myshelter.dequeueAny();

    myshelter.printout();

    myshelter.dequeueAny();

    myshelter.printout();






    myshelter.dequeueDog();

    myshelter.printout();


    myshelter.dequeueCat();

    myshelter.printout();


    myshelter.dequeueAny();

    myshelter.printout();


    myshelter.enqueue("cat");

    myshelter.printout();


    myshelter.dequeueAny();

    myshelter.printout();

    myshelter.dequeueAny();

    myshelter.printout();

    return 0;
}