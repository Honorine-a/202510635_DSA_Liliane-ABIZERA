#ifndef VEHICLE_H
#define VEHICLE_H

#include "User.h"
#include <string>
using namespace std;

// Derived class — inherits User, represents a vehicle owner
class VehicleOwner : public User {
public:
    // Default constructor — calls User default constructor
    VehicleOwner() : User() {}

    // Parameterised constructor — chains to User constructor
    VehicleOwner(string n, string e, string p) : User(n, e, p) {}
};

// Separate class — represents a vehicle linked to an owner
class Vehicle {
private:
    string       plateNumber;
    string       vehicleType;
    int          year;
    VehicleOwner owner;      // association: Vehicle has a VehicleOwner

public:
    // Default constructor
    Vehicle() : plateNumber(""), vehicleType(""), year(0), owner() {}

    // Parameterised constructor
    Vehicle(string plate, string type, int yr, VehicleOwner ow)
        : plateNumber(plate), vehicleType(type), year(yr), owner(ow) {}

    // Getters
    string       getPlateNumber() const { return plateNumber; }
    string       getVehicleType() const { return vehicleType; }
    int          getYear()        const { return year;        }
    VehicleOwner getOwner()       const { return owner;       }

    // Setters
    void setPlateNumber(string p)    { plateNumber = p;  }
    void setVehicleType(string t)    { vehicleType = t;  }
    void setYear(int y)              { year        = y;  }
    void setOwner(VehicleOwner o)    { owner       = o;  }

    // Display one record neatly
    void display() const;
};

#endif
