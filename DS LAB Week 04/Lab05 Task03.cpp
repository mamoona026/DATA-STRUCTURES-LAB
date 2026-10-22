#include <iostream>
#include <string>
#include <cctype> // Required for isdigit()

using namespace std;

// Node structure for the Dynamic Stack (Linked List implementation)
struct Node {
    int data;       // Holds the integer data (since we are evaluating numbers)
    Node* next;     // Pointer to the next node
};

// Dynamic Stack class for integers
class DynamicStack {
private:
    Node* top;      // Pointer to the top of the stack

public:
    // Constructor
    DynamicStack() {
        top = nullptr;
    }

    // Destructor to free memory
    ~DynamicStack() {
        while (!isEmpty()) {
            pop();
        }
    }

    // Check if stack is empty
    bool isEmpty() {
        return top == nullptr;
    }

    // Push an integer onto the stack
    void push(int value) {
        Node* newNode = new Node(); // Allocate memory for new node
        newNode->data = value;      // Set data
        newNode->next = top;        // Link to current top
        top = newNode;              // Update top
    }

    // Pop an integer from the stack
    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!" << endl;
            return -1; // Return error value
        }
        Node* temp = top;       // Hold current top
        int popped = top->data; // Get data
        top = top->next;        // Move top down
        delete temp;            // Free memory
        return popped;          // Return value
    }
};

// Function to evaluate a postfix expression
int evaluatePostfix(string postfix) {
    DynamicStack s; // Create a dynamic stack for operands

    // Iterate through each character in the postfix string
    for (char c : postfix) {
        // If character is a digit, convert to integer and push onto stack
        if (isdigit(c)) {
            s.push(c - '0'); // '0' is subtracted to convert char digit to int
        }
        // If character is an operator
        else {
            // Pop the top two operands from the stack
            int val2 = s.pop(); // Right operand (popped first)
            int val1 = s.pop(); // Left operand (popped second)

            // Perform the operation based on the operator
            switch (c) {
                case '+': s.push(val1 + val2); break;
                case '-': s.push(val1 - val2); break;
                case '*': s.push(val1 * val2); break;
                case '/': 
                    if (val2 != 0) s.push(val1 / val2); 
                    else cout << "Error: Division by zero" << endl;
                    break;
                default: cout << "Invalid operator" << endl;
            }
        }
    }
    // The final result will be the only element left in the stack
    return s.pop();
}

int main() {
    string postfixExpr = "28*54*+1+"; // Example: (2*3) + (5*4) - 9
    cout << "Postfix Expression: " << postfixExpr << endl;
    cout << "Evaluated Result: " << evaluatePostfix(postfixExpr) << endl;

    return 0;
}
