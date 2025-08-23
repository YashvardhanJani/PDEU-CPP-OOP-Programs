// Write a program to print hourglass pattern using asterix symbol

#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of rows (half height of hourglass): ";
    cin >> n;

    // Top half of hourglass
    for (int i = 0; i < n; i++) {
        // Print leading spaces
        for (int space = 0; space < i; space++) {
            cout << " ";
        }
        // Print stars
        for (int star = 0; star < 2 * (n - i) - 1; star++) {
            cout << "*";
        }
        cout << endl;
    }

    // Bottom half of hourglass
    for (int i = 2; i <= n; i++) {
        // Print leading spaces
        for (int space = 0; space < n - i; space++) {
            cout << " ";
        }
        // Print stars
        for (int star = 0; star < 2 * i - 1; star++) {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}