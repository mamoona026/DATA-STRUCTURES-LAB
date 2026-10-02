#include <iostream>
using namespace std;

// Node structure
struct NodeT
{
    int key;
    NodeT* next;
};

// Insert a node at the end
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

// Display circular linked list
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

// Delete node with given key
void deleteNode(NodeT*& pNode, int givenKey)
{
    // If list is empty
    if (pNode == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }

    NodeT* p;
    NodeT* q;
    NodeT* q1;

    q = pNode;

    // Find the node with givenKey
    do
    {
        q1 = q;
        q = q->next;

        if (q->key == givenKey)
            break;
    }
    while (q != pNode);

    // Check if key was found
    if (q->key == givenKey)
    {
        // If there is only one node
        if (q == q->next)
        {
            pNode = NULL;
        }
        else
        {
            // Remove q from the circular list
            q1->next = q->next;

            // If q is pNode, move pNode to previous node
            if (q == pNode)
            {
                pNode = q1;
            }
        }

        // Free memory
        delete q;

        cout << "Node with key " << givenKey
             << " deleted." << endl;
    }
    else
    {
        cout << "Key " << givenKey << " not found." << endl;
    }
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

    cout << "Original Circular Linked List: ";
    display(pNode);

    // Delete node 30
    deleteNode(pNode, 30);

    cout << "After deleting 30: ";
    display(pNode);

    // Delete first node
    deleteNode(pNode, 10);

    cout << "After deleting 10: ";
    display(pNode);

    // Delete another node
    deleteNode(pNode, 40);

    cout << "After deleting 40: ";
    display(pNode);

    return 0;
}
