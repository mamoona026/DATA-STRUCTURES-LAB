#include <iostream>
#include <stack>    // Required for using the built-in stack container
#include <string>   // Required for using the string class

using namespace std;

// Function to check if the brackets are balanced
bool isBalanced(string expr) {
    stack<char> s; // Declare a stack of characters to store opening brackets

    // Loop through each character in the input string
    for (char c : expr) {
        // If the character is an opening bracket, push it onto the stack
        if (c == '(' || c == '{' || c == '[') {
            s.push(c);
        }
        // If the character is a closing bracket
        else if (c == ')' || c == '}' || c == ']') {
            // If the stack is empty, there's no matching opening bracket
            if (s.empty()) {
                return false; // Not balanced
            }

            // Get the top element of the stack (the most recent opening bracket)
            char top = s.top(); 
            s.pop(); // Remove the top element from the stack

            // Check if the popped opening bracket matches the current closing bracket
            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '[')) {
                return false; // Mismatched brackets
            }
        }
    }

    // After processing all characters, the stack should be empty if balanced
    return s.empty(); 
}

int main() {
    // Test cases
    string expr1 = "[{(})]"; // Example of a balanced expression
    string expr2 = "{[(])}"; // Example of an unbalanced expression

    // Check and print the result for expr1
    cout << "Expression: " << expr1 << " -> " 
         << (isBalanced(expr1) ? "Balanced" : "Not Balanced") << endl;

    // Check and print the result for expr2
    cout << "Expression: " << expr2 << " -> " 
         << (isBalanced(expr2) ? "Balanced" : "Not Balanced") << endl;

    return 0;
}
