#include <iostream>
#include <string>
#include <cctype> // Required for isalnum() and isdigit()

using namespace std;

// Node structure for the Dynamic Stack (Linked List implementation)
struct Node {
    char data;      // Holds the character data
    Node* next;     // Pointer to the next node in the stack
};

// Dynamic Stack class
class DynamicStack {
private:
    Node* top;      // Pointer to the top of the stack

public:
    // Constructor to initialize an empty stack
    DynamicStack() {
        top = nullptr; 
    }

    // Destructor to free allocated memory
    ~DynamicStack() {
        while (!isEmpty()) {
            pop();
        }
    }

    // Check if the stack is empty
    bool isEmpty() {
        return top == nullptr;
    }

    // Push an element onto the stack
    void push(char value) {
        Node* newNode = new Node(); // Create a new node dynamically
        newNode->data = value;      // Assign the value
        newNode->next = top;        // Point new node to current top
        top = newNode;              // Update top pointer to new node
    }

    // Pop an element from the stack
    char pop() {
        if (isEmpty()) {
            return '\0'; // Return null character if stack is empty
        }
        Node* temp = top;   // Store current top in temp
        char popped = top->data; // Get the data
        top = top->next;    // Move top pointer to next node
        delete temp;        // Free the memory of the popped node
        return popped;      // Return the popped value
    }

    // Peek at the top element without removing it
    char peek() {
        if (isEmpty()) {
            return '\0';
        }
        return top->data;
    }
};

// Function to return the precedence of an operator
int precedence(char op) {
    if (op == '+' || op == '-') return 1; // Lowest precedence
    if (op == '*' || op == '/') return 2; // Medium precedence
    if (op == '^') return 3;              // Highest precedence
    return 0;                             // For non-operators
}

// Function to convert Infix to Postfix
string infixToPostfix(string infix) {
    DynamicStack s;     // Create a dynamic stack for operators
    string postfix = ""; // Resultant string

    // Iterate through each character in the infix expression
    for (char c : infix) {
        // If the character is an operand (letter or digit), add it to the result
        if (isalnum(c)) {
            postfix += c;
        }
        // If the character is an opening parenthesis, push it to stack
        else if (c == '(') {
            s.push(c);
        }
        // If the character is a closing parenthesis
        else if (c == ')') {
            // Pop from stack and add to result until an opening parenthesis is found
            while (!s.isEmpty() && s.peek() != '(') {
                postfix += s.pop();
            }
            s.pop(); // Remove the '(' from the stack
        }
        // If the character is an operator
        else {
            // Pop operators with higher or equal precedence from stack and add to result
            while (!s.isEmpty() && precedence(s.peek()) >= precedence(c)) {
                postfix += s.pop();
            }
            s.push(c); // Push the current operator onto the stack
        }
    }

    // Pop any remaining operators from the stack
    while (!s.isEmpty()) {
        postfix += s.pop();
    }

    return postfix;
}

int main() {
    string infixExpr = "A+B*C"; // Example infix expression
    cout << "Infix Expression: " << infixExpr << endl;
    cout << "Postfix Expression: " << infixToPostfix(infixExpr) << endl;

    return 0;
}
