
#include <iostream>
#include <string>
using namespace std;

string stack[100];
int top = -1;

void visit(string url)
{
    stack[++top] = url;
    cout << "Page visited\n";
}

void back()
{
    if (top > 0)
    {
        top--;
        cout << "Went back\n";
    }
    else
        cout << "No previous page\n";
}

void current()
{
    if (top == -1)
        cout << "No page open\n";
    else
        cout << "Current page: " << stack[top] << endl;
}

void history()
{
    if (top == -1)
        cout << "History is empty\n";

    for (int i = top; i >= 0; i--)
        cout << stack[i] << endl;
}

int main()
{
    int ch;
    string url;

    do
    {
        cout << "\n1.Visit  2.Back  3.Current Page  4.History  5.Exit\n";
        cout << "Enter choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "Enter URL: ";
            cin >> url;
            visit(url);
            break;

        case 2:
            back();
            break;

        case 3:
            current();
            break;

        case 4:
            history();
            break;
        }
    } while (ch != 5);

    return 0;
}
