#include <iostream>

using namespace std;

int binary(int n)
{
    if(n == 0)
    {
        return 0;
    }
    else
    {
        return (n % 2 + 10 * binary(n/2));
    }
}

int main() {

    int n;
    char more = 'y';
    do {
        cout<<"Enter one positive integer: ";
        cin>>n;
        cout<<"Decimal "<<n<<" -> "<<binary(n)<<endl;
        cout<<"More (y/n) ?"<<endl;
        cin >> more;
    } while (more == 'y');
}
