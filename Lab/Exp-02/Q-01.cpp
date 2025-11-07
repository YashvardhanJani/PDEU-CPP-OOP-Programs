#include <iostream>
using namespace std;

// Recursive function to compute factorial
int factorial(int n) {
    if (n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}

// Recursive function to check prime
bool isPrime(int n, int i = 2) {
    if (n <= 2)
        return (n == 2) ? true : false;
    if (n % i == 0)
        return false;
    if (i * i > n) // optimization: stop at sqrt(n)
        return true;
    return isPrime(n, i + 1);
}

int main() {
    int factNum, primeNum;

    cout << "Factorial of: ";
    cin >> factNum;

    cout << "Check prime for: ";
    cin >> primeNum;

    cout << "Factorial of " << factNum << " is: " << factorial(factNum) << endl;

    if (isPrime(primeNum))
        cout << primeNum << " is a prime number." << endl;
    else
        cout << primeNum << " is not a prime number." << endl;

    return 0;
}