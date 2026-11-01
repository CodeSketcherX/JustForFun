
#include <iostream>
using namespace std;

struct Node
{
    int marks;
    Node *next;
};

int main()
{
    int n, marks[100], count = 0;
    Node *head = NULL, *temp, *newnode;

    cout << "Enter number of students: ";
    cin >> n;

    // Insert marks in array and linked list
    for (int i = 0; i < n; i++)
    {
        cout << "Enter marks: ";
        cin >> marks[i];

        newnode = new Node;
        newnode->marks = marks[i];
        newnode->next = NULL;

        if (head == NULL)
            head = newnode;
        else
        {
            temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newnode;
        }
    }

    // Display array
    cout << "\nArray representation:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Index " << i << " = " << marks[i] << endl;

        if (marks[i] > 80)
            count++;
    }

    // Display linked list
    cout << "\nLinked list representation:\n";
    temp = head;

    while (temp != NULL)
    {
        cout << temp->marks << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";

    cout << "\nStudents scoring above 80: " << count;

    return 0;
}
