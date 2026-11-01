// Write a program for the Student Information System which stores details of N students (Roll No, Name, CGPA). Write functions for the following: 
// a. Insert a new student at a given position 
// b. Delete a student by roll number 
// c. Search a student by roll number and display the record 
// d. Display all students stored in the array.


#include <iostream>
using namespace std;

struct Student {
    int roll;
    string name;
    float cgpa;
};

Student s[100];
int n = 0;

// Insert student at given position
void insert() {
    int pos;
    cout << "Enter position: ";
    cin >> pos;

    if (pos < 1 || pos > n + 1) {
        cout << "Invalid position!\n";
        return;
    }

    for (int i = n; i >= pos; i--)
        s[i] = s[i - 1];

    cout << "Enter Roll No, Name and CGPA: ";
    cin >> s[pos - 1].roll >> s[pos - 1].name >> s[pos - 1].cgpa;

    n++;
    cout << "Student inserted!\n";
}

// Delete student by roll number
void deleteStudent() {
    int roll, i;
    cout << "Enter roll number: ";
    cin >> roll;

    for (i = 0; i < n; i++) {
        if (s[i].roll == roll)
            break;
    }

    if (i == n) {
        cout << "Student not found!\n";
        return;
    }

    for (int j = i; j < n - 1; j++)
        s[j] = s[j + 1];

    n--;
    cout << "Student deleted!\n";
}

// Search student by roll number
void search() {
    int roll;
    cout << "Enter roll number: ";
    cin >> roll;

    for (int i = 0; i < n; i++) {
        if (s[i].roll == roll) {
            cout << "Roll No: " << s[i].roll << endl;
            cout << "Name: " << s[i].name << endl;
            cout << "CGPA: " << s[i].cgpa << endl;
            return;
        }
    }

    cout << "Student not found!\n";
}

// Display all students
void display() {
    if (n == 0) {
        cout << "No student records!\n";
        return;
    }

    for (int i = 0; i < n; i++) {
        cout << "\nRoll No: " << s[i].roll;
        cout << "\nName: " << s[i].name;
        cout << "\nCGPA: " << s[i].cgpa << endl;
    }
}

int main() {
    int choice;

    do {
        cout << "\n1. Insert Student";
        cout << "\n2. Delete Student";
        cout << "\n3. Search Student";
        cout << "\n4. Display Students";
        cout << "\n5. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: insert(); break;
            case 2: deleteStudent(); break;
            case 3: search(); break;
            case 4: display(); break;
            case 5: cout << "Exiting...";
                    break;
            default: cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}
