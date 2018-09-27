#ifndef TREEUTILITY_H
#define TREEUTILITY_H

#include <iostream>

class TreeNode {

public:

    TreeNode(int data);

    double data;
    TreeNode *left;
    TreeNode *right;

};

TreeNode::TreeNode(int data){

    this->data = data;
    this->left = nullptr;
    this->right = nullptr;
}


//overload
TreeNode* createMinBST(std::vector<int> arr, int low_idx, int high_idx){

    //std::cout<< "low_idx "<< low_idx <<", high_idx "<< high_idx << std::endl;

    //stop checking
    if(high_idx < low_idx){
        //std::cout<< "high_idx < low_idx, stop, return NULL" << std::endl;
        return nullptr;
    }

    int mid = (low_idx + high_idx) / 2;

    // |low_idx|~~~~~~~~~|mid -1|mid|mid+1|~~~~~~~~~~~~|hight_idx|

    //create new node by allcat
    //std::cout << "new mid TreeNode idx "<< mid << std::endl;
    TreeNode* node = new TreeNode(arr[mid]);
    node->left = createMinBST(arr, low_idx, mid -1);
    //std::cout << "left end" << std::endl;
    node->right = createMinBST(arr, mid + 1, high_idx);
    //std::cout << "right end" << std::endl;

    return node;
}

TreeNode* createMinBST(std::vector<int> arr){

    if(arr.size()==0){
        std::cout<< "arr is empty" << std::endl;
        return nullptr;
    }

    //std::cout << "input arr size " << arr.size() << std::endl;
    TreeNode* root = createMinBST(arr,0, arr.size()-1);

    return root;

}


//kind of the DFS
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

    freeTree(node->left);
    freeTree(node->right);

    //std::cout << "Free node: "<< node->data << std::endl;
    delete node;
    node = nullptr;

}



#endif










