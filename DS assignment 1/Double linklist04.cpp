#include <iostream>                 // Include input-output stream
using namespace std;                // Use standard namespace

struct Node {                       // Node structure for doubly linked list
    int data;                       // Seat number
    Node* next;                     // Pointer to next node
    Node* prev;                     // Pointer to previous node
};                                  // End Node structure

Node* createNode(int data) {        // Create a new node
    Node* newNode = new Node;       // Allocate memory
    newNode->data = data;           // Set data
    newNode->next = nullptr;        // Next null
    newNode->prev = nullptr;        // Prev null
    return newNode;                 // Return new node
}                                   // End createNode

void insertAtEnd(Node*& head, int data) { // Insert node at end
    Node* newNode = createNode(data);     // Create new node
    if (head == nullptr) {                // If list empty
        head = newNode;                   // New node becomes head
        return;                           // Exit
    }                                     // End if
    Node* temp = head;                    // Start from head
    while (temp->next != nullptr) {       // Go to last node
        temp = temp->next;                // Move next
    }                                     // End while
    temp->next = newNode;                 // Link old last to new
    newNode->prev = temp;                 // Link new back to old last
}                                         // End insertAtEnd

void printForward(Node* head) {           // Print list forward
    Node* temp = head;                    // Start from head
    while (temp != nullptr) {             // Until end
        cout << temp->data;               // Print data
        if (temp->next != nullptr)        // If not last
            cout << " -> ";               // Print arrow
        temp = temp->next;                // Move next
    }                                     // End while
    cout << " -> NULL" << endl;           // Print end
}                                         // End printForward

void alternateSwap(Node* head) {          // Swap seats alternately from both ends
    if (head == nullptr) return;          // If empty, do nothing
    int n = 1;                            // Count nodes, start with 1
    Node* tail = head;                    // Tail pointer
    while (tail->next != nullptr) {       // Traverse to last node
        tail = tail->next;                // Move forward
        n++;                              // Increment count
    }                                     // End while
    if (n < 3) return;                    // Need at least 3 nodes
    Node* left = head->next;              // Left starts at second node
    Node* right = tail->prev;             // Right starts at second-last node
    for (int l = 2, r = n - 1; l < r; l += 2, r -= 2) { // Swap pairs
        int temp = left->data;            // Store left data
        left->data = right->data;         // Copy right to left
        right->data = temp;               // Copy temp to right
        if (left->next != nullptr && left->next->next != nullptr) // If can move two steps
            left = left->next->next;      // Move left forward two
        else
            left = nullptr;               // Otherwise null
        if (right->prev != nullptr && right->prev->prev != nullptr) // If can move two steps
            right = right->prev->prev;    // Move right backward two
        else
            right = nullptr;              // Otherwise null
    }                                     // End for
}                                         // End alternateSwap

int main() {                              // Main function
    Node* head = nullptr;                 // Initialize empty list
    for (int i = 1; i <= 9; i++) {        // Insert 1 to 9
        insertAtEnd(head, i);             // Insert each number
    }                                     // End for
    cout << "Original: ";                 // Print label
    printForward(head);                   // Display original
    alternateSwap(head);                  // Perform alternate swaps
    cout << "After calling method: ";     // Print label
    printForward(head);                   // Display modified
    return 0;                             // Return success
}                                         // End main
