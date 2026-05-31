#ifndef LIBRARYBOOK_H
#define LIBRARYBOOK_H

#include <string>
using namespace std;

class LibraryBook {
private:
    int bookID;
    string title;
    string author;
    string borrowerName;
    int daysBorrowed;
    bool isBorrowed;

public:
    LibraryBook();
    LibraryBook(int id, string t, string a);
    ~LibraryBook();

    // Getters
    int getID();
    string getTitle();
    string getAuthor();
    string getBorrower();
    int getDays();
    bool getStatus();

    // Setters
    void setBorrower(string name);
    void setDays(int days);
    void setStatus(bool status);

    // Methods
    void display();
    int calculateFine();
};

#endif
