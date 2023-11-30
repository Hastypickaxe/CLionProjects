#include <iostream>
#include <unordered_map>
#include <vector>
#include <fstream>

using namespace std;

// Function to check if all elements in a sub-matrix are the same
bool isSame(const vector<vector<int>>& matrix, int row, int col, int size) {
    int firstElement = matrix[row][col];

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (matrix[row + i][col + j] != firstElement) {
                return false;
            }
        }
    }

    return true;
}

// Recursive function to apply divide and conquer algorithm on the matrix
unordered_map<int, int> divideAndConquer(const vector<vector<int>>& matrix, int row, int col, int size) {
    unordered_map<int, int> count;

    // If the matrix size is 1 or all elements in the matrix are the same, count the element and return
    if (size == 1 || isSame(matrix, row, col, size)) {
        count[matrix[row][col]]++;
        return count;
    }

    // Divide the matrix into 3x3 sub-matrices
    int subSize = size / 3;

    // Iterate through each sub-matrix and recursively apply divide and conquer
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            auto subResult = divideAndConquer(matrix, row + i * subSize, col + j * subSize, subSize);
            // Accumulate the counts from each sub-matrix
            for (const auto& [key, value] : subResult) {
                count[key] += value;
            }
        }
    }

    return count;
}

// Function to read a matrix from a file and count the occurrences of each piece
void countPiece(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Failed to open file " << filename << endl;
        return;
    }

    // Read the size of the matrix from the file
    int size;
    file >> size;
    vector<vector<int>> matrix(size, vector<int>(size));

    // Populate the matrix from the file
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            file >> matrix[i][j];
        }
    }

    // Apply the divide and conquer algorithm and get the counts of each piece
    unordered_map<int, int> result = divideAndConquer(matrix, 0, 0, size);

    // Print the counts of each piece
    cout << "-1 : " << result[-1] << endl;
    cout << "0 : " << result[0] << endl;
    cout << "1 : " << result[1] << endl;
}

int main() {
    string filename;
    cout << "Enter filename: ";
    cin >> filename;
    countPiece(filename);

    return 0;
}
