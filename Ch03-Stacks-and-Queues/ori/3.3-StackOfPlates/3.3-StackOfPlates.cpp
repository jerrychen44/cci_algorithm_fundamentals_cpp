#include "stack.hpp"
#include "setofstack.hpp"
#include <iostream>


int main(){

    Setofstack mysetofstack = Setofstack(2);
    /*
    mysetofstack.push(1);
    mysetofstack.push(2);
    mysetofstack.push(3);
    mysetofstack.push(4);

    std::cout << "===" << std::endl;
    mysetofstack.pop();
    mysetofstack.pop();
    mysetofstack.pop();
    mysetofstack.pop();
    mysetofstack.pop();

    //mysetofstack.push(5);
    //mysetofstack.push(6);
    */

    for (int i = 0; i < 11; ++i)
    {
        mysetofstack.push(i);
        std::cout << i << " is pushed into the stack " << mysetofstack.cur_sof_stacknum << std::endl;
    }

    std::cout << std::endl;

    while (mysetofstack.cur_sof_stacknum != 0)
    {
        std::cout << mysetofstack.pop() << " is popped from the stack " << mysetofstack.cur_sof_stacknum << std::endl;
    }

    std::cout << std::endl;


    return 0;
}