#include "student.h"

Student students[100];
int studentCount = 0;

void addStudent() {
    cout << "\nEnter Student ID: ";
    cin >> students[studentCount].id;

    cin.ignore();

    cout << "Enter Name: ";
    getline(cin, students[studentCount].name);

    cout << "Enter Age: ";
    cin >> students[studentCount].age;

    cin.ignore();

    cout << "Enter Course: ";
    getline(cin, students[studentCount].course);

    studentCount++;

    cout << "Student added successfully.\n";
}

void displayStudents() {

    if (studentCount == 0) {
        cout << "\nNo students available.\n";
        return;
    }

    cout << "\n===== STUDENT LIST =====\n";

    for (int i = 0; i < studentCount; i++) {

        cout << "\nStudent " << i + 1 << endl;
        cout << "ID: " << students[i].id << endl;
        cout << "Name: " << students[i].name << endl;
        cout << "Age: " << students[i].age << endl;
        cout << "Course: " << students[i].course << endl;
    }
}

void searchStudent() {
    int id;
    bool found = false;

    cout << "\nEnter Student ID to search: ";
    cin >> id;

    for (int i = 0; i < studentCount; i++) {

        if (students[i].id == id) {

            cout << "\nStudent Found\n";
            cout << "ID: " << students[i].id << endl;
            cout << "Name: " << students[i].name << endl;
            cout << "Age: " << students[i].age << endl;
            cout << "Course: " << students[i].course << endl;

            found = true;
        }
    }

    if (!found) {
        cout << "Student not found.\n";
    }
}

void updateStudent() {
    int id;
    bool found = false;

    cout << "\nEnter Student ID to update: ";
    cin >> id;

    cin.ignore();

    for (int i = 0; i < studentCount; i++) {

        if (students[i].id == id) {

            cout << "Enter new name: ";
            getline(cin, students[i].name);

            cout << "Enter new age: ";
            cin >> students[i].age;

            cin.ignore();

            cout << "Enter new course: ";
            getline(cin, students[i].course);

            cout << "Student updated successfully.\n";

            found = true;
        }
    }

    if (!found) {
        cout << "Student not found.\n";
    }
}

void deleteStudent() {
    int id;
    bool found = false;

    cout << "\nEnter Student ID to delete: ";
    cin >> id;

    for (int i = 0; i < studentCount; i++) {

        if (students[i].id == id) {

            for (int j = i; j < studentCount - 1; j++) {
                students[j] = students[j + 1];
            }

            studentCount--;

            cout << "Student deleted successfully.\n";

            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Student not found.\n";
    }
}
