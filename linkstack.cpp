#include <iostream>

struct Node {
    int data;
    Node* next;
};

class Stack {
    Node* top = nullptr;

public:
    void push(int val) {
        top = new Node{val, top}; // Creates node and points it to old top in one step
    }

    void pop() {
        if (top) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }

    int peek() {
        return top ? top->data : -1; // Returns -1 if empty
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    
    std::cout << "Top: " << s.peek() << "\n"; // Outputs 20
    
    s.pop();
    std::cout << "Top: " << s.peek() << "\n"; // Outputs 10
    
    return 0;
}