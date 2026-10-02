#include <iostream>
using namespace std;

// Node structure
struct NodeT
{
    int key;
    NodeT* next;
};

// Insert a node at the end of circular linked list
void insertEnd(NodeT*& pNode, int value)
{
    NodeT* p = new NodeT;
    p->key = value;

    // If list is empty
    if (pNode == NULL)
    {
        pNode = p;
        p->next = pNode;
        return;
    }

    // Find last node
    NodeT* q = pNode;

    while (q->next != pNode)
    {
        q = q->next;
    }

    q->next = p;
    p->next = pNode;
}

// Display the circular linked list
void display(NodeT* pNode)
{
    if (pNode == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }

    NodeT* p = pNode;

    do
    {
        cout << p->key << " ";
        p = p->next;
    }
    while (p != pNode);

    cout << endl;
}

// Delete the complete circular linked list
void deleteList(NodeT*& pNode)
{
    if (pNode == NULL)
    {
        cout << "List is already empty." << endl;
        return;
    }

    NodeT* p;
    NodeT* p1;

    p = pNode;

    do
    {
        p1 = p;
        p = p->next;

        delete p1;
    }
    while (p != pNode);

    pNode = NULL;

    cout << "All nodes have been deleted." << endl;
}

// Main function
int main()
{
    NodeT* pNode = NULL;

    // Create circular linked list
    insertEnd(pNode, 10);
    insertEnd(pNode, 20);
    insertEnd(pNode, 30);
    insertEnd(pNode, 40);
    insertEnd(pNode, 50);

    cout << "Circular Linked List: ";
    display(pNode);

    // Delete all nodes
    deleteList(pNode);

    // Display after deletion
    cout << "After deleting the complete list: ";
    display(pNode);

    return 0;
}
