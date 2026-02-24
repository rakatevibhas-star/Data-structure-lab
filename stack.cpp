#include <iostream>
using namespace std;

#define MAX 5

int stack[MAX];
int top = -1;

void display()
{
    if(top == -1)
    {
        cout << "Stack is empty\n";
        return;
    }

    cout << "Current Stack (Top to Bottom): ";
    for(int i = top; i >= 0; i--)
    {
        cout << stack[i] << " ";
    }
    cout << endl;
}

void push()
{
    int value;
    if(top == MAX - 1)
    {
        cout << "Stack Overflow\n";
    }
    else
    {
        cout << "Enter value to push: ";
        cin >> value;
        stack[++top] = value;
        cout << "Pushed successfully\n";
        display();
    }
}

void pop()
{
    if(top == -1)
    {
        cout << "Stack Underflow\n";
    }
    else
    {
        cout << "Popped element: " << stack[top--] << endl;
        display();
    }
}

int main()
{
    int n;

    // Initial stack input
    cout << "Enter number of elements to initialize stack (Max " << MAX << "): ";
    cin >> n;

    if(n > MAX)
    {
        cout << "Limit exceeded! Only first " << MAX << " elements will be taken.\n";
        n = MAX;
    }

    cout << "Enter " << n << " elements:\n";
    for(int i = 0; i < n; i++)
    {
        cin >> stack[i];
        top++;
    }

    display();

    int choice;
    do
    {
        cout << "\n1. Push\n2. Pop\n3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: cout << "Exit\n"; break;
            default: cout << "Invalid choice\n";
        }
    }
    while(choice != 3);

    return 0;
}