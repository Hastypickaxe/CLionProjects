#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int M = 25; // Hash table size
const int P = 7;  // Prime number for polynomial rolling hash function

int polynomialRollingHash(const string& str, int length) {
    int hashValue = 0;
    for (int i = 0; i < length; ++i) {
        hashValue = (hashValue * P + str[i]) % M;
        if (hashValue < 0) {
            hashValue += M;
        }
    }
    return hashValue;
}

class LinearProbingHashTable {
private:
    pair<string, int> table[M];

public:
    LinearProbingHashTable() {
        for (int i = 0; i < M; ++i) {
            table[i] = make_pair("", 0); // Use an empty string for key and 0 for count to represent an empty slot
        }
    }

    void insert(const string& key, int value) {
        int hashValue = polynomialRollingHash(key, key.length());
        int index = hashValue % M;
        int originalIndex = index;
        int probingCount = 0;

        while (table[index].second != 0) { // Check for 0 to detect an empty slot
            // Linear probing
            index = (index + 1) % M;
            probingCount++;

            // Check if we have completed a full loop
            if (index == originalIndex) {
                cerr << "Hash table is full. Unable to insert: " << key << endl;
                return;
            }
        }

        table[index] = make_pair(key, value);
    }

    pair<int, int> search(const string& key) {
        int hashValue = polynomialRollingHash(key, key.length());
        int index = hashValue % M;
        int probingCount = 0;

        while (table[index].second != 0 && table[index].first != key) { // Check for 0 to detect an empty slot
            // Linear probing
            index = (index + 1) % M;
            probingCount++;

            // Check if we have completed a full loop
            if (probingCount == M) {
                cout << "Key not found in the hash table." << endl;
                return make_pair(-1, probingCount);
            }
        }

        if (table[index].first == key) {
            return make_pair(index, probingCount + 1);
        } else {
            // Key not found
            return make_pair(-1, probingCount + 1); // Increment probing count for unsuccessful search
        }
    }

    const pair<string, int>& operator[](int index) const {
        return table[index];
    }
};

int main() {
    ifstream inputFile("data.txt");
    if (!inputFile.is_open()) {
        cout << "Error opening file." << endl;
        return 1;
    }

    LinearProbingHashTable hashTable;

    string surname;
    int count;

    while (inputFile >> surname >> count) {
        hashTable.insert(surname, count);
    }

    inputFile.close();

    cout << "< Hash Table (Linear Probing) >" << endl;
    cout << "-------------------------------------" << endl;

    for (int i = 0; i < M; ++i) {
        pair<int, int> result = hashTable.search(hashTable[i].first);
        if (result.first != -1) {
            cout << i << " " << hashTable[result.first].first << " " << hashTable[result.first].second << endl;
        }
    }

    while (true) {
        cout << "\nEnter surname to search: ";
        cin >> surname;

        pair<int, int> result = hashTable.search(surname);

        if (result.first != -1) {
            cout << surname << " is found after " << result.second << " probing" << endl;
            cout << "There are " << hashTable[result.first].second << " people with the surname '" << surname << "'" << endl;
        } else {
            cout << surname << " not found in the hash table." << endl;
        }

        cout << "More to search? (y/n): ";
        char choice;
        cin >> choice;

        if (choice != 'y' && choice != 'Y') {
            break;
        }
    }

    return 0;
}
