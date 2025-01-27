#include <iostream>
#define MAX 5 
using namespace std;

int queue[MAX];
int front = -1, rear = -1;

// Function to check if the queue is empty
bool isEmpty() {
    
}

// Function to check if the queue is full
bool isFull() 
{
  
}

void enqueue(int value) 
{
	if(rear==MAX-1){
        cout<<"overflow, queue is Full";
        return;
    }
    if(front==-1 && rear==-1){
        front++;
    
    rear++;
    queue[rear]=value;
    cout<<"insertion done successfully";
}
}


void dequeue() 
{
//    if(fytront&&rear ==-1)
}


void TraveseQueue() 
{
    if (front && rear ==-1)
    {
        cout << "queue is empty";
        return;
    }
    for (int i = front;i<rear;i++){
        cout<<queue[i]<<" ";
    }
}

void SearchQueue()
{
}

int main() {
    int choice, value;

    do {
        cout << "\n--- Queue Menu ---\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Traverse \n";
	   cout << "4. Search\n";
        cout << "5. IsEmpty\n";
        cout << "6. IsFull\n";
        cout << ". Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to enqueue: ";
                cin >> value;
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                TraveseQueue();
                break;
            case 4:
                SearchQueue();
                break;
            case 5:
                cout << isEmpty();
                break;
            case 6:
                cout << isFull();
                break;
            case 7:
                cout << "Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 7);

    return 0;
}