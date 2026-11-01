
#include <iostream>
using namespace std;

struct Student
{
    int id;
    float cgpa;
};

Student q[100];
int n = 0, processed = 0;

void insert()
{
    Student s;

    if (n == 100)
    {
        cout << "Queue is Full!\n";
        return;
    }

    cout << "Enter Student ID and CGPA: ";
    cin >> s.id >> s.cgpa;

    int i = n - 1;

    while (i >= 0 && q[i].cgpa < s.cgpa)
    {
        q[i + 1] = q[i];
        i--;
    }

    q[i + 1] = s;
    n++;

    cout << "Student inserted.\n";
}

void deleteHighest()
{
    if (n == 0)
    {
        cout << "Queue is Empty!\n";
        return;
    }

    cout << "Deleted Student ID: " << q[0].id
         << " CGPA: " << q[0].cgpa << endl;

    for (int i = 0; i < n - 1; i++)
        q[i] = q[i + 1];

    n--;
    processed++;
}

void display()
{
    if (n == 0)
    {
        cout << "Queue is Empty!\n";
        return;
    }

    cout << "Priority Queue:\n";

    for (int i = 0; i < n; i++)
        cout << "ID: " << q[i].id
             << " CGPA: " << q[i].cgpa << endl;
}

int main()
{
    int choice;

    do
    {
        cout << "\n1. Insert Student";
        cout << "\n2. Delete Highest CGPA";
        cout << "\n3. Display Queue";
        cout << "\n4. Count Processed Students";
        cout << "\n5. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                insert();
                display();
                break;

            case 2:
                deleteHighest();
                display();
                break;

            case 3:
                display();
                break;

            case 4:
                cout << "Students Processed: "
                     << processed << endl;
                break;

            case 5:
                cout << "Exiting...";
                break;

            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}
