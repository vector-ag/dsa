// deletion in a binary search tree
#include<bits/stdc++.h>
using namespace std;
// Binary Search Tree Node
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
void printInorder(struct Node* node)
{
	if (node == NULL)
		return;

	/* first recur on left child */
	printInorder(node->left);

	/* then print the data of node */
	cout << node->data << " ";

	/* now recur on right child */
	printInorder(node->right);
}
// funtion to get succersor;
Node * getsuccessor(Node * root){
    Node * curr = root -> right;
    while(curr != NULL && curr -> left != NULL){
        curr = curr -> left;
    }
    return curr;
}
Node* deleteNode(Node *root,int key){
    if( root == NULL)return root;
    if(key < root-> data){
        root -> left = deleteNode(root->left,key);
    }
    else if(key > root -> data){
        root -> right = deleteNode(root->right,key);
    }
    else{
        // case1 no child
        if(root -> left == NULL && root -> right == NULL){
            delete root;
            return NULL;
        }
        // case2 one child
        else if(root -> left == NULL){
            Node *temp = root -> right;
            delete root;
            return temp;
        }
        else if(root -> right == NULL){
            Node *temp = root -> left;
            delete root;
            return temp;
        }
        // case2 2 children
        else{
            Node * succ = getsuccessor(root);
            root -> data = succ -> data;
            root -> right = deleteNode(root->right,succ-> data);
        }
    }
    return root;
}
int main(){
    Node* root = newNode(10);
    root->left = newNode(5);
    root->right = newNode(15);
    root->left->left = newNode(3);
    root->left->right = newNode(7);
    root->right->right = newNode(18);
    
    cout << "Inorder traversal of the BST before deletion:\n";
    printInorder(root);
    cout << endl;
    cout << "Deleting 10\n";
    root = deleteNode(root, 10);
    
    cout << "Deleting 5\n";
    root = deleteNode(root, 5);
    
    cout << "Deleting 15\n";
    root = deleteNode(root, 15);
    cout << "Inorder traversal of the BST after deletion:\n";
    printInorder(root);
    cout << endl;
    
    return 0;
}