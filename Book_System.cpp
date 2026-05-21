#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void readFile(string fileName) {
    ifstream file(fileName);

    string line;

    if (file.is_open()) {

        while (getline(file, line)) {
            cout << line << endl;
        }

        file.close();

    } else {
        cout << "Unable to open file!" << endl;
    }
}

void historyMenu() {
    cout << "\n===== HISTORY OF C++ =====\n";
    readFile("history.txt");
}

void learnCppMenu() {
    int choice;

    do {
        cout << "\n===== LEARN C++ =====" << endl;
        cout << "1. Data Types" << endl;
        cout << "2. Loops" << endl;
        cout << "3. Arrays" << endl;
        cout << "4. Exit Learning Section" << endl;
        cout << "Choose option: ";
        cin >> choice;

        switch(choice) {

            case 1:
                readFile("datatypes.txt");
                break;

            case 2:
                readFile("loops.txt");
                break;

            case 3:
                readFile("arrays.txt");
                break;

            case 4:
                cout << "Leaving learning section..." << endl;
                break;

            default:
                cout << "Invalid option!" << endl;
        }

    } while(choice != 4);
}

int main() {

    int choice;

    do {
        cout << "\n===== FOUNDATIONS AND HISTORY OF C++ =====" << endl;
        cout << "1. View History of C++" << endl;
        cout << "2. Learn C++ Concepts" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter choice: ";

        cin >> choice;

        switch(choice) {

            case 1:
                historyMenu();
                break;

            case 2:
                learnCppMenu();
                break;

            case 3:
                cout << "Program terminated." << endl;
                break;

            default:
                cout << "Invalid option!" << endl;
        }

    } while(choice != 3);

    return 0;
}