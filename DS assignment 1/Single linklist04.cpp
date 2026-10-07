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

bool detectLoop(Node* head) {       // Detect loop using Floyd cycle
    Node* slow = head;              // Slow pointer starts head
    Node* fast = head;              // Fast pointer starts head
    while (fast != nullptr && fast->next != nullptr) { // While fast can move
        slow = slow->next;          // Move slow by one
        fast = fast->next->next;    // Move fast by two
        if (slow == fast) {         // If pointers meet
            return true;            // Loop exists
        }
    }
    return false;                   // No loop found
}

int main() {                        // Main function
    Node* head = createNode(1);     // Create first node
    head->next = createNode(2);     // Add second node
    head->next->next = createNode(3); // Add third node
    head->next->next->next = createNode(4); // Add fourth node
    head->next->next->next->next = head->next; // Create loop to node 2
    if (detectLoop(head)) {         // Check loop
        cout << "Loop detected" << endl; // Print if loop
    } else {
        cout << "No loop" << endl;  // Print if no loop
    }
    return 0;                       // End program
}
