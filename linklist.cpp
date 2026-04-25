#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = NULL;
    }

    // Insert at Front
    void insertFront(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    // Insert at End
    void insertEnd(int val) {
        Node* newNode = new Node(val);

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    // Insert at Any Position (1-based index)
    void insertAtPosition(int val, int pos) {
        Node* newNode = new Node(val);

        if (pos == 1) {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* temp = head;
        for (int i = 1; i < pos - 1 && temp != NULL; i++) {
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Position out of range\n";
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Display Linked List
    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    LinkedList list;

    list.insertFront(10);
    list.insertFront(5);

    list.insertEnd(20);
    list.insertEnd(30);

    list.insertAtPosition(15, 3);
    list.insertAtPosition(25, 4);

    cout << "Linked List: ";
    list.display();

    return 0;
}