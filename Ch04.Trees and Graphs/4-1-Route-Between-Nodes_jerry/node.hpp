#ifndef NODE_H
#define NODE_H


class Node {

public:

    Node(int data);



    int data;//-999 is default
    int visiting_state;//0:unvisited, 1:visiting, 2:visited


    Node *nextNode;


};



#endif