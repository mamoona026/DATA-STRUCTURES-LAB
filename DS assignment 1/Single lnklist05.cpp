#include <iostream>                 // Include input-output library
using namespace std;                // Use standard namespace

struct Node {                       // Node structure
    int data;                       // Friend ID
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

Node* findLeftMiddle(Node* head) {  // Find left middle node
    if (head == nullptr) return nullptr; // Empty list
    Node* slow = head;              // Slow pointer
    Node* fast = head;              // Fast pointer
    while (fast->next != nullptr && fast->next->next != nullptr) { // For left middle
        slow = slow->next;          // Move slow by one
        fast = fast->next->next;    // Move fast by two
    }
    return slow;                    // Return middle node
}

int main() {                        // Main function
    Node* head = nullptr;           // Empty list
    insertEnd(head, 1);             // Insert 1
    insertEnd(head, 2);             // Insert 2
    insertEnd(head, 3);             // Insert 3
    insertEnd(head, 4);             // Insert 4
    Node* middle = findLeftMiddle(head); // Find middle
    if (middle != nullptr) {        // If list not empty
        cout << "Left middle: " << middle->data << endl; // Print middle
    }
    return 0;                       // End program
}
