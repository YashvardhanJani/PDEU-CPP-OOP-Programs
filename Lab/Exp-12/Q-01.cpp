#include <iostream>
#include <string>
#include <cassert>
using namespace std;

bool isEven(int number) {
    return (number % 2 == 0);
}

void TEST(const string& testName, bool expected, bool actual, int& passCount, int& failCount) {
    if (expected == actual) {
        cout << "[PASS] " << testName << endl;
        passCount++;
    } else {
        cout << "[FAIL] " << testName << " (Expected: " << expected << ", Got: " << actual << ")" << endl;
        failCount++;
    }
}

int main() {
    cout << "--- Running isEven() Unit Tests ---" << endl;

    int passCount = 0, failCount = 0;

    TEST("isEven(4)", true, isEven(4), passCount, failCount);
    TEST("isEven(7)", false, isEven(7), passCount, failCount);
    TEST("isEven(0)", true, isEven(0), passCount, failCount);
    TEST("isEven(-6)", true, isEven(-6), passCount, failCount);
    TEST("isEven(-3)", false, isEven(-3), passCount, failCount);
    TEST("isEven(1000000)", true, isEven(1000000), passCount, failCount);
    TEST("isEven(999999)", false, isEven(999999), passCount, failCount);

    cout << "\n--- isEven() Test Summary ---" << endl;
    cout << "Passed: " << passCount << endl;
    cout << "Failed: " << failCount << endl;

    return 0;
}