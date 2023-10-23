#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

void random(int A[])
{
    srand(time(NULL));
    for(int i = 0; i < 10; i++)
    {
        int r = rand()%50+1;
        A[i] = r;
    }
}

void print(int A[])
{
    for(int i = 0; i< 10; i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}

void swapCase(int A[], int left, int right)
{
    if(left < right)
    {
        swap(A[left], A[right]);
        swapCase(A, left + 1, right - 1);
    }
    else {
        print(A);
    }
}

int main() {
    int total;
    int A[10];
    random(A);
    print(A);
    swapCase(A, 0, 9);
}
