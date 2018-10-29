#ifndef TREEUTILITY_H
#define TREEUTILITY_H


class TreeNode {

public:

    TreeNode(int data);

    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent;

};

TreeNode::TreeNode(int data){

    this->data = data;
    this->left = nullptr;
    this->right = nullptr;
    this->parent = nullptr;

}



//kind of the DFS but used on BST
void printPreorder(TreeNode *node){

    if(node == nullptr){
        return;
    }

    std::cout << node->data << std::endl;
    printPreorder(node->left);
    printPreorder(node->right);

}

void freeTree(TreeNode *node){



    //the same code with printPreorder()
    if(node == nullptr){
        return;
    }

    //std::cout << "In " << node->data << std::endl;
    //std::cout << node << std::endl;

    freeTree(node->left);
    freeTree(node->right);

    //std::cout << "Free node: "<< node->data << std::endl;
    delete node;
    node = nullptr;

}


void setlrp(TreeNode *node, TreeNode *left, TreeNode *right, TreeNode *parent){

	node->left = left;
	node->right = right;
	node->parent = parent;

}


TreeNode * buildTree(){


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

    return root;

}

#endif
