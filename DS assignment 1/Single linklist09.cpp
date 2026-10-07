#include <iostream>                 // Include input-output library
using namespace std;                // Use standard namespace

struct Node {                       // Node structure
    int data;                       // Book identifier
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

Node* deleteAll(Node* head, int key) { // Delete all matching nodes
    while (head != nullptr && head->data == key) { // If head matches
        Node* temp = head;          // Save head
        head = head->next;          // Move head forward
        delete temp;                // Delete old head
    }
    Node* current = head;           // Start from new head
    while (current != nullptr && current->next != nullptr) { // Traverse
        if (current->next->data == key) { // If next matches
            Node* temp = current->next; // Save matching node
            current->next = current->next->next; // Skip it
            delete temp;            // Delete matching node
        } else {
            current = current->next; // Move current forward
        }
    }
    return head;                    // Return updated head
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
    insertEnd(head, 3);             // Insert 3 at beginning
    insertEnd(head, 5);             // Insert 5
    insertEnd(head, 3);             // Insert 3 in middle
    insertEnd(head, 7);             // Insert 7
    insertEnd(head, 3);             // Insert 3 at end
    cout << "Original: ";           // Label
    printList(head);                // Print original
    head = deleteAll(head, 3);      // Delete all 3s
    cout << "After deleting 3: ";   // Label
    printList(head);                // Print final
    return 0;                       // End program
}
