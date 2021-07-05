#include <iostream>
#include <climits>


struct Node {
    int data;
    Node *left;
    Node *right;

    Node (int d){
        this->data=d;
        this->left=this->right=NULL;
    }
};


bool returnIsBST(Node *node,int MIN=INT_MIN,int MAX=INT_MAX){
    if (!node)return true;
    if (node->data < MIN || node->data > MAX)return false;
    return returnIsBST(node->left,MIN,node->data-1) && returnIsBST(node->right,node->data+1,MAX);
}