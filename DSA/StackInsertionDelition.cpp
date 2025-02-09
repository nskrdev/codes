#include<iostream>
#include<stack>
using namespace std;

int main() {
    stack<int>s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    cout<< "Stack after pushing elements"<<endl;

    cout<< "Top of stack: "<<s.top()<<endl;

    cout<< "Poping elements from stack:"<<endl;

    while (!s.empty()){
        cout<<"Poped: "<<s.top() << endl;
        s.pop();
    }
    if (s.empty()){
        cout<<"Stack is now empty"<< endl;
    }
    return 0;

}