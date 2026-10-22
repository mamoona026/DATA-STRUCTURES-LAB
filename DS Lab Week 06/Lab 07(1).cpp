
#include <iostream>                 // Includes input and output functions
using namespace std;                // Allows us to use cout and cin directly

struct Node                            // Defines one node of the BST
{
    int data;                          // Stores the value of the node
    Node* left;                        // Points to the left child
    Node* right;                       // Points to the right child

    Node(int value)                    // Constructor to initialize a node
    {
        data = value;                  // Stores the given value
        left = nullptr;                // Initially, there is no left child
        right = nullptr;               // Initially, there is no right child
    }
};

Node* insert(Node* root, int value)    // Inserts a value into the BST
{
    if (root == nullptr)               // Checks whether the position is empty
        return new Node(value);        // Creates and returns a new node

    if (value < root->data)            // Checks if the value is smaller
        root->left = insert(root->left, value); // Inserts into left subtree
    else if (value > root->data)       // Checks if the value is greater
        root->right = insert(root->right, value); // Inserts into right subtree

    return root;                       // Returns the root of this subtree
}

void preorderNRL(Node* root)           // Preorder: Node, Right, Left
{
    if (root == nullptr)               // Stops if the node does not exist
        return;                        // Returns to the previous function call

    cout << root->data << " ";         // Visits the current node first
    preorderNRL(root->right);          // Visits the right subtree second
    preorderNRL(root->left);           // Visits the left subtree third
}

void postorderRLN(Node* root)          // Postorder: Right, Left, Node
{
    if (root == nullptr)               // Checks for an empty subtree
        return;                        // Stops this recursive call

    postorderRLN(root->right);         // Visits the right subtree first
    postorderRLN(root->left);          // Visits the left subtree second
    cout << root->data << " ";         // Visits the current node last
}

void inorderRNL(Node* root)            // Inorder: Right, Node, Left
{
    if (root == nullptr)               // Checks for an empty subtree
        return;                        // Stops this recursive call

    inorderRNL(root->right);           // Visits the right subtree first
    cout << root->data << " ";         // Visits the current node second
    inorderRNL(root->left);            // Visits the left subtree last
}

int main()                             // Program execution starts here
{
    Node* root = nullptr;              // Starts with an empty BST
    int n, value;                      // Declares the number and input value

    cout << "Enter number of nodes: "; // Asks how many values to insert
    cin >> n;                          // Reads the number of nodes

    for (int i = 0; i < n; i++)        // Repeats for all input values
    {
        cout << "Enter value: ";       // Asks for a value
        cin >> value;                  // Reads the value
        root = insert(root, value);    // Inserts the value into the BST
    }

    cout << "\nPreorder (NRL): ";      // Displays the traversal heading
    preorderNRL(root);                 // Calls preorder traversal

    cout << "\nPostorder (RLN): ";     // Displays the traversal heading
    postorderRLN(root);                // Calls postorder traversal

    cout << "\nInorder (RNL): ";       // Displays the traversal heading
    inorderRNL(root);                  // Calls inorder traversal

    cout << endl;                      // Moves the cursor to a new line
    return 0;                          // Ends the program successfully
}

