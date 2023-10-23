#include <iostream>

using namespace std;

int main() {
    string temp;
   string word;
   cout << "Enter some words: ";
   cin >> word;
   cout << "You entered: " << word << endl;
    cin.ignore();

    string line;
   cout << "Enter a line of input: ";
   getline(cin, line);
   cout << "You entered: " << line << endl;

    return 0;
}
