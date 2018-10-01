#include <iostream>
#include <vector>

#include "tree_utility.cpp"

TreeNode* mostLeft(TreeNode* cur_node) {
	while (cur_node->left != nullptr) {
		cur_node = cur_node->left;
	}
	return cur_node;
}

TreeNode* findSuccessor(TreeNode* cur_node) {
	if (cur_node->right != nullptr) {
		return mostLeft(cur_node->right);
	}
	TreeNode* child = cur_node;
	TreeNode* ancestor = cur_node->parent;
	while(ancestor != nullptr && ancestor->right == child) {
		//keep loknig up, until we hit acestor->left = child
		child = ancestor;
		ancestor = child->parent;
	}
	return ancestor;
}


void setlrp(TreeNode *node, TreeNode *left, TreeNode *right, TreeNode *parent){

	node->left = left;
	node->right = right;
	node->parent = parent;

}

int main(){



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

    TreeNode *root = node30;

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








    //find target
    TreeNode *target = node23;


    TreeNode* rst = findSuccessor(target);
    std::cout <<"target node: "<< target->data <<", findSuccessor: " << rst->data << std::endl;

    //log
	//target node: 14, findSuccessor: 20
	//target node: 18, findSuccessor: 14
	//target node: 23, findSuccessor: 30
	//target node: 55, findSuccessor: 70





    freeTree(root);

    return 0;
}