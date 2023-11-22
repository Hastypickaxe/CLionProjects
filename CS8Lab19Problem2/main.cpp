#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class QuadraticProbingHashTable {
private:
    int size;

public:
    QuadraticProbingHashTable(int size) : size(size) {
        table = new pair<string, int>[size];
        for (int i = 0; i < size; ++i) {
            table[i] = make_pair("", -1); // Initialize table with empty slots
        }
    }

    int hashFunction(string surname) {
        int P = 7;
        int l = surname.length();
        int h = 0;
        for (int i = 0; i < l; ++i) {
            h = (h * P + surname[i]) % size;
        }
        return h;
    }

    void insert(string surname, int value) {
        int index = hashFunction(surname);
        int originalIndex = index;
        int i = 1;
        while (table[index].second != -1) {
            index = (originalIndex + i * i) % size;
            i += 1;
        }
        table[index] = make_pair(surname, value);
    }

    pair<int, int> search(string surname) {
        int index = hashFunction(surname);
        int originalIndex = index;
        int i = 1;
        while (table[index].second != -1 && table[index].first != surname) {
            index = (originalIndex + i * i) % size;
            i += 1;
        }
        if (table[index].first == surname) {
            return make_pair(index, i);
        } else {
            return make_pair(-1, i);
        }
    }

    void displayTable() {
        cout << "< Hash Table (Quadratic Probing) >" << endl;
        cout << "-------------------------------------" << endl;
        for (int i = 0; i < size; ++i) {
            if (table[i].second != -1) {
                cout << i << " " << table[i].first << " " << table[i].second << endl;
            } else {
                cout << i << "  -1" << endl;
            }
        }
    }

    pair<string, int>* table;
};

int main() {
    QuadraticProbingHashTable hashTable(25);

    // Read data from file
    ifstream inputFile("data.txt");
    string surname;
    int value;
    while (inputFile >> surname >> value) {
        hashTable.insert(surname, value);
    }
    inputFile.close();

    hashTable.displayTable();

    // Search for a surname
    string searchSurname;
    char moreToSearch;
    do {
        cout << "Enter surname to search: ";
        cin >> searchSurname;

        auto result = hashTable.search(searchSurname);
        if (result.first != -1) {
            cout << searchSurname << " is found after " << result.second << " probing" << endl;
            cout << "There are " << hashTable.table[result.first].second << " people with the surname '" << searchSurname << "'" << endl;
        } else {
            cout << searchSurname << " not found" << endl;
        }

        cout << "More to search? (y/n): ";
        cin >> moreToSearch;
    } while (moreToSearch == 'y' || moreToSearch == 'Y');

    return 0;
}
