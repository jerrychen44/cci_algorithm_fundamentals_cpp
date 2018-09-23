//#include<bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

class Node {

public:

    Node(int data);

    int data;
    Node *left;
    Node *right;


};

Node::Node(int data){
    this->data = data;
    this->left = nullptr;
    this->right = nullptr;
}


//overload
Node* createMinBST(vector<int> arr, int low_idx, int high_idx){

    cout<< "low_idx "<< low_idx <<", high_idx "<< high_idx << endl;

    //stop checking
    if(high_idx < low_idx){
        cout<< "high_idx < low_idx, stop, return NULL" << endl;
        return nullptr;
    }

    int mid = (low_idx + high_idx) / 2;

    // |low_idx|~~~~~~~~~|mid -1|mid|mid+1|~~~~~~~~~~~~|hight_idx|

    //create new node by allcat
    cout << "new mid Node idx "<< mid << endl;
    Node* node = new Node(arr[mid]);
    node->left = createMinBST(arr, low_idx, mid -1);
    cout << "left end" << endl;
    node->right = createMinBST(arr, mid + 1, high_idx);
    cout << "right end" << endl;

    return node;
}

Node* createMinBST(vector<int> arr){

    if(arr.size()==0){
        cout<< "arr is empty" << endl;
        return nullptr;
    }

    cout << "input arr size " << arr.size() << endl;
    Node* root = createMinBST(arr,0, arr.size()-1);

    return root;

}

void printPreorder(Node *node){

    if(node == nullptr){
        return;
    }

    cout << node->data << endl;
    printPreorder(node->left);
    printPreorder(node->right);

}

//TO DO: ~the tree

int main(){

    //Node myNode = Node(5);
    //cout << myNode.data << endl;


    int A[] = {1, 2, 3, 4, 5, 6, 7};
    vector<int> arr (A, A + sizeof(A) / sizeof(A[0]) );
    Node *root = createMinBST(arr);

    /*
        Convert List to BST {1,2,3,4,5,6,7}
                         4
                      /     \
                    2         6
                  /   \     /   \
                 1     3   5     7
    */
    //need tracing the func call, and print it out
    //Done
    printPreorder(root);


    return 0;
}
