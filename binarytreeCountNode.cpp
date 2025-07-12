// count the nodes if complete binary tree
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
//Navie approach
int countNodes(Node *root){
    if(root == NULL) return 0;
    else{
        return 1 + countNodes(root -> left) + countNodes(root -> right); 
    }
}
// efficient approach
int countNodeEff(Node *root){
    if(root == NULL) return 0;
    int lh = 0,rh =0;
    Node *curr = root;
    while(curr != NULL){
        lh ++;
        curr =  curr -> left;
    }
    curr = root;
    while(curr != NULL){
        rh++;
        curr = curr -> right;
    }
    if(lh == rh){
        return pow(2,lh)-1;
    }
    else{
        return 1 + countNodeEff(root -> left) + countNodeEff(root -> right);
    }
}
int main(){
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    
    cout << "Total number of nodes in the binary tree: " << countNodes(root) << endl;
    cout << "Total number of nodes in the binary tree: " << countNodeEff(root) << endl;
    
    return 0;
}