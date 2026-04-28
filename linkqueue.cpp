#include <iostream>

struct Node {
    int data;
    Node* next;
};

class Queue {
    Node* front = nullptr;
    Node* rear = nullptr;

public:
    // Enqueue: Add an element to the back of the queue
    void enqueue(int val) {
        Node* newNode = new Node{val, nullptr};
        if (!rear) {
            front = rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
    }

    // Dequeue: Remove the front element from the queue
    void dequeue() {
        if (!front) return; // Queue is empty
        
        Node* temp = front;
        front = front->next;
        
        if (!front) {
            rear = nullptr; // If the queue becomes empty, reset rear
        }
        delete temp;
    }

    // Peek: Get the value of the front element
    int peek() {
        return front ? front->data : -1; // Returns -1 if empty
    }
};

int main() {
    Queue q;
    
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    
    std::cout << "Front element: " << q.peek() << "\n"; // Outputs 10
    
    q.dequeue();
    std::cout << "Front after 1 dequeue: " << q.peek() << "\n"; // Outputs 20
    
    return 0;
}