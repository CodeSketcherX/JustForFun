
#include <iostream>
using namespace std;

void quickSort(float a[], int low, int high)
{
    if (low < high)
    {
        float pivot = a[high];
        int i = low - 1;

        for (int j = low; j < high; j++)
        {
            if (a[j] < pivot)
            {
                i++;
                swap(a[i], a[j]);
            }
        }

        swap(a[i + 1], a[high]);
        int p = i + 1;

        quickSort(a, low, p - 1);
        quickSort(a, p + 1, high);
    }
}

int main()
{
    float a[100];
    int n;

    cout << "Enter number of students: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter percentage: ";
        cin >> a[i];
    }

    quickSort(a, 0, n - 1);

    cout << "\nSorted percentages:\n";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}
