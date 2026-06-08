#ifndef USER_H
#define USER_H

#include <string>
using namespace std;

// Base class — holds general person information
class User {
private:
    string name;
    string email;
    string phone;

public:
    // Default constructor
    User() : name(""), email(""), phone("") {}

    // Parameterised constructor
    User(string n, string e, string p) : name(n), email(e), phone(p) {}

    // Getters
    string getName()  const { return name;  }
    string getEmail() const { return email; }
    string getPhone() const { return phone; }

    // Setters
    void setName(string n)  { name  = n; }
    void setEmail(string e) { email = e; }
    void setPhone(string p) { phone = p; }
};

#endif
