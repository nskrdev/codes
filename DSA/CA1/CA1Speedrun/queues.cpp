#include <iostream>
using namespace std;

#define n 20

class queue {
    int *arr;
    int front;
    int back;

public:
    queue() {
        arr = new int[n];
        front = -1;
        back = -1;
    }

    ~queue() {
        delete[] arr;
    }

    void push(int x) {
        if (back == n - 1) {
            cout << "Queue overflow\n";
            return;
        }
        back++;
        arr[back] = x;

        if (front == -1) {
            front++;
        }
    }

    void pop() {
        if (front == -1 || front > back) {
            cout << "No elements in queue\n";
            return;
        }
        front++;
        if (front > back) {
            front = -1;  
            back = -1;
        }
    }

    int peek() {
        if (front == -1 || front > back) {
            cout << "No elements in queue\n";
            return -1;
        }
        return arr[front];
    }

    bool isEmpty() {
        return front == -1;
    }

    void traverse() {
        if (front == -1 || front > back) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= back; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    cout << "Queue before pop:\n";
    q.traverse(); 

    q.pop();
    cout << "Queue after pop:\n";
    q.traverse(); 

    return 0;
}
