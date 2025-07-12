// finding pair with given sum in a bst;
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;
};
Node* newNode(int data){
    Node* node = new Node();
    node-> data = data;
    node -> left = NULL;
    node -> right = NULL;
    return node;
}

// efficient solution for this
bool pairofsum(Node *root,int sum,unordered_set<int>&s){
    if(root== NULL)return false;
    if(pairofsum(root->left,sum,s) == true){
        return true;
    }
    if(s.find(sum-root->data) != s.end()){
        cout << "Pair found: (" << sum - root->data << ", " << root->data << ")\n";
        return true;
    }
    else{
        s.insert(root->data);
    }
    return pairofsum(root->right,sum,s);
}
bool findPair(Node* root, int sum) {
    unordered_set<int> s;
    return pairofsum(root, sum, s);
}
void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    /*
          15
         /  \
        10   20
       / \   / \
      8  12 16 25
    */

    Node* root = newNode(15);
    root->left = newNode(10);
    root->right = newNode(20);
    root->left->left = newNode(8);
    root->left->right = newNode(12);
    root->right->left = newNode(16);
    root->right->right = newNode(25);

    cout << "Inorder Traversal of BST: ";
    inorder(root);
    cout << endl;

    int sum = 33;

    if (!findPair(root, sum)) {
        cout << "No pair found with sum " << sum << endl;
    }
    else{
        cout << "pair found with given sum" << endl;
    }

    return 0;
}