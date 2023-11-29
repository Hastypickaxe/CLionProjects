#include "hashtable.h"

using namespace std;

int hashing1(string name) {

    int index = 0;

    for (int i = 0; i < name.length(); ++i) {
        index += (name[i] * pow(7,i));
    }

    return index % MAX;
}

int hashing2(string name) {

    int index = 0;

    for (int i = 0; i < name.length(); ++i) {
        index += name[i];
    }

    return index % MAX;
}

void doubleHashing(hashTable table[], string name, int n) {
    int index = hashing1(name);
    int index2 = hashing2(name);
    int i = 0;
    int temp = index;

    while (table[temp].getName() != " ") {
        temp = (index + (index2 * i)) % MAX;
        i++;
    }

    table[temp] = hashTable(name, n);
}

void probe(hashTable table[], string name) {
    int index = hashing1(name);
    int index2 = hashing2(name);
    int probes = 0;
    int i = 0;
    int temp = index;

    while (table[temp].getName() != name && table[temp].getName() != " ") {
        temp = (index + (index2 * i)) % MAX;
        i++;
        probes++;
    }

    if (table[temp].getName() == name) {
        cout << name << " is found after " << probes + 1 << " probing" << endl;
        cout << "There are " << table[temp].getValue() << " people who have surname " << name <<endl;
    } else {
        cout << "There is no surname " << name << endl;
    }
}

void print(hashTable table[]) {
    cout << "< Hash Table (Double Hashing) >" << endl;
    cout << "-------------------------------" << endl;

    for(int i = 0; i < MAX; i++) {
        cout << setw(3) << i << setw(12);

        if (table[i].getName() == " ") {
            cout << setw(12) << " " << endl;
        } else {
            cout << setw(12) << table[i].getName() << setw(12) << table[i].getValue() << endl;
        }
    }
    cout << "-------------------------------" << endl;
}

int main() {
    ifstream infile;
    string file = "data.txt";

    infile.open(file);

    if(infile.fail()) {
        cout << "File failed to open" << endl;
        exit(1);
    }

    string name;
    int value;
    hashTable table[MAX];

    // reads in the data from file and stores into class
    while(!infile.eof()) {
        infile >> name >> value;
        doubleHashing(table, name, value);
    }

    print(table);

    cout << endl;

    char more;
    string input;

    do {
        cout << "Enter surname to search : ";
        cin >> input;

        probe(table, input);

        cout << endl;
        cout << "More to search? (y/n) ";
        cin >> more;
        cout << endl;
    } while(more == 'y' || more == 'Y');

    infile.close();
    return 0;
}
