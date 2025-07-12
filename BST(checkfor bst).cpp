// chech for BST
#include <bits/stdc++.h>
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
// Function to check if a binary tree is a BST
bool isbst(Node * root,int mn, int mx){
    if(root == NULL)return true;
    return (root->data > mn && root->data < mx) && 
           isbst(root->left, mn, root->data) && 
           isbst(root->right, root->data, mx);
}
bool checkBST(Node *root) {
    return isbst(root, INT_MIN, INT_MAX);
}
// now checking for bst using inorder traversal
bool isbstinorder(Node *root,int &prev) {
    if (root == NULL) return true;

    if (isbstinorder(root->left, prev) == false) return false;

    if (root->data <= prev) return false;
    prev = root->data;

    return isbstinorder(root->right, prev);

}
int main() {
    Node* root = newNode(10);
    root->left = newNode(5);
    root->right = newNode(15);
    root->left->left = newNode(3);
    root->left->right = newNode(7);
    root->right->right = newNode(18);

    if (checkBST(root)) {
        cout << "The tree is a BST." << endl;
    } else {
        cout << "The tree is not a BST." << endl;
    }
    int prev = INT_MIN;
    if (isbstinorder(root, prev)) {
        cout << "The tree is a BST using inorder traversal." << endl;
    } else {
        cout << "The tree is not a BST using inorder traversal." << endl;
    }
    // Clean up memory (not shown here, but recommended in production code)
    return 0;
}