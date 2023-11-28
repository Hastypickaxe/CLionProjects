#include<iostream>

//Time complexity for test2: 

using namespace std;

const int N = 20; // array size

int test2(int A[], int x)
{

}

int main() {
    int A[N] = { 1, 1, 1, 3, 3, 3, 3, 3, 4, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 7 };

    int answer = test2(A, 3);
    if (answer > 0) cout << "3 appears " << answer << " times in A" << endl;
    else cout << "3 does not appear in A" << endl;

    answer = test2(A, 6);
    if (answer > 0) cout << "6 appears " << answer << " times in A" << endl;
    else cout << "6 does not appear in A" << endl;

    answer = test2(A, 2);
    if (answer > 0) cout << answer << '\n';
    else cout << "2 does not appear in A" << endl;
}