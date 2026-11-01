
#include <iostream>
using namespace std;

void selectionSort(float a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;

        for (int j = i + 1; j < n; j++)
            if (a[j] < a[min])
                min = j;

        swap(a[i], a[min]);
    }
}

void bubbleSort(float a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
        }
    }
}

int main()
{
    float a[100], b[100];
    int n;

    cout << "Enter number of students: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter percentage: ";
        cin >> a[i];
        b[i] = a[i];
    }

    selectionSort(a, n);
    bubbleSort(b, n);

    cout << "\nSelection Sort (Ascending): ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    cout << "\nBubble Sort (Ascending): ";
    for (int i = 0; i < n; i++)
        cout << b[i] << " ";

    cout << "\nTop Five Scores:\n";
    for (int i = n - 1; i >= 0 && i >= n - 5; i--)
        cout << b[i] << " ";

    return 0;
}
