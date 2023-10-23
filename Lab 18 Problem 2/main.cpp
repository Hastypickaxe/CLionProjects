#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

void random(int A[])
{
    srand(time(NULL));
    for(int i = 0; i < 10; i++)
    {
        int r = rand()%10+1;
        A[i] = r;
    }
}

void print(int A[]) {
    for (int i = 0; i < 10; i++) {
        cout << A[i] << " ";
    }
    cout<<endl;
}

int sum(int A[], int size)
{
    if(size == 1)
    {
        return A[0];
    }
    return A[size] + sum(A, size - 1);
}

int main()
{
    int total;
    int A[10];
    random(A);
    print(A);
    total = sum(A, 9);
    cout<<total;
}
