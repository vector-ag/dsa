// LCA of a binary tree;
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
// Naive approach
// O(n) time complexity ..by making [path array for each node]
bool findpath(Node *root,int n ,vector<int>&path){
    if(root == NULL)return false;
    path.push_back(root->data);
    if(root->data == n)return true;
    if(findpath(root->left,n,path) || findpath(root->right,n,path))return true;
    path.pop_back();
    return false;
}
// Function to find LCA of n1 and n2.
Node* LCA(Node* root, int n1, int n2) {
    vector<int> path1,path2;
    if(!findpath(root,n1,path1) || !findpath(root,n2,path2))return NULL;
    int i;
    for(i = 0; i < path1.size()-1 && i < path2.size()-1; i++){
        if(path1[i+1] != path2[i+1]){
            return newNode(path1[i]);
        }
    }
    return NULL;
}
// efficient approach
// O(n) time complexity(but now using only 1 path array)
Node*LCA1(Node *root,int n1,int n2){
    if(root == NULL)return NULL;
    if(root ->data == n1 || root ->data == n2)return root;
    Node* left = LCA1(root->left,n1,n2);
    Node *right = LCA1(root->right,n1,n2);
    if(left != NULL && right != NULL){
        return root;
    }
    if(left == NULL){
        return right;
    }
    else{
        return left;
    }

}
int main(){
    int n1 = 4, n2 = 5;
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5); 
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    Node* lca = LCA(root, n1, n2);
    if (lca != NULL) {
        cout << "LCA of " << n1 << " and " << n2 << " is " << lca->data;
    } else {
        cout << "LCA does not exist";
    }
    cout << endl;
    Node* lca1 = LCA1(root, n1, n2);
    if (lca1 != NULL) {
        cout << "LCA of " << n1 << " and " << n2 << " is " << lca1->data;
    } else {
        cout << "LCA does not exist";
    }
    cout << endl;
    
    return 0;
}
