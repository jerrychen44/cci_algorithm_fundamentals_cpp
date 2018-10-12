#include <iostream>
#include <vector>
#include <cmath>
#include "tree_utility.cpp"


int nodeDepth(TreeNode *node){
    int depth = 0;

    TreeNode *tmp;
    tmp = node;
    while( tmp != nullptr){
        tmp = tmp->parent;
        depth ++;
    }

    std::cout << "node: " <<node->data << ", depth: "<< depth << std::endl;
    std::cout << tmp << ", " << node << std::endl;
    return depth;
}

TreeNode* moveDeeperNodeUp(TreeNode* node, int depDelta){
    TreeNode *tmp = node;
    while(depDelta > 0 && tmp!=nullptr){
        tmp = tmp->parent;
        depDelta--;
    }
    return tmp;
}


TreeNode* commonAncestor(TreeNode *node1, TreeNode *node2){

    std::cout << "node1: " << node1->data << std::endl;
    std::cout << "node2: " << node2->data << std::endl;

    int depDelta = nodeDepth(node1) - nodeDepth(node2);
    std::cout << "depDelta: " << depDelta << std::endl;

    TreeNode *shallowerNode;
    TreeNode *deeperNode;

    if(depDelta > 0){
        //node1 deeper then node2
        shallowerNode = node2;
        deeperNode = node1;
        std::cout << "node1 deeper then node2" << std::endl;

    }else if(depDelta < 0){
        //node2 deeper then node1
        shallowerNode = node1;
        deeperNode = node2;
        std::cout << "node2 deeper then node1" << std::endl;
    }else{
        std::cout << "node1 has the same depth as node2" << std::endl;
    }
    //update the deeperNode to the upest node
    //which at the same level with node2
    deeperNode = moveDeeperNodeUp(deeperNode, abs(depDelta));
    std::cout << "updated deeperNode:" << deeperNode->data << std::endl;

    //now deeperNode and shallowerNode are both at the same level
    //we up move these two node together to see their common parent
    while(shallowerNode != deeperNode && shallowerNode!=nullptr && deeperNode!=nullptr){
        shallowerNode = shallowerNode->parent;
        deeperNode = deeperNode->parent;
    }

    //check result
    if(shallowerNode ==nullptr || deeperNode == nullptr){
        std::cout << "shallowerNode ==nullptr || deeperNode == nullptr, return null, no common ancestor" << std::endl;
        return nullptr;
    }

    std::cout << "commonAncestor: " << shallowerNode->data << std::endl;
    //std::cout << "commonAncestor: " << deeperNode->data << std::endl;

    return shallowerNode; //or deeperNode, they are the same now.
}

int main(){

    //TreeNode *root;
    //root = buildTree();


    //build tree here

    TreeNode *node30 = new TreeNode(30);
    TreeNode *node20 = new TreeNode(20);
    TreeNode *node18 = new TreeNode(18);
    TreeNode *node23 = new TreeNode(23);
    TreeNode *node9 = new TreeNode(9);
    TreeNode *node14 = new TreeNode(14);
    TreeNode *node22 = new TreeNode(22);
    TreeNode *node6 = new TreeNode(6);
    TreeNode *node12 = new TreeNode(12);
    TreeNode *node21 = new TreeNode(21);
    TreeNode *node70 = new TreeNode(70);
    TreeNode *node55 = new TreeNode(55);

    TreeNode * root = node30;
    //std::cout<< root << ", " << node30 << std::endl;

    /*
    						     30
    					 /				\
                         20 			70
                      /     \      	    /
                    18        23      55
                  /   \     /
                 9    14   22
                / \       /
               6  12     21
    */


    setlrp(node30,node20,node70,nullptr);
    setlrp(node20,node18,node23,node30);
    setlrp(node18,node9,node14,node20);
    setlrp(node9,node6,node12,node18);
    setlrp(node6,nullptr,nullptr,node9);
    setlrp(node12,nullptr,nullptr,node9);
    setlrp(node14,nullptr,nullptr,node18);
    setlrp(node23,node22,nullptr,node20);
    setlrp(node22,node21,nullptr,node23);
    setlrp(node21,nullptr,nullptr,node22);
    setlrp(node70,node55,nullptr,node30);
    setlrp(node55,nullptr,nullptr,node70);

    printPreorder(root);




    //First common Ancestor
    //depth testing
    //nodeDepth(node21);
    commonAncestor(node9, node70);



    freeTree(root);


    return 0;
}
