#include<iostream>
using namespace std;
  
struct Queue {
    int items[10];
    int front;
    int rear;
};
 
void createQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}
  
bool isFull(Queue *q) {
    if ((q->rear + 1) % 10 == q->front){
        return true;
    }
    return false;
}
  
bool isEmpty(Queue *q) {
    if (q->rear == -1)
       return true;
    return false;
} 

void enqueue(Queue *q, int num) {
    if (isFull(q)) {
        cout << "Queue is full\n";
        return;
    } else if (isEmpty(q)) {
        q->front = q->rear = 0;
    } 
    else{
        q->rear = (q->rear + 1) % 10;
    }
    q->items[q->rear] = num;
}
  
int dequeue(Queue *q) {
    int num;
    if (isEmpty(q)) {
        cout << "Queue is empty\n";
        return (-1);
    } else if (q->front == q->rear){
        num = q->items[q->front];
        createQueue(q);
        return num;
    } 
    else {
        num = q->items[q->front];
        q->front = (q->front + 1) % 10;
        return num;
    }
}
  
void display(Queue *q) {
    int i = q->front;
    if (!isEmpty(q)){
        cout << "Elements in the Circular Queue are: ";
        while (i != q->rear){
            cout  << q->items[i] <<  " ";
            i  = (i + 1) % 10;
        }
        cout <<  q->items[i];   
        cout << "\n";
    }
}
  
void sortQueue(Queue *q){
    int temp;
    for (int i = 0; i < 10; ++i) {
        for (int j = i + 1; j < 10; ++j) {
            if (q->items[i] > q->items[j]) {
                temp = q->items[i];
                q->items[i] = q->items[j];
                q->items[j] = temp;
            }
        }
    }
} 
  
int main() {
   Queue q;
   createQueue(&q);
   enqueue(&q, 10);
   enqueue(&q, 20);
   enqueue(&q, 30);
   enqueue(&q, 40);
   display(&q);
   sortQueue(&q);
    cout<<"Sorted Queue is: ";
   display(&q);
   return 0;
}