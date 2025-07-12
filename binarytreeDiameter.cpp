// Diameter of a binary tree
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};
//Utility function to create a new node
Node*newNode(int data){
    Node *temp = new Node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
// fuction to compute height of the tree
int height(Node *root){
    if(root == NULL)return 0;
    else return 1 + max(height(root->left),height(root->right));
}
//funtion to compute diameter of the tree
// this is a naive solution O(n^2) time complexity
int diameter(Node *root){
    if(root == NULL)return 0;
    int lheight = height(root->left);
    int rheight = height(root->right);
    int ldiameter = diameter(root->left);
    int rdiameter = diameter(root->right);
    return max(1+lheight+rheight,max(ldiameter,rdiameter));
}
//efficient solution O(n) time complexity
int result = 0;
int diameter2(Node *root){
    if(root == NULL)return 0;
    int lh = diameter2 (root->left);
    int rh = diameter2(root->right);
    result = max(result,lh+rh+1);
    return max(lh,rh)+1;
}
int main(){
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->left->left = newNode(6);
    cout << "Diameter of the tree is: " << diameter(root) << endl;
    //diameter using efficient solution
    diameter2(root);
    cout << "Diameter of the tree is: " << result << endl;
    return 0;
}