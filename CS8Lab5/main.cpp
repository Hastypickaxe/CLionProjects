#include <iostream>
#include "Polynomial.h"

using namespace std;

int main() {
    double coef1 = 3;
//    cout << "Enter 3 numbers for the first coefficient in decimals: " << endl;
//    cin >> coef1;

    double coef2 = 6;
//    cout << "Enter 3 numbers for the second coefficient in decimals: " << endl;
//    cin >> coef2;

    polynomial p1(2, &coef1);
    polynomial p2(2, &coef2);

    polynomial sum = p1 + p2;

    cout << "p1 : " << p1 << endl;
    cout << "p2 : " << p2 << endl;
    cout << "p1 + p1 : " << sum << endl;
    
    return 0;
}

