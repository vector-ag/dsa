// interative preorder traversal of a binary tree
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
// Function to perform iterative preorder traversal
void iterativePreorder(Node *root){
    if(root == NULL)return;
    stack<Node*>st;
    st.push(root);
    while(st.empty() == false){
        Node * curr = st.top();
        st.pop();
        cout << curr -> data << " ";
        if(curr -> right  != NULL){
            st.push(curr -> right);
        }
        if(curr->left != NULL){
            st.push(curr -> left);
        }
    }  
}
// preorder using space optimized solution
void iterativepreorder(Node *root){
    if(root == NULL)return;
    stack<Node*>st;
    Node* curr = root;
    while(curr != NULL || st.empty() == false){
        while(curr != NULL){
            cout << curr -> data << " ";
            if(curr -> right != NULL){
                st.push(curr -> right);
            }
            curr = curr -> left;
        }
        if(st.empty() == false){
            curr = st.top();
            st.pop();
        }
        else{
            curr = NULL;
        }
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
    
    cout << "Iterative preorder traversal of the binary tree: " << endl;
    iterativePreorder(root);
    cout << endl;
    cout << "Iterative preorder traversal of the binary tree using space optimized solution: " << endl;
    iterativepreorder(root);
    cout << endl;
    return 0;
}