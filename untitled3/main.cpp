/*#include <iostream>
using namespace std;
void hanoi(int n, char S, char D, char A)
{
    if (n == 0) return;
    hanoi(n - 1, S, A, D);
    cout << "Move " << n << " from " << S << " to " << D << endl;
    hanoi(n - 1, A, D, S);
}
int main()
{
    int N = 8;
    hanoi(N, 'S', 'D', 'A');
    return 0;
}*/

#include<iostream>
using namespace std;
void write_vertical(int number)
{
    if (number < 10) cout << number << endl;
    else {
        write_vertical(number/10);
        cout << number % 10 << endl;
    }
}
int main()
{
    int n;
    cout << "Enter an integer : ";
    cin >> n;
    write_vertical(n);
    return 0;
}