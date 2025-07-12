// insetion in bst;
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
// Function to insert a new node in the BST
// 1- recursive solution
Node * insert(Node *root,int key){
    if(root == NULL)return newNode(key);
    if(key < root -> data){
        root -> left = insert(root -> left,key);
    }
    else if(key > root -> data){
        root -> right = insert(root ->right,key);
    }
    return root;
}
// 2- iterative solution
Node * insertIterative(Node *root,int key){
    Node *newNode = new Node();
    newNode -> data = key;
    if(root == NULL)return newNode;
    Node * curr = root;
    Node * parent = NULL;
    while(curr != NULL){
        parent = curr;
        if(key < curr -> data){
            curr = curr -> left;
        }
        else{
            curr = curr -> right;
        }
        return root;
    }
    if(key < parent -> data){
        parent -> left = newNode;
    }
    else{
        parent -> right = newNode;
    }
    return root;
}
int main(){
    Node* root = newNode(10);
    root->left = newNode(5);
    root->right = newNode(15);
    root->left->left = newNode(3);
    root->left->right = newNode(7);
    root->right->right = newNode(18);

    int key = 12;
    root = insert(root, key);

    cout << "Inserted " << key << " into the BST." << endl;

    int ky = 13;   
    root = insertIterative(root,key);
    cout << "Inserted " << key << " into the BST" << endl;

    return 0;
}