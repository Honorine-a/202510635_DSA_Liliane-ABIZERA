#include "Functions.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cctype>
using namespace std;
 
const string FILE_NAME = "records.txt";
 
// --------------------------------------------
//  VALIDATION
// --------------------------------------------
 
bool isValidEmail(const string& email) {
    if (email.empty()) return false;
    if (email[0] == '@' || email[0] == '.') return false;
    if (email[email.size()-1] == '@' || email[email.size()-1] == '.') return false;
 
    bool hasAt  = false;
    bool hasDot = false;
    int  atPos  = -1;
 
    for (int i = 0; i < (int)email.size(); i++) {
        if (email[i] == '@') { hasAt = true; atPos = i; }
        if (email[i] == '.' && atPos != -1) hasDot = true;
    }
    return hasAt && hasDot;
}
 
bool isValidPhone(const string& phone) {
    if (phone.size() != 13)           return false;
    if (phone.substr(0, 4) != "+250") return false;
    for (int i = 1; i < 13; i++) {
        if (!isdigit(phone[i])) return false;
    }
    return true;
}
 
bool isValidPlate(const string& plate) {
    if (plate.size() != 7) return false;
    for (int i = 0; i < 3; i++)
        if (!isalpha(plate[i]) || !isupper(plate[i])) return false;
    for (int i = 3; i < 6; i++)
        if (!isdigit(plate[i])) return false;
    if (!isalpha(plate[6]) || !isupper(plate[6])) return false;
    return true;
}
 
// --------------------------------------------
//  FILE HANDLING
// --------------------------------------------
 
void saveRecord(const Vehicle& v) {
    ofstream file(FILE_NAME.c_str(), ios::app);
    if (!file) {
        cout << "  [!] Could not open file for writing.\n";
        return;
    }
    file << v.getPlateNumber()      << ","
         << v.getVehicleType()      << ","
         << v.getYear()             << ","
         << v.getOwner().getName()  << ","
         << v.getOwner().getEmail() << ","
         << v.getOwner().getPhone() << "\n";
    file.close();
    cout << "  [OK] Record saved to " << FILE_NAME << "\n";
}
 
void displayAll() {
    ifstream file(FILE_NAME.c_str());
    if (!file) {
        cout << "  [!] No records file found. Add a record first.\n";
        return;
    }
 
    string line;
    bool   empty = true;
 
    cout << "\n";
    cout << string(90, '=') << "\n";
    cout << left
         << setw(10) << "Plate"
         << setw(10) << "Type"
         << setw(6)  << "Year"
         << setw(20) << "Owner Name"
         << setw(25) << "Email"
         << setw(15) << "Phone"
         << "\n";
    cout << string(90, '-') << "\n";
 
    while (getline(file, line)) {
        if (line.empty()) continue;
        empty = false;
 
        stringstream ss(line);
        string plate, type, yearStr, name, email, phone;
 
        getline(ss, plate,   ',');
        getline(ss, type,    ',');
        getline(ss, yearStr, ',');
        getline(ss, name,    ',');
        getline(ss, email,   ',');
        getline(ss, phone,   ',');
 
        int year = 0;
        stringstream ys(yearStr);
        ys >> year;
 
        VehicleOwner owner(name, email, phone);
        Vehicle v(plate, type, year, owner);
        v.display();
    }
 
    cout << string(90, '=') << "\n";
    if (empty) cout << "  No records found.\n";
    file.close();
}
 
void searchByPlate(const string& plate) {
    ifstream file(FILE_NAME.c_str());
    if (!file) {
        cout << "  [!] No records file found.\n";
        return;
    }
 
    string line;
    bool   found = false;
 
    while (getline(file, line)) {
        if (line.empty()) continue;
 
        stringstream ss(line);
        string p, type, yearStr, name, email, phone;
 
        getline(ss, p,       ',');
        getline(ss, type,    ',');
        getline(ss, yearStr, ',');
        getline(ss, name,    ',');
        getline(ss, email,   ',');
        getline(ss, phone,   ',');
 
        if (p == plate) {
            found = true;
            int year = 0;
            stringstream ys(yearStr);
            ys >> year;
 
            cout << "\n  -- Record Found --\n";
            cout << "  Plate Number : " << p     << "\n";
            cout << "  Vehicle Type : " << type  << "\n";
            cout << "  Year         : " << year  << "\n";
            cout << "  Owner Name   : " << name  << "\n";
            cout << "  Email        : " << email << "\n";
            cout << "  Phone        : " << phone << "\n";
            cout << "  ------------------\n";
            break;
        }
    }
 
    if (!found)
        cout << "  [!] No vehicle with plate \"" << plate << "\" found.\n";
 
    file.close();
}
 
// --------------------------------------------
//  INPUT WITH VALIDATION
// --------------------------------------------
 
Vehicle inputVehicle() {
    string plate, type, name, email, phone;
    int    year;
 
    // Plate number
    do {
        cout << "  Plate Number (e.g. RAA123A, uppercase): ";
        cin  >> plate;
        if (!isValidPlate(plate))
            cout << "  [!] Invalid plate. Must be 3 UPPERCASE letters + 3 digits + 1 UPPERCASE letter.\n";
    } while (!isValidPlate(plate));
 
    cin.ignore();
 
    // Vehicle type
    cout << "  Vehicle Type (e.g. Sedan, SUV, Truck)  : ";
    getline(cin, type);
 
    // Year
    do {
        cout << "  Year of Manufacture (e.g. 2020)        : ";
        cin  >> year;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            year = 0;
        }
        if (year < 1900 || year > 2025)
            cout << "  [!] Year must be between 1900 and 2025.\n";
    } while (year < 1900 || year > 2025);
 
    cin.ignore();
 
    // Owner name
    cout << "  Owner Full Name                        : ";
    getline(cin, name);
 
    // Email
    do {
        cout << "  Owner Email                            : ";
        getline(cin, email);
        if (!isValidEmail(email))
            cout << "  [!] Invalid email. Must contain @ and a dot after @.\n";
    } while (!isValidEmail(email));
 
    // Phone
    do {
        cout << "  Owner Phone (+250XXXXXXXXX)            : ";
        getline(cin, phone);
        if (!isValidPhone(phone))
            cout << "  [!] Invalid. Must start with +250 and be 13 characters total.\n";
    } while (!isValidPhone(phone));
 
    VehicleOwner owner(name, email, phone);
    Vehicle      v(plate, type, year, owner);
    return v;
}

