
#include <iostream>                  // Includes input and output functions
using namespace std;                 // Allows us to use cout and cin directly

// Defines a node of the linked list
struct Node
{
    int data;                        // Stores the queue element
    Node* next;                      // Points to the next node

    Node(int value)                  // Constructor to initialize a node
    {
        data = value;                // Stores the given value
        next = nullptr;              // Initially, the node points to nothing
    }
};

// Defines the Dynamic Queue class
class Queue
{
private:
    Node* front;                     // Points to the first node
    Node* rear;                      // Points to the last node

public:
    Queue()                          // Constructor of the queue
    {
        front = nullptr;             // Queue is initially empty
        rear = nullptr;              // No last node exists initially
    }

    bool is_empty()                  // Checks whether the queue is empty
    {
        return front == nullptr;     // True if there are no nodes
    }

    void enqueue(int value)          // Inserts an element at the rear
    {
        Node* newNode = new Node(value); // Creates a new node dynamically

        if (is_empty())              // Checks if the queue has no elements
        {
            front = newNode;         // New node becomes the front
            rear = newNode;          // New node also becomes the rear
        }
        else                         // Executes when queue is not empty
        {
            rear->next = newNode;    // Links the last node to the new node
            rear = newNode;          // Updates rear to the new last node
        }

        cout << value << " inserted into queue.\n"; // Displays confirmation
    }

    void dequeue()                   // Removes the front element
    {
        if (is_empty())              // Checks if queue is empty
        {
            cout << "Queue is empty.\n"; // Displays an error message
            return;                  // Stops the function
        }

        Node* temp = front;          // Saves the front node temporarily
        cout << temp->data << " removed from queue.\n"; // Displays removed value
        front = front->next;         // Moves front to the next node

        if (front == nullptr)        // Checks if the queue became empty
        {
            rear = nullptr;          // Rear must also become null
        }

        delete temp;                 // Frees the removed node's memory
    }

    void get_front()                 // Displays the front element
    {
        if (is_empty())              // Checks if queue is empty
        {
            cout << "Queue is empty.\n"; // Displays an error message
            return;                  // Stops the function
        }

        cout << "Front element: " << front->data << '\n'; // Prints front
    }

    void display()                   // Displays all queue elements
    {
        if (is_empty())              // Checks if queue is empty
        {
            cout << "Queue is empty.\n"; // Displays an error message
            return;                  // Stops the function
        }

        Node* temp = front;          // Starts traversal from the front
        cout << "Queue: ";           // Prints the queue label

        while (temp != nullptr)      // Continues until the last node
        {
            cout << temp->data << " "; // Prints the current node's data
            temp = temp->next;       // Moves to the next node
        }

        cout << '\n';                // Moves output to the next line
    }

    ~Queue()                         // Destructor releases remaining nodes
    {
        while (!is_empty())          // Continues while nodes remain
        {
            Node* temp = front;      // Saves the current front node
            front = front->next;     // Advances front to the next node
            delete temp;             // Frees the old front node
        }

        rear = nullptr;              // Resets rear after clearing the queue
    }
};

// Main function: program execution starts here
int main()
{
    Queue q;                         // Creates an empty queue
    int choice, value;               // Declares menu choice and input value

    do                               // Repeats the menu until user exits
    {
        cout << "\n--- Dynamic Queue Menu ---\n"; // Displays menu heading
        cout << "1. Enqueue\n";       // Option to insert an element
        cout << "2. Dequeue\n";       // Option to remove an element
        cout << "3. Display\n";       // Option to display the queue
        cout << "4. Front element\n"; // Option to show the front element
        cout << "5. Check empty\n";   // Option to check whether queue is empty
        cout << "0. Exit\n";          // Option to terminate the program
        cout << "Enter choice: ";     // Asks user to select an option
        cin >> choice;               // Reads the selected option

        switch (choice)              // Executes the selected operation
        {
            case 1:                  // Enqueue operation
                cout << "Enter value: "; // Asks for a value
                cin >> value;        // Reads the value
                q.enqueue(value);    // Inserts the value into the queue
                break;               // Ends this case

            case 2:                  // Dequeue operation
                q.dequeue();         // Removes the front element
                break;               // Ends this case

            case 3:                  // Display operation
                q.display();         // Prints all queue elements
                break;               // Ends this case

            case 4:                  // Front operation
                q.get_front();       // Prints the front element
                break;               // Ends this case

            case 5:                  // Check-empty operation
                if (q.is_empty())    // Checks whether queue is empty
                    cout << "Queue is empty.\n"; // Prints empty status
                else                 // Executes if queue has elements
                    cout << "Queue is not empty.\n"; // Prints non-empty status
                break;               // Ends this case

            case 0:                  // Exit operation
                cout << "Program ended.\n"; // Displays exit message
                break;               // Ends this case

            default:                 // Handles an invalid menu choice
                cout << "Invalid choice.\n"; // Displays an error message
        }

    } while (choice != 0);           // Repeats until choice is zero

    return 0;                        // Ends the program successfully
}

