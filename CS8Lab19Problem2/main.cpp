// Include the header file that contains the definition of the hashTable class
#include "hash.h"

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
