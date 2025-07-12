// implementing children sum property in binary tree

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *left, *right;
};
// Utility function to create a new tree node
struct Node* newNode(int data){
    struct Node* temp = new Node;
    temp->data=data;
    temp->left = NULL;
    temp ->right = NULL;
    return temp;
}
// Function to check if a binary tree satisfies the children sum property
bool isChildrenSumProperty(struct Node* root){
    // Base case: if the node is NULL, return true
    if (root == NULL)
        return true;

    // If the node is a leaf node, return true
    if (root->left == NULL && root->right == NULL)
        return true;

    // Get the sum of left and right children
    int leftData = (root->left != NULL) ? root->left->data : 0;
    int rightData = (root->right != NULL) ? root->right->data : 0;

    // Check if the current node's data is equal to the sum of its children's data
    if (root->data == leftData + rightData)
        return isChildrenSumProperty(root->left) && isChildrenSumProperty(root->right);

    // If the condition is not satisfied, return false
    return false;
}
// Driver code
int main(){
    struct Node* root = newNode(10);
    root->left = newNode(8);
    root->right = newNode(2);
    root->left->left = newNode(3);
    root->left->right = newNode(5);
    root->right->left = newNode(2);

    if (isChildrenSumProperty(root))
        cout << "The tree satisfies the children sum property." << endl;
    else
        cout << "The tree does not satisfy the children sum property." << endl;

    return 0;
}