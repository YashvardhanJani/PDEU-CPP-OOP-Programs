#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Structure to represent a term of the polynomial
struct Term {
    int coeff;
    int exp;
};

// Class to represent a polynomial
class Polynomial {
private:
    vector<Term> terms;

public:
    // Input polynomial terms
    void inputTerms() {
        int n;
        cout << "Enter number of terms in polynomial: ";
        cin >> n;

        for (int i = 0; i < n; i++) {
            Term t;
            cout << "Enter coefficient and exponent for term " << i + 1 << ": ";
            cin >> t.coeff >> t.exp;
            terms.push_back(t);
        }
    }

    // Display polynomial
    void display() {
        for (size_t i = 0; i < terms.size(); i++) {
            cout << terms[i].coeff << "x^" << terms[i].exp;
            if (i != terms.size() - 1)
                cout << " + ";
        }
        cout << endl;
    }

    // Add two polynomials
    Polynomial add(Polynomial p2) {
        Polynomial result;
        bool matched[100] = {false};

        // Add terms with same exponents
        for (auto &t1 : terms) {
            bool found = false;
            for (size_t j = 0; j < p2.terms.size(); j++) {
                if (t1.exp == p2.terms[j].exp) {
                    Term t;
                    t.exp = t1.exp;
                    t.coeff = t1.coeff + p2.terms[j].coeff;
                    result.terms.push_back(t);
                    matched[j] = true;
                    found = true;
                    break;
                }
            }
            if (!found) {
                result.terms.push_back(t1);
            }
        }

        // Add remaining unmatched terms from p2
        for (size_t j = 0; j < p2.terms.size(); j++) {
            if (!matched[j])
                result.terms.push_back(p2.terms[j]);
        }

        return result;
    }

    // Evaluate polynomial at given x
    double evaluate(double x) {
        double sum = 0;
        for (auto &t : terms) {
            sum += t.coeff * pow(x, t.exp);
        }
        return sum;
    }
};

// Main function
int main() {
    Polynomial p1, p2, sum;
    double x;

    cout << "Enter details for Polynomial 1:\n";
    p1.inputTerms();

    cout << "\nEnter details for Polynomial 2:\n";
    p2.inputTerms();

    cout << "\nPolynomial 1: ";
    p1.display();

    cout << "Polynomial 2: ";
    p2.display();

    sum = p1.add(p2);

    cout << "\nSum of Polynomials: ";
    sum.display();

    cout << "\nEnter value of x for evaluation: ";
    cin >> x;

    cout << "Evaluation of Sum at x = " << x << " : " << sum.evaluate(x) << endl;

    return 0;
}