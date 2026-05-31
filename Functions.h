#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "LibraryBook.h"

const int MAX_BOOKS = 100;

void addBook(LibraryBook books[], int &count);
void displayBooks(LibraryBook books[], int count);
void searchBook(LibraryBook books[], int count);
void borrowBook(LibraryBook books[], int count);
void returnBook(LibraryBook books[], int count);
void displayOverdueBooks(LibraryBook books[], int count);
void calculateTotalFines(LibraryBook books[], int count);

#endif
