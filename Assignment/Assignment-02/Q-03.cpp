/*
WAP to rotate a matrix 90 degree clockwise
Function:
void rotateMatrix90(vector<vector<int>>& mat);
Concept:
In place transpose and reverse rows
*/

#include <iostream>
#include <vector>
using namespace std;

// Function to input a matrix
void inputMatrix(int matrix[10][10], int &rows, int &cols)
{
    cout << "Enter rows and columns of Matrix: ";
    cin >> rows >> cols;
    cout << "Enter elements of Matrix A:\n";
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            cin >> matrix[i][j];
}

// Function to print a matrix
void printMatrix(int matrix[10][10], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}

// Function to transpose the matrix
void transposeMatrix(int matrix[10][10], int r1, int c1)
{
    for (int i = 0; i < r1; i++)
    {
        for (int j = i + 1; j < c1; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}

// Function to reverse the rows of the transposed matrix
void reverseRows(int matrix[10][10], int r1, int c1)
{
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1 / 2; j++)
        {
            swap(matrix[i][j], matrix[i][c1 - j - 1]);
        }
    }
}

int main()
{
    int A[10][10], B[10][10];
    int r1, c1;

    // Input the matrix
    inputMatrix(A, r1, c1);

    // Transpose the matrix
    transposeMatrix(A, r1, c1);

    // Reverse the rows of the transposed matrix
    reverseRows(A, r1, c1);

    cout << "\n90 degree clockwise rotated matrix:\n";
    printMatrix(A, r1, c1);

    return 0;
}