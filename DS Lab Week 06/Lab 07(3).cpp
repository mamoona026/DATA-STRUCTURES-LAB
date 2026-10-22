
#include <iostream>                          // Includes input and output functions
using namespace std;                         // Allows direct use of cin and cout

struct Node                                 // Defines a node of the BST
{
    int data;                                // Stores the node's value
    Node* left;                              // Points to the left child
    Node* right;                             // Points to the right child

    Node(int value)                          // Constructor for a new node
    {
        data = value;                        // Stores the given value
        left = nullptr;                      // Initially has no left child
        right = nullptr;                     // Initially has no right child
    }
};

Node* insert(Node* root, int value)          // Inserts a value into the BST
{
    if (root == nullptr)                     // Checks if the position is empty
        return new Node(value);              // Creates and returns a new node

    if (value < root->data)                  // Checks if the value is smaller
        root->left = insert(root->left, value); // Inserts into the left subtree
    else if (value > root->data)             // Checks if the value is greater
        root->right = insert(root->right, value); // Inserts into the right subtree

    return root;                             // Returns the updated subtree root
}

Node* findMin(Node* root)                   // Finds the smallest node in a subtree
{
    while (root != nullptr && root->left != nullptr) // Moves left while possible
        root = root->left;                   // Moves to the left child

    return root;                             // Returns the smallest node
}

Node* deleteNode(Node* root, int key)        // Deletes a node containing key
{
    if (root == nullptr)                     // Checks if the BST or subtree is empty
        return root;                         // Nothing to delete

    if (key < root->data)                    // If key is smaller than current value
        root->left = deleteNode(root->left, key); // Searches in the left subtree

    else if (key > root->data)               // If key is greater than current value
        root->right = deleteNode(root->right, key); // Searches in the right subtree

    else                                     // The node to delete has been found
    {
        if (root->left == nullptr && root->right == nullptr) // Case 1: no children
        {
            delete root;                     // Frees the leaf node's memory
            return nullptr;                  // Replaces the deleted node with nothing
        }

        else if (root->left == nullptr)      // Case 2: only a right child
        {
            Node* temp = root->right;        // Saves the right child
            delete root;                     // Deletes the current node
            return temp;                     // Replaces it with its right child
        }

        else if (root->right == nullptr)     // Case 2: only a left child
        {
            Node* temp = root->left;         // Saves the left child
            delete root;                     // Deletes the current node
            return temp;                     // Replaces it with its left child
        }

        else                                 // Case 3: the node has two children
        {
            Node* temp = findMin(root->right); // Finds the inorder successor
            root->data = temp->data;         // Copies its value into the current node
            root->right = deleteNode(root->right, temp->data); // Deletes the successor
        }
    }

    return root;                             // Returns the updated subtree root
}

void inorder(Node* root)                     // Displays the BST in ascending order
{
    if (root == nullptr)                     // Checks whether the subtree is empty
        return;                              // Stops the recursive call

    inorder(root->left);                     // Visits the left subtree
    cout << root->data << " ";               // Prints the current node
    inorder(root->right);                    // Visits the right subtree
}

int main()                                   // Main function starts
{
    Node* root = nullptr;                    // Starts with an empty BST
    int n, value, key;                       // Declares input variables

    cout << "Enter number of nodes: ";       // Asks for the number of nodes
    cin >> n;                                // Reads the number of nodes

    for (int i = 0; i < n; i++)              // Repeats for all input values
    {
        cout << "Enter value: ";             // Asks the user for a value
        cin >> value;                        // Reads the value
        root = insert(root, value);          // Inserts the value into the BST
    }

    cout << "\nBST before deletion: ";       // Displays the original BST heading
    inorder(root);                            // Prints values in ascending order

    cout << "\nEnter value to delete: ";     // Asks which node to delete
    cin >> key;                              // Reads the value to delete

    root = deleteNode(root, key);            // Deletes the requested node

    cout << "BST after deletion: ";          // Displays the updated BST heading
    inorder(root);                            // Prints the updated BST in order
    cout << endl;                             // Moves to the next line

    return 0;                                // Ends the program successfully
}

