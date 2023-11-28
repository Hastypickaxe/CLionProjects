#include <iostream>
using namespace std;

const int N = 20; // array size

// Time complexity: O(log N), where N is the size of the array

int binarySearchFirst(int A[], int low, int high, int x) {
    int result = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (A[mid] == x) {
            result = mid;
            high = mid - 1;
        } else if (A[mid] < x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return result;
}

int binarySearchLast(int A[], int low, int high, int x) {
    int result = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (A[mid] == x) {
            result = mid;
            low = mid + 1;
        } else if (A[mid] < x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return result;
}

int test2(int A[], int x) {
    int firstOccurrence = binarySearchFirst(A, 0, N - 1, x);
    if (firstOccurrence == -1) {
        return 0; // Element not found
    }

    int lastOccurrence = binarySearchLast(A, 0, N - 1, x);
    return lastOccurrence - firstOccurrence + 1;
}

int main() {
    int A[N] = {1, 1, 1, 3, 3, 3, 3, 3, 4, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 7};

    int answer = test2(A, 3);
    if (answer > 0) cout << "3 appears " << answer << " times in A" << endl;
    else cout << "3 does not appear in A" << endl;

    answer = test2(A, 6);
    if (answer > 0) cout << "6 appears " << answer << " times in A" << endl;
    else cout << "6 does not appear in A" << endl;

    answer = test2(A, 2);
    if (answer > 0) cout << answer << '\n';
    else cout << "2 does not appear in A" << endl;

    return 0;
}
