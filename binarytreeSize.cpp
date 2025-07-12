//size of a given binary tree

#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
and a pointer to right child */
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
// Function to calculate the size of a binary tree
int size(Node* root)
{
    // Base case: if the tree is empty
    if (root == NULL)
        return 0;

    // Recursively calculate the size of left and right subtrees
    return 1 + size(root->left) + size(root->right);
}
// Driver code
int main()
{
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    // Function call
    cout << "Size of the binary tree is: " << size(root) << endl;

    return 0;
}