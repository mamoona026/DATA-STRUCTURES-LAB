
#include <iostream>                  // Header file for input and output
using namespace std;                 // Allows use of cout and cin without std::

class Node                           // Defines a node of the doubly linked list
{
public:                              // Makes data members accessible
    int data;                        // Stores the value of the node
    Node* next;                      // Points to the next node
    Node* prev;                      // Points to the previous node

    Node(int x)                      // Constructor to initialize a node
    {
        data = x;                    // Stores the given value in the node
        next = NULL;                 // Initially, next points to nothing
        prev = NULL;                 // Initially, prev points to nothing
    }
};

class Deque                          // Defines the Deque class
{
private:                             // Makes the following members private
    Node* front;                     // Points to the first node
    Node* rear;                      // Points to the last node

public:                              // Makes functions accessible from main()

    Deque()                          // Constructor to initialize an empty deque
    {
        front = NULL;                // Initially, front points to nothing
        rear = NULL;                  // Initially, rear points to nothing
    }

    bool is_empty()                  // Function to check whether deque is empty
    {
        return (front == NULL);      // Returns true if there are no nodes
    }

    void insert_front(int x)         // Inserts an element at the front
    {
        Node* newNode = new Node(x); // Creates a new node dynamically

        if (is_empty())              // Checks whether the deque is empty
        {
            front = rear = newNode;  // New node becomes both front and rear
        }
        else                         // Executes if the deque is not empty
        {
            newNode->next = front;   // Connects new node to the old front
            front->prev = newNode;   // Connects old front back to new node
            front = newNode;         // Updates front to the new node
        }

        cout << x << " inserted at front.\n"; // Displays insertion message
    }

    void insert_rear(int x)          // Inserts an element at the rear
    {
        Node* newNode = new Node(x); // Creates a new node dynamically

        if (is_empty())              // Checks whether the deque is empty
        {
            front = rear = newNode;  // New node becomes both front and rear
        }
        else                         // Executes if the deque is not empty
        {
            rear->next = newNode;    // Connects old rear to the new node
            newNode->prev = rear;    // Connects new node back to old rear
            rear = newNode;          // Updates rear to the new node
        }

        cout << x << " inserted at rear.\n"; // Displays insertion message
    }

    void delete_front()              // Deletes the front element
    {
        if (is_empty())              // Checks whether the deque is empty
        {
            cout << "Deque is empty. Nothing to delete.\n"; // Error message
            return;                  // Stops this function
        }

        Node* temp = front;           // Saves the current front node

        if (front == rear)            // Checks whether only one node exists
        {
            front = rear = NULL;      // Deque becomes empty
        }
        else                          // Executes if multiple nodes exist
        {
            front = front->next;      // Moves front to the next node
            front->prev = NULL;       // Removes the backward link to old front
        }

        cout << temp->data << " deleted from front.\n"; // Displays deleted value
        delete temp;                  // Frees memory of the deleted node
    }

    void delete_rear()                // Deletes the rear element
    {
        if (is_empty())               // Checks whether the deque is empty
        {
            cout << "Deque is empty. Nothing to delete.\n"; // Error message
            return;                   // Stops this function
        }

        Node* temp = rear;            // Saves the current rear node

        if (front == rear)             // Checks whether only one node exists
        {
            front = rear = NULL;       // Deque becomes empty
        }
        else                           // Executes if multiple nodes exist
        {
            rear = rear->prev;         // Moves rear to the previous node
            rear->next = NULL;         // Removes the forward link to old rear
        }

        cout << temp->data << " deleted from rear.\n"; // Displays deleted value
        delete temp;                   // Frees memory of the deleted node
    }

    void display()                     // Displays deque from front to rear
    {
        if (is_empty())                // Checks whether the deque is empty
        {
            cout << "Deque is empty.\n"; // Displays an empty message
            return;                    // Stops this function
        }

        Node* temp = front;             // Starts traversal from the front

        cout << "Deque: ";              // Prints the deque heading

        while (temp != NULL)            // Continues until the end of the list
        {
            cout << temp->data << " ";  // Prints the current node's value
            temp = temp->next;          // Moves to the next node
        }

        cout << endl;                   // Moves output to the next line
    }

    ~Deque()                            // Destructor to release remaining nodes
    {
        while (!is_empty())             // Continues while nodes remain
        {
            Node* temp = front;         // Saves the current front node
            front = front->next;        // Moves front to the next node
            delete temp;                // Frees the old front node
        }

        rear = NULL;                    // Resets rear after deleting all nodes
    }
};

int main()                              // Main function: execution starts here
{
    Deque d;                            // Creates an empty deque

    d.insert_front(10);                 // Inserts 10 at the front
    d.insert_front(20);                 // Inserts 20 at the front
    d.insert_rear(30);                  // Inserts 30 at the rear
    d.insert_rear(40);                  // Inserts 40 at the rear

    d.display();                        // Displays all deque elements

    d.delete_front();                   // Deletes the front element (20)
    d.display();                        // Displays the deque after deletion

    d.delete_rear();                    // Deletes the rear element (40)
    d.display();                        // Displays the deque after deletion

    d.insert_front(5);                  // Inserts 5 at the front
    d.insert_rear(50);                  // Inserts 50 at the rear

    d.display();                        // Displays the final deque

    return 0;                           // Ends the program successfully
}

