#include <iostream>                 // Include input-output stream library.
using namespace std;                // Use standard namespace.

struct Node {                       // Define a node for circular linked list.
    int data;                       // Store person number.
    Node* next;                     // Pointer to next node.
};                                  // End of Node structure.

Node* createCircle(int n) {         // Function to create circular linked list of 1..n.
    if (n <= 0) return nullptr;     // Return null if invalid count.
    Node* head = new Node;          // Allocate first node.
    head->data = 1;                 // Set first person number.
    head->next = nullptr;           // Initialize next pointer.
    Node* last = head;              // last points to last created node.
    for (int i = 2; i <= n; i++) {  // Create persons 2 to n.
        Node* newNode = new Node;   // Allocate new node.
        newNode->data = i;          // Set person number.
        newNode->next = nullptr;    // Initialize next pointer.
        last->next = newNode;       // Link old last to new node.
        last = newNode;             // Update last.
    }                               // End for.
    last->next = head;              // Make list circular.
    return head;                    // Return head of circle.
}                                   // End createCircle.

int josephus(int n, int m) {        // Function returns survivor position.
    if (n <= 0 || m <= 0) return -1;// Validate inputs.
    Node* head = createCircle(n);   // Create circle.
    Node* curr = head;              // curr starts at head.
    Node* prev = head;              // prev will point to node before curr.
    while (prev->next != head) {    // Find last node.
        prev = prev->next;          // Move prev forward.
    }                               // Now prev is last node.
    while (curr->next != curr) {    // Loop until one node remains.
        for (int i = 1; i < m; i++) { // Skip m-1 persons.
            prev = curr;            // Move prev to curr.
            curr = curr->next;      // Move curr to next person.
        }                           // End for; curr is Mth person to eliminate.
        prev->next = curr->next;    // Unlink curr from circle.
        if (curr == head) {         // If head is being deleted,
            head = curr->next;      // Update head.
        }                           // End if.
        Node* temp = curr;          // Store node to delete.
        curr = prev->next;          // Move curr to next person.
        delete temp;                // Free memory of eliminated person.
    }                               // End while.
    int survivor = curr->data;      // Store survivor number.
    delete curr;                    // Delete last node.
    return survivor;                // Return survivor.
}                                   // End josephus.

int main() {                        // Program starts here.
    int n, m;                       // n = total persons, m = count.
    cout << "Enter number of persons N: "; // Prompt for N.
    cin >> n;                       // Read N.
    cout << "Enter count M: ";      // Prompt for M.
    cin >> m;                       // Read M.
    int result = josephus(n, m);    // Call Josephus function.
    if (result == -1) {             // Check invalid input.
        cout << "Invalid input.\n"; // Print error.
    } else {                        // Otherwise,
        cout << "Safe position is: " << result << endl; // Print survivor.
    }                               // End if.
    return 0;                       // Return success.
}                                   // End main.
