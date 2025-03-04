#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int val)
    {
        data = val;
        next= NULL;
    }

};

class List{
    Node* head;
    Node* tail;

public:
    List(){
        head=tail=NULL;
    }

    void pushFont(int val){
        Node* newNode = new Node(val);
        if(head==NULL){
            head = tail = newNode;
            return;
        } else {
            newNode->next = head;
            head = newNode;
        }

    }
    void pushBack(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
        }

    }
    void popFront(){
        if (head==NULL){
            cout<<"Linked list is empty"<<endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        temp->next = NULL;

        delete temp;
    }
    void popBack(){
        if(head==NULL){
            cout<<"LL is empty\n";
            return;
        }
        Node* temp = head;
        while(temp->next !=tail){
            temp = temp->next;
        }
        temp ->next = NULL;
        delete tail;
        tail = temp;
    }
    void insert(int val, int pos){
        if (pos<0){
            cout<<"invalid position\n";
            return;
        }
        if (pos == 0){
            pushFont(val);
            return;
        }
        Node* temp = head;
        for (int i =0; i<pos-1; i++){
            if(temp ==NULL){
                cout<<"Invalid position\n";
                return;
            }
            temp = temp->next;
        }
        Node*newNode = new Node(val);
        newNode->next=temp->next;
        temp->next=newNode;

    }

    void printLL(){
        Node* temp = head;
        while(temp != NULL){
            cout<<temp->data<<" ";
            temp = temp->next;

        }
        cout<<NULL<<endl;
    }
    int search(int key){
        Node* temp = head;
        int idx = 0;
        while (temp !=NULL){
            if(temp->data==key){
                return idx;
            }
            temp = temp->next;
            idx++;
        }
        return -1;
    }
};

int main()
{

    List ll;
    
    ll.pushFont(1);
    ll.pushFont(2);
    ll.pushFont(3);
    ll.pushBack(4);
    ll.insert(10,2);
    ll.popFront();
    ll.popBack();
    ll.printLL();
    cout<<ll.search(0)<<endl;
    return 0;
}
