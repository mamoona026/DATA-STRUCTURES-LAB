#include <iostream>
using namespace std;

// Node structure
struct NodeT
{
    int key;
    NodeT* next;
};

// Insert a node at the end of the circular linked list
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

    // Find the last node
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


// --------------------------------------------------
// INSERT BEFORE A NODE WITH GIVEN KEY
// --------------------------------------------------
void insertBefore(NodeT*& pNode, int givenKey, int newKey)
{
    if (pNode == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }

    // Create new node
    NodeT* p = new NodeT;
    p->key = newKey;

    NodeT* q;
    NodeT* q1;

    q1 = NULL;
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
        q1->next = p;
        p->next = q;

        cout << "Node inserted before " << givenKey << "." << endl;
    }
    else
    {
        cout << "Key " << givenKey << " not found." << endl;
        delete p;
    }
}


// --------------------------------------------------
// INSERT AFTER A NODE WITH GIVEN KEY
// --------------------------------------------------
void insertAfter(NodeT*& pNode, int givenKey, int newKey)
{
    if (pNode == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }

    // Create new node
    NodeT* p = new NodeT;
    p->key = newKey;

    NodeT* q;
    q = pNode;

    // Find the node with givenKey
    do
    {
        if (q->key == givenKey)
            break;

        q = q->next;
    }
    while (q != pNode);

    // Check if key was found
    if (q->key == givenKey)
    {
        p->next = q->next;
        q->next = p;

        cout << "Node inserted after " << givenKey << "." << endl;
    }
    else
    {
        cout << "Key " << givenKey << " not found." << endl;
        delete p;
    }
}


// --------------------------------------------------
// MAIN FUNCTION
// --------------------------------------------------
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


    // Insert 15 before 20
    insertBefore(pNode, 20, 15);

    cout << "After inserting 15 before 20: ";
    display(pNode);


    // Insert 25 after 20
    insertAfter(pNode, 20, 25);

    cout << "After inserting 25 after 20: ";
    display(pNode);


    return 0;
}
