#include <iostream>                 // Include input-output library
using namespace std;                // Use standard namespace

struct Node {                       // Node structure
    int data;                       // Contact ID
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

void removeDuplicates(Node* head) { // Remove duplicate values
    Node* current = head;           // Start from head
    while (current != nullptr && current->next != nullptr) { // Traverse each node
        Node* runner = current;     // Runner starts from current
        while (runner->next != nullptr) { // Check all later nodes
            if (runner->next->data == current->data) { // If duplicate found
                Node* dup = runner->next; // Save duplicate node
                runner->next = runner->next->next; // Skip duplicate
                delete dup;         // Delete duplicate node
            } else {
                runner = runner->next; // Move runner forward
            }
        }
        current = current->next;    // Move current forward
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
    insertEnd(head, 10);            // Insert 10
    insertEnd(head, 20);            // Insert 20
    insertEnd(head, 10);            // Insert duplicate 10
    insertEnd(head, 30);            // Insert 30
    insertEnd(head, 20);            // Insert duplicate 20
    cout << "Original: ";           // Label
    printList(head);                // Print original
    removeDuplicates(head);         // Remove duplicates
    cout << "After removing duplicates: "; // Label
    printList(head);                // Print final list
    return 0;                       // End program
}
