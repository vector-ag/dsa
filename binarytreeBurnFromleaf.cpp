// Burn a binary tree from a leaf node
#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};
// Function to create a new node
Node* newNode(int data) {
    Node* node = new Node();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}
// Function to find the farthest node from the given node
int res =0;
int burntime(Node *root,int leaf,int &dist){
    if(root == NULL)return 0;
    if(root -> data == leaf){
        dist = 0;
        return 1;
    }
    int ldist = -1,rdist = -1;
    int lh = burntime(root->left,leaf,ldist);
    int rh  = burntime(root->right,leaf,rdist);
    if(ldist!=-1){
        dist = ldist +1;
        res = max(res,dist+rh);
    }
    else if(rdist != -1){
        dist = rdist + 1;
        res = max(res,dist+lh);
    }
    return max(lh,rh)+1;
}
 int main(){
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    int dist = 0;
    int leaf = 4;
    burntime(root,leaf,dist);
    cout << "The time taken to burn the tree from leaf node " << leaf << " is: " << res << endl;

    return 0;
 }