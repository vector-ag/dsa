// implementation of the binary tree maximum algorithm

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *left, *right;
};
// Utility function to create a new tree node
Node* newNode(int data)
{
    Node* temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
// Function to find the maximum value in a binary tree
int findMax(Node* root)
{
    // Base case: if the tree is empty
    if (root == NULL)
        return INT_MIN; // Return a very small value

    // Recursively find the maximum value in left and right subtrees
    int leftMax = findMax(root->left);
    int rightMax = findMax(root->right);

    // Return the maximum of the current node's data, left max, and right max
    return max(root->data, max(leftMax, rightMax));
}
int main()
{
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    // Function call
    cout << "Maximum value in the binary tree is: " << findMax(root) << endl;

    return 0;
}