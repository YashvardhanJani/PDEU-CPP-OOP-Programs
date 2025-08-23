/*  [Star-Problem]
You are given an array of n integers. Find the number of non-empty subsets whose XOR sum is a prime number.
Constraints:
•	1 <= n <= 20 (2^20 subsets max)
•	1 <= a[i] <= 1000
Function signature
int countPrimeXORSubsets(const int arr[], const int n);	
*/

#include <iostream>
#include <vector>   
#include <cmath>
using namespace std;

bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

int countPrimeXORSubsets(const int arr[], const int n) {
    int count = 0;
    // Iterate over all possible subsets
    for (int i = 1; i < (1 << n); i++) {
        int xorSum = 0;
        for (int j = 0; j < n; j++) {
            // If j-th element is included in the subset
            if (i & (1 << j)) {
                xorSum ^= arr[j];
            }
        }
        // Check if the XOR sum is prime
        if (isPrime(xorSum)) {
            count++;
        }
    }
    return count;
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    int arr[20]; // Maximum size as per constraints
    cout << "Enter the elements of the array (1-1000):" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int result = countPrimeXORSubsets(arr, n);
    cout << "Number of non-empty subsets with prime XOR sum: " << result << endl;
    
    return 0;
}