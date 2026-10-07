#include <iostream>                 // Include input-output library
using namespace std;                // Use standard namespace

struct Node {                       // Node structure
    int data;                       // Task ID
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

Node* swapPairs(Node* head) {       // Swap every two nodes
    if (head == nullptr || head->next == nullptr) return head; // If less than 2 nodes
    Node* newHead = head->next;     // Second node becomes new head
    Node* prev = nullptr;           // Previous pair tail
    Node* curr = head;              // Current node
    while (curr != nullptr && curr->next != nullptr) { // While pair exists
        Node* first = curr;         // First node of pair
        Node* second = curr->next;  // Second node of pair
        Node* nextPair = second->next; // Next pair start
        second->next = first;       // Second points to first
        first->next = nextPair;     // First points to next pair
        if (prev != nullptr) {      // If previous pair exists
            prev->next = second;    // Connect previous pair to second
        }
        prev = first;               // First becomes previous tail
        curr = nextPair;            // Move to next pair
    }
    return newHead;                 // Return new head
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
    insertEnd(head, 1);             // Insert 1
    insertEnd(head, 2);             // Insert 2
    insertEnd(head, 3);             // Insert 3
    insertEnd(head, 4);             // Insert 4
    insertEnd(head, 5);             // Insert 5
    insertEnd(head, 6);             // Insert 6
    cout << "Original: ";           // Label
    printList(head);                // Print original
    head = swapPairs(head);         // Swap pairs
    cout << "After swapping pairs: "; // Label
    printList(head);                // Print result
    return 0;                       // End program
}
