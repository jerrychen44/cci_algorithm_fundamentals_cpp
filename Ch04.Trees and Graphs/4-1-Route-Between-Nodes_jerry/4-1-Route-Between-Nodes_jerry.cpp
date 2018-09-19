#include <iostream>
#include "graph.hpp"
#include "queue.hpp"



int main()
{


    /*
    //testing queue
    myQueue myq = myQueue();

    myq.add(1);
    myq.add(2);
    myq.add(3);

    myq.printQ();

    std::cout << myq.remove() << std::endl;

    myq.printQ();

    myq.add(4);

    myq.printQ();
    */


    Graph myg = Graph(6);
    myg.addEdge(5, 2);
    myg.addEdge(5, 0);
    myg.addEdge(4, 0);
    myg.addEdge(4, 1);
    myg.addEdge(2, 3);
    myg.addEdge(3, 1);

    myg.printAdj();

    std::cout<<"isRoute :" << myg.isRoute(5,4)<<std::endl; // false
    std::cout<<"isRoute :" << myg.isRoute(5,1)<<std::endl; // true

    return 0;
}