#include <iostream>


struct Node {
    int data;
    Node*left;
    Node *right;
};

bool helper(Node *left,Node *right){
    if (!left and !right)return true;
    if (left && right   && left->data == right->data)
    return helper(left->left,right->right) && helper(left->right,right->left);
    return false;
}


bool checkIfMirror(Node *root){
    if (!root)return true;
    return helper(root->left,root->right);
}