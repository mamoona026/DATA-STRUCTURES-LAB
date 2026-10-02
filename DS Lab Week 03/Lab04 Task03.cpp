#include <iostream>
using namespace std;

// Node structure
struct Node
{
    int data;
    Node* next;
};

// Insert node at the end
void insertEnd(Node*& head, int value)
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Display the linked list
void display(Node* head)
{
    Node* temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

// Delete all even-positioned nodes
void deleteEvenPositionNodes(Node*& head)
{
    if (head == NULL)
        return;

    Node* current = head;

    // Position 1 is kept.
    // Delete position 2, then 4, then 6, etc.
    while (current != NULL && current->next != NULL)
    {
        Node* temp = current->next;

        // Skip the even-positioned node
        current->next = temp->next;

        // Delete it
        delete temp;

        // Move to the next odd-positioned node
        current = current->next;
    }
}

// Main function
int main()
{
    Node* head = NULL;

    // Create linked list
    insertEnd(head, 10);
    insertEnd(head, 20);
    insertEnd(head, 30);
    insertEnd(head, 40);
    insertEnd(head, 50);
    insertEnd(head, 60);
    insertEnd(head, 70);
    insertEnd(head, 80);

    cout << "Original Linked List: ";
    display(head);

    // Delete even-positioned nodes
    deleteEvenPositionNodes(head);

    cout << "After deleting even-positioned nodes: ";
    display(head);

    return 0;
}
