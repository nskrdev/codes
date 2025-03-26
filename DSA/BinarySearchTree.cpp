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
    
    // Case 1: 0 Child Case 
    if ((current->left == nullptr) && (current->right == nullptr)) {
        if (parent == nullptr) {
            root = nullptr; // If deleting root node
        } 
        else {
            if(parent->left == current)
                parent->left = nullptr;
            else
                parent->right = nullptr;
        }
        delete current;
    } // Case 2: 1 Child Case 
    else if (current->left == nullptr || current->right == nullptr) {
        Node* temp = (current->left != nullptr) ? current->left : current->right;
        if (parent->left == current) {
            parent->left = temp;
        } else {
            parent->right = temp;
        }
        delete current;
    } 
    else { // Case 3: 2 children case
        Node* successor = findMin(current->right); // Find inorder successor
        int successorValue = successor->data;
        deleteNode(successorValue); // Delete the successor
        current->data = successorValue; // Replace current node with successor value
    }
}

// Function to perform inorder traversal
void Inorder(Node* root) {
    Node* temp = root;
    if (temp != nullptr) {
        Inorder(temp->left);
        cout << temp->data << " ";
        Inorder(temp->right);
    }
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
    insert(90);

    cout << "Inorder traversal before deletion: ";
    Inorder(root);

    // Delete nodes
    deleteNode(50);

    cout << "Inorder traversal after deleting 50: ";
    Inorder(root);

    return 0;
}
