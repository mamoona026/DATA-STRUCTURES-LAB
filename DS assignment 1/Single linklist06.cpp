#include <iostream>                 // Include input-output library
using namespace std;                // Use standard namespace

struct Node {                       // Node structure
    int data;                       // Fruit price
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

void splitEvenOdd(Node* head, Node*& evenHead, Node*& oddHead) { // Split list
    evenHead = nullptr;             // Even list head
    oddHead = nullptr;              // Odd list head
    Node* evenTail = nullptr;       // Even list tail
    Node* oddTail = nullptr;        // Odd list tail
    Node* curr = head;              // Start from head
    while (curr != nullptr) {       // Traverse original list
        Node* nextNode = curr->next; // Save next node
        curr->next = nullptr;       // Detach current node
        if (curr->data % 2 == 0) {  // If price is even
            if (evenHead == nullptr) { // First even node
                evenHead = curr;    // Set even head
                evenTail = curr;    // Set even tail
            } else {
                evenTail->next = curr; // Link to even list
                evenTail = curr;    // Update even tail
            }
        } else {                    // If price is odd
            if (oddHead == nullptr) { // First odd node
                oddHead = curr;     // Set odd head
                oddTail = curr;     // Set odd tail
            } else {
                oddTail->next = curr; // Link to odd list
                oddTail = curr;     // Update odd tail
            }
        }
        curr = nextNode;            // Move to next node
    }
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
    insertEnd(head, 10);            // Insert even
    insertEnd(head, 15);            // Insert odd
    insertEnd(head, 22);            // Insert even
    insertEnd(head, 7);             // Insert odd
    insertEnd(head, 8);             // Insert even
    Node* evenHead = nullptr;       // Even list head
    Node* oddHead = nullptr;        // Odd list head
    splitEvenOdd(head, evenHead, oddHead); // Split list
    cout << "Even prices: ";        // Label
    printList(evenHead);            // Print even list
    cout << "Odd prices: ";         // Label
    printList(oddHead);             // Print odd list
    return 0;                       // End program
}
