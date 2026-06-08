#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "Vehicle.h"
#include <string>
using namespace std;

// Validation
bool isValidEmail(const string& email);
bool isValidPhone(const string& phone);
bool isValidPlate(const string& plate);

// File handling
void saveRecord(const Vehicle& v);
void displayAll();
void searchByPlate(const string& plate);

// Input helpers
Vehicle inputVehicle();

#endif
