#ifndef NODE_H
#define NODE_H

class Node{

public:

    Node(int data);

    Node *nextnode;
    int data;
    int timestampNode;
};

#endif