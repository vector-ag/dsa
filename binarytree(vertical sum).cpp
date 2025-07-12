// vertical sum in binary tree
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
void vsumr(Node*root,int hd,map<int,int>&mp){
    if(root == NULL)return;
    vsumr(root->left,hd-1,mp);
    mp[hd] = mp[hd] + root->data;
    vsumr(root->right,hd+1,mp);
}
void vsum(Node *root){
    map<int,int>mp;
    vsumr(root,0,mp);
    for(auto pr : mp){
        cout << pr.second << " ";
    }
    cout << endl;
}
int main() {
    /*
            1
           / \
          2   3
         / \   \
        4   5   6
    */

    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);

    cout << "Vertical sums are: ";
    vsum(root);

    return 0;
}
