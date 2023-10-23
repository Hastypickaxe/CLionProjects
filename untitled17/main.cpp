#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    const int MAX_LEN = 100;

    char str[MAX_LEN];
    cout << "Enter str : ";
    cin.getline(str, MAX_LEN);

    char* ptr = strtok(str, " ");
    while (ptr != NULL)
    {
        cout << ptr << endl;
        ptr = strtok(NULL, " ");
    }
}