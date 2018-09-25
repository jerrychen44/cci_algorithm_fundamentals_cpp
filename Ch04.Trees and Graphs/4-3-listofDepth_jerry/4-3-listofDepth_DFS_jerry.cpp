//#include<bits/stdc++.h>//didn't work on mac
#include <iostream>
#include <vector>
#include<unistd.h>

//using namespace std;

class Node {

public:

    Node(int data);

    double data;
    Node *left;
    Node *right;

};

Node::Node(int data){

    this->data = data;
    this->left = nullptr;
    this->right = nullptr;
}


class ListNode{
public:
    ListNode();
    Node* treenode;
    ListNode *nextlistNode;

};


ListNode::ListNode(){

    this->treenode = nullptr;
    this->nextlistNode = nullptr;
}


//overload
Node* createMinBST(std::vector<int> arr, int low_idx, int high_idx){

    //std::cout<< "low_idx "<< low_idx <<", high_idx "<< high_idx << std::endl;

    //stop checking
    if(high_idx < low_idx){
        //std::cout<< "high_idx < low_idx, stop, return NULL" << std::endl;
        return nullptr;
    }

    int mid = (low_idx + high_idx) / 2;

    // |low_idx|~~~~~~~~~|mid -1|mid|mid+1|~~~~~~~~~~~~|hight_idx|

    //create new node by allcat
    //std::cout << "new mid Node idx "<< mid << std::endl;
    Node* node = new Node(arr[mid]);
    node->left = createMinBST(arr, low_idx, mid -1);
    //std::cout << "left end" << std::endl;
    node->right = createMinBST(arr, mid + 1, high_idx);
    //std::cout << "right end" << std::endl;

    return node;
}

Node* createMinBST(std::vector<int> arr){

    if(arr.size()==0){
        std::cout<< "arr is empty" << std::endl;
        return nullptr;
    }

    //std::cout << "input arr size " << arr.size() << std::endl;
    Node* root = createMinBST(arr,0, arr.size()-1);

    return root;

}
//kind of the DFS
void printPreorder(Node *node){

    if(node == nullptr){
        return;
    }

    std::cout << node->data << std::endl;
    printPreorder(node->left);
    printPreorder(node->right);

}


void createLevelDepthList_DFS(Node * treeRoot,std::vector<ListNode* > *depthVector, int currentLevel){

    //base case when hit the end of node
    if(treeRoot == nullptr){
        std::cout << "hit the end of node, return" << std::endl;
        return;
    }

    std::cout << "depthVector->size() :"<< depthVector->size() <<", currentLevel:"<< currentLevel << std::endl;

    ListNode* curNode;
    curNode = new ListNode();

    //the first time to build the level
    if( depthVector->size() == currentLevel ){
        depthVector->push_back(curNode);
    }else{
        ListNode *tmp;
        tmp = depthVector->at(currentLevel);

        while(tmp->nextlistNode !=nullptr){
            tmp = tmp->nextlistNode;
        }
        tmp->nextlistNode = curNode;

    }


    curNode->treenode = treeRoot;
    createLevelDepthList_DFS(treeRoot->left, depthVector,currentLevel +1);
    createLevelDepthList_DFS(treeRoot->right, depthVector,currentLevel +1);



}

void deiniDFS(std::vector<ListNode *> *depthVector){


    for (int i=0; i < depthVector->size(); ++i){

        ListNode *tmp = (depthVector)->at(i);
        std::cout << "level i:" << i << std::endl;

        while(tmp !=nullptr){
            std::cout << "Free " << tmp->treenode->data << ", ";
            ListNode *discard;
            discard = tmp;
            tmp = tmp -> nextlistNode;
            delete discard;
            discard=nullptr;
        }
        std::cout<<std::endl;

    }

    //delete depthVector;
}

void createLevelDepthList_DFS(Node * treeRoot){


    std::vector<ListNode * > depthVector;
    //std::cout << "depthVector.size()" << (depthVector).size() <<std::endl;

    createLevelDepthList_DFS(treeRoot, &depthVector, 0);

    ///////////
    //print out
    //////////
    std::cout << "Print depthVector: " << std::endl;
    std::cout << "depthVector.size()" << (depthVector).size() <<std::endl;

    for (int i=0; i < depthVector.size(); ++i){
        std::cout << "level i:" << i << std::endl;
        ListNode *tmp = (depthVector).at(i);

        while(tmp !=nullptr){
            std::cout << tmp->treenode->data << ", ";
            tmp = tmp -> nextlistNode;
        }
        std::cout<<std::endl;

    }


    /////////
    // deinit
    /////////
    deiniDFS(&depthVector);

}



int main(){

    //Node myNode = Node(5);
    //cout << myNode.data << endl;

    //construct a tree for example
    int A[] = {1, 2, 3, 4, 5, 6, 7};
    std::vector<int> arr (A, A + sizeof(A) / sizeof(A[0]) );
    Node *root = createMinBST(arr);
    //printPreorder(root);
    /*
        Convert List to BST {1,2,3,4,5,6,7}
                         4
                      /     \
                    2         6
                  /   \     /   \
                 1     3   5     7
    */


    createLevelDepthList_DFS(root);










    return 0;
}
