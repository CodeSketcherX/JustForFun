
#include <iostream>
using namespace std;

int q[5];
int front = -1, rear = -1;
int size = 5;

void insert(int id)
{
    if ((rear + 1) % size == front)
        cout << "Queue is full\n";
    else
    {
        if (front == -1)
            front = 0;

        rear = (rear + 1) % size;
        q[rear] = id;
        cout << "Student added\n";
    }
}

void deleteID()
{
    if (front == -1)
        cout << "Queue is empty\n";
    else
    {
        cout << "Pass issued to student: " << q[front] << endl;

        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % size;
    }
}

void display()
{
    if (front == -1)
    {
        cout << "Queue is empty\n";
        return;
    }

    cout << "Circular Queue: ";
    int i = front;

    while (true)
    {
        cout << q[i] << " ";
        if (i == rear)
            break;
        i = (i + 1) % size;
    }
    cout << endl;
}

int main()
{
    int ch, id;

    do
    {
        cout << "\n1.Insert  2.Issue Pass  3.Display  4.Exit\n";
        cout << "Enter choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "Enter student ID: ";
            cin >> id;
            insert(id);
            break;

        case 2:
            deleteID();
            break;

        case 3:
            display();
            break;
        }
    } while (ch != 4);

    return 0;
}
