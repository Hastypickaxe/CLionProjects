// hashtable.h

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

using namespace std;

const int MAX = 10; // You can adjust the size according to your needs

class Hash_Table {
private:
    string name;
    int value;

public:
    Hash_Table() : name(" "), value(0) {}
    Hash_Table(string n, int v) : name(n), value(v) {}

    string getName() const { return name; }
    int getValue() const { return value; }
};

int linear_hash(string key);
void print_hash(Hash_Table table[]);
void probing(Hash_Table table[], string key);

#endif // HASHTABLE_H
