
#include <iostream>
using namespace std;

class Que
{
public:
    int size;       // Capacity of queue
    int *q;         // Dynamic array for queue elements
    int front;      // Front index
    int rear;       // Rear index

    // Default constructor
    Que()
    {
        size = 10;
        q = new int[size];
        front = -1;
        rear = -1;
    }

    // Overloaded constructor
    Que(int x)
    {
        size = x;
        q = new int[size];
        front = -1;
        rear = -1;
    }

    // Check whether queue is empty
    bool is_empty()
    {
        return (rear == -1);
    }

    // Check whether queue is full
    bool is_full()
    {
        return (rear == size - 1);
    }

    // Display queue elements
    void display()
    {
        if (is_empty())
        {
            cout << "\nQueue is empty.";
        }
        else
        {
            for (int i = front; i <= rear; i++)
            {
                cout << "\nValue at index " << i
                     << " is: " << q[i];
            }
        }
        cout << endl;
    }

    // Insert an element into queue
    void enqueue(int x)
    {
        if (is_full())
        {
            cout << "\nNo space in queue.";
        }
        else
        {
            if (is_empty())
            {
                front = rear = 0;
            }
            else
            {
                rear++;
            }

            q[rear] = x;
            cout << "\nInserted: " << x;
        }
    }

    // Remove an element from queue
    int dequeue()
    {
        if (is_empty())
        {
            cout << "\nQueue is already empty.";
            return -1;
        }
        else
        {
            int x = q[front];

            if (front == rear)
            {
                front = rear = -1;
            }
            else
            {
                front++;
            }

            return x;
        }
    }

    // Destructor: release dynamically allocated memory
    ~Que()
    {
        delete[] q;
    }
};

int main()
{
    // Objects using constructors
    Que q1;       // Default capacity = 10
    Que q2(5);    // Capacity = 5
    Que q3(15);   // Capacity = 15

    // Insert elements
    q1.enqueue(5);
    q2.enqueue(7);
    q3.enqueue(6);

    // Remove an element from q2
    int x = q2.dequeue();

    cout << "\nDequeued element from q2 is: " << x;

    // Display queues
    cout << "\n\nQueue q1:";
    q1.display();

    cout << "\nQueue q2:";
    q2.display();

    cout << "\nQueue q3:";
    q3.display();

    return 0;
}

