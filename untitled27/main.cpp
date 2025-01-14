// Name: Justin Dang
// 
// Add any header files you need
#include<iostream>
#include <array>


using namespace std;

// Write the time complexity of your test1 function.
// Time complexity:O(n)

// The two strings, s1 and s2, always have the same length.

const int CHAR_RANGE = 128;

bool test1(string s1, string s2)
{
    array<int, CHAR_RANGE> count1 = {0};
    array<int, CHAR_RANGE> count2 = {0};

    for (char c : s1) {
        count1[c]++;
    }

    for (char c : s2) {
        count2[c]++;
    }

    for (int i = 0; i < CHAR_RANGE; ++i) {
        if (count1[i] != count2[i]) {
            return false;
        }
    }

    return true;
}

// Do not change the main function
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