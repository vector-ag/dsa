// doublylinkedlist.cpp
#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};
// Function to create a new node
Node* newNode(int data) {
    Node* node = new Node();
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
    return node;
}
// Function to insert a new node at the end of the doubly linked list
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
    new_node->prev = current;
}
// Function to print the doubly linked list
void printDoublyLinkedList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}
// Function to delete the doubly linked list
void deleteDoublyLinkedList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
}
// Function to search for a value in the doubly linked list
bool searchDoublyLinkedList(Node* head, int value) {
    Node* current = head;
    while (current != NULL) {
        if (current->data == value) {
            return true;  // Value found
        }
        current = current->next;
    }
    return false;  // Value not found
}
//delete function to remove a node with a specific value from the doubly linked list
void deleteNode(Node*& head, int value) {
    if (head == NULL) return;  // List is empty
    if (head->data == value) {
        Node* temp = head;
        head = head->next;  // Move head to next node
        if (head != NULL) {
            head->prev = NULL;  // Update new head's prev pointer
        }
        delete temp;  // Delete old head
        return;
    }
    Node* current = head;
    while (current != NULL && current->data != value) {
        current = current->next;  // Traverse to find the node
    }
    if (current != NULL) {
        if (current->prev != NULL) {
            current->prev->next = current->next;  // Bypass current node
        }
        if (current->next != NULL) {
            current->next->prev = current->prev;  // Update next node's prev pointer
        }
        delete current;  // Delete the node
    }
}
//reverse function to reverse the doubly linked list
void reverseDoublyLinkedList(Node*& head) {
    Node* current = head;
    Node* temp = NULL;
    while (current != NULL) {
        temp = current->prev;  // Store the previous node
        current->prev = current->next;  // Swap next and prev pointers
        current->next = temp;  // Move to the next node
        current = current->prev;  // Move to the next node in the original order
    }
    if (temp != NULL) {
        head = temp->prev;  // Update head to the new first node
    }
}
int main() {
    Node* head = NULL;

    // Insert nodes at the end
    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);

    // Print the doubly linked list
    cout << "Doubly Linked List: ";
    printDoublyLinkedList(head);

    // Search for a value
    int searchValue = 20;
    if (searchDoublyLinkedList(head, searchValue)) {
        cout << "Value " << searchValue << " found in the list." << endl;
    } else {
        cout << "Value " << searchValue << " not found in the list." << endl;
    }

    // Delete a node
    deleteNode(head, 20);
    cout << "After deleting 20: ";
    printDoublyLinkedList(head);

    // Reverse the doubly linked list
    reverseDoublyLinkedList(head);
    cout << "Reversed Doubly Linked List: ";
    printDoublyLinkedList(head);

    // Delete the entire doubly linked list
    deleteDoublyLinkedList(head);
    
    return 0;
}