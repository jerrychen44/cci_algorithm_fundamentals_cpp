#include <iostream>
#include <vector>

#include "tree_utility.cpp"


//pre-order
bool checkBST(TreeNode* node,int min,int max){



    //base case
    if(node == nullptr){
        std::cout << "  node == nullptr, return true" << std::endl;
        return true;
    }
    std::cout << "== level node->data: "<< node->data << std::endl;

    //we skip the fisrt compare because that is the root
    if ( (min!=-9999999 && node->data <= min) || (max!=9999999 && node->data > max) ){
        std::cout << "  (node->data <= min) || (node->data > max), return false" << std::endl;
        return false;
    }


    int leftrst = checkBST(node->left, min, node->data);
    //std::cout << "testing" << std::endl;
    if(!leftrst ){
        std::cout << "  !leftrst , return false" << std::endl;
        return false;
    }
    int rightrst = checkBST(node->right, node->data, max);

    if(!rightrst){
        std::cout << "  !rightrst, return false" << std::endl;
        return false;
    }

    //everything is fine in this level.
    return true;

}


bool checkBST(TreeNode* node){
    int min =  -9999999;
    int max = 9999999;
    return checkBST(node, min, max );
}


int main(){

    //construct a tree for example
    //int A[] = {1, 2, 3, 4, 5, 6, 7};
    int A[] = {1, 9, 3, 4, 5, 6, 7};

    std::vector<int> arr (A, A + sizeof(A) / sizeof(A[0]) );
    TreeNode *root = createMinBST(arr);
    //printPreorder(root);
    /*
        Convert List to BST {1,2,3,4,5,6,7}
                         4
                      /     \
                    2         6
                  /   \     /   \
                 1     3   5     7
    */



    int rst = checkBST(root);
    std::cout << "checkBST: " << rst << std::endl;






    freeTree(root);

    return 0;
}