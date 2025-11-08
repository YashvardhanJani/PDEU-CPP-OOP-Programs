#include <iostream>
#include <stdexcept>
#include <algorithm>
using namespace std;

// Forward declaration for friend functions
class Fraction;

// Standalone GCD helper function
int gcd(int a, int b) {
    a = abs(a);
    b = abs(b);
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Fraction Class Definition
class Fraction {
private:
    int numerator;
    int denominator;

    // Private helper method to simplify the fraction
    void simplify() {
        // Handle zero numerator
        if (numerator == 0) {
            denominator = 1;
            return;
        }

        // Calculate GCD and simplify
        int g = gcd(numerator, denominator);
        numerator /= g;
        denominator /= g;
    }

public:
    // Parameterized Constructor
    Fraction(int num, int den) : numerator(num), denominator(den) {
        if (denominator == 0) {
            cerr << "Error: Denominator cannot be zero. Setting denominator to 1." << endl;
            numerator = 0;
            denominator = 1;
        }
        simplify();
    }

    // Default Constructor
    Fraction() : numerator(0), denominator(1) {}

    // Getter methods
    int getNumerator() const {
        return numerator;
    }

    int getDenominator() const {
        return denominator;
    }

    // Display method
    void displayFraction() const {
        if (denominator == 1) {
            cout << numerator;
        } else {
            cout << numerator << "/" << denominator;
        }
    }

    // Operator overloading - Addition
    Fraction operator+(const Fraction& other) const {
        int num = (this->numerator * other.denominator) + 
                  (other.numerator * this->denominator);
        int den = this->denominator * other.denominator;
        return Fraction(num, den);
    }

    // Operator overloading - Subtraction
    Fraction operator-(const Fraction& other) const {
        int num = (this->numerator * other.denominator) - 
                  (other.numerator * this->denominator);
        int den = this->denominator * other.denominator;
        return Fraction(num, den);
    }

    // Operator overloading - Multiplication
    Fraction operator*(const Fraction& other) const {
        int num = this->numerator * other.numerator;
        int den = this->denominator * other.denominator;
        return Fraction(num, den);
    }

    // Operator overloading - Division
    Fraction operator/(const Fraction& other) const {
        if (other.numerator == 0) {
            cerr << "Error: Division by zero. Second operand's numerator is zero." << endl;
            return Fraction(0, 1);
        }
        int num = this->numerator * other.denominator;
        int den = this->denominator * other.numerator;
        return Fraction(num, den);
    }

    // Equality operator for testing
    bool operator==(const Fraction& other) const {
        return (this->numerator == other.numerator) && 
               (this->denominator == other.denominator);
    }

    // Display operator (friend function for cleaner output)
    friend ostream& operator<<(ostream& os, const Fraction& f) {
        if (f.denominator == 1) {
            os << f.numerator;
        } else {
            os << f.numerator << "/" << f.denominator;
        }
        return os;
    }
};

int main() {
    Fraction f1(1, 2);
    Fraction f2(3, 4);
    Fraction f3(2, 4);  // Should simplify to 1/2

    cout << "Fraction 1: " << f1 << endl;
    cout << "Fraction 2: " << f2 << endl;
    cout << "Fraction 3 (2/4 simplifies to): " << f3 << endl;
    
    Fraction f4(5, 0);  // Should show error and set denominator to 1
    cout << "Fraction 4 (5/0 handled): " << f4 << endl << endl;

    // Addition
    Fraction add1 = f1 + f2;  // 1/2 + 3/4 = 5/4
    cout << "Addition (" << f1 << " + " << f2 << ") = " << add1 << endl;

    // Subtraction
    Fraction sub1 = f2 - f1;  // 3/4 - 1/2 = 1/4
    cout << "Subtraction (" << f2 << " - " << f1 << ") = " << sub1 << endl;

    // Multiplication
    Fraction mul1 = f1 * f2;  // 1/2 * 3/4 = 3/8
    cout << "Multiplication (" << f1 << " * " << f2 << ") = " << mul1 << endl;

    // Division
    Fraction div1 = f2 / f1;  // 3/4 ÷ 1/2 = 3/2
    cout << "Division (" << f2 << " / " << f1 << ") = " << div1 << endl;

    return 0;
}