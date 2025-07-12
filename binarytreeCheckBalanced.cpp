//implementation of a function that checks if a binary tree is balanced.

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *left,*right;
};
// Utility function to create a new tree node
struct Node* newNode(int data){
    struct Node* temp = new Node;
    temp ->data = data;
    temp ->left = NULL;
    temp->right = NULL;
    return temp;
}
// Function to check if a binary tree is balanced
// this function take O(n^2) time complexity
// because it calls isBalanced function for each node
bool isBalanced(struct Node* root){
    // Base case: if the node is NULL, return true
    if (root == NULL)
        return true;

    // Get the height of left and right subtrees
    int leftHeight = isBalanced(root->left);
    int rightHeight = isBalanced(root->right);

    // Check if the current node is balanced
    if (abs(leftHeight - rightHeight) <= 1 && isBalanced(root->left) && isBalanced(root->right))
        return true;

    // If the condition is not satisfied, return false
    return false;
}

//efficient implementation of isBalanced function
// this function take O(n) time complexity
// because it calculates the height of the tree in a single traversal
int isbalanced(struct Node* root){
    if(root == NULL){
        return 0;
    }
    int lefthight = isbalanced(root->left);
    if(lefthight == -1){
        return -1;
    }
    int righthight = isbalanced(root->right);
    if(righthight == -1){
        return -1;
    }
    if(abs(lefthight - righthight) > 1){
        return -1;
    }
    return max(lefthight, righthight) + 1;
}
// Driver code
int main(){
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    if (isBalanced(root))
        cout << "The tree is balanced." << endl;
    else
        cout << "The tree is not balanced." << endl;

    if(isbalanced(root) != -1){
        cout << "The tree is balanced." << endl;
    }
    else{
        cout << "The tree is not balanced." << endl;
    }

    return 0;
}

