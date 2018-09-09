#include <iostream>
#include <vector>

#include "SetOfStacks.hpp"

int main()
{


    SetOfStacks stackset = SetOfStacks(2);

    //std::cout << stackset.capcity << std::endl;
    //std::cout << stackset.setofstacks.size() << std::endl;


    stackset.push(5);
    //std::cout << stackset.setofstacks[0]->cur_stacksize << std::endl;

    stackset.push(6);
    //std::cout << stackset.setofstacks[0]->cur_stacksize << std::endl;

    stackset.push(2);
    //std::cout << stackset.setofstacks.size() << std::endl;

    //std::cout << stackset.setofstacks[0]->cur_stacksize << std::endl;

    //std::vector<int> test;


    stackset.pop();
    stackset.pop();
    stackset.pop();


    stackset.pop();

    return 0;
}