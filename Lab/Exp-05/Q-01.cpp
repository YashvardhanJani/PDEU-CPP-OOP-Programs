#include <iostream>
using namespace std;

class Complex {
private:
    double real; 
    double imag;  

public:
    Complex(double r, double i) {
        real = r;
        imag = i;
    }

    // Overload + operator as a member function
    Complex operator+(const Complex& other) const {
        double newReal = real + other.real;
        double newImag = imag + other.imag;
        return Complex(newReal, newImag);
    }

    void displayComplex() const {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main() {
    double r1, i1, r2, i2;

    cout << "Enter first complex number (real and imaginary part): ";
    cin >> r1 >> i1;

    cout << "Enter second complex number (real and imaginary part): ";
    cin >> r2 >> i2;

    Complex c1(r1, i1);
    Complex c2(r2, i2);

    // Add two complex numbers using overloaded +
    Complex c3 = c1 + c2;

    cout << "Sum: ";
    c3.displayComplex();

    return 0;
}