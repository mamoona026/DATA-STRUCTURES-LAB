
#include <iostream>                  // Includes input and output functions
using namespace std;                 // Allows direct use of cin and cout

// Defines a node of the doubly linked list
struct Node
{
    int data;                        // Stores the node's value
    Node* next;                      // Points to the next node
    Node* prev;                      // Points to the previous node

    Node(int value)                  // Constructor initializes a new node
    {
        data = value;                // Stores the given value
        next = nullptr;              // Initially, there is no next node
        prev = nullptr;              // Initially, there is no previous node
    }
};

// Defines the Deque class
class Deque
{
private:
    Node* front;                     // Points to the first node
    Node* rear;                      // Points to the last node

public:
    Deque()                          // Constructor creates an empty deque
    {
        front = nullptr;             // No first node exists initially
        rear = nullptr;              // No last node exists initially
    }

    bool is_empty()                  // Checks whether deque is empty
    {
        return front == nullptr;     // Returns true if deque has no nodes
    }

    void insert_front(int value)     // Inserts an element at the front
    {
        Node* newNode = new Node(value); // Creates a new node dynamically

        if (is_empty())              // Checks whether deque is empty
        {
            front = newNode;         // New node becomes the front
            rear = newNode;          // New node also becomes the rear
        }
        else                         // Executes if deque has elements
        {
            newNode->next = front;   // Connects new node to old front
            front->prev = newNode;   // Connects old front to new node
            front = newNode;         // Updates front to the new node
        }

        cout << value << " inserted at front.\n"; // Displays confirmation
    }

    void insert_rear(int value)      // Inserts an element at the rear
    {
        Node* newNode = new Node(value); // Creates a new node dynamically

        if (is_empty())              // Checks whether deque is empty
        {
            front = newNode;         // New node becomes the front
            rear = newNode;          // New node also becomes the rear
        }
        else                         // Executes if deque has elements
        {
            rear->next = newNode;    // Connects old rear to new node
            newNode->prev = rear;    // Connects new node to old rear
            rear = newNode;          // Updates rear to the new node
        }

        cout << value << " inserted at rear.\n"; // Displays confirmation
    }

    void delete_front()              // Removes an element from the front
    {
        if (is_empty())              // Checks whether deque is empty
        {
            cout << "Deque is empty.\n"; // Displays an error message
            return;                  // Stops the function
        }

        Node* temp = front;          // Saves the front node temporarily
        cout << temp->data << " deleted from front.\n"; // Prints removed value

        if (front == rear)           // Checks if there is only one node
        {
            front = nullptr;         // Makes front null
            rear = nullptr;          // Makes rear null
        }
        else                         // Executes if multiple nodes exist
        {
            front = front->next;     // Moves front to the next node
            front->prev = nullptr;   // Removes backward link to old front
        }

        delete temp;                 // Frees memory of the removed node
    }

    void delete_rear()               // Removes an element from the rear
    {
        if (is_empty())              // Checks whether deque is empty
        {
            cout << "Deque is empty.\n"; // Displays an error message
            return;                  // Stops the function
        }

        Node* temp = rear;           // Saves the rear node temporarily
        cout << temp->data << " deleted from rear.\n"; // Prints removed value

        if (front == rear)           // Checks if there is only one node
        {
            front = nullptr;         // Makes front null
            rear = nullptr;          // Makes rear null
        }
        else                         // Executes if multiple nodes exist
        {
            rear = rear->prev;       // Moves rear to the previous node
            rear->next = nullptr;    // Removes forward link to old rear
        }

        delete temp;                 // Frees memory of the removed node
    }

    void get_front()                 // Displays the front element
    {
        if (is_empty())              // Checks whether deque is empty
        {
            cout << "Deque is empty.\n"; // Displays an error message
            return;                  // Stops the function
        }

        cout << "Front element: " << front->data << '\n'; // Prints front
    }

    void get_rear()                  // Displays the rear element
    {
        if (is_empty())              // Checks whether deque is empty
        {
            cout << "Deque is empty.\n"; // Displays an error message
            return;                  // Stops the function
        }

        cout << "Rear element: " << rear->data << '\n'; // Prints rear
    }

    void display()                   // Displays elements from front to rear
    {
        if (is_empty())              // Checks whether deque is empty
        {
            cout << "Deque is empty.\n"; // Displays an error message
            return;                  // Stops the function
        }

        Node* temp = front;          // Starts traversal from the front
        cout << "Deque (front to rear): "; // Prints the direction

        while (temp != nullptr)      // Continues until the end of the list
        {
            cout << temp->data << " "; // Prints the current node's data
            temp = temp->next;       // Moves to the next node
        }

        cout << '\n';                // Moves output to the next line
    }

    void display_reverse()           // Displays elements from rear to front
    {
        if (is_empty())              // Checks whether deque is empty
        {
            cout << "Deque is empty.\n"; // Displays an error message
            return;                  // Stops the function
        }

        Node* temp = rear;           // Starts traversal from the rear
        cout << "Deque (rear to front): "; // Prints the direction

        while (temp != nullptr)      // Continues until the beginning
        {
            cout << temp->data << " "; // Prints the current node's data
            temp = temp->prev;       // Moves to the previous node
        }

        cout << '\n';                // Moves output to the next line
    }

    ~Deque()                         // Destructor releases remaining nodes
    {
        while (front != nullptr)     // Continues while nodes remain
        {
            Node* temp = front;      // Saves the current front node
            front = front->next;     // Advances front to the next node
            delete temp;             // Frees memory of the old front node
        }

        rear = nullptr;              // Resets rear after clearing the deque
    }
};

// Main function: program execution starts here
int main()
{
    Deque d;                         // Creates an empty deque
    int choice, value;               // Declares menu choice and input value

    do                               // Repeats the menu until user exits
    {
        cout << "\n--- Deque Menu ---\n"; // Displays the menu heading
        cout << "1. Insert at front\n"; // Option to insert at front
        cout << "2. Insert at rear\n";  // Option to insert at rear
        cout << "3. Delete from front\n"; // Option to delete from front
        cout << "4. Delete from rear\n"; // Option to delete from rear
        cout << "5. Display\n";       // Option to display from front to rear
        cout << "6. Display reverse\n"; // Option to display from rear to front
        cout << "7. Get front\n";     // Option to display front element
        cout << "8. Get rear\n";      // Option to display rear element
        cout << "9. Check empty\n";   // Option to check whether deque is empty
        cout << "0. Exit\n";          // Option to exit the program
        cout << "Enter choice: ";     // Asks the user for a choice
        cin >> choice;               // Reads the selected choice

        switch (choice)              // Selects the required operation
        {
            case 1:                  // Insert at front
                cout << "Enter value: "; // Asks for a value
                cin >> value;        // Reads the value
                d.insert_front(value); // Inserts value at the front
                break;               // Ends this case

            case 2:                  // Insert at rear
                cout << "Enter value: "; // Asks for a value
                cin >> value;        // Reads the value
                d.insert_rear(value); // Inserts value at the rear
                break;               // Ends this case

            case 3:                  // Delete from front
                d.delete_front();    // Removes the front element
                break;               // Ends this case

            case 4:                  // Delete from rear
                d.delete_rear();     // Removes the rear element
                break;               // Ends this case

            case 5:                  // Display in forward direction
                d.display();         // Displays front to rear
                break;               // Ends this case

            case 6:                  // Display in reverse direction
                d.display_reverse(); // Displays rear to front
                break;               // Ends this case

            case 7:                  // Get front element
                d.get_front();       // Displays the front element
                break;               // Ends this case

            case 8:                  // Get rear element
                d.get_rear();        // Displays the rear element
                break;               // Ends this case

            case 9:                  // Check whether deque is empty
                if (d.is_empty())    // Tests whether deque has no nodes
                    cout << "Deque is empty.\n"; // Prints empty status
                else                 // Executes if deque has elements
                    cout << "Deque is not empty.\n"; // Prints non-empty status
                break;               // Ends this case

            case 0:                  // Exit the program
                cout << "Program ended.\n"; // Displays exit message
                break;               // Ends this case

            default:                 // Handles an invalid choice
                cout << "Invalid choice.\n"; // Displays an error message
        }

    } while (choice != 0);           // Repeats until the user selects zero

    return 0;                        // Ends the program successfully
}

