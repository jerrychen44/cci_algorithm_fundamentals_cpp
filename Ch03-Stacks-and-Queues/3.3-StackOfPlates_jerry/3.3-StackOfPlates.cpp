#include <iostream>
#include <vector>

#include "SetOfStacks.hpp"

int main()
{


    SetOfStacks stackset = SetOfStacks(3);

    //std::cout << stackset.capcity << std::endl;
    //std::cout << stackset.setofstacks.size() << std::endl;


    stackset.push(5);
    //std::cout << stackset.setofstacks[0]->cur_stacksize << std::endl;

    stackset.push(6);
    //std::cout << stackset.setofstacks[0]->cur_stacksize << std::endl;

    stackset.push(2);


    stackset.push(99);

    stackset.push(42);

    stackset.push(8);


    stackset.push(22);

    stackset.push(33);

    stackset.push(44);


    stackset.push(55);

    stackset.push(66);

    stackset.push(77);

    //std::cout << stackset.setofstacks.size() << std::endl;

    //std::cout << stackset.setofstacks[0]->cur_stacksize << std::endl;

    //std::vector<int> test;


    //stackset.printSet();
    //stackset.pop();
    //stackset.pop();
    //stackset.pop();

    stackset.printSet();

    stackset.popAt(1);
    stackset.printSet();

    stackset.popAt(1);
    stackset.printSet();

    stackset.popAt(1);
    stackset.printSet();

    stackset.popAt(2);
    stackset.printSet();



    return 0;
}