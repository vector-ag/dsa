// print all those nodes which are at kth distance from the root node of a binary tree.

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
// Function to print all nodes at distance k from a given node
void printKDistanceNodes(Node* root, int k)
{
    // Base case
    if (root == NULL || k < 0)
        return;

    // If we reach a k distant node, print it
    if (k == 0) {
        cout << root->data << " ";
    }

    // Recur for left and right subtrees
    printKDistanceNodes(root->left, k - 1);
    printKDistanceNodes(root->right, k - 1);
}
int main(){
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    int k = 2;
    cout << "Nodes at distance " << k << " from the root are: ";
    printKDistanceNodes(root, k);

    return 0;
}