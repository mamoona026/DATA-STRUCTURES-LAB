
#include <iostream>               // Header file for input and output
using namespace std;              // Allows us to use cout without std::

class Que                         // Defines a class named Que
{
public:                           // Makes members accessible outside the class

    int size;                     // Stores the maximum capacity of the queue
    int *q;                       // Pointer to dynamically allocated array
    int front;                    // Stores the index of the front element
    int rear;                     // Stores the index of the rear element

    // Default constructor
    Que()
    {
        size = 10;                // Sets the default queue capacity to 10
        q = new int[size];        // Dynamically allocates an integer array
        front = -1;               // -1 means the queue is initially empty
        rear = -1;                // -1 means there is no rear element
    }

    // Overloaded constructor
    Que(int x)
    {
        size = x;                 // Sets capacity to the size provided by user
        q = new int[size];        // Dynamically allocates an array of size x
        front = -1;               // Initializes front to indicate an empty queue
        rear = -1;                // Initializes rear to indicate an empty queue
    }

    // Function to check whether the queue is empty
    bool is_empty()
    {
        return (rear == -1);      // Returns true if the queue is empty
    }

    // Function to check whether the queue is full
    bool is_full()
    {
        return (rear == size - 1); // Returns true if rear reaches the last index
    }

    // Function to display all elements of the queue
    void display()
    {
        if (is_empty())           // Checks whether the queue is empty
        {
            cout << "\nQueue is empty."; // Displays message if empty
        }
        else                      // Executes if the queue contains elements
        {
            for (int i = front; i <= rear; i++) // Traverses queue elements
            {
                cout << "\nValue at index " << i // Displays the current index
                     << " is: " << q[i];          // Displays its stored value
            }
        }

        cout << endl;             // Moves output to the next line
    }

    // Function to insert an element into the queue
    void enqueue(int x)
    {
        if (is_full())            // Checks whether the queue is full
        {
            cout << "\nNo space in queue."; // Displays overflow message
        }
        else                      // Executes if space is available
        {
            if (is_empty())       // Checks whether this is the first element
            {
                front = rear = 0; // Sets both indexes to zero
            }
            else                  // Executes if the queue already has elements
            {
                rear++;           // Moves rear to the next available index
            }

            q[rear] = x;          // Stores the new element at the rear index
            cout << "\nInserted: " << x; // Displays the inserted element
        }
    }

    // Function to remove and return the front element
    int dequeue()
    {
        if (is_empty())           // Checks whether the queue is empty
        {
            cout << "\nQueue is already empty."; // Displays underflow message
            return -1;            // Returns -1 to indicate failure
        }
        else                      // Executes if the queue contains elements
        {
            int x = q[front];     // Saves the front element before removing it

            if (front == rear)    // Checks whether only one element exists
            {
                front = rear = -1; // Resets indexes because queue becomes empty
            }
            else                  // Executes if multiple elements exist
            {
                front++;          // Moves front to the next element
            }

            return x;             // Returns the removed element
        }
    }

    // Destructor to release dynamically allocated memory
    ~Que()
    {
        delete[] q;               // Frees the memory allocated using new[]
    }
};

int main()                        // Main function: program execution starts here
{
    Que q1;                       // Creates a queue with default capacity 10
    Que q2(5);                    // Creates a queue with capacity 5
    Que q3(15);                   // Creates a queue with capacity 15

    q1.enqueue(5);                // Inserts 5 into queue q1
    q2.enqueue(7);                // Inserts 7 into queue q2
    q3.enqueue(6);                // Inserts 6 into queue q3

    int x = q2.dequeue();         // Removes 7 from q2 and stores it in x

    cout << "\nDequeued element from q2 is: " << x;
                                  // Displays the removed element

    cout << "\n\nQueue q1:";      // Prints the heading for q1
    q1.display();                 // Displays the elements of q1

    cout << "\nQueue q2:";        // Prints the heading for q2
    q2.display();                 // Displays the elements of q2

    cout << "\nQueue q3:";        // Prints the heading for q3
    q3.display();                 // Displays the elements of q3

    return 0;                     // Ends the program successfully
}

