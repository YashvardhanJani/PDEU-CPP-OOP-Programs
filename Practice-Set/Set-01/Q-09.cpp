// [Star-Problem]
// Given an n x n matrix of digits (0–9), find the number of unique paths from top-left to bottom-right, such that the sum of digits on the path is divisible by 7. You can only move right or down.

#include <iostream>
#include <vector>
using namespace std;

int n;

// Function to collect and print paths
void findPaths(const vector<vector<int>>& grid, int row, int col, int sum, vector<int>& path, int& count) {
    // Add current cell to path
    path.push_back(grid[row][col]);
    sum += grid[row][col];

    // If we reached bottom-right
    if (row == n - 1 && col == n - 1) {
        if (sum % 7 == 0) {
            count++;
            cout << "Path " << count << ": ";
            for (int x : path) cout << x << " ";
            cout << "(Sum = " << sum << ")" << endl;
        }
    } else {
        // Move right
        if (col + 1 < n) {
            findPaths(grid, row, col + 1, sum, path, count);
        }
        // Move down
        if (row + 1 < n) {
            findPaths(grid, row + 1, col, sum, path, count);
        }
    }

    // Backtrack
    path.pop_back();
}

int main() {
    cout << "Enter the size (n) of the matrix (n x n): ";
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));
    cout << "Enter the elements of the matrix (0-9):" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    vector<int> path;
    int count = 0;
    findPaths(grid, 0, 0, 0, path, count);

    cout << "Total number of valid paths: " << count << endl;
    return 0;
}