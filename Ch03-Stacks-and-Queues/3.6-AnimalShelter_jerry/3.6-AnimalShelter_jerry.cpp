#include <iostream>
#include "queue.hpp"
#include "node.hpp"

int main(){


    Queue myq = Queue();

    myq.add(1);
    myq.add(2);
    myq.add(3);

    myq.add(4);

    myq.printq();

    myq.remove();

    myq.printq();

    myq.peek();


    return 0;
}