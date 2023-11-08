#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void heapify(vector<int>& arr, int n, int i) {
    int large = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[large]) {
        large = left;
    }

    if (right < n && arr[right] > arr[large]) {
        large = right;
    }

    if (large != i) {
        swap(arr[i], arr[large]);
        heapify(arr, n, large);
    }
}

void buildHeap(vector<int>& arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; --i) {
        heapify(arr, n, i);
    }
}

bool isHeap(const vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i <= (n - 2) / 2; ++i) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (arr[i] < arr[left]) {
            return false;
        }

        if (right < n && arr[i] < arr[right]) {
            return false;
        }
    }

    return true;
}

int main() {
    ifstream infile("data.txt");
    if (!infile) {
        cout << "File failed to open";
        return 1;
    }

    int n;
    while (infile >> n) {
        vector<int> arr;
        while (infile >> n) {
            arr.push_back(n);
        }

        cout << "Original heap: ";
        for (int i : arr) {
            cout << i << " ";
        }
        cout << endl;

        if (isHeap(arr)) {
            cout << "Max heap" << endl;
        } else {
            cout << "Not a heap. Applying Heapify algorithm" << endl;
            buildHeap(arr);
            cout << "New heap: ";
            for (int i : arr) {
                cout << i << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    infile.close();
    return 0;
}
