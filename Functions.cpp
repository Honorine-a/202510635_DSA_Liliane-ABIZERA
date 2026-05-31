#include "Functions.h"
#include <iostream>
using namespace std;

void addBook(LibraryBook books[], int &count) {
    int id;
    string title, author;

    cout << "Enter Book ID: ";
    cin >> id;
    cin.ignore();

    cout << "Enter Title: ";
    getline(cin, title);

    cout << "Enter Author: ";
    getline(cin, author);

    books[count] = LibraryBook(id, title, author);
    count++;

    cout << "Book added successfully!\n";
}

void displayBooks(LibraryBook books[], int count) {
    for (int i = 0; i < count; i++) {
        books[i].display();
    }
}

void searchBook(LibraryBook books[], int count) {
    int id;
    cout << "Enter Book ID to search: ";
    cin >> id;

    for (int i = 0; i < count; i++) {
        if (books[i].getID() == id) {
            books[i].display();
            return;
        }
    }
    cout << "Book not found!\n";
}

void borrowBook(LibraryBook books[], int count) {
    int id, days;
    string name;

    cout << "Enter Book ID: ";
    cin >> id;

    for (int i = 0; i < count; i++) {
        if (books[i].getID() == id) {
            if (books[i].getStatus() == false) {
                cin.ignore();
                cout << "Enter borrower name: ";
                getline(cin, name);

                cout << "Enter number of days: ";
                cin >> days;

                books[i].setBorrower(name);
                books[i].setDays(days);
                books[i].setStatus(true);

                cout << "Book borrowed successfully!\n";
            } else {
                cout << "Book already borrowed!\n";
            }
            return;
        }
    }
    cout << "Book not found!\n";
}

void returnBook(LibraryBook books[], int count) {
    int id;

    cout << "Enter Book ID to return: ";
    cin >> id;

    for (int i = 0; i < count; i++) {
        if (books[i].getID() == id) {
            books[i].setStatus(false);
            books[i].setBorrower("");
            books[i].setDays(0);

            cout << "Book returned successfully!\n";
            return;
        }
    }
    cout << "Book not found!\n";
}

void displayOverdueBooks(LibraryBook books[], int count) {
    for (int i = 0; i < count; i++) {
        if (books[i].getDays() > 7) {
            books[i].display();
        }
    }
}

void calculateTotalFines(LibraryBook books[], int count) {
    int total = 0;

    for (int i = 0; i < count; i++) {
        total += books[i].calculateFine();
    }

    cout << "Total fines = " << total << " RWF\n";
}
