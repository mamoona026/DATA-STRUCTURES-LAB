#include <iostream>
using namespace std;

// Node structure
struct Node
{
    int data;
    Node* next;
};

// Create a circular linked list
Node* createList(int n)
{
    Node* head = NULL;
    Node* last = NULL;

    for (int i = 1; i <= n; i++)
    {
        Node* newNode = new Node;
        newNode->data = i;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
            last = newNode;
        }
        else
        {
            last->next = newNode;
            last = newNode;
        }
    }

    // Make the list circular
    last->next = head;

    return head;
}

// Josephus problem function
int josephus(int n, int k)
{
    Node* head = createList(n);

    // Find the last node
    Node* previous = head;

    while (previous->next != head)
    {
        previous = previous->next;
    }

    Node* current = head;

    // Continue until only one node remains
    while (current->next != current)
    {
        // Move k-1 positions
        for (int count = 1; count < k; count++)
        {
            previous = current;
            current = current->next;
        }

        // Delete current node
        cout << "Eliminated: " << current->data << endl;

        previous->next = current->next;

        Node* temp = current;
        current = current->next;

        delete temp;
    }

    // The remaining person
    int survivor = current->data;

    delete current;

    return survivor;
}

int main()
{
    int n, k;

    cout << "Enter number of people: ";
    cin >> n;

    cout << "Enter counting number (k): ";
    cin >> k;

    if (n <= 0 || k <= 0)
    {
        cout << "Invalid input." << endl;
        return 0;
    }

    cout << "\nElimination order:\n";

    int survivor = josephus(n, k);

    cout << "\nThe surviving person is: " << survivor << endl;

    return 0;
}
