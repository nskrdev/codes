#include <iostream>
using namespace std;

// Define the structure for a node
struct Node {
    int data;
    Node* next;
};

// Global head pointer
Node* head = nullptr;

// Function to insert at the beginning
void insertAtBeginning(int value) {
    // Step 1: Create a new node
    Node* newNode = new Node(); 
    newNode->data = value;  // Assign value to the new node
    newNode->next = head;   // Point new node's `next` to the current head

    // Step 2: Update head to the new node
    head = newNode;
    cout << "Inserted " << value << " at the beginning.\n";
}

// Function to insert at the end
void insertAtEnd(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr) { 
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {  // Traverse to the last node
            temp = temp->next;
        }
        temp->next = newNode;  // Attach new node at the end
    }
    cout << "Inserted " << value << " at the end.\n";
}

// Function to insert at a specific position
void insertAtPosition(int value, int position) {
    if (position < 1) {
        cout << "Invalid position!\n";
        return;
    }

    Node* newNode = new Node();
    newNode->data = value;

    if (position == 1) {  // Insert at beginning
        newNode->next = head;
        head = newNode;
    } else {
        Node* temp = head;
        for (int i = 1; temp != nullptr && i < position - 1; i++) {
            temp = temp->next;  // Move temp to (position - 1)
        }

        if (temp == nullptr) {
            cout << "Position out of bounds!\n";
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    cout << "Inserted " << value << " at position " << position << ".\n";
}

// Function to display the linked list
void display() {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }
    
    Node* temp = head;
    cout << "Linked List: ";
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// Main function
int main() {
    int choice, value, position;
    
    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Position\n";
        cout << "4. Display List\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                insertAtBeginning(value);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> value;
                insertAtEnd(value);
                break;
            case 3:
                cout << "Enter value: ";
                cin >> value;
                cout << "Enter position: ";
                cin >> position;
                insertAtPosition(value, position);
                break;
            case 4:
                display();
                break;
            case 5:
                cout << "Program Exiting... Thank you!\n";
                return 0;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }
    
    return 0;
}
