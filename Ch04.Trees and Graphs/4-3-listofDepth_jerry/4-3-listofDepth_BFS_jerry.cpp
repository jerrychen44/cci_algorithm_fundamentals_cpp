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
    Node *next;

};

Node::Node(int data){

    this->data  = data;
    this->left  = nullptr;
    this->right = nullptr;
    this->next  = nullptr;
}


class LinkList{
public:
    LinkList();
    void add(Node* inNode);
    int size();


    int nodesize;
    Node* headNode;
    Node* tailNode;

};


LinkList::LinkList(){

    this->nodesize = 0;
    this->headNode = nullptr;
    this->tailNode = nullptr;

}

void LinkList::add(Node* inNode){

    if(nodesize == 0){
        this->headNode = inNode;
        this->tailNode = headNode;
    }else{
        tailNode->next = inNode;
        tailNode = inNode;
    }
    this->nodesize ++;
}

int LinkList::size(){
    return this->nodesize;
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


void createLevelDepthList_BFS(Node * treeRoot,std::vector<LinkList* > *depthVector){

    //base case when hit the end of node
    if(treeRoot == nullptr){
        std::cout << "hit the end of node, return" << std::endl;
        return;
    }

    std::cout << "depthVector->size() :"<< depthVector->size() << std::endl;

    LinkList *currentlist = new LinkList();

    if(treeRoot != nullptr){
        //handle the root node, it must the only one in this level
        currentlist->add(treeRoot);
    }

    //handle the rest of the node
    while( currentlist->size() > 0){

        //put the currentlist to depthVecotr
        //the first time, it only put the root layer

        depthVector->push_back(currentlist);

        //record the currentlist as parentlist
        LinkList *parentlist = currentlist;

        //create another list, but assign the same name to currentlist
        //this new list will use to save the child
        currentlist = new LinkList();

        //loop over pareant's node
        Node * tmp = parentlist->headNode;
        while(tmp !=nullptr){

            //visit child
            if(tmp->left != nullptr){
                //add to new list, prepare to record them all for this layer
                currentlist->add(tmp->left);
            }

            if(tmp->right !=nullptr){
                currentlist->add(tmp->right);
            }

            tmp = tmp -> next;
        }

    }




}

void deiniBFS(std::vector<LinkList *> *depthVector){

    std::cout<<"Deinit====="<<std::endl;

    for (int i=0; i < depthVector->size(); ++i){

        Node *tmp = (depthVector)->at(i)->headNode;
        std::cout << "level i:" << i << std::endl;

        while(tmp !=nullptr){
            std::cout << "Free " << tmp->data << ", ";
            Node *discard;
            discard = tmp;
            tmp = tmp -> next;
            delete discard;
            discard=nullptr;
        }
        std::cout<<std::endl;

    }

    //delete depthVector;
}

void createLevelDepthList_BFS(Node * treeRoot){


    std::vector<LinkList * > depthVector;
    //std::cout << "depthVector.size()" << (depthVector).size() <<std::endl;

    createLevelDepthList_BFS(treeRoot, &depthVector);

    ///////////
    //print out
    //////////

    std::cout << "Print depthVector: " << std::endl;
    std::cout << "depthVector.size()" << (depthVector).size() <<std::endl;

    for (int i=0; i < depthVector.size(); ++i){
        std::cout << "level i:" << i << std::endl;
        LinkList *tmp = (depthVector).at(i);
        Node* tmpNode = tmp->headNode;
        while(tmpNode !=nullptr){
            std::cout << tmpNode->data << ", ";
            tmpNode = tmpNode -> next;
        }
        std::cout<<std::endl;

    }


    /////////
    // deinit
    /////////
    deiniBFS(&depthVector);
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


    createLevelDepthList_BFS(root);










    return 0;
}
