#include "Vehicle.h"
#include <iostream>
#include <iomanip>
using namespace std;

void Vehicle::display() const {
    cout << left
         << setw(10) << plateNumber
         << setw(10) << vehicleType
         << setw(6)  << year
         << setw(20) << owner.getName()
         << setw(25) << owner.getEmail()
         << setw(15) << owner.getPhone()
         << endl;
}
