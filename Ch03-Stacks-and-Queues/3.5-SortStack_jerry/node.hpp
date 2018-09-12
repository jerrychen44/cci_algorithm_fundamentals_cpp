#ifndef NODE_H
#define NODE_H

class Node{

public:

    Node(int data,Node *prenode);

    Node *prenode;
    int data;
};

#endif