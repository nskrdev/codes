#include <iostream>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

class Stack {
private:
    struct node *stack;
    int top;
    
public:
    Stack() {
        this->stack = nullptr;
        this->top = -1;
    }
    
    Stack(int data) {
        this->stack = new struct node;
        this->stack->data = data;
        this->stack->next = nullptr;
        this->stack->prev = nullptr;
        this->top = 0;
    }
    
    ~Stack() {
        while (stack != nullptr) {
            struct node* temp = stack;
            stack = stack->prev;
            delete temp;
        }
    }

    struct node *get_curr() {
        return this->stack;
    }

    Stack *push(int data) {
        struct node* newNode = new struct node;
        newNode->data = data;
        newNode->next = nullptr;
        newNode->prev = stack;
        
        if (stack != nullptr) {
            stack->next = newNode;
        }
        stack = newNode;
        top++;
        return this;
    }

    Stack *pop() {
        if (stack == nullptr) {
            return this;
        }
        
        struct node* temp = stack;
        stack = stack->prev;
        
        if (stack != nullptr) {
            stack->next = nullptr;
        }
        
        delete temp;
        top--;
        return this;
    }

    int search(int key) {
        struct node *temp = this->stack;
        int index = this->top;
        while(temp != nullptr) {
            if(temp->data == key) {
                return index;
            }
            temp = temp->prev;
            index--;
        }
        return -1;
    }

    void print_all() {
        struct node *temp = this->stack;
        while(temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->prev;
        }
        std::cout << std::endl;
    }

    int get_top() {
        return this->top;
    }
};

int main(void) {
    Stack s(2);
    s.push(3)->push(30)->push(40)->push(50)->push(180);
    s.print_all();
    std::cout << "Search result for 40: " << s.search(40) << std::endl;
    s.pop()->pop();
    std::cout << "After popping two elements: " << std::endl;
    s.print_all();
    return 0;
}