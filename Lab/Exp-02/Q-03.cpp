#include <iostream>
#include <vector>
using namespace std;

int main() {
    int rowsA, colsA, rowsB, colsB, rowsC, colsC;

    // Input for Matrix A
    cout << "Enter dimensions for Matrix A (rows columns): ";
    cin >> rowsA >> colsA;
    vector<vector<int>> A(rowsA, vector<int>(colsA));

    cout << "Enter elements for Matrix A (" << rowsA << "x" << colsA << "):\n";
    for (int i = 0; i < rowsA; i++)
        for (int j = 0; j < colsA; j++)
            cin >> A[i][j];

    // Input for Matrix B
    cout << "Enter dimensions for Matrix B (rows columns): ";
    cin >> rowsB >> colsB;
    vector<vector<int>> B(rowsB, vector<int>(colsB));

    cout << "Enter elements for Matrix B (" << rowsB << "x" << colsB << "):\n";
    for (int i = 0; i < rowsB; i++)
        for (int j = 0; j < colsB; j++)
            cin >> B[i][j];

    // Matrix Addition
    cout << "\nMatrix Addition (A + B):\n";
    if (rowsA == rowsB && colsA == colsB) {
        vector<vector<int>> add(rowsA, vector<int>(colsA));
        for (int i = 0; i < rowsA; i++) {
            for (int j = 0; j < colsA; j++) {
                add[i][j] = A[i][j] + B[i][j];
                cout << add[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "Matrix addition not possible (Dimension mismatch)\n";
    }

    // Input for Matrix C
    cout << "\nEnter dimensions for Matrix C (rows columns): ";
    cin >> rowsC >> colsC;
    vector<vector<int>> C(rowsC, vector<int>(colsC));

    cout << "Enter elements for Matrix C (" << rowsC << "x" << colsC << "):\n";
    for (int i = 0; i < rowsC; i++)
        for (int j = 0; j < colsC; j++)
            cin >> C[i][j];

    // Matrix Multiplication
    cout << "\nMatrix Multiplication (A * C):\n";
    if (colsA == rowsC) {
        vector<vector<int>> mult(rowsA, vector<int>(colsC, 0));
        for (int i = 0; i < rowsA; i++) {
            for (int j = 0; j < colsC; j++) {
                for (int k = 0; k < colsA; k++) {
                    mult[i][j] += A[i][k] * C[k][j];
                }
                cout << mult[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "Matrix multiplication not possible (Dimension mismatch)\n";
    }

    return 0;
}