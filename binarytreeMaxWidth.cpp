//max width of the binary tree
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
// Function to find the maximum width of a binary tree
int MaxWidth(struct Node* root)
{
    if (root == NULL)
        return 0;

    queue<Node*> q;
    q.push(root);
    int maxWidth = 0;

    while (!q.empty()) {
        int count = q.size();
        maxWidth = max(maxWidth, count);

        for (int i = 0; i < count; i++) {
            Node* node = q.front();
            q.pop();
            if (node->left != NULL)
                q.push(node->left);
            if (node->right != NULL)
                q.push(node->right);
        }
    }
    return maxWidth;
}
// Driver code
int main()
{
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    cout << "Maximum width of the binary tree is " << MaxWidth(root) << endl;

    return 0;
}