// Write a C++ program to perform addition and multiplication of Two Matrices.

#include <iostream>
#include <vector>
using namespace std;

// Function to input a matrix
vector<vector<int>> inputMatrix(int &rows, int &cols, int seq) {
    cout << "Enter rows and columns for matrix " << seq << ": ";
    cin >> rows >> cols;

    vector<vector<int>> matrix(rows, vector<int>(cols));
    cout << "Enter elements of matrix " << seq << ":\n";
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            cin >> matrix[i][j];

    return matrix;
}

// Function to print a matrix
void printMatrix(const vector<vector<int>> &matrix) {
    for (auto &row : matrix) {
        for (int val : row)
            cout << val << " ";
        cout << "\n";
    }
}

// Function to add matrices
vector<vector<int>> addMatrices(const vector<vector<int>> &A, const vector<vector<int>> &B) {
    int rows = A.size(), cols = A[0].size();
    vector<vector<int>> result(rows, vector<int>(cols));
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            result[i][j] = A[i][j] + B[i][j];
    return result;
}

// Function to multiply matrices
vector<vector<int>> multiplyMatrices(const vector<vector<int>> &A, const vector<vector<int>> &B) {
    int r1 = A.size(), c1 = A[0].size(), c2 = B[0].size();
    vector<vector<int>> result(r1, vector<int>(c2, 0));

    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c2; j++)
            for (int k = 0; k < c1; k++)
                result[i][j] += A[i][k] * B[k][j];

    return result;
}

int main() {
    int r1, c1, r2, c2;

    // Input matrices
    auto A = inputMatrix(r1, c1, 1);
    auto B = inputMatrix(r2, c2, 2);

    // Matrix Addition
    if (r1 == r2 && c1 == c2) {
        cout << "\nMatrix Addition:\n";
        auto sum = addMatrices(A, B);
        printMatrix(sum);
    } else {
        cout << "\nAddition not possible (dimensions do not match).\n";
    }

    // Matrix Multiplication
    if (c1 == r2) {
        cout << "\nMatrix Multiplication:\n";
        auto product = multiplyMatrices(A, B);
        printMatrix(product);
    } else {
        cout << "\nMultiplication not possible (columns of first != rows of second).\n";
    }

    return 0;
}