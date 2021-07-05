#include <iostream>


using namespace std;

struct Node{
    int data;
    Node *left,*right;
};

int height(Node *node){
    if (!node)return 0;
    return max(height(node->left),height(node->right)) +1;
}


bool checkHeightBalance(Node *node){
    if (!node)return true;
    const int leftHeight = height(node->left);
    const int rightHeight = height(node->right);
    if (abs(leftHeight-rightHeight)>1)return false;

    return checkHeightBalance(node->left) && checkHeightBalance(node->right);
}

