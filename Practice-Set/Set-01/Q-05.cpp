// Print a diamond shape using user specified character.

#include <iostream>
using namespace std;

int main() {
    char ch;
    int n;

    cout << "Enter a character: ";
    cin >> ch;
    cout << "Enter the number of rows for half of the diamond: ";
    cin >> n;

    // Upper part of the diamond
    for (int i = 1; i <= n; i++) {
        for (int j = i; j < n; j++) {
            cout << " ";
        }
        for (int j = 1; j <= (2 * i - 1); j++) {
            cout << ch;
        }
        cout << endl;
    }

    // Lower part of the diamond
    for (int i = n - 1; i >= 1; i--) {
        for (int j = n; j > i; j--) {
            cout << " ";
        }
        for (int j = 1; j <= (2 * i - 1); j++) {
            cout << ch;
        }
        cout << endl;
    }

    return 0;
}