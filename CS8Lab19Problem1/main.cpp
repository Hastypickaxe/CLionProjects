#include "hash.h"

// Hashing function to find the index in the hash table
int linearHash(string name) {
    int index = 0;

    // Iterates through the string and applies a formula to find the index to save the name-value pair
    for (int i = 0; i < name.length(); i++) {
        index += name[i] * pow(7, i);
    }

    return index % MAX;
}

// Function to print the hash table
void printHash(hashTable table[]) {
    cout << "< Hash Table (Linear probing) >" << endl;
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

// Function that searches for a name in the hash table using linear probing
void probing(hashTable table[], string name) {
    int index = linearHash(name);
    int probes = 0;

    // If name not in table and table is not empty
    while (table[index].getName() != name && table[index].getName() != " "){
        index = (index + 1) % MAX;
        probes++;
    }

    // If name is found in table, outputs the results
    if(name == table[index].getName()) {
        cout << name << " is found after " << probes + 1 << " probing" << endl;
        cout << "There are " << table[index].getValue() << " people who have surname " << name << endl;
    } else {
        cout << "There is no surname " << name << endl;
    }
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

    // Read in the data from the file and store it in the hash table
    while(!infile.eof()) {
        infile >> name >> value;
        int index = linearHash(name);

        // If not empty, apply the check for collision and then insert into table
        while(table[index].getName() != " ") {
            index = (index + 1) % MAX;
        }
        table[index] = hashTable(name, value);
    }

    // Print the hash table
    printHash(table);

    cout << endl;

    char choice;
    string userInput;

    // Search for surnames in the hash table based on user input
    do {
        cout << "Enter surname to search : ";
        cin >> userInput;

        probing(table, userInput);

        cout << endl;
        cout << "More to search? (y/n) ";
        cin >> choice;
        cout << endl;
    } while(choice == 'y' || choice == 'Y');

    // Close the file
    infile.close();

    return 0;
}