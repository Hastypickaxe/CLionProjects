#include <iostream>
#include "mystring.h"

using namespace std;

int main() {
   /* mystring str;
    std::cout << "Enter a string: ";
    std::cin >> str; // Use the input operator (>>)

    std::cout << "You entered: " << str << std::endl; // Use the output operator (<<)
*/
//    mystring greeting("Peace");
//    cout << greeting[0]; // P

//    mystring jack;
//    mystring adjective("nimble");
//    jack += adjective;
//    jack += '&';
//    jack += "quick";
//
//    cout << jack << endl;
//    cout << adjective;

//    mystring name("Alice Bauer");
//    mystring middlename("Kay ");
//    name.insert(middlename, 6);
//    cout << name << endl;
//    cout << middlename;

//    mystring sentence("Hi hello there");
//    sentence.remove(3, 9);
//    cout << sentence;

//    mystring sentence("Hi hello hi you hi there");
//    mystring x("hello");
//    mystring y("hey");
//    sentence.replace(x, y);
//    cout << sentence;

    mystring sentence("Hi hi you hi there");
    mystring x("hi");
    int p = sentence.search(x);
    cout << p;

    return 0;
}

