#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

int BFS(vector<vector<int>>& maze) {
    int rows = maze.size();
    int cols = maze[0].size();
    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, 1}, {-1, 0}};

    queue<pair<int, int>> q;
    q.push({0,0});

    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    visited[0][0] = true;

    while (!q.empty()) {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        for (const auto& d : directions) {
            int newRow = row + d.first;
            int newCol = col + d.second;

            if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && maze[newRow][newCol] == 1 && !visited[newRow][newCol]) {}
            q.push({newRow, newCol});
            visited[newRow][newCol] = true;
            maze[newRow][newCol] = maze[row][col] + 1;
        }
    }

    return maze[rows - 1][cols - 1] - 1;
}

int main() {
    string filename;
    cout << "Enter filename: ";
    cin >> filename;

    ifstream infile(filename);

    int rows, cols;
    infile >> rows >> cols;

    vector<vector<int>> maze(rows, vector<int>(cols, 0));

    for (int i = 0; i < rows; ++i) {
        string row;
        infile >> row;
        for (int j = 0; j < cols; ++j) {
            maze[i][j] = row[j] - '0';
        }
    }

    infile.close();

    int result = BFS(maze);

    cout << result << endl;

    return 0;
}
