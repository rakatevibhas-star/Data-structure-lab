#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;
};

Node* head = NULL;

// Insert node at end
void insert(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    }
    else {
        Node* temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->prev = temp;
    }
}

// Display list forward
void display() {
    Node* temp = head;

    if (temp == NULL) {
        cout << "List is empty";
        return;
    }

    cout << "Doubly Linked List: ";
    while (temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL";
}

int main() {
    int n, value;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> value;
        insert(value);
    }

    display();

    return 0;
}