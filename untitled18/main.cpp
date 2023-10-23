#include <iostream>
#include <cassert>

using namespace std;

double power(double x, int n)
{
    if (x == 0)
    {
        assert(n > 0);
        return 0;
    }

    if(n==0){
        return 1;
    }

    if(n > 0) {
        return x * power(x, n - 1);
    }

    else {
        return 1 / (x * power(x, -n - 1));
    }
}

int main() {
   double x1 = 2.0, x2 = 3.0;
   int n1 = 3, n2 = -4;

   cout << power(x1, n1) << endl;
   cout << power(x2, n2) << endl;

   return 0;
}
