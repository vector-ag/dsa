#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node* next;
};
// Function to create a new node
Node* newNode(int data) {
    Node* node = new Node();
    node->data = data;
    node->next = NULL;
    return node;
}
// array to linked list conversion
Node* arrayToLinkedList(vector<int>& arr) {
    if (arr.empty()) return NULL;
    Node* head = newNode(arr[0]);
    Node* current = head;
    for (size_t i = 1; i < arr.size(); ++i) {
        current->next = newNode(arr[i]);
        current = current->next;
    }
    return head;
}
// traversal function to print linked list
void printLinkedList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}
//search function to find a value in the linked list
bool searchLinkedList(Node* head, int value) {
    Node* current = head;   
    while (current != NULL) {
        if (current->data == value) {
            return true;  // Value found
        }
        current = current->next;
    }
    return false;  // Value not found
}
// Function to delete a linked list
void deleteLinkedList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
}
//insert function to add a new node at the end of the linked list
void insertAtEnd(Node*& head, int data) {
    Node* new_node = newNode(data);
    if (head == NULL) {
        head = new_node;
        return;
    }
    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
}
// Function to delete a node with a specific value
void deleteNode(Node*& head, int value) {
    if (head == NULL) return;  // List is empty
    if (head->data == value) {
        Node* temp = head;
        head = head->next;  // Move head to next node
        delete temp;  // Delete old head
        return;
    }
    Node* current = head;
    while (current->next != NULL && current->next->data != value) {
        current = current->next;  // Traverse to find the node
    }
    if (current->next != NULL) {
        Node* temp = current->next;  // Node to be deleted
        current->next = current->next->next;  // Bypass the node
        delete temp;  // Delete the node
    }
}

// reverse linked list using recursion
void reverseLinkedListRec(Node*& head) {
    if (head == NULL || head->next == NULL) return;  // Base case
    Node* rest = head->next;  // Store the rest of the list
    reverseLinkedListRec(rest);  // Reverse the rest of the list
    head->next->next = head;  // Make the current node point to itself
    head->next = NULL;  // Set the next of current node to NULL
    head = rest;  // Update head to the new first node
}
// reverse linked list iteratively
void reverseLinkedListIter(Node*& head) {
    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;
    while (current != NULL) {
        next = current->next;  // Store next node
        current->next = prev;  // Reverse the link
        prev = current;  // Move prev to current
        current = next;  // Move to next node
    }
    head = prev;  // Update head to the new first node
}
int main() {
    // Create a linked list: 1 -> 2 -> 3
    Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);

    // Print the linked list
    Node* current = head;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;

    // Free the allocated memory
    current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}