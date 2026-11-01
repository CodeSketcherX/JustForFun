
#include <iostream>
using namespace std;

int main()
{
    int n, i, j, min;
    float cgpa[100], key;
    int shifts = 0;

    cout << "Enter number of students: ";
    cin >> n;

    for (i = 0; i < n; i++)
    {
        cout << "Enter CGPA: ";
        cin >> cgpa[i];
    }

    // Selection sort in descending order
    for (i = 0; i < n - 1; i++)
    {
        min = i;

        for (j = i + 1; j < n; j++)
        {
            if (cgpa[j] > cgpa[min])
                min = j;
        }

        key = cgpa[i];
        cgpa[i] = cgpa[min];
        cgpa[min] = key;
    }

    // Insertion sort in descending order
    for (i = 1; i < n; i++)
    {
        key = cgpa[i];
        j = i - 1;

        while (j >= 0 && cgpa[j] < key)
        {
            cgpa[j + 1] = cgpa[j];
            j--;
            shifts++;
        }

        cgpa[j + 1] = key;
    }

    cout << "\nMerit List:\n";
    for (i = 0; i < n; i++)
        cout << cgpa[i] << endl;

    cout << "Total shifts: " << shifts << endl;

    cout << "\nTop 5 Students:\n";
    for (i = 0; i < n && i < 5; i++)
        cout << cgpa[i] << endl;

    return 0;
}
