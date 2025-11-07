// Simulate Collatz Conjecture for 1 to N and find the number with longest steps in C++.

#include <iostream>
using namespace std;

// Function to count steps for a given number in Collatz sequence
int collatzSteps(long long n) {
    int steps = 0;
    while (n != 1) {
        if (n % 2 == 0)
            n = n / 2;
        else
            n = 3 * n + 1;
        steps++;
    }
    return steps;
}

int main() {
    int N;
    cout << "Enter N: ";
    cin >> N;

    int maxSteps = 0;
    int numberWithMaxSteps = 1;

    for (int i = 1; i <= N; i++) {
        int steps = collatzSteps(i);
        if (steps > maxSteps) {
            maxSteps = steps;
            numberWithMaxSteps = i;
        }
        cout << "Number " << i << " : " << steps << " steps" << endl;
    }

    cout << "\nNumber with longest Collatz sequence between 1 and " << N << " is " << numberWithMaxSteps << endl;
    cout << "It takes " << maxSteps << " steps to reach 1." << endl;

    return 0;
}