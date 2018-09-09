#include "stack.hpp"
#include <iostream>
#include <vector>

class SetOfStacks {

public:
    SetOfStacks(int capcity);
    ~SetOfStacks();
    void push(int v);
    int pop();

    Stack* getLastStack();

//private:
    int capcity;
    std::vector<Stack* > setofstacks;


};