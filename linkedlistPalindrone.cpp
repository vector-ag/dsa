//check linked list is palindrome or not
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
// Function to check if the linked list is a palindrome
bool isPalindrome(Node* head) {
    if (head == NULL || head->next == NULL) return true;  // Empty or single node list is a palindrome
    Node* slow = head;  // Slow pointer 
    Node* fast = head;  // Fast pointer
    stack<int> s;  // Stack to store the first half of the list
    while (fast != NULL && fast->next != NULL) {
        s.push(slow->data);  // Push the first half elements onto the stack
        slow = slow->next;  // Move slow pointer by one step
        fast = fast->next->next;  // Move fast pointer by two steps
    }
    // If the list has an odd number of elements, skip the middle element
    if (fast != NULL) {
        slow = slow->next;  // Move slow pointer to the next node
    }
    while (slow != NULL) {
        if (s.top() != slow->data) {  // Compare the second half with   the stack
            return false;  // Not a palindrome
        }
        s.pop();  // Pop the top element from the stack
        slow = slow->next;  // Move to the next node
    }
    return true;  // All elements matched, it's a palindrome
}
// by reversing the second half of the linked list using Floyd's Cycle-Finding Algorithm
bool isPalindromeReverse(Node* head) {
    if (head == NULL || head->next == NULL) return true;  // Empty or single node list is a palindrome
    Node* slow = head;  // Slow pointer
    Node* fast = head;  // Fast pointer 
    Node* prev = NULL;  // Previous pointer to reverse the second half
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;  // Move fast pointer by two steps
        Node* next = slow->next;  // Store the next node
        slow->next = prev;  // Reverse the link
        prev = slow;  // Move prev pointer to the current node
        slow = next;  // Move slow pointer to the next node
    }
    // If the list has an odd number of elements, skip the middle element
    if (fast != NULL) { 
        slow = slow->next;  // Move slow pointer to the next node
    }
    // Compare the first half with the reversed second half
    Node* firstHalf = prev;  // Start from the end of the first half
    Node* secondHalf = slow;  // Start from the beginning of the second half
    while (firstHalf != NULL && secondHalf != NULL) {
        if (firstHalf->data != secondHalf->data) {
            return false;  // Not a palindrome
        }
        firstHalf = firstHalf->next;  // Move to the next node in the first half
        secondHalf = secondHalf->next;  // Move to the next node in the second half
    }
    return true;  // All elements matched, it's a palindrome
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
    // Create a linked list: 1 -> 2 -> 3 -> 2 -> 1
    Node* head = newNode(1);
    head->next = newNode(2);        
    head->next->next = newNode(3);
    head->next->next->next = newNode(2);
    head->next->next->next->next = newNode(1);  
    // Print the linked list
    cout << "Linked List: ";
    printLinkedList(head);  
    // Check if the linked list is a palindrome
    if (isPalindrome(head)) {
        cout << "The linked list is a palindrome." << endl;
    } else {
        cout << "The linked list is not a palindrome." << endl;
    }
    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5
    head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);    
    head->next->next->next->next = newNode(5);
    // Print the linked list
    cout << "Linked List: ";
    printLinkedList(head);
    // Check if the linked list is a palindrome
    if (isPalindrome(head)) {
        cout << "The linked list is a palindrome." << endl;
    } else {
        cout << "The linked list is not a palindrome." << endl;
    }
    // Check using reverse method
    if (isPalindromeReverse(head)) {
        cout << "The linked list is a palindrome using reverse method." << endl;
    } else {
        cout << "The linked list is not a palindrome using reverse method." << endl;
    }
    // Clean up memory
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        delete temp;  // Delete each node
    }
    cout << "Memory cleaned up." << endl;
    // Return 0 to indicate successful execution
    cout << "Program completed successfully." << endl;
    cout << "Exiting the program." << endl;     
    return 0;  // Exit the program

}