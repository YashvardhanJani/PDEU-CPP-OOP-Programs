/* # Theory:
-> Test-Driven Development (TDD) is a software development approach where tests are written
before the actual implementation code.
-> The development process follows the Red → Green → Refactor cycle:
1. Red: Write a failing test (since the implementation doesn’t exist yet).
2. Green: Write the minimum code required to make the test pass.
3. Refactor: Improve the code quality while ensuring all tests still pass. */

#include <iostream>
#include <cassert>
using namespace std;

// // RED: No implementation yet
// bool isEven(int n); // Only declaration

// // GREEN: Make Test Pass
// bool isEven(int n) return n % 2 == 0;

// REFACTOR: Done Improvements
bool isEven(int n) {
    return n % 2 == 0;
}

void runTests() {
    assert(isEven(4) == true);
    assert(isEven(3) == false);
    assert(isEven(0) == true);
    assert(isEven(-2) == true);
    assert(isEven(-7) == false);
}

int main() {

    // // RED: No implementation yet
    // cout << "--- TDD Step 1: RED (Failing Test) ---" << endl;
    // assert(isEven(4) == true);  // Expected to fail (no implementation yet)
    // cout << "Test Passed!" << endl;

    // // GREEN: Make Test Pass
    // cout << "--- TDD Step 2: GREEN (Test Passing) ---" << endl;
    // assert(isEven(4) == true);  // Should now pass
    // cout << "Test Passed: isEven(4) == true" << endl;

    // REFACTOR: Done Improvements
    cout << "--- Running isEven() TDD Tests ---" << endl;
    runTests();
    cout << "All test cases passed successfully!" << endl;

    return 0;
}