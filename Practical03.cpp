
#include <iostream>
using namespace std;

struct Node
{
    int roll;
    Node *prev, *next;
};

Node *head = NULL;

void insert(int r)
{
    Node *n = new Node;
    n->roll = r;
    n->prev = n->next = NULL;

    if (head == NULL || head->roll >= r)
    {
        n->next = head;
        if (head != NULL)
            head->prev = n;
        head = n;
    }
    else
    {
        Node *t = head;

        while (t->next != NULL && t->next->roll < r)
            t = t->next;

        n->next = t->next;
        n->prev = t;

        if (t->next != NULL)
            t->next->prev = n;

        t->next = n;
    }
}

void deleteStudent(int r)
{
    Node *t = head;

    while (t != NULL && t->roll != r)
        t = t->next;

    if (t == NULL)
    {
        cout << "Student not found\n";
        return;
    }

    if (t->prev != NULL)
        t->prev->next = t->next;
    else
        head = t->next;

    if (t->next != NULL)
        t->next->prev = t->prev;

    delete t;
    cout << "Student deleted\n";
}

void forward()
{
    Node *t = head;

    while (t != NULL)
    {
        cout << t->roll << " ";
        t = t->next;
    }
    cout << endl;
}

void backward()
{
    Node *t = head;

    if (t == NULL)
        return;

    while (t->next != NULL)
        t = t->next;

    while (t != NULL)
    {
        cout << t->roll << " ";
        t = t->prev;
    }
    cout << endl;
}

int main()
{
    int ch, r;

    do
    {
        cout << "\n1.Insert  2.Delete  3.Forward  4.Backward  5.Exit\n";
        cout << "Enter choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "Enter roll number: ";
            cin >> r;
            insert(r);
            break;

        case 2:
            cout << "Enter roll number to delete: ";
            cin >> r;
            deleteStudent(r);
            break;

        case 3:
            forward();
            break;

        case 4:
            backward();
            break;
        }
    } while (ch != 5);

    return 0;
}

