// BST implementation;
#include<bits/stdc++.h>
using namespace std;
// Binary Search Tree Node
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
// searching usign resursive function
bool search(Node *root,int key){
    if(root == NULL)return false;
    if(root -> data == key)return true;
    if(key < root -> data){
        return search(root -> left,key);
    }
    else{
        return search(root -> right,key);
    }
}
//seraching using iterative function
bool searchIterative(Node *root,int key){
    while(root != NULL){
        if(root -> data == key)return true;
        if(key < root -> data){
            root = root -> left;
        }
        else{
            root = root -> right;
        }
    }
    return false;
}
int main(){
    Node* root = newNode(10);
    root->left = newNode(5);
    root->right = newNode(15);
    root->left->left = newNode(3);
    root->left->right = newNode(7);
    root->right->right = newNode(18);

    int key = 7;
    if (search(root, key)) {
        cout << "Key " << key << " found in the BST." << endl;
    } else {
        cout << "Key " << key << " not found in the BST." << endl;
    }
    
    return 0;
}