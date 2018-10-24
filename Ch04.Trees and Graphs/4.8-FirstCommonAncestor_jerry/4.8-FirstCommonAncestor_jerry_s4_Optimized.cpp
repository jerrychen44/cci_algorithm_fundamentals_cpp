#include <iostream>
#include <vector>
#include <cmath>
#include "tree_utility.cpp"


class Result{
public:
    TreeNode * node;
    bool isAncestor;

    Result(TreeNode *n, bool isAnc){
        this->node = n;
        this->isAncestor = isAnc;
    }
};

Result* Helper(TreeNode *root, TreeNode *node1, TreeNode *node2){


    if(root == nullptr)
        return new Result(nullptr, false);

    //if root equaly as node1 and node2, then
    // root is Ancestor for sure.
    if( root == node1 && root == node2){
        return new Result(root, true);
    }


    //check the left child will be the ancestor or not
    //handle the isAncestor = True
    Result *leftrst = Helper(root->left, node1, node2);
    if(leftrst->isAncestor){
        return leftrst;
    }

    Result *rightrst = Helper(root->right, node1, node2);
    if(rightrst ->isAncestor){
        return rightrst;
    }


    //handle is the leftrst or rightrst isAncestor = false
    // if the code run to this part, which means the isAncestor = false
    // let us check the node is nullptr or not
    if(leftrst->node != nullptr && rightrst->node !=nullptr){
        std::cout <<"leftrst->node != nullptr && rightrst->node !=nullptr, return Result(root, true)"<<std::endl;
        return new Result(root, true);
    }else if(root == node1 || root ==node2){
        //If we're currently at node1 or node2, and we also found one of those nodes in a subtree,
        //then this is truly an ancestor and the flag should be true.
        bool isAncestor = leftrst->node !=nullptr || rightrst->node !=nullptr;
        return new Result(root, isAncestor);
    }else{
        return new Result(leftrst->node != nullptr ? leftrst->node : rightrst->node, false);
    }




    return new Result(nullptr, 1);
}



TreeNode* commonAncestor(TreeNode *root, TreeNode *node1/* p */, TreeNode *node2/* q */){
    std::cout << "root: " << root->data << std::endl;
    std::cout << "node1: " << node1->data << std::endl;
    std::cout << "node2: " << node2->data << std::endl;

    Result *r = Helper(root, node1, node2);
    if(r->isAncestor){
        if (r->node != nullptr)
            std::cout << "r isAncestor, return r.node:"<< r->node->data << std::endl;
        return r->node;
    }

    return nullptr; //or deeperNode, they are the same now.
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
    commonAncestor(root, node12, node55);



    freeTree(root);


    return 0;
}
