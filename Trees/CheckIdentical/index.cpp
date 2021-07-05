#include <iostream>


struct Node{
    int data;
    Node *left;
    Node *right;
};


bool checkIdentical(Node *node1,Node *node2){
    if (!node1 && !node2)return true;
    if (!node2  || !node2)return false;
    if (node1->data != node2->data)return false;
    if (!checkIdentical(node1->left,node2->left))return false;
    if (!checkIdentical(node1->right,node2->right))return false;


    return true;
}