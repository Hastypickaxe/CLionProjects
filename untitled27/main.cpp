#include <iostream>
#include <map>
#include <iomanip>

//Time complexity for tes1:

using namespace std;

bool test1(string s1, string s2)
{
    if (s1 == s2) {

    }
}

int main()
{
    string s1, s2;
    cout << "Enter s1: ";
    cin >> s1;
    cout << "Enter s2: ";
    cin >> s2;

    if (test1(s1, s2))
        cout << s1 << " and " << s2 << " have same composition" << endl;
    else
        cout << s1 << " and " << s2 << " have different composition" << endl;
    return 0;
}
