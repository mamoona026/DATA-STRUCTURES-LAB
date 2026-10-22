#include <iostream>
#include <algorithm> // For std::max

using namespace std;

// Structure for an AVL Tree Node
struct Node {
    int key;        // The data value
    Node* left;     // Pointer to the left child
    Node* right;    // Pointer to the right child
    int height;     // Height of the node from the leaf
    
    // Constructor to initialize a new node
    Node(int val) {
        key = val;
        left = nullptr;
        right = nullptr;
        height = 1; // A new node starts at height 1
    }
};

// Utility function to get the height of a node
int getHeight(Node* N) {
    if (N == nullptr) return 0; // Null nodes have height 0
    return N->height;           // Return stored height
}

// Utility function to get the maximum of two integers
int maxInt(int a, int b) {
    return (a > b) ? a : b;
}

// ---------------------------------------------------------
// 1. RIGHT ROTATION (Used for Left-Left Imbalance)
// ---------------------------------------------------------
Node* rightRotate(Node* y) {
    Node* x = y->left;      // x is the left child of y
    Node* T2 = x->right;    // T2 is the right child of x

    // Perform rotation
    x->right = y;           // y becomes the right child of x
    y->left = T2;           // T2 becomes the left child of y

    // Update heights after rotation
    y->height = maxInt(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = maxInt(getHeight(x->left), getHeight(x->right)) + 1;

    return x;               // x becomes the new root of this subtree
}

// ---------------------------------------------------------
// 2. LEFT ROTATION (Used for Right-Right Imbalance)
// ---------------------------------------------------------
Node* leftRotate(Node* x) {
    Node* y = x->right;     // y is the right child of x
    Node* T2 = y->left;     // T2 is the left child of y

    // Perform rotation
    y->left = x;            // x becomes the left child of y
    x->right = T2;          // T2 becomes the right child of x

    // Update heights after rotation
    x->height = maxInt(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = maxInt(getHeight(y->left), getHeight(y->right)) + 1;

    return y;               // y becomes the new root of this subtree
}

// Utility to get Balance Factor (Height of Left - Height of Right)
int getBalance(Node* N) {
    if (N == nullptr) return 0;
    return getHeight(N->left) - getHeight(N->right);
}

// Helper function to print the tree (rotated 90 degrees counter-clockwise)
void printTree(Node* root, int space = 0, int COUNT = 5) {
    if (root == nullptr) return;
    space += COUNT;
    printTree(root->right, space); // Print right subtree first
    cout << endl;
    for (int i = COUNT; i < space; i++) cout << " "; // Add indentation
    cout << root->key << "\n"; // Print current node
    printTree(root->left, space); // Print left subtree
}

// ---------------------------------------------------------
// INSERTION FUNCTION (Handles all 4 rotation cases)
// ---------------------------------------------------------
Node* insert(Node* node, int key) {
    // 1. Normal BST Insertion
    if (node == nullptr) return new Node(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node; // Duplicate keys not allowed

    // 2. Update height of this ancestor node
    node->height = 1 + maxInt(getHeight(node->left), getHeight(node->right));

    // 3. Get the balance factor
    int balance = getBalance(node);

    // 4. Check for imbalances and apply rotations

    // Case 1: Left Left (LL) -> Right Rotation
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // Case 2: Right Right (RR) -> Left Rotation
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // Case 3: Left Right (LR) -> Left Rotate child, then Right Rotate root
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Case 4: Right Left (RL) -> Right Rotate child, then Left Rotate root
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node; // Return the unchanged node pointer
}

// Main function to test Lab Task 1
int main() {
    Node* root = nullptr;

    // Inserting values that force all 4 rotation types
    cout << "Inserting 10, 20, 30 (Triggers Left Rotation)" << endl;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);

    cout << "Inserting 40, 50 (Triggers Left Rotation)" << endl;
    root = insert(root, 40);
    root = insert(root, 50);

    cout << "Inserting 25 (Triggers Right-Left Rotation)" << endl;
    root = insert(root, 25);

    cout << "\nFinal Balanced AVL Tree Structure:\n";
    printTree(root);

    return 0;
}
