#include <iostream>                 // Include input-output library
using namespace std;                // Use standard namespace

struct Node {                       // Define node structure
    int data;                       // Store data
    Node* next;                     // Pointer to next node
};

Node* createNode(int value) {       // Create new node
    Node* n = new Node;             // Allocate memory
    n->data = value;                // Set data
    n->next = nullptr;              // Set next null
    return n;                       // Return node
}

void insertEnd(Node*& head, int value) { // Insert at end
    Node* n = createNode(value);    // Create node
    if (head == nullptr) {          // If empty list
        head = n;                   // Set head
        return;                     // Exit
    }
    Node* temp = head;              // Start from head
    while (temp->next != nullptr) { // Go to last node
        temp = temp->next;          // Move forward
    }
    temp->next = n;                 // Link last node
}

Node* reverseList(Node* head) {     // Reverse linked list
    Node* prev = nullptr;           // Previous pointer starts null
    Node* curr = head;              // Current pointer starts head
    Node* next = nullptr;           // Next pointer for saving
    while (curr != nullptr) {       // Traverse all nodes
        next = curr->next;          // Save next node
        curr->next = prev;          // Reverse current link
        prev = curr;                // Move prev forward
        curr = next;                // Move curr forward
    }
    return prev;                    // New head is prev
}

void printList(Node* head) {        // Print linked list
    Node* temp = head;              // Start from head
    while (temp != nullptr) {       // Until end
        cout << temp->data << " ";  // Print data
        temp = temp->next;          // Move next
    }
    cout << endl;                   // Newline
}

int main() {                        // Main function
    Node* head = nullptr;           // Empty list
    insertEnd(head, 1);             // Insert 1
    insertEnd(head, 2);             // Insert 2
    insertEnd(head, 3);             // Insert 3
    insertEnd(head, 4);             // Insert 4
    cout << "Original: ";           // Label
    printList(head);                // Print original
    head = reverseList(head);       // Reverse list
    cout << "Reversed: ";           // Label
    printList(head);                // Print reversed
    return 0;                       // End program
}
