#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

// Breadth-First Search function to find the minimum steps in the maze
int BFS(vector<vector<int>>& maze) {
    // Get the number of rows and columns in the maze
    int rows = maze.size();
    int cols = maze[0].size();

    // Define directions (right, down, left, up)
    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    // Initialize a queue for BFS and start from the top-left corner
    queue<pair<int, int>> q;
    q.push({0, 0});

    // Initialize a 2D boolean array to mark visited cells
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    visited[0][0] = true;

    // Perform BFS
    while (!q.empty()) {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        // Explore neighboring cells in all four directions
        for (const auto& d : directions) {
            int newRow = row + d.first;
            int newCol = col + d.second;

            // Check if the new cell is within bounds, is passable, and hasn't been visited
            if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && maze[newRow][newCol] == 1 && !visited[newRow][newCol]) {
                // Enqueue the new cell, mark it as visited, and update the steps
                q.push({newRow, newCol});
                visited[newRow][newCol] = true;
                maze[newRow][newCol] = maze[row][col] + 1;
            }
        }
    }

    // Return the minimum steps required to reach the destination
    return maze[rows - 1][cols - 1];
}

int main() {
    // Get the input filename from the user
    string filename;
    cout << "Enter filename: ";
    cin >> filename;

    // Open the input file
    ifstream infile(filename);

    // Read the number of rows and columns from the file
    int rows, cols;
    infile >> rows >> cols;

    // Initialize the maze with larger values for unvisited cells
    vector<vector<int>> maze(rows, vector<int>(cols, INT_MAX));

    // Read the maze configuration from the file
    for (int i = 0; i < rows; ++i) {
        string row;
        infile >> row;
        for (int j = 0; j < cols; ++j) {
            // Convert the character representation to an integer (0 or 1)
            maze[i][j] = row[j] - '0';
        }
    }

    // Close the file
    infile.close();

    // Find and output the minimum steps using BFS
    int result = BFS(maze);
    cout << result << endl;

    // Return 0 to indicate successful execution
    return 0;
}
