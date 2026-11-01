
#include <iostream>
using namespace std;

int q[100];
int front = -1, rear = -1;

void enqueue(int token)
{
    if (rear == 99)
        cout << "Queue is full\n";
    else
    {
        if (front == -1)
            front = 0;

        q[++rear] = token;
        cout << "Student added\n";
    }
}

void dequeue()
{
    if (front == -1 || front > rear)
        cout << "Queue is empty\n";
    else
    {
        cout << "Processed student: " << q[front] << endl;
        front++;
    }
}

void displayFrontRear()
{
    if (front == -1 || front > rear)
        cout << "Queue is empty\n";
    else
    {
        cout << "Front token: " << q[front] << endl;
        cout << "Rear token: " << q[rear] << endl;
    }
}

void display()
{
    if (front == -1 || front > rear)
        cout << "Queue is empty\n";
    else
    {
        cout << "Queue: ";
        for (int i = front; i <= rear; i++)
            cout << q[i] << " ";
        cout << endl;
    }
}

int main()
{
    int ch, token;

    do
    {
        cout << "\n1.Enqueue  2.Dequeue  3.Front/Rear  4.Display  5.Exit\n";
        cout << "Enter choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "Enter token number: ";
            cin >> token;
            enqueue(token);
            break;

        case 2:
            dequeue();
            break;

        case 3:
            displayFrontRear();
            break;

        case 4:
            display();
            break;
        }
    } while (ch != 5);

    return 0;
}
