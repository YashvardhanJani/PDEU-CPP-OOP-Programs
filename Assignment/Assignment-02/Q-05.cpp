/*

Given an array arr[] of size n, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum. Implement Kadane’s algo for the same.

Kadane’s Algorithm is a famous and efficient algorithm used to solve the problem of finding the maximum sum subarray in a 1D array of integers, especially when the array contains both positive and negative numbers.
•	Traverse the array while keeping track of:
o	max_current: Maximum sum ending at current position
o	max_global: Maximum sum found so far
If at any point max_current becomes less than 0, reset it to 0 (or the current element, if implemented that way).

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int kadaneMaxSubarraySum(vector<int>& arr, int& start, int& end) {
    int max_current = arr[0];
    int max_global = arr[0];
    start = end = 0;
    int temp_start = 0;
 
    // Traverse the array starting from the second element
    for (int i = 1; i < arr.size(); ++i) {
        if (arr[i] > max_current + arr[i]) {
            max_current = arr[i];
            temp_start = i;
        } else {
            max_current += arr[i];
        }

        // Update max_global if we found a new maximum
        if (max_current > max_global) {
            max_global = max_current;
            start = temp_start;
            end = i;
        }
    }

    return max_global;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    // input array of size n
    vector<int> arr(n);
    cout << "Enter " << n << " elements (positive or negative): ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int start, end;
    int max_sum = kadaneMaxSubarraySum(arr, start, end);

    cout << "\nMaximum Subarray Sum: " << max_sum << endl;

    // print the subarray
    cout << "Subarray: ";
    for (int i = start; i <= end; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}