// detect loop  using hasing in linked list
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
// Function to detect a loop in the linked list using hashing
bool detectLoop(Node* head) {
    unordered_set<Node*> visited;  // Set to store visited nodes
    Node* current = head;
    while (current != NULL) {
        // If the current node is already in the set, a loop is detected
        if (visited.find(current) != visited.end()) {
            return true;  // Loop detected
        }
        visited.insert(current);  // Add the current node to the set
        current = current->next;  // Move to the next node
    }
    return false;  // No loop detected
}
//now using Floyd's Cycle-Finding Algorithm (Tortoise and Hare)
bool detectLoopFloyd(Node* head) {
    if (head == NULL) return false;  // List is empty
    Node* slow = head;  // Slow pointer
    Node* fast = head;  // Fast pointer 
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;  // Move slow pointer by one step
        fast = fast->next->next;  // Move fast pointer by two steps
        if (slow == fast) {
            return true;  // Loop detected
        }
    }
    return false;  // No loop detected
}
// starting node of the loop using Floyd's Cycle-Finding Algorithm
Node* findLoopStart(Node* head) {
    if (head == NULL) return NULL;  // List is empty
    Node* slow = head;  // Slow pointer
    Node* fast = head;  // Fast pointer
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;  // Move slow pointer by one step
        fast = fast->next->next;  // Move fast pointer by two steps 
        if (slow == fast) {  // Loop detected
            Node* start = head;  // Start pointer from head
            while (start != slow) {  // Move both pointers one step at a time
                start = start->next;
                slow = slow->next;
            }
            return start;  // Return the starting node of the loop
        }
    }
    return NULL;  // No loop detected
}
// using hashing to find the starting node of the loop
Node* findLoopStartHashing(Node* head) {
    unordered_set<Node*> visited;  // Set to store visited nodes
    Node* current = head;
    while (current != NULL) {
        // If the current node is already in the set, it's the start of the loop
        if (visited.find(current) != visited.end()) {
            return current;  // Return the starting node of the loop
        }
        visited.insert(current);  // Add the current node to the set
        current = current->next;  // Move to the next node
    }
    return NULL;  // No loop detected
}
//lenght of the loop using Floyd's Cycle-Finding Algorithm
int loopLength(Node* head) {
    if (head == NULL) return 0;  // List is empty
    Node* slow = head;  // Slow pointer
    Node* fast = head;  // Fast pointer
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;  // Move slow pointer by one step
        fast = fast->next->next;  // Move fast pointer by two steps
        if (slow == fast) {  // Loop detected
            int length = 1;  // Initialize length
            Node* temp = slow;  // Start from the meeting point
            while (temp->next != slow) {  // Count the loop length
                length++;
                temp = temp->next;  // Move to the next node
            }
            return length;  // Return the length of the loop
        }
    }
    return 0;  // No loop detected
}
//using hashing to find the length of the loop
int loopLengthHashing(Node* head) {
    unordered_set<Node*> visited;  // Set to store visited nodes
    Node* current = head;
    int length = 0;  // Initialize length
    while (current != NULL) {
        // If the current node is already in the set, it's the start of the loop
        if (visited.find(current) != visited.end()) {
            Node* temp = current;  // Start from the current node
            do {
                length++;  // Count the loop length
                temp = temp->next;  // Move to the next node
            } while (temp != current);  // Continue until we reach the starting node
            return length;  // Return the length of the loop
        }
        visited.insert(current);  // Add the current node to the set
        current = current->next;  // Move to the next node
    }
    return 0;  // No loop detected
}
int main() {
    // Create a linked list: 1 -> 2 -> 3
    Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);

    // Create a loop for testing
    head->next->next->next = head;  // Loop created: 3 -> 1

    // Detect loop
    if (detectLoop(head)) {
        cout << "Loop detected in the linked list." << endl;
    } else {
        cout << "No loop detected in the linked list." << endl;
    }

    // Clean up memory (not reached due to loop)
    // deleteLinkedList(head);  // Uncomment if you want to delete the list without a loop

    return 0;
}