#include <iostream>                 // Include input-output stream
#include <string>                   // Include string class
using namespace std;                // Use standard namespace

struct Node {                       // Node structure for doubly linked list
    string name;                    // Data: desk/person name
    Node* next;                     // Pointer to next node
    Node* prev;                     // Pointer to previous node
};                                  // End of Node structure

Node* createNode(string name) {     // Function to create a new node
    Node* newNode = new Node;       // Allocate memory for new node
    newNode->name = name;           // Set node data
    newNode->next = nullptr;        // Initialize next pointer to null
    newNode->prev = nullptr;        // Initialize prev pointer to null
    return newNode;                 // Return new node
}                                   // End of createNode

void insertAtEnd(Node*& head, string name) { // Insert node at end
    Node* newNode = createNode(name);        // Create new node
    if (head == nullptr) {                   // If list is empty
        head = newNode;                      // New node becomes head
        return;                              // Exit function
    }                                        // End if
    Node* temp = head;                       // Start from head
    while (temp->next != nullptr) {          // Traverse to last node
        temp = temp->next;                   // Move to next node
    }                                        // End while
    temp->next = newNode;                    // Link old last to new node
    newNode->prev = temp;                    // Link new node back to old last
}                                            // End insertAtEnd

void printForward(Node* head) {              // Print list from head to tail
    Node* temp = head;                       // Start from head
    while (temp != nullptr) {                // Until end of list
        cout << temp->name;                  // Print current name
        if (temp->next != nullptr)           // If not last node
            cout << " <-> ";                 // Print separator
        temp = temp->next;                   // Move to next node
    }                                        // End while
    cout << endl;                            // Print new line
}                                            // End printForward

void swapSymmetric(Node* head) {             // Swap first with last, second with second-last, etc.
    if (head == nullptr) return;             // If list empty, do nothing
    Node* tail = head;                       // Start tail from head
    while (tail->next != nullptr) {          // Traverse to last node
        tail = tail->next;                   // Move forward
    }                                        // End while
    Node* left = head;                       // Left pointer starts at head
    Node* right = tail;                      // Right pointer starts at tail
    while (left != right && left->prev != right) { // Stop when pointers meet/cross
        string temp = left->name;            // Store left data
        left->name = right->name;            // Copy right data to left
        right->name = temp;                  // Copy stored data to right
        left = left->next;                   // Move left forward
        right = right->prev;                 // Move right backward
    }                                        // End while
}                                            // End swapSymmetric

int main() {                                 // Main function
    Node* head = nullptr;                    // Initialize empty list
    insertAtEnd(head, "Alice");              // Insert Alice
    insertAtEnd(head, "Bob");                // Insert Bob
    insertAtEnd(head, "Charlie");            // Insert Charlie
    insertAtEnd(head, "Dana");               // Insert Dana
    insertAtEnd(head, "Eva");                // Insert Eva
    insertAtEnd(head, "Frank");              // Insert Frank
    cout << "Original: ";                    // Print label
    printForward(head);                      // Display original list
    swapSymmetric(head);                     // Perform symmetric swaps
    cout << "After swaps: ";                 // Print label
    printForward(head);                      // Display modified list
    return 0;                                // Return success
}                                            // End main
