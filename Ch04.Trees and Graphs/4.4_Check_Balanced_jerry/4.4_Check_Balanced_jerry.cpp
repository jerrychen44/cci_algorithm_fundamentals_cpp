#include <iostream>
#include <vector>
#include<unistd.h>

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


int checkHeight(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }
    int leftHeight = checkHeight(root->left);
    if (leftHeight == -1) {
        return -1;
    }
    int rightHeight = checkHeight(root->right);
    if (rightHeight == -1) {
        return -1;
    }

    if (abs(leftHeight - rightHeight) > 1) {
        return -1;
    }
    else {
        return std::max(leftHeight, rightHeight) + 1;
    }
}

bool isBalanced(TreeNode* root) {
    return (checkHeight(root) != -1);
}

int main(){

    //Node myNode = Node(5);
    //cout << myNode.data << endl;

    //construct a tree for example
    int A[] = {1, 2, 3, 4, 5, 6, 7};
    std::vector<int> arr (A, A + sizeof(A) / sizeof(A[0]) );
    TreeNode *root = createMinBST(arr);
    printPreorder(root);
    /*
        Convert List to BST {1,2,3,4,5,6,7}
                         4
                      /     \
                    2         6
                  /   \     /   \
                 1     3   5     7
    */


    std::cout << "isBalanced: " << isBalanced(root) << std::endl;



    return 0;
}
