// floor in bst;
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
// Function to find the floor of a given key in the BST
Node* findfloor(Node *root,int key){
    Node * res = NULL;
    while(root != NULL){
        if(root -> data == key){
            return root;
        }
        else if(root-> data > key){
            root  = root -> left;
        }
        else{
            res = root;
            root = root -> right;
        }
    }
    return res;
}
// function to find the ceil of a given key in the BST
Node *findceil(Node *root,int key){
    Node * res = NULL;
    while(root != NULL){
        if(root -> data == key){
            return root;
        }
        else if(root -> data < key){
            root = root -> right;
        }
        else{
            res = root;
            root = root -> left;
        }
    }
    return res;
}

// Driver code
int main(){
    Node* root = newNode(10);
    root->left = newNode(5);
    root->right = newNode(15);
    root->left->left = newNode(3);
    root->left->right = newNode(7);
    root->right->right = newNode(18);

    int key = 6;
    Node *floorNode = findfloor(root, key);
    if (floorNode != NULL) {
        cout << "Floor of " << key << " is " << floorNode->data << endl;
    } else {
        cout << "No floor found for " << key << endl;
    }
    Node *ceilNode = findceil(root, key);
    if (ceilNode != NULL) {
        cout << "Ceil of " << key << " is " << ceilNode->data << endl;
    } else {
        cout << "No ceil found for " << key << endl;
    }
    
    return 0;
}