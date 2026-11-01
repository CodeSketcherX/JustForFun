
#include <iostream>
using namespace std;

struct Node
{
    char attendance;
    Node *next;
};

Node *head = NULL;

void insert(char a)
{
    Node *newnode = new Node;
    newnode->attendance = a;
    newnode->next = NULL;

    if (head == NULL)
        head = newnode;
    else
    {
        Node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newnode;
    }
}

void update(int day, char a)
{
    Node *temp = head;

    for (int i = 1; temp != NULL && i < day; i++)
        temp = temp->next;

    if (temp == NULL)
        cout << "Invalid day\n";
    else
        temp->attendance = a;
}

void count()
{
    int p = 0, a = 0;
    Node *temp = head;

    while (temp != NULL)
    {
        if (temp->attendance == 'P')
            p++;
        else
            a++;
        temp = temp->next;
    }

    cout << "Present: " << p << endl;
    cout << "Absent: " << a << endl;
}

void display()
{
    Node *temp = head;
    int day = 1;

    while (temp != NULL)
    {
        cout << "Day " << day << ": "
             << temp->attendance << endl;
        temp = temp->next;
        day++;
    }
}

int main()
{
    int ch, day;
    char a;

    do
    {
        cout << "\n1.Insert  2.Update  3.Count  4.Display  5.Exit\n";
        cout << "Enter choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "Enter P or A: ";
            cin >> a;
            insert(a);
            break;

        case 2:
            cout << "Enter day: ";
            cin >> day;
            cout << "Enter P or A: ";
            cin >> a;
            update(day, a);
            break;

        case 3:
            count();
            break;

        case 4:
            display();
            break;
        }
    } while (ch != 5);

    return 0;
}
