#include <iostream>
using namespace std;

// Structure for a node in BST
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Global root pointer
Node* root = nullptr;

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

// Function to insert a node in BST
void insert(int value) {
    Node* newNode = createNode(value);
    if (root == nullptr) {
        root = newNode;
        return;
    }
    Node* current = root;
    Node* parent = nullptr;
    while (current != nullptr) {
        parent = current;
        if (value < current->data) {
            current = current->left;
        } else if (value > current->data) {
            current = current->right;
        } else {
            return; // No duplicate values allowed
        }
    }
    if (value < parent->data) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }
}

// Function to find the minimum value node in BST
Node* findMin(Node* node) {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

// Function to delete a node in BST
void deleteNode(int value) {
    Node* current = root;
    Node* parent = nullptr;
    while (current != nullptr && current->data != value) {
        parent = current;
        if (value < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    if (current == nullptr) {
        return; // Node not found
    }
    
    // Case 1: Node with one or no child
    if (current->left == nullptr || current->right == nullptr) {
        Node* temp = (current->left != nullptr) ? current->left : current->right;
        if (parent == nullptr) {
            root = temp; // If deleting root node
        } else if (parent->left == current) {
            parent->left = temp;
        } else {
            parent->right = temp;
        }
        delete current;
    } 
    else { // Case 2: Node with two children
        Node* successor = findMin(current->right); // Find inorder successor
        int successorValue = successor->data;
        deleteNode(successorValue); // Delete the successor
        current->data = successorValue; // Replace current node with successor value
    }
}

// Function to perform inorder traversal
void inorder(Node* node) {
    if (node != nullptr) {
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }
}

void displayInorder() {
    inorder(root);
    cout << endl;
}

int main() {
    // Insert nodes
    insert(50);
    insert(30);
    insert(70);
    insert(20);
    insert(40);
    insert(60);
    insert(80);

    cout << "Inorder traversal before deletion: ";
    displayInorder();

    // Delete nodes
    deleteNode(50);

    cout << "Inorder traversal after deleting 50: ";
    displayInorder();

    return 0;
}