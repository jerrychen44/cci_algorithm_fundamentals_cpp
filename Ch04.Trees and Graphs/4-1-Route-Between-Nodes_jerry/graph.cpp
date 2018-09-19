#include "graph.hpp"
#include <vector>
#include <iostream>
#include "queue.hpp"



Graph::Graph(int totalnum){
    std::cout << totalnum << std::endl;
    this -> totalnum = totalnum;
    this -> adjlist = new std::vector<int>[totalnum];
    std::cout << "new adjlist size :" << adjlist->size() << std::endl;
}

Graph::~Graph(){
    //adjlist->clear();
    //delete adjlist;
}


void Graph::addEdge(int from, int to){

    //std::cout << "B adjlist size :" << adjlist[from].size() << std::endl;

    adjlist[from].push_back(to);
    //std::cout <<  (*adjlist)[from] <<std::endl;
    std::cout << "Added adjlist["<< from <<"], to " << to <<" size :" << adjlist[from].size() << std::endl;

}


bool Graph::isRoute(int from, int to){




    //BFS, build via a queue.
    myQueue bfsqueue = myQueue();
    //viewed list
    std::vector<bool> viewing_list(totalnum,false);


    //put the from as a start node
    bfsqueue.add(from);
    //bfsqueue.printQ();
    //bfsqueue.remove();
    //std::cout << bfsqueue.cur_queuesize << std::endl;
    //std::cout << bfsqueue.isEmpty() << std::endl;

    //keep traversal until the bfsqueue is Empty
    while( !bfsqueue.isEmpty() ){

        int cur = bfsqueue.peekhead();

        if( cur == to ){
            std::cout << "meet the 'to' node, here is a route" << std::endl;
            return true;
        }

        bfsqueue.remove();//viewed
        viewing_list[cur] = true;

        //check the adj matrix
        int node_size = adjlist[cur].size();
        for (int i = 0; i < node_size; ++i){

            //if not viewed yet
            if(viewing_list[ adjlist[cur][i]  ] == false){
                //add to queue, wait to process
                bfsqueue.add( adjlist[cur][i] );
            }//if

        }//for

    }//while

    //if above code dosen't return true, which means
    //from node can't meet the to node.
    return false;
}




void Graph::printAdj(){

    std::cout << std::endl;
    std::cout << "Pring ADJ" << std::endl;
    for (int e=0; e < totalnum ; ++e) {
        std::cout <<"From : " << e << ": "<< std::endl;

        for(int i=0; i < adjlist[e].size() ; ++i){
            std::cout <<"    To : " << adjlist[e][i] <<std::endl;
        }
    }
}