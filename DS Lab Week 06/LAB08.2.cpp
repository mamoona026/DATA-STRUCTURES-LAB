#include <iostream>
#include <queue> // Required for the STL queue
#include <algorithm>

using namespace std;

// Structure for an AVL Tree Node
struct Node {
    int key;
    Node* left;
    Node* right;
    int height;

    // Constructor
    Node(int val) {
        key = val;
        left = nullptr;
        right = nullptr;
        height = 1;
    }
};

// Utility to get height
int getHeight(Node* N) {
    if (N == nullptr) return 0;
    return N->height;
}

// Utility to get max of two integers
int maxInt(int a, int b) {
    return (a > b) ? a : b;
}

// Right Rotation
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = maxInt(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = maxInt(getHeight(x->left), getHeight(x->right)) + 1;
    return x;
}

// Left Rotation
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = maxInt(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = maxInt(getHeight(y->left), getHeight(y->right)) + 1;
    return y;
}

// Get Balance Factor
int getBalance(Node* N) {
    if (N == nullptr) return 0;
    return getHeight(N->left) - getHeight(N->right);
}

// Standard AVL Insertion
Node* insert(Node* node, int key) {
    if (node == nullptr) return new Node(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;

    node->height = 1 + maxInt(getHeight(node->left), getHeight(node->right));
    int balance = getBalance(node);

    // Rotations
    if (balance > 1 && key < node->left->key) return rightRotate(node);
    if (balance < -1 && key > node->right->key) return leftRotate(node);
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

// ---------------------------------------------------------
// LAB TASK 2: LEVEL ORDER TRAVERSAL
// ---------------------------------------------------------
void printLevelOrder(Node* root) {
    // If tree is empty, return
    if (root == nullptr) {
        cout << "Tree is empty." << endl;
        return;
    }

    // Create a queue to hold nodes to be visited
    queue<Node*> q;

    // Push the root node into the queue first
    q.push(root);

    // While the queue is not empty
    while (!q.empty()) {
        // 1. Get the node at the front of the queue
        Node* current = q.front();
        
        // 2. Print its data
        cout << current->key << " ";
        
        // 3. Remove it from the queue
        q.pop();

        // 4. If the left child exists, push it into the queue
        if (current->left != nullptr) {
            q.push(current->left);
        }

        // 5. If the right child exists, push it into the queue
        if (current->right != nullptr) {
            q.push(current->right);
        }
    }
    cout << endl; // Print a newline at the end
}

// Main function to test Lab Task 2
int main() {
    Node* root = nullptr;

    // Inserting values to create a balanced tree
    // The tree will auto-balance to look roughly like:
    //          30
    //       /      \
    //     20        40
    //   /   \         \
    // 10     25        50
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 10);
    root = insert(root, 25);
    root = insert(root, 50);

    cout << "Level Order Traversal of the AVL Tree: " << endl;
    
    // Call the specific traversal function
    printLevelOrder(root);

    return 0;
}
