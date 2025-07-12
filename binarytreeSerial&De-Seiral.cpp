#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

// Function to create a new node
Node* newNode(int data) {
    Node* node = new Node();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to serialize the binary tree
void serialize(Node *root, vector<int>& v) {
    if (root == NULL) {
        v.push_back(-1);  // marker for NULL
        return;
    }
    v.push_back(root->data);
    serialize(root->left, v);
    serialize(root->right, v);
}

// Deserialize helper with index passed by reference
Node* deserializeHelper(vector<int>& v, int& index) {
    if (index == v.size()) return NULL;

    int val = v[index];
    index++;

    if (val == -1) return NULL;

    Node* root = newNode(val);
    root->left = deserializeHelper(v, index);
    root->right = deserializeHelper(v, index);

    return root;
}

Node* deserialize(vector<int>& v) {
    int index = 0;  // reset index each time
    return deserializeHelper(v, index);
}

// Utility function for preorder traversal (for verification)
void preorder(Node* root) {
    if (!root) {
        cout << -1 << " ";
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    // Construct a binary tree
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    // Serialize the tree
    vector<int> v;
    serialize(root, v);

    cout << "Serialized binary tree: ";
    for (int val : v) {
        cout << val << " ";
    }
    cout << endl;

    // Deserialize
    Node* deserializedRoot = deserialize(v);

    // Verify with preorder traversal
    cout << "Deserialized binary tree (preorder traversal): ";
    preorder(deserializedRoot);
    cout << endl;

    return 0;
}
