#include <iostream>
#include "stack.hpp"
#include "node.hpp"
#include "queue.hpp"

int main(){

    /*
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
    */


    QueueviaStack myqueue = QueueviaStack();

    myqueue.add(3);
    std::cout << myqueue.inputstack->cur_stacksize << std::endl;
    std::cout << myqueue.outputstack->cur_stacksize << std::endl;


    myqueue.add(4);
    std::cout << myqueue.inputstack->cur_stacksize << std::endl;
    std::cout << myqueue.outputstack->cur_stacksize << std::endl;

    myqueue.add(5);
    std::cout << myqueue.inputstack->cur_stacksize << std::endl;
    std::cout << myqueue.outputstack->cur_stacksize << std::endl;

    myqueue.remove();
    std::cout << myqueue.inputstack->cur_stacksize << std::endl;
    std::cout << myqueue.outputstack->cur_stacksize << std::endl;

    myqueue.remove();
    std::cout << myqueue.inputstack->cur_stacksize << std::endl;
    std::cout << myqueue.outputstack->cur_stacksize << std::endl;


    myqueue.add(7);
    std::cout << myqueue.inputstack->cur_stacksize << std::endl;
    std::cout << myqueue.outputstack->cur_stacksize << std::endl;


    myqueue.remove();
    std::cout << myqueue.inputstack->cur_stacksize << std::endl;
    std::cout << myqueue.outputstack->cur_stacksize << std::endl;

    myqueue.remove();
    std::cout << myqueue.inputstack->cur_stacksize << std::endl;
    std::cout << myqueue.outputstack->cur_stacksize << std::endl;




    myqueue.remove();
    std::cout << myqueue.inputstack->cur_stacksize << std::endl;
    std::cout << myqueue.outputstack->cur_stacksize << std::endl;



    return 0;
}