#include <iostream>
#include <fstream>
#include <string>
#include "notepad.h"

using namespace std;

void writeFile(string filename)
{
    ofstream file(filename.c_str());

    if (!file)
    {
        cout << "Error creating file." << endl;
        return;
    }

    string line;

    cout << "Enter text (type END to finish):" << endl;

    cin.ignore();

    while (true)
    {
        getline(cin, line);

        if (line == "END")
            break;

        file << line << endl;
    }

    file.close();

    cout << "File saved successfully." << endl;
}

void readFile(string filename)
{
    ifstream file(filename.c_str());

    if (!file)
    {
        cout << "File not found." << endl;
        return;
    }

    string line;

    cout << "\nFile Contents:\n";

    while (getline(file, line))
    {
        cout << line << endl;
    }

    file.close();
}

void appendFile(string filename)
{
    ofstream file(filename.c_str(), ios::app);

    if (!file)
    {
        cout << "Error opening file." << endl;
        return;
    }

    string line;

    cout << "Enter text to append (type END to finish):" << endl;

    cin.ignore();

    while (true)
    {
        getline(cin, line);

        if (line == "END")
            break;

        file << line << endl;
    }

    file.close();

    cout << "Text appended successfully." << endl;
}
