#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

Node* newNode(int data) {
    Node* temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Function to convert binary tree to doubly linked list
void convertToDLL(Node* root, Node*& head, Node*& prev) {
    if (root == NULL) return;

    // Recursively convert the left subtree
    convertToDLL(root->left, head, prev);

    // Process current node
    if (prev == NULL) {
        head = root;
    } else {
        root->left = prev;
        prev->right = root;
    }
    prev = root;

    // Recursively convert the right subtree
    convertToDLL(root->right, head, prev);
}

// Utility function to print the doubly linked list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->right;
    }
    cout << endl;
}

int main() {
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    Node* head = NULL;
    Node* prev = NULL;

    convertToDLL(root, head, prev);

    cout << "Doubly linked list is: ";
    printList(head);

    return 0;
}
