// This is a header guard to prevent the inclusion of this header file multiple times in the same program.
#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <iomanip>

using namespace std;

// Maximum size of the hash table
const int MAX = 25;

// Class representing data to be stored in the hash table
class hashTable {
private:
    string name;
    int value;
public:
    // Constructors
    hashTable() : name(" "), value(0) {}
    hashTable(string n, int p) : name(n), value(p) {}

    // Setters
    void setName(string n) { name = n; }
    void setValue(int p) { value = p; }

    // Getters
    string getName() { return name; }
    int getValue() { return value; }

};

#endif  // HASHTABLE_H