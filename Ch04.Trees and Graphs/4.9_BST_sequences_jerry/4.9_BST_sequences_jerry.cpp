#include <iostream>
#include <vector>
#include <cmath>
#include "tree_utility.cpp"



std::vector<std::vector<int> *>* allSequence(TreeNode* node){

    std::vector< std::vector<int> * > *result = new std::vector<std::vector<int> *>;

    if(node == nullptr){
        result->push_back(new std::vector<int>);
        return result;
    }


    std::vector<int> *prefix  = new std::vector<int>;
    prefix->push_back(node->data);

    //Recurse on left and right subtrees
    std::vector<std::vector<int> *>* leftSeq  = allSequence(node->left);
    std::vector<std::vector<int> *>* rightSeq = allSequence(node->right);


    //weave together each list from the left and right sides
    for (int i =0; i < leftSeq->size(); ++i){
        for(int j = 0; j < rightSeq->size(); ++ j){

            std::vector< std::vector<int> * > * weaved = new std::vector<std::vector<int> *>;
            weaveLists(leftSeq[i],rightSeq[j],weaved,prefix);

            for(int w=0; w<weaved->size(); ++w)
                result->push_back(weaved->at(w));

        }
    }




    return result;
}


int main(){

    //TreeNode *root;
    //root = buildTree();


    //build tree here

    TreeNode *node50 = new TreeNode(50);
    TreeNode *node20 = new TreeNode(20);
    TreeNode *node60 = new TreeNode(60);
    TreeNode *node10 = new TreeNode(10);
    TreeNode *node25 = new TreeNode(25);
    TreeNode *node70 = new TreeNode(70);
    TreeNode *node5 = new TreeNode(5);
    TreeNode *node15 = new TreeNode(15);
    TreeNode *node65 = new TreeNode(65);
    TreeNode *node80 = new TreeNode(80);


    TreeNode * root = node50;
    //std::cout<< root << ", " << node30 << std::endl;

    /*
    						     50
    					 /				\
                         20 			60
                      /     \      	      \
                    10        25           70
                  /   \                   /  \
                 5    15                 65   80

    */


    setlrp(node50,node20,node60,nullptr);
    setlrp(node20,node10,node25,node50);
    setlrp(node60,nullptr,node70,node50);
    setlrp(node10,node5,node15,node20);
    setlrp(node25,nullptr,nullptr,node20);
    setlrp(node5,nullptr,nullptr,node10);
    setlrp(node15,nullptr,nullptr,node10);
    setlrp(node70,node65,node80,node60);
    setlrp(node65,nullptr,nullptr,node70);
    setlrp(node80,nullptr,nullptr,node70);


    printPreorder(root);




    //First common Ancestor
    //depth testing
    //nodeDepth(node21);
    //commonAncestor(root, node12, node55);
    allSequence(root);


    freeTree(root);


    return 0;
}
