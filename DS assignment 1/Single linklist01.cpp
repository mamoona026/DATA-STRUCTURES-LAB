#include <iostream>                 // Include input-output library
using namespace std;                // Use standard namespace

struct Node {                       // Define node structure
    int data;                       // Store integer data
    Node* next;                     // Pointer to next node
};

Node* createNode(int value) {       // Function to create a new node
    Node* n = new Node;             // Allocate memory for node
    n->data = value;                // Set data value
    n->next = nullptr;              // Set next pointer to null
    return n;                       // Return new node
}

void insertEnd(Node*& head, int value) { // Insert node at end
    Node* n = createNode(value);    // Create new node
    if (head == nullptr) {          // If list is empty
        head = n;                   // Make new node the head
        return;                     // Exit function
    }
    Node* temp = head;              // Start from head
    while (temp->next != nullptr) { // Traverse to last node
        temp = temp->next;          // Move to next node
    }
    temp->next = n;                 // Link last node to new node
}

void printReverse(Node* head) {     // Print list in reverse order
    if (head == nullptr) return;    // Base case: empty node
    printReverse(head->next);       // Recursively go to end
    cout << head->data << " ";      // Print while returning back
}

void printForward(Node* head) {     // Print list in normal order
    Node* temp = head;              // Start from head
    while (temp != nullptr) {       // Until end of list
        cout << temp->data << " ";  // Print current data
        temp = temp->next;          // Move forward
    }
    cout << endl;                   // Print newline
}

int main() {                        // Main function
    Node* head = nullptr;           // Initially empty list
    insertEnd(head, 10);            // Insert 10
    insertEnd(head, 20);            // Insert 20
    insertEnd(head, 30);            // Insert 30
    insertEnd(head, 40);            // Insert 40
    cout << "Forward: ";            // Print label
    printForward(head);             // Print normal list
    cout << "Reverse: ";            // Print label
    printReverse(head);             // Print reversed order
    cout << endl;                   // Print newline
    return 0;                       // End program
}
