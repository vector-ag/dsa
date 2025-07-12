// implemetation of the left view of a binary tree

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
// Function to print the left view of a binary tree
void leftViewUtil(Node* root, int level, vector<int>& maxLevel)
{
    // Base case
    if (root == NULL)
        return;

    // If this is the first node of its level
    if (maxLevel.size() < level) {
        maxLevel.push_back(root->data);
    }

    // Recur for left and right subtrees
    leftViewUtil(root->left, level + 1, maxLevel);
    leftViewUtil(root->right, level + 1, maxLevel);
}
// Function to print the left view of a binary tree
void leftView(Node* root)
{
    vector<int> maxLevel;
    leftViewUtil(root, 1, maxLevel);

    // Print the left view
    for (int i = 0; i < maxLevel.size(); i++) {
        cout << maxLevel[i] << " ";
    }
}


//now using iterative approach using level order traversal
// printing the fisrt node of each level
void leftViewIterative(Node* root)
{
    if (root == NULL)
        return;

    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        int n = q.size();
        for (int i = 0; i < n; i++) {
            Node* node = q.front();
            q.pop();

            // Print the first node of this level
            if (i == 0)
                cout << node->data << " ";

            // Add left and right children to the queue
            if (node->left)
                q.push(node->left);
            if (node->right)
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

    cout << "Left view of the binary tree is: ";
    leftView(root);
    cout << endl;
    cout << "Left view of the binary tree using iterative approach is: ";
    leftViewIterative(root);

    return 0;
}