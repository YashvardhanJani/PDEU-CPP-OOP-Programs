// Write a Program to Calculate the Lowest Common Multiple (LCM) of Two Numbers (use UDF)

#include<iostream>
using namespace std;    

int findLCM(int a, int b) {
    int lcm = (a > b) ? a : b; // Start with the larger of the two numbers
    while (true) {
        if (lcm % a == 0 && lcm % b == 0) {
            break; // Found the LCM
        }
        lcm++; // Increment lcm until we find a common multiple
    }
    return lcm;
}

int main() {
    int a, b;
    cout << "Enter the two numbers: ";
    cin >> a >> b;

    int lcm = findLCM(a, b);
    cout << "LCM of " << a << " & " << b << " is: " << lcm << endl;

    return 0;
}