#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>

using namespace std;

struct Student {
    int id;
    string name;
    int age;
    string course;
};

void addStudent();
void displayStudents();
void searchStudent();
void updateStudent();
void deleteStudent();

#endif
