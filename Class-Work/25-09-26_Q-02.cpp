//Input no. of testcases from User. Take 2 doubles a and b, perform a/b and print result. If Result is zero or negetive then throw exception and print "Result is zero or negative". If b = 0, the program should throw exception and print "Cannot divide by zero!".

#include <iostream>
#include <stdexcept>
using namespace std;

int main()
{
    int t;

    cout << "Enter number of Testcases: ";
    cin >> t;

    while(t) {
        double a, b;

        try {
            cout << "Enter two integers (a and b): ";
            cin >> a >> b; 

            if (a <= 0 || b < 0) {
            throw "Result is zero or negative!";
            }

            if (b == 0) {
                throw "Cannot divide by zero!";
            }

            double result = a/b;
            cout << "Result: " << result << endl;
            
        }

        catch(const char* e) {
            cout << e << endl;
        }
        
        t--;
    }
    
    return 0;
}