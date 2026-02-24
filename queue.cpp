#include <iostream>
using namespace std;

int main()
{
    int q[5];
    int front = -1, rear = -1;
    int choice, value;

    for(;;)
    {
        cout << "\n1.Insert  2.Delete  3.Display  4.Exit\n";
        cin >> choice;

        
        if(choice == 1)
        {
            if(rear == 4)
            {
                cout << "Queue Full\n";
            }
            else
            {
                if(front == -1)  // first element
                    front = 0;

                cout << "Enter value: ";
                cin >> value;

                q[++rear] = value;
                cout << "Inserted\n";

                
                for(int i = front; i <= rear; i++)
                    cout << q[i] << " ";
                cout << endl;
            }
        }

        
        else if(choice == 2)
        {
            if(front == -1 || front > rear)
            {
                cout << "Queue Empty\n";
            }
            else
            {
                cout << "Deleted: " << q[front] << endl;
                front++;

                if(front > rear)   // reset queue
                    front = rear = -1;

                // display after delete
                if(front != -1)
                {
                    for(int i = front; i <= rear; i++)
                        cout << q[i] << " ";
                    cout << endl;
                }
                else
                    cout << "Queue Empty\n";
            }
        }

        // DISPLAY
        else if(choice == 3)
        {
            if(front == -1)
                cout << "Queue Empty\n";
            else
            {
                for(int i = front; i <= rear; i++)
                    cout << q[i] << " ";
                cout << endl;
            }
        }

        else
            break;
    }

    return 0;
}