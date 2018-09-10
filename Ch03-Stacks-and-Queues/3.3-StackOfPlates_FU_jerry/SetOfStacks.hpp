#include "stack.hpp"
#include <iostream>
#include <vector>

class SetOfStacks {

public:
    SetOfStacks(int capcity);
    ~SetOfStacks();
    void push(int v);
    int pop();

    int popAt(int indx);

    Stack* getLastStack();

    void printSet();

//private:
    int capcity;
    std::vector<Stack* > setofstacks;


};