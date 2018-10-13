#include <iostream>
#include <vector>
#include <cmath>
#include "tree_utility.cpp"


//check the node are covered by the root all
//along in subtree
bool covers(TreeNode* root, TreeNode* node){
    std::cout <<"== covers"<<std::endl;

    if(root == nullptr){
        std::cout <<"   root == null, return false"<<std::endl;
        return false;
    }
    std::cout <<"   root:"<< root->data <<", node:"<< node->data <<std::endl;
    if(root == node){
        std::cout <<"   root == node, return true"<<std::endl;
        return true;
    }

    return covers(root->left, node) || covers(root->right, node);
}

//return sibling
TreeNode * getSibling(TreeNode *node){
    std::cout <<"== getSibling"<<std::endl;

    if(node == nullptr || node->parent == nullptr){
        std::cout << "  node == nullptr || node->parent == nullptr" << std::endl;
        return nullptr;
    }

    TreeNode* parent = node->parent;

    if(parent->left == node){
        return parent->right;
    }else{
        return parent->left;
    }

}

TreeNode* commonAncestor(TreeNode *root, TreeNode *node1/* p */, TreeNode *node2/* q */){
    std::cout << "root: " << root->data << std::endl;
    std::cout << "node1: " << node1->data << std::endl;
    std::cout << "node2: " << node2->data << std::endl;

    //check if either node is not in the tree , or if one covers the other
    if(!covers(root, node1) || !covers(root,node2)){
        std::cout << "node1 or node2 not in the tree, return nullptr" << std::endl;
        return nullptr;
    }else if( covers(node1, node2)){
        std::cout << "node1 covers node2" << std::endl;
        return node1;
    }else if ( covers(node2, node1)){
        std::cout << "node2 covers node1" << std::endl;
        return node2;
    }else{
        std::cout << "node2, node1 in the tree, but not covered by each other, keep going" << std::endl;
    }

    //Traverse upwards until you find a node that covers node2
    TreeNode *node1sibling = getSibling(node1);
    TreeNode *node1parent = node1->parent;

    if(node1parent != nullptr && node1sibling != nullptr){
        std::cout << "node1 ,"<< node1->data <<" node1sibling is : "<< node1sibling->data << std::endl;
        std::cout << "node1 ,"<< node1->data <<" node1parent is : "<< node1parent->data << std::endl;
    }

    while(!covers(node1sibling, node2)){
        node1sibling = getSibling(node1parent);
        node1parent = node1parent->parent;
        std::cout <<"updated, node1sibling is : "<< node1sibling->data << std::endl;
        std::cout <<"updated, node1parent is : "<< node1parent->data << std::endl;
    }

    std::cout << "commonAncestor: "<< node1parent->data << std::endl;
    return node1parent; //or deeperNode, they are the same now.
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
    commonAncestor(root, node55, node20);



    freeTree(root);


    return 0;
}
