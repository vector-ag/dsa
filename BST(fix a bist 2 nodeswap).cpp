#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

Node* newNode(int data) {
    Node* node = new Node();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node *prevNode = NULL, *first = NULL, *second = NULL;

void fixBST(Node* root) {
    if (root == NULL) return;

    fixBST(root->left);

    if (prevNode != NULL && root->data < prevNode->data) {
        if (first == NULL)
            first = prevNode;
        second = root;
    }

    prevNode = root;

    fixBST(root->right);
}

void recoverBST(Node* root) {
    // Reset pointers
    prevNode = first = second = NULL;
    fixBST(root);
    if (first && second)
        swap(first->data, second->data);
}

void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    /*
           10
          /  \
         5    8  <- wrong, should be 20
        / \
       2   20 <- wrong, should be 8
    */

    Node* root = newNode(10);
    root->left = newNode(5);
    root->right = newNode(8);      // Wrong node
    root->left->left = newNode(2);
    root->left->right = newNode(20); // Wrong node

    cout << "Inorder before fix: ";
    inorder(root);
    cout << endl;

    recoverBST(root);

    cout << "Inorder after fix: ";
    inorder(root);
    cout << endl;

    return 0;
}
