#ifndef GRAPH_H
#define GRAPH_H
#include <vector>


class Graph{


public:

    Graph(int totalnum);
    ~Graph();
    void addEdge(int from,int to);
    bool isRoute(int from, int to);

    void printAdj();



    int totalnum;
    std::vector<int > *adjlist;



};



#endif