#include <iostream>                 // Include input-output library
using namespace std;                // Use standard namespace

struct Node {                       // Node structure
    int data;                       // Store data
    Node* next;                     // Next pointer
};

Node* createNode(int value) {       // Create node
    Node* n = new Node;             // Allocate memory
    n->data = value;                // Set data
    n->next = nullptr;              // Set next null
    return n;                       // Return node
}

void insertEnd(Node*& head, int value) { // Insert at end
    Node* n = createNode(value);    // Create node
    if (head == nullptr) {          // If empty
        head = n;                   // Set head
        return;                     // Exit
    }
    Node* temp = head;              // Start from head
    while (temp->next != nullptr) { // Go to last
        temp = temp->next;          // Move forward
    }
    temp->next = n;                 // Link last node
}

Node* reverseNodes(Node* head) {    // Reverse a list
    Node* prev = nullptr;           // Previous pointer
    Node* curr = head;              // Current pointer
    Node* next = nullptr;           // Next pointer
    while (curr != nullptr) {       // Traverse list
        next = curr->next;          // Save next
        curr->next = prev;          // Reverse link
        prev = curr;                // Move prev
        curr = next;                // Move curr
    }
    return prev;                    // Return new head
}

Node* reverseHalves(Node* head) {   // Reverse both halves
    if (head == nullptr || head->next == nullptr) return head; // If 0 or 1 node
    int n = 0;                      // Count nodes
    Node* temp = head;              // Start from head
    while (temp != nullptr) {       // Count all nodes
        n++;                        // Increase count
        temp = temp->next;          // Move next
    }
    int firstCount = n / 2;         // First half size
    Node* firstHead = head;         // First half head
    Node* firstTail = head;         // First half tail
    for (int i = 1; i < firstCount; i++) { // Find first half tail
        firstTail = firstTail->next; // Move forward
    }
    Node* secondHead = firstTail->next; // Second half head
    firstTail->next = nullptr;      // Split list
    Node* newFirstHead = reverseNodes(firstHead); // Reverse first half
    Node* newSecondHead = reverseNodes(secondHead); // Reverse second half
    firstHead->next = newSecondHead; // Connect first half tail to second half
    return newFirstHead;            // Return new head
}

void printList(Node* head) {        // Print list
    Node* temp = head;              // Start from head
    while (temp != nullptr) {       // Until end
        cout << temp->data << " ";  // Print data
        temp = temp->next;          // Move next
    }
    cout << endl;                   // Newline
}

int main() {                        // Main function
    Node* head = nullptr;           // Empty list
    for (int i = 1; i <= 8; i++) {  // Insert 1 to 8
        insertEnd(head, i);         // Insert current number
    }
    cout << "Original: ";           // Label
    printList(head);                // Print original
    head = reverseHalves(head);     // Reverse halves
    cout << "After reversing halves: "; // Label
    printList(head);                // Print result
    return 0;                       // End program
}
