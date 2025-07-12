// implementaion of the iterative inorder traversal of a binary tree
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
// Function to perform iterative inorder traversal
void iterativeinorder(Node *root){
    stack<Node*>st;
    Node*curr = root;
    while(curr != NULL || st.empty() == false){
        while(curr != NULL){
            st.push(curr);
            curr = curr ->left;
        }
        curr = st.top();
        st.pop();
        cout << curr->data << " ";
        curr = curr -> right;
    }
}
// Driver code
int main(){
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    
    cout << "Iterative inorder traversal of the binary tree: ";
    iterativeinorder(root);
    
    return 0;
}