// print level order traversal of a binary tree.

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
// another way to print level order traversal;
void printLevelOrder2(Node* root)
{
    if (root == NULL)
        return;

    // Create a queue to store nodes at each level
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* node = q.front();
        cout << node->data << " ";
        q.pop();

        // Add left and right children to the queue
        if (node->left != NULL)
            q.push(node->left);
        if (node->right != NULL)
            q.push(node->right);
    }
}

// another way to print level order traversal (line by line)
 void printLevelOrder3(Node* root){
    if (root == NULL)
        return;
    // Create a queue to store nodes at each level
    queue<Node*> q;
    q.push(root);
    q.push(NULL); // Marker for end of level
    while (!q.empty()) {
        Node* node = q.front();i
        q.pop();

        // If we reach the end of a level
        if (node == NULL) {
            cout << endl; // Move to the next line after each level
            if (!q.empty())
                q.push(NULL); // Add marker for next level
        } else {
            cout << node->data << " ";
            // Add left and right children to the queue
            if (node->left != NULL)
                q.push(node->left);
            if (node->right != NULL)
                q.push(node->right);
        }
    }
    cout << endl; // Print a final newline after the last level
 }
int main()
{
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    cout << "\nLevel order traversal of binary tree is: \n";
    printLevelOrder2(root);

    cout << "\nLevel order traversal(line by line) of binary tree is: \n";   
    printLevelOrder3(root);

    return 0;
}