
#include <iostream>                         // Includes input and output functions
using namespace std;                        // Allows direct use of cin and cout

struct Node                                // Defines a BST node
{
    int data;                               // Stores the node's value
    Node* left;                             // Points to the left child
    Node* right;                            // Points to the right child

    Node(int value)                         // Constructor for a new node
    {
        data = value;                       // Assigns the given value
        left = nullptr;                     // Initializes the left child
        right = nullptr;                    // Initializes the right child
    }
};

Node* insert(Node* root, int value)         // Inserts a value into the BST
{
    if (root == nullptr)                    // Checks for an empty position
        return new Node(value);             // Creates a new node there

    if (value < root->data)                 // If the value is smaller
        root->left = insert(root->left, value); // Inserts into the left subtree
    else if (value > root->data)            // If the value is greater
        root->right = insert(root->right, value); // Inserts into the right subtree

    return root;                            // Returns the updated subtree root
}

void printLeaves(Node* root)                // Prints all leaf nodes
{
    if (root == nullptr)                    // Checks whether the subtree is empty
        return;                             // Stops if no node exists

    if (root->left == nullptr && root->right == nullptr) // Checks for a leaf
    {
        cout << root->data << " ";          // Prints the leaf node's value
        return;                             // No need to check children
    }

    printLeaves(root->left);                // Searches for leaves on the left
    printLeaves(root->right);               // Searches for leaves on the right
}

int countLeaves(Node* root)                 // Counts the leaf nodes
{
    if (root == nullptr)                    // Checks whether the node is empty
        return 0;                           // An empty subtree has zero leaves

    if (root->left == nullptr && root->right == nullptr) // Checks for a leaf
        return 1;                           // Counts this leaf as one

    return countLeaves(root->left) +        // Counts leaves in the left subtree
           countLeaves(root->right);        // Adds leaves in the right subtree
}

int main()                                  // Main function starts
{
    Node* root = nullptr;                   // Creates an initially empty BST
    int n, value;                           // Declares input variables

    cout << "Enter number of nodes: ";      // Asks for the number of nodes
    cin >> n;                               // Reads the number of nodes

    for (int i = 0; i < n; i++)             // Repeats for each node
    {
        cout << "Enter value: ";            // Asks the user for a value
        cin >> value;                       // Reads the value
        root = insert(root, value);         // Inserts the value into the BST
    }

    cout << "\nLeaf nodes: ";               // Displays the leaf-node heading
    printLeaves(root);                      // Prints all leaf nodes

    cout << "\nTotal leaf nodes: ";         // Displays the count heading
    cout << countLeaves(root) << endl;      // Prints the total number of leaves

    return 0;                               // Ends the program successfully
}

