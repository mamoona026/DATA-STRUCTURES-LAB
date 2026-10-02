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
    if (head == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }

    Node* temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

// Delete all even-valued nodes
void deleteEven(Node*& head)
{
    // Delete even nodes from the beginning
    while (head != NULL && head->data % 2 == 0)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // Delete even nodes from the rest of the list
    if (head != NULL)
    {
        Node* current = head;

        while (current->next != NULL)
        {
            if (current->next->data % 2 == 0)
            {
                Node* temp = current->next;
                current->next = temp->next;
                delete temp;
            }
            else
            {
                current = current->next;
            }
        }
    }
}

// Delete all odd-valued nodes
void deleteOdd(Node*& head)
{
    // Delete odd nodes from the beginning
    while (head != NULL && head->data % 2 != 0)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // Delete odd nodes from the rest of the list
    if (head != NULL)
    {
        Node* current = head;

        while (current->next != NULL)
        {
            if (current->next->data % 2 != 0)
            {
                Node* temp = current->next;
                current->next = temp->next;
                delete temp;
            }
            else
            {
                current = current->next;
            }
        }
    }
}

// Main function
int main()
{
    Node* head = NULL;

    // Create linked list
    insertEnd(head, 10);
    insertEnd(head, 15);
    insertEnd(head, 20);
    insertEnd(head, 25);
    insertEnd(head, 30);
    insertEnd(head, 35);
    insertEnd(head, 40);

    cout << "Original Linked List: ";
    display(head);

    // Delete even-valued nodes
    deleteEven(head);

    cout << "After deleting even values: ";
    display(head);

    return 0;
}
