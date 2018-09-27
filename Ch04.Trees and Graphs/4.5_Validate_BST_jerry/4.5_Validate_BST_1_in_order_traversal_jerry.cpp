#include <iostream>
#include <vector>

#include "tree_utility.cpp"



bool checkBST(TreeNode* node,int *lastest_traversaled_node){


    if(node == nullptr){
        //hit the end
        std::cout << "  hit the end,  node = nullptr, return true" << std::endl;
        return true;
    }
    std::cout << "node->data: " << node->data << ", lastest_traversaled_node = " << *lastest_traversaled_node << std::endl;

    //check / recrse left
    if( !checkBST(node->left,lastest_traversaled_node) ){
        std::cout << "  !checkBST(node.left), return false" << std::endl;
        return false;
    }

    //check current node, current should > lastest_traversaled_node
    if(*lastest_traversaled_node !=-99999 && node->data <= *lastest_traversaled_node){
        std::cout << "  *lastest_traversaled_node !=0 && node->data <= *lastest_traversaled_node, return false" << std::endl;

        return false;
    }

    *lastest_traversaled_node = node->data;
    std::cout << "  set lastest_traversaled_node to " << *lastest_traversaled_node << std::endl;

    //check / recurse right
    if( !checkBST(node->right,lastest_traversaled_node) ){
        std::cout << "  !checkBST(node.right), return false" << std::endl;
        return false;
    }

    return true; //All good
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



    int lastest_traversaled_node = -99999;
    int rst = checkBST(root, &lastest_traversaled_node);
    std::cout << "checkBST: " << rst << std::endl;






    freeTree(root);

    return 0;
}