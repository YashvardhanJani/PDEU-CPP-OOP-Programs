/*

WAP that serves as Suduku Validator
Function:
bool isValidSudoku(vector<vector<char>>& board);

Suduku validity rules:
•	Every row has digits 1–9 with no duplicates
•	Every column has digits 1–9 with no duplicates
•	Every 3×3 box has digits 1–9 with no duplicates

Valid Suduku example:
5 3 4 | 6 7 8 | 9 1 2
6 7 2 | 1 9 5 | 3 4 8
1 9 8 | 3 4 2 | 5 6 7
------+-------+------
8 5 9 | 7 6 1 | 4 2 3
4 2 6 | 8 5 3 | 7 9 1
7 1 3 | 9 2 4 | 8 5 6
------+-------+------
9 6 1 | 5 3 7 | 2 8 4
2 8 7 | 4 1 9 | 6 3 5
3 4 5 | 2 8 6 | 1 7 9

*/


#include <iostream>
#include <vector>
#include <set> // Using set for efficient duplicate checking

using namespace std;

// Function to validate a Sudoku board
bool isValidSudoku(vector<vector<char>>& board) {
    // Check rows
    for (int i = 0; i < 9; ++i) {
        set<char> row_seen;
        for (int j = 0; j < 9; ++j) {
            if (board[i][j] != '.') {
                if (row_seen.count(board[i][j])) {
                    return false; // Duplicate in row
                }
                row_seen.insert(board[i][j]);
            }
        }
    }

    // Check columns
    for (int j = 0; j < 9; ++j) {
        set<char> col_seen;
        for (int i = 0; i < 9; ++i) {
            if (board[i][j] != '.') {
                if (col_seen.count(board[i][j])) {
                    return false; // Duplicate in column
                }
                col_seen.insert(board[i][j]);
            }
        }
    }

    // Check 3x3 sub-boxes
    for (int block_row = 0; block_row < 3; ++block_row) {
        for (int block_col = 0; block_col < 3; ++block_col) {
            set<char> box_seen;
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    char current_char = board[block_row * 3 + i][block_col * 3 + j];
                    if (current_char != '.') {
                        if (box_seen.count(current_char)) {
                            return false; // Duplicate in sub-box
                        }
                        box_seen.insert(current_char);
                    }
                }
            }
        }
    }

    return true; // Board is valid
}

int main() {
    vector<vector<char>> board(9, vector<char>(9));

    cout << "Enter the Sudoku board (9 rows, 9 columns). Use '.' for empty cells:" << endl;
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cin >> board[i][j];
            // Basic input validation: ensure input is a digit or '.'
            if (!isdigit(board[i][j]) && board[i][j] != '.') {
                cerr << "Invalid input. Please enter digits (1-9) or '.' for empty cells." << endl;
                return 1; // Exit with error
            }
        }
    }

    if (isValidSudoku(board)) {
        cout << "The entered Sudoku board is valid." << endl;
    } else {
        cout << "The entered Sudoku board is NOT valid." << endl;
    }

    return 0;
}