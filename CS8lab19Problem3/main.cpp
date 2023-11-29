// Include the header file that contains the definition of the hashTable class
#include "hashtable.h"

// Function to compute the hash index using the first hashing method
int hashing1(string name) {
    int index = 0;

    // Iterate through each character in the name and apply a formula to calculate the index
    for (int i = 0; i < name.length(); ++i) {
        index += (name[i] * pow(7, i));
    }

    // Take the modulo to fit within the bounds of the hash table size
    return index % MAX;
}

// Function to compute the hash index using the second hashing method
int hashing2(string name) {
    int index = 0;

    // Iterate through each character in the name and sum their ASCII values
    for (int i = 0; i < name.length(); ++i) {
        index += name[i];
    }

    // Take the modulo to fit within the bounds of the hash table size
    return index % MAX;
}

// Function to insert a value into the hash table using double hashing
void doubleHashing(hashTable table[], string name, int n) {
    int index = hashing1(name);
    int index2 = hashing2(name);
    int i = 0;
    int temp = index;

    // While the current position is not empty, apply double hashing to find the next position
    while (table[temp].getName() != " ") {
        temp = (index + (index2 * i)) % MAX;
        i++;
    }

    // Insert the data into the hash table
    table[temp] = hashTable(name, n);
}

// Function to search for a name in the hash table using double hashing
void probe(hashTable table[], string name) {
    int index = hashing1(name);
    int index2 = hashing2(name);
    int probes = 0;
    int i = 0;
    int temp = index;

    // While the current position is not the desired name and not an empty slot
    while (table[temp].getName() != name && table[temp].getName() != " ") {
        // Apply double hashing to find the next position
        temp = (index + (index2 * i)) % MAX;
        i++;
        probes++;
    }

    // If the desired name is found, print the results
    if (table[temp].getName() == name) {
        cout << name << " is found after " << probes + 1 << " probing" << endl;
        cout << "There are " << table[temp].getValue() << " people who have surname " << name << endl;
    } else {
        cout << "There is no surname " << name << endl;
    }
}

// Function to print the hash table
void print(hashTable table[]) {
    cout << "< Hash Table (Double Hashing) >" << endl;
    cout << "-------------------------------" << endl;

    // Iterate through the hash table and print each element
    for(int i = 0; i < MAX; i++) {
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

// Main function
int main() {
    // Open the data file
    ifstream infile;
    string file = "data.txt";
    infile.open(file);

    // Check if the file opened successfully
    if(infile.fail()) {
        cout << "File failed to open" << endl;
        exit(1);
    }

    string name;
    int value;
    hashTable table[MAX];

    // Read in the data from the file and store it in the hash table using double hashing
    while(!infile.eof()) {
        infile >> name >> value;
        doubleHashing(table, name, value);
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

        // Perform the search using double hashing
        probe(table, input);

        cout << endl;
        cout << "More to search? (y/n) ";
        cin >> more;
        cout << endl;
    } while(more == 'y' || more == 'Y');

    // Close the file
    infile.close();
    return 0;
}
