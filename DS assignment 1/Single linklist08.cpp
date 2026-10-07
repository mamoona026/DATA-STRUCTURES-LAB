#include <iostream>                 // Include input-output library
using namespace std;                // Use standard namespace

struct Node {                       // Node structure
    int data;                       // Stamp design ID
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

void removeDuplicates(Node* head) { // Remove duplicate stamps
    Node* current = head;           // Start from head
    while (current != nullptr && current->next != nullptr) { // For each node
        Node* runner = current;     // Runner starts at current
        while (runner->next != nullptr) { // Check later nodes
            if (runner->next->data == current->data) { // If duplicate
                Node* dup = runner->next; // Save duplicate
                runner->next = runner->next->next; // Skip duplicate
                delete dup;         // Delete duplicate
            } else {
                runner = runner->next; // Move runner
            }
        }
        current = current->next;    // Move current
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
    insertEnd(head, 101);           // Insert stamp
    insertEnd(head, 102);           // Insert stamp
    insertEnd(head, 101);           // Insert duplicate
    insertEnd(head, 103);           // Insert stamp
    insertEnd(head, 102);           // Insert duplicate
    cout << "Original stamps: ";    // Label
    printList(head);                // Print original
    removeDuplicates(head);         // Remove duplicates
    cout << "Unique stamps: ";      // Label
    printList(head);                // Print final
    return 0;                       // End program
}
