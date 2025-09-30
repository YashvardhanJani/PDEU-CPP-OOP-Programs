// Write a Program to Check for the Equality of Two Numbers Without Using Arithmetic or Comparison Operator.

#include <iostream>
using namespace std;    

int main() {
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;

    // Using bitwise XOR to check for equality
    if ((a ^ b) == 0) {
        cout << "The numbers are equal." << endl;
    } else {
        cout << "The numbers are not equal." << endl;
    }

    return 0;
}