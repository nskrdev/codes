#include<iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next;
};

void insert(Node** head, int new_data)
{
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data  = new_data;
    new_node->next = (*head);
    (*head)    = new_node;
}

void printList(Node *n)
{
    while (n != NULL) {
        cout<< n->data <<" ";
        n = n->next;
    }
}

void deleteNode(struct Node **head_ref, int key)
{
   struct Node* temp = *head_ref, *prev;

    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    prev->next = temp->next;

    free(temp);
}

int main()
{
    Node* head = NULL;

    insert(&head, 50); 
    insert(&head, 40); 
    insert(&head, 30); 
    insert(&head, 20); 
    insert(&head, 10); 

    cout << "Linked List: ";
    printList(head); 
    cout << endl;

    deleteNode(&head, 30); 

    cout << "Linked List after removal of 30: ";
    printList(head); 
    cout << endl;


    return 0;
}