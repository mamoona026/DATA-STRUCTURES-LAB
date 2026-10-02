#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    Node* prev;
};

// Doubly Linked List
struct List {
    Node* first;
    Node* last;

    // Constructor
    List() {
        first = NULL;
        last = NULL;
    }
};

// Create a new node
Node* createNode(int value) {
    Node* p = new Node;

    p->data = value;
    p->next = NULL;
    p->prev = NULL;

    return p;
}

// Insert before the first node
void insertBeforeFirst(List* L, int value) {
    Node* p = createNode(value);

    // Empty list
    if (L->first == NULL) {
        L->first = L->last = p;
        p->next = p->prev = NULL;
    }
    else {
        // Non-empty list
        p->next = L->first;
        p->prev = NULL;

        L->first->prev = p;
        L->first = p;
    }
}

// Insert after the last node
void insertAfterLast(List* L, int value) {
    Node* p = createNode(value);

    // Empty list
    if (L->first == NULL) {
        L->first = L->last = p;
        p->next = p->prev = NULL;
    }
    else {
        // Non-empty list
        p->next = NULL;
        p->prev = L->last;

        L->last->next = p;
        L->last = p;
    }
}

// Insert after a node having a given key
void insertAfterKey(List* L, int key, int value) {
    Node* q = L->first;

    // Search for the node containing the key
    while (q != NULL && q->data != key) {
        q = q->next;
    }

    // Key not found
    if (q == NULL) {
        cout << "Key " << key << " not found." << endl;
        return;
    }

    Node* p = createNode(value);

    // Insert p after q
    p->prev = q;
    p->next = q->next;

    if (q->next != NULL) {
        q->next->prev = p;
    }

    q->next = p;

    // If q was the last node, update last
    if (L->last == q) {
        L->last = p;
    }
}

// Display list from first to last
void displayForward(List* L) {
    Node* current = L->first;

    cout << "Forward: ";

    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }

    cout << endl;
}

// Display list from last to first
void displayBackward(List* L) {
    Node* current = L->last;

    cout << "Backward: ";

    while (current != NULL) {
        cout << current->data << " ";
        current = current->prev;
    }

    cout << endl;
}

// Main function
int main() {
    List L;

    // Insert before first node
    insertBeforeFirst(&L, 20);
    insertBeforeFirst(&L, 10);

    // Insert after last node
    insertAfterLast(&L, 30);
    insertAfterLast(&L, 40);

    // Insert after node with key 20
    insertAfterKey(&L, 20, 25);

    // Display the list
    displayForward(&L);
    displayBackward(&L);

    return 0;
}
