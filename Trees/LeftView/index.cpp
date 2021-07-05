#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using intVec = vector<int>;

struct Node{
    Node *left;
    Node *right;
    int data;

};



intVec returnLeftView(Node *root){
    if (!root)return {};
    intVec finalResult;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()){
        int size = q.size();
        for (int i=1;i<size;i++){
            Node* temp = q.front();
            q.pop();
            if (i == 1)finalResult.push_back(temp->data);
            if (temp->left)q.push(temp->left);
            if (temp->right)q.push(temp->right);
        };

    };

    return finalResult;

}



