// middle element in linked list using Tortoise and hare algorithm
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
// Function to find the middle element of the linked list
Node* findMiddle(Node* head) {
    if (head == NULL) return NULL;  // List is empty
    Node* slow = head;  // Slow pointer
    Node* fast = head;  // Fast pointer
    while (fast != NULL && fast->next != NULL) {  
        slow = slow->next;  // Move slow pointer by one step
        fast = fast->next->next;  // Move fast pointer by two steps
    }
    return slow;  // Slow pointer will be at the middle node
}
// Function to print the linked list
void printLinkedList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;   
}  
int main() {
    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5
    Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);

    // Print the linked list
    cout << "Linked List: ";
    printLinkedList(head);

    // Find and print the middle element
    Node* middle = findMiddle(head);
    if (middle != NULL) {
        cout << "Middle Element: " << middle->data << endl;
    } else {
        cout << "The list is empty." << endl;
    }
    //for even length linked list
    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5 -> 6
    head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);
    head->next->next->next->next->next = newNode(6);
    // Print the linked list
    cout << "Linked List: ";
    printLinkedList(head);
    // Find and print the middle element
    middle = findMiddle(head);
    if (middle != NULL) {
        cout << "Middle Element: " << middle->data << endl;
    } else {
        cout << "The list is empty." << endl;
    }

    // Clean up memory
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}