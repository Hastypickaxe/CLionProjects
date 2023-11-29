//#include <iostream>
//#include <fstream>
//#include <string>
//
//using namespace std;
//
//class QuadraticProbingHashTable {
//private:
//    int size;
//
//public:
//    QuadraticProbingHashTable(int size) : size(size) {
//        table = new pair<string, int>[size];
//        for (int i = 0; i < size; ++i) {
//            table[i] = make_pair("", -1); // Initialize table with empty slots
//        }
//    }
//
//    int hashFunction(string surname) {
//        int P = 7;
//        int l = surname.length();
//        int h = 0;
//        for (int i = 0; i < l; ++i) {
//            h = (h * P + surname[i]) % size;
//        }
//        return h;
//    }
//
//    void insert(string surname, int value) {
//        int index = hashFunction(surname);
//        int originalIndex = index;
//        int i = 1;
//        while (table[index].second != -1) {
//            index = (originalIndex + i * i) % size;
//            i += 1;
//        }
//        table[index] = make_pair(surname, value);
//    }
//
//    pair<int, int> search(string surname) {
//        int index = hashFunction(surname);
//        int originalIndex = index;
//        int i = 1;
//        while (table[index].second != -1 && table[index].first != surname) {
//            index = (originalIndex + i * i) % size;
//            i += 1;
//        }
//        if (table[index].first == surname) {
//            return make_pair(index, i);
//        } else {
//            return make_pair(-1, i);
//        }
//    }
//
//    void displayTable() {
//        cout << "< Hash Table (Quadratic Probing) >" << endl;
//        cout << "-------------------------------------" << endl;
//        for (int i = 0; i < size; ++i) {
//            if (table[i].second != -1) {
//                cout << i << " " << table[i].first << " " << table[i].second << endl;
//            } else {
//                cout << i << "  -1" << endl;
//            }
//        }
//    }
//
//    pair<string, int>* table;
//};
//
//int main() {
//    QuadraticProbingHashTable hashTable(25);
//
//    // Read data from file
//    ifstream inputFile("data.txt");
//    string surname;
//    int value;
//    while (inputFile >> surname >> value) {
//        hashTable.insert(surname, value);
//    }
//    inputFile.close();
//
//    hashTable.displayTable();
//
//    // Search for a surname
//    string searchSurname;
//    char moreToSearch;
//    do {
//        cout << "Enter surname to search: ";
//        cin >> searchSurname;
//
//        auto result = hashTable.search(searchSurname);
//        if (result.first != -1) {
//            cout << searchSurname << " is found after " << result.second << " probing" << endl;
//            cout << "There are " << hashTable.table[result.first].second << " people with the surname '" << searchSurname << "'" << endl;
//        } else {
//            cout << searchSurname << " not found" << endl;
//        }
//
//        cout << "More to search? (y/n): ";
//        cin >> moreToSearch;
//    } while (moreToSearch == 'y' || moreToSearch == 'Y');
//
//    return 0;
//}

// Include the header file that contains the definition of the hashTable class
#include "hashtable.h"

// Function to compute the hash index using quadratic probing
int hashing(string name) {
    int index = 0;

    // Iterate through each character in the name and apply a formula to calculate the index
    for (int i = 0; i < name.length(); ++i) {
        index += name[i] * pow(7, i);
    }

    // Take the modulo to fit within the bounds of the hash table size
    return index % MAX;
}

// Function to print the hash table
void print(hashTable table[]) {
    cout << "< Hash Table (Quadratic probing) >" << endl;
    cout << "-------------------------------" << endl;

    // Iterate through the hash table and print each element
    for (int i = 0; i < MAX; ++i) {
        cout << setw(3) << i << setw(12);

        // Check if the current element is empty
        if (table[i].getName() == " ") {
            cout << setw(12) << " " << endl;
        } else {
            cout << setw(12) << table[i].getName() << setw(12) << table[i].getValue() << endl;
        }
    }
    cout << "-------------------------------" << endl;
}

// Function to search for a name in the hash table using quadratic probing
void probe(hashTable table[], string name) {
    int index = hashing(name);
    int probes = 0;
    int i = 0;
    int temp = index;

    // While the current position is not the desired name and not an empty slot
    while (table[temp].getName() != name && table[temp].getName() != " ") {
        // Apply quadratic probing to find the next position
        temp = (index + int(pow(i, 2))) % MAX;
        i++;
        probes++;
    }

    // If the desired name is found, print the results
    if (name == table[temp].getName()) {
        if (probes == 0) {
            cout << name << " is found after " << probes + 1 << " probing" << endl;
            cout << "There are " << table[temp].getValue() << " people who have surname " << name << endl;
        } else {
            cout << name << " is found after " << probes << " probing" << endl;
            cout << "There are " << table[temp].getValue() << " people who have surname " << name << endl;
        }
    } else {
        cout << "There is no surname " << name << endl;
    }
}

// Main function
int main() {
    // Open the data file
    ifstream infile;
    string filename = "data.txt";
    infile.open(filename);

    // Check if the file opened successfully
    if (infile.fail()) {
        cout << "Failed to open file";
        exit(1);
    }

    string name;
    int n;
    hashTable table[MAX];

    // Read in the data from the file and store it in the hash table using quadratic probing
    while (!infile.eof()) {
        infile >> name >> n;
        int index = hashing(name);

        int i = 0;
        int temp = index;

        // While the current position is not empty, apply quadratic probing to find the next position
        while (table[temp].getName() != " ") {
            temp = (index + int(pow(i, 2))) % MAX;
            i++;
        }

        // Insert the data into the hash table
        table[temp] = hashTable(name, n);
    }

    // Print the hash table
    print(table);

    cout << endl;

    char more;
    string input;

    // Search for surnames in the hash table based on user input
    do {
        cout << "Enter surname to search : ";
        cin >> input;

        // Perform the search using quadratic probing
        probe(table, input);

        cout << endl;
        cout << "More to search? (y/n) ";
        cin >> more;
        cout << endl;
    } while (more == 'y' || more == 'Y');

    // Close the file
    infile.close();

    return 0;
}
