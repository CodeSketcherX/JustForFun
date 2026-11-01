
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Student
{
    int roll;
    string name, division;
};

int main()
{
    Student s[100], temp;
    int n, i, j, key, comp, found;
    string searchName;

    cout << "Enter number of students: ";
    cin >> n;

    for (i = 0; i < n; i++)
    {
        cout << "Enter roll, name and division: ";
        cin >> s[i].roll >> s[i].name >> s[i].division;
    }

    // Linear search by name
    cout << "\nEnter name to search: ";
    cin >> searchName;

    comp = 0;
    found = -1;

    for (i = 0; i < n; i++)
    {
        comp++;
        if (s[i].name == searchName)
        {
            found = i;
            break;
        }
    }

    if (found != -1)
        cout << "Found: " << s[found].roll << " "
             << s[found].name << " " << s[found].division << endl;
    else
        cout << "Student not found\n";

    cout << "Linear search comparisons: " << comp << endl;

    // Sort by roll number
    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
            if (s[i].roll > s[j].roll)
            {
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }

    // Binary search by roll number
    cout << "\nEnter roll number to search: ";
    cin >> key;

    int low = 0, high = n - 1;
    found = -1;
    comp = 0;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        comp++;

        if (s[mid].roll == key)
        {
            found = mid;
            break;
        }
        else if (s[mid].roll < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    if (found != -1)
        cout << "Found: " << s[found].roll << " "
             << s[found].name << " " << s[found].division << endl;
    else
        cout << "Student not found\n";

    cout << "Binary search comparisons: " << comp << endl;

    return 0;
}
