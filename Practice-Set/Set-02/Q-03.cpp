// [Star-Problem]
// Given 3 positives numbers a, b and c. Return the minimum flips required in some bits of a and b to make ( a OR b == c ). (bitwise OR operation). Flip operation consists of change any single bit 1 to 0 or change the bit 0 to 1 in their binary representation.

#include <iostream>
using namespace std;

int minFlips(int a, int b, int c) {
    int flips = 0;
    for (int i = 0; i < 32; i++) {  // check each bit
        int ai = (a >> i) & 1;
        int bi = (b >> i) & 1;
        int ci = (c >> i) & 1;

        if (ci == 1) {
            // At least one must be 1
            if ((ai | bi) == 0) flips += 1;
        } else {
            // ci == 0 → both must be 0
            if (ai == 1 && bi == 1) flips += 2;
            else if (ai == 1 || bi == 1) flips += 1;
        }
    }
    return flips;
}

int main() {
    int a, b, c;
    cout << "Enter a, b, c: ";
    cin >> a >> b >> c;

    cout << "Minimum flips required = " << minFlips(a, b, c) << endl;
    return 0;
}