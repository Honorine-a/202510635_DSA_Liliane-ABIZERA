#include <iostream>
#include <limits>
#include "Functions.h"
using namespace std;

void printMenu() {
    cout << "\n";
    cout << "  +--------------------------------------------------+\n";
    cout << "  ¦   VEHICLE REGISTRATION & OWNER MANAGEMENT SYSTEM ¦\n";
    cout << "  ¦   Transport Authority — Rwanda                    ¦\n";
    cout << "  ¦--------------------------------------------------¦\n";
    cout << "  ¦  1. Register New Vehicle                          ¦\n";
    cout << "  ¦  2. Display All Vehicles                          ¦\n";
    cout << "  ¦  3. Search Vehicle by Plate Number                ¦\n";
    cout << "  ¦  4. Exit                                          ¦\n";
    cout << "  +--------------------------------------------------+\n";
    cout << "  Enter choice (1-4): ";
}

int main() {
    int choice;

    do {
        printMenu();

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "  [!] Please enter a number.\n";
            continue;
        }

        switch (choice) {
            case 1: {
                cout << "\n--- Register New Vehicle ---\n";
                Vehicle v = inputVehicle();
                saveRecord(v);
                break;
            }
            case 2:
                displayAll();
                break;

            case 3: {
                string plate;
                cout << "\n  Enter Plate Number to search: ";
                cin  >> plate;
                searchByPlate(plate);
                break;
            }
            case 4:
                cout << "\n  Goodbye!\n";
                break;

            default:
                cout << "  [!] Choose between 1 and 4.\n";
        }

    } while (choice != 4);

    return 0;
}
