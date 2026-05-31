#include "LibraryBook.h"
#include <iostream>
using namespace std;

// Default constructor
LibraryBook::LibraryBook() {
    bookID = 0;
    title = "";
    author = "";
    borrowerName = "";
    daysBorrowed = 0;
    isBorrowed = false;
}

// Parameterized constructor
LibraryBook::LibraryBook(int id, string t, string a) {
    bookID = id;
    title = t;
    author = a;
    borrowerName = "";
    daysBorrowed = 0;
    isBorrowed = false;
}

// Destructor
LibraryBook::~LibraryBook() {
    cout << "Book object with ID " << bookID << " destroyed." << endl;
}

// Getters
int LibraryBook::getID() { return bookID; }
string LibraryBook::getTitle() { return title; }
string LibraryBook::getAuthor() { return author; }
string LibraryBook::getBorrower() { return borrowerName; }
int LibraryBook::getDays() { return daysBorrowed; }
bool LibraryBook::getStatus() { return isBorrowed; }

// Setters
void LibraryBook::setBorrower(string name) {
    borrowerName = name;
}

void LibraryBook::setDays(int days) {
    daysBorrowed = days;
}

void LibraryBook::setStatus(bool status) {
    isBorrowed = status;
}

// Display book
void LibraryBook::display() {
    cout << "ID: " << bookID
         << " | Title: " << title
         << " | Author: " << author
         << " | Status: " << (isBorrowed ? "Borrowed" : "Available") << endl;
}

// Fine calculation
int LibraryBook::calculateFine() {
    if (daysBorrowed > 7) {
        return (daysBorrowed - 7) * 100;
    }
    return 0;
}
