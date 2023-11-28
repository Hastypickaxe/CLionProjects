#include <iostream>
#include <array>

using namespace std;

// Time complexity: O(n), where n is the length of the input strings

bool test1(string s1, string s2)
{
    // Assuming ASCII characters, but can be adjusted for Unicode
    const int CHAR_RANGE = 128;

    // Arrays to store character counts
    array<int, CHAR_RANGE> count1 = {0};
    array<int, CHAR_RANGE> count2 = {0};

    // Count characters in s1
    for (char c : s1) {
        count1[c]++;
    }

    // Count characters in s2
    for (char c : s2) {
        count2[c]++;
    }

    // Compare character counts
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
        cout << s1 << " and " << s2 << " have the same composition" << endl;
    else
        cout << s1 << " and " << s2 << " have different composition" << endl;

    return 0;
}
