#include <iostream>
using namespace std;
// Structure for heap node
struct Node {
    int data;
    Node* left;
    Node* right;
    Node* parent;
};
// Global root of the heap
Node* root = nullptr;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = new Node{data, nullptr, nullptr};
    return newNode;
}

// Function to swap two nodes' data
void swap(Node* a, Node* b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

// Function to find the position for the new node (Manual Traversal)
Node* findInsertPosition() {
    if (root == nullptr) return nullptr;

    Node* temp = root;

    while (true) {
        // If left child is missing, return current node for insertion
        if (temp->left == nullptr) return temp;
        // If right child is missing, return current node for insertion
        if (temp->right == nullptr) return temp;

        // Check if the left subtree is full. If full, go right. Otherwise, go left.
        if ( (temp->left->left != nullptr && temp->left->right != nullptr) &&
             (temp->right->left == nullptr || temp->right->right == nullptr) ) {
            temp = temp->right;  // Move right if left is full
        } else {
            temp = temp->left;   // Otherwise, move left
        }
    }
}


// Function to insert a new node in the heap
void insert(int data) {
    Node* newNode = createNode(data);
    if (root==nullptr) {
        root = newNode;
        return;
    }

    Node* insertPos = findInsertPosition();
    if (insertPos->left == nullptr) {
        insertPos->left = newNode;
    } else {
        insertPos->right = newNode;
    }
    newNode->parent = insertPos;

    // Heapify Up to maintain heap property
    while (newNode->parent && newNode->data > newNode->parent->data) {
        swap(newNode, newNode->parent);
        newNode = newNode->parent;
    }
}

// Function to find the last inserted node (Manual Traversal)
Node* findLastNode() {
    if (root == nullptr) return nullptr;

    Node* temp = root;
    while (temp->left!=nullptr || temp->right!=nullptr) {
        if (temp->right!=nullptr) {
            temp = temp->right;
        } else {
            temp = temp->left;
        }
    }
    return temp;
}

// Function to delete the root node (Max-Heap Delete)
void deleteRoot() {
    if (root==nullptr) {
        cout << "Heap is empty!" << endl;
        return;
    }

    Node* lastNode = findLastNode();
    if (lastNode == root) {
        delete root;
        root = nullptr;
        return;
    }

    // Swap last node's value with root
    swap(root, lastNode);

    // Remove the last node manually
    if (lastNode->parent->right == lastNode) {
        lastNode->parent->right = nullptr;
    } else {
        lastNode->parent->left = nullptr;
    }

    delete lastNode;

    // Heapify Down
    Node* temp = root;
    while (true) {
        Node* smallest = temp;
        if (temp->left && temp->left->data > smallest->data)
            smallest = temp->left;
        if (temp->right && temp->right->data > smallest->data)
            smallest = temp->right;

        if (smallest == temp)
            break;

        swap(temp, smallest);
        temp = smallest;
    }
}

// Function to print heap in in-order traversal
void printHeap(Node* node) {
    if (node==nullptr) return;
    printHeap(node->left);
    cout << node->data << " ";
    printHeap(node->right);
}

// Driver function
int main() {
    int Arr[] = {10,20,15,30,40,5,50,100};
    int size = sizeof(Arr) / sizeof(Arr[0]);
    for(int i=0; i<size;i++)
    {
        insert(Arr[i]);
    }
    
    cout << "\nHeap elements (in-order traversal): \n";
    printHeap(root);
    
    cout << endl;

    cout<<"\nDeleting root element iteratively and heapify to get the max at root.\n";
    for(int i = 0; i< size; i++)
    {
        cout<<"Iteration number : "<<i+1<<", Deleting Root, where Root is "<<root->data<<endl;
        Arr[size-i-1] = root->data;
        deleteRoot();
    }

    cout<<"sorted Array is : \n";
    for(int i = 0; i< size; i++)
    {
        cout<<Arr[i]<<" ";
    }

    cout << endl;

    return 0;
}
