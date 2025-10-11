#include <iostream>
#include <stdexcept>
using namespace std;

// Custom exception for division by zero
class DivideByZeroException : public runtime_error {
public:
    explicit DivideByZeroException(const char* message)
        : runtime_error(message) {}
};

// Function to perform the division and throw exception if denominator is zero
double divideNumbers(double numerator, double denominator) {
    if (denominator == 0.0)
        throw DivideByZeroException("Error: Division by zero is not allowed!");
    return numerator / denominator;
}

// Optimized function to perform division with exception handling and print results
void performDivision(double numerator, double denominator) {
    cout << "Attempting to divide " << numerator << " by " << denominator << endl;
    try {
        double result = divideNumbers(numerator, denominator);
        cout << "Result of division: " << result << endl;
    } catch (const DivideByZeroException& e) {
        cout << "Caught exception: " << e.what() << endl;
    } catch (const exception& e) {
        cout << "Exception: " << e.what() << endl;
    } catch (...) {
        cout << "Unknown exception caught." << endl;
    }
    cout << endl;
}

int main() {
    cout << "--- Test Case 1: Valid Division ---" << endl;
    performDivision(10.0, 2.0);

    cout << "--- Test Case 2: Division by Zero ---" << endl;
    performDivision(5.0, 0.0);

    return 0;
}
