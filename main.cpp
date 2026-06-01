#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

// Student Object
struct Student
{
    string rollNo;
    string name;
    int age;
};

// Display All Students
void displayStudents()
{
    ifstream file("student.txt");

    string line;

    cout << "\n===== ALL STUDENTS =====\n";

    while(getline(file, line))
    {
        stringstream ss(line);

        string rollNo, name, age;

        getline(ss, rollNo, ',');
        getline(ss, name, ',');
        getline(ss, age, ',');

        cout << "Roll No: " << rollNo << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "------------------------" << endl;
    }

    file.close();
}

// Search Student
void searchStudent()
{
    string searchRoll;

    cout << "Enter Roll Number: ";
    cin >> searchRoll;

    ifstream file("student.txt");

    string line;
    bool found = false;

    while(getline(file, line))
    {
        stringstream ss(line);

        string rollNo, name, age;

        getline(ss, rollNo, ',');
        getline(ss, name, ',');
        getline(ss, age, ',');

        if(rollNo == searchRoll)
        {
            cout << "\nStudent Found\n";
            cout << "Roll No: " << rollNo << endl;
            cout << "Name: " << name << endl;
            cout << "Age: " << age << endl;

            found = true;
            break;
        }
    }

    if(!found)
    {
        cout << "Student not found!" << endl;
    }

    file.close();
}

// Update Student
void updateStudent()
{
    string searchRoll;

    cout << "Enter Roll Number to Update: ";
    cin >> searchRoll;

    ifstream file("student.txt");
    ofstream temp("temp.txt");

    string line;
    bool found = false;

    while(getline(file, line))
    {
        stringstream ss(line);

        string rollNo, name, age;

        getline(ss, rollNo, ',');
        getline(ss, name, ',');
        getline(ss, age, ',');

        if(rollNo == searchRoll)
        {
            found = true;

            Student s;

            s.rollNo = rollNo;

            cout << "Enter New Name: ";
            cin >> s.name;

            cout << "Enter New Age: ";
            cin >> s.age;

            temp << s.rollNo << ","
                 << s.name << ","
                 << s.age << endl;
        }
        else
        {
            temp << line << endl;
        }
    }

    file.close();
    temp.close();

    remove("student.txt");
    rename("temp.txt", "student.txt");

    if(found)
        cout << "Record Updated Successfully!" << endl;
    else
        cout << "Student not found!" << endl;
}

// Delete Student
void deleteStudent()
{
    string searchRoll;

    cout << "Enter Roll Number to Delete: ";
    cin >> searchRoll;

    ifstream file("student.txt");
    ofstream temp("temp.txt");

    string line;
    bool found = false;

    while(getline(file, line))
    {
        stringstream ss(line);

        string rollNo, name, age;

        getline(ss, rollNo, ',');
        getline(ss, name, ',');
        getline(ss, age, ',');

        if(rollNo == searchRoll)
        {
            found = true;
        }
        else
        {
            temp << line << endl;
        }
    }

    file.close();
    temp.close();

    remove("student.txt");
    rename("temp.txt", "student.txt");

    if(found)
        cout << "Record Deleted Successfully!" << endl;
    else
        cout << "Student not found!" << endl;
}

// Main Function
int main()
{
    int choice;

    do
    {
        cout << "\n===== STUDENT MANAGEMENT SYSTEM =====\n";
        cout << "1. Display All Students\n";
        cout << "2. Search Student\n";
        cout << "3. Update Student\n";
        cout << "4. Delete Student\n";
        cout << "5. Exit\n";

        cout << "Enter Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                displayStudents();
                break;

            case 2:
                searchStudent();
                break;

            case 3:
                updateStudent();
                break;

            case 4:
                deleteStudent();
                break;

            case 5:
                cout << "Goodbye!" << endl;
                break;

            default:
                cout << "Invalid Choice!" << endl;
        }

    } while(choice != 5);

    return 0;
}
