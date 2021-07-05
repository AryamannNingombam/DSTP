#include <iostream>

using namespace std;

class Node{
    public:
    int data;
    Node *left;
    Node *right;
    Node(int d) : data{d},left{nullptr},right{nullptr}{};

};


int returnMaxHeight(Node *root){
    if (root == nullptr)return 0;
    int left = returnMaxHeight(root->left);
    int right   = returnMaxHeight(root->right);

    return max(left,right) +1;

}