#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int data) {
    Node* node = new Node();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Level order traversal to maintain top-to-bottom order within each vertical
void verticalTraverasl(Node* root) {
    map<int, vector<int>> mp; // FIXED THIS LINE
    queue<pair<Node*, int>> q;
    q.push({root, 0});

    while (!q.empty()) {
        auto p = q.front();
        q.pop();
        Node* curr = p.first;
        int hd = p.second;

        mp[hd].push_back(curr->data);

        if (curr->left != NULL) {
            q.push({curr->left, hd - 1});
        }
        if (curr->right != NULL) {
            q.push({curr->right, hd + 1});
        }
    }

    cout << "Vertical order traversal:\n";
    for (auto pr : mp) {
        for (int val : pr.second) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    /*
            1
           / \
          2   3
         / \   \
        4   5   6
    */

    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);

    verticalTraverasl(root);

    return 0;
}
