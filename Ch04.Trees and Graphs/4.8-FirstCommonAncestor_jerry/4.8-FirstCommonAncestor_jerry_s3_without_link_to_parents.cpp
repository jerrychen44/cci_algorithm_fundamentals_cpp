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
TreeNode* ancestorHelper(TreeNode *root, TreeNode *node1/* p */, TreeNode *node2/* q */){
    std::cout <<"=== ancestorHelper, current root:"<< root -> data <<std::endl;

    if(root == nullptr || node1 == root || node2 == root){
        std::cout <<"   root == nullptr || node1 == root || node2 == root, return root:"<< root->data<<std::endl;
        return root;
    }

    bool node1IsOnLeft = covers(root->left, node1);
    std::cout <<"   node1IsOnLeft: "<< node1IsOnLeft <<std::endl;

    bool node2IsOnLeft = covers(root->left, node2);
    std::cout <<"   node1IsOnLeft: "<< node2IsOnLeft <<std::endl;

    if(node1IsOnLeft != node2IsOnLeft){
        std::cout <<"   node1, node2 are on different side, current root is their commonAncestor, return root: "<< root->data<<std::endl;
        return root;
    }

    std::cout <<"   node1, node2 are on the same side"<<std::endl;
    TreeNode *chilrdasNextRoot;

    if( node1IsOnLeft ){
        chilrdasNextRoot = root->left;
        std::cout <<"   chilrdasNextRoot = root->left side"<<std::endl;

    }else{
        chilrdasNextRoot = root->right;
        std::cout <<"   chilrdasNextRoot = root->right side"<<std::endl;

    }

    return ancestorHelper(chilrdasNextRoot, node1, node2);

}


TreeNode* commonAncestor(TreeNode *root, TreeNode *node1/* p */, TreeNode *node2/* q */){
    std::cout << "root: " << root->data << std::endl;
    std::cout << "node1: " << node1->data << std::endl;
    std::cout << "node2: " << node2->data << std::endl;

    //check if either node is not in the tree , or if one covers the other
    if(!covers(root, node1) || !covers(root,node2)){
        std::cout << "node1 or node2 not in the tree, return nullptr" << std::endl;
        return nullptr;
    }
    std::cout << "node1 or node2 in the tree, keep going" << std::endl;


    TreeNode *commonAncestor;
    commonAncestor = ancestorHelper(root, node1/* p */, node2/* q */);
    std::cout << "commonAncestor: "<< commonAncestor->data << std::endl;
    return commonAncestor; //or deeperNode, they are the same now.
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
    commonAncestor(root, node18, node14);



    freeTree(root);


    return 0;
}
