#include <iostream>
using namespace std;

// Node structure
struct NodeT
{
    int key;
    NodeT* next;
};

// Insert a node into a circular linked list
void insertNode(NodeT*& pNode, int value)
{
    NodeT* newNode = new NodeT;
    newNode->key = value;

    if (pNode == NULL)
    {
        pNode = newNode;
        newNode->next = pNode;
    }
    else
    {
        NodeT* p = pNode;

        // Find the last node
        while (p->next != pNode)
        {
            p = p->next;
        }

        p->next = newNode;
        newNode->next = pNode;
    }
}

// Traverse and display the circular linked list
void display(NodeT* pNode)
{
    NodeT* p;
    p = pNode;

    if (p != NULL)
    {
        do
        {
            cout << p->key << " ";
            p = p->next;
        }
        while (p != pNode);
    }

    cout << endl;
}

// Search for a given key
NodeT* search(NodeT* pNode, int givenKey)
{
    NodeT* p;
    p = pNode;

    if (p != NULL)
    {
        do
        {
            if (p->key == givenKey)
            {
                // Key found at address p
                return p;
            }

            p = p->next;
        }
        while (p != pNode);
    }

    // Key not found
    return NULL;
}

int main()
{
    NodeT* pNode = NULL;

    // Insert values
    insertNode(pNode, 10);
    insertNode(pNode, 20);
    insertNode(pNode, 30);
    insertNode(pNode, 40);
    insertNode(pNode, 50);

    // Display list
    cout << "Circular Linked List: ";
    display(pNode);

    // Search for a key
    int givenKey;
    cout << "Enter key to search: ";
    cin >> givenKey;

    NodeT* result = search(pNode, givenKey);

    if (result != NULL)
    {
        cout << "Key " << givenKey << " found." << endl;
    }
    else
    {
        cout << "Key " << givenKey << " not found." << endl;
    }

    return 0;
}
