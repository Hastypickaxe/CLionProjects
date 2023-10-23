#include <iostream>

using namespace std;

int findPower(int base, int exp);

int main() {
   int base = 0, e = 0;

   cout<<"Enter a base number: ";
   cin >> base;
   cout<<"Enter and exponent: ";
   cin>>e;

   cout<<base<<"^"<<e<<"="<<findPower(base, e);
}

int findPower(int base, int exp)
{
    if(exp == 0)
    {
       return 1;
    }
    return base * findPower(base, exp-1 );
}
