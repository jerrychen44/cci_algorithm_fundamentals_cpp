#include <iostream>
#include "stack.hpp"
#include "node.hpp"

int main(){


    Stack mystack = Stack();

    std::cout << mystack.cur_stacksize << std::endl;
    //std::cout << mystack.nodehead->data << std::endl;


    mystack.push(5);
    std::cout << mystack.nodehead << std::endl;
    std::cout << mystack.cur_stacksize << std::endl;
    std::cout << mystack.nodehead->data << std::endl;
    std::cout << mystack.nodehead->prenode << std::endl;


    mystack.push(9);

    std::cout << mystack.nodehead << std::endl;
    std::cout << mystack.cur_stacksize << std::endl;
    std::cout << mystack.nodehead->data << std::endl;
    std::cout << mystack.nodehead->prenode << std::endl;

    mystack.push(7);

    std::cout << mystack.nodehead << std::endl;
    std::cout << mystack.cur_stacksize << std::endl;
    std::cout << mystack.nodehead->data << std::endl;
    std::cout << mystack.nodehead->prenode << std::endl;


    std::cout << "pop: " << mystack.pop() << std::endl;

    std::cout << mystack.nodehead << std::endl;
    std::cout << mystack.cur_stacksize << std::endl;
    std::cout << mystack.nodehead->data << std::endl;
    std::cout << mystack.nodehead->prenode << std::endl;


    mystack.printStack();


    mystack.push(2);

    mystack.push(33);

    mystack.printStack();


    mystack.sortStack();


    return 0;
}