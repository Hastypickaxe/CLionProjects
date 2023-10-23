#include <iostream>

using namespace std;

template <class T>
int index_of_maximal(T a[], int b){
            T max = a[b];
            int indexMax = b;

            for(int i = 0; i < b; i++){
                if(a[i]>max){
                    max = a[i];
                    indexMax = i;
                }
            }
            return indexMax;
        }

int main()
{
int index;
int A[6] = { 10, 20, 30, 1, 2, 3 };
index = index_of_maximal(A, 6);
cout << "index : " << index << endl;

double B[7] = { 3.3, 1.2, 0.5, 2.2, 4.5, 1.7 };
index = index_of_maximal(B, 7);
cout << "index : " << index << endl;

char C[10] = { 'h', 'a', 'q', 'n', 'c', 'o', 'p', 'z', 's', 'j' };
index = index_of_maximal(C, 10);
cout << "index : " << index << endl;
return 0;
}