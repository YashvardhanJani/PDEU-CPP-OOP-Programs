/*
Constructor Deligation C++11 onwards
To avoid code duplication and improve code maintenance, concept of constructor delegation was introduced  c++11 onwards.
 
Try the constructor delegation through this sample code:
Note: The code also demonstrates how to document your source code by adding appropriate comments.
*/ 
 
#include <iostream>
using namespace std;

class Point {
private:
    int x;
    int y;
        
public:
    // Primary constructor
    Point(int x_coord, int y_coord) : x(x_coord), y(y_coord) {
        // Additional initialization logic if needed
    }
 
    // Delegating constructor for a point on the x-axis
    Point(int x_coord) : Point(x_coord, 0) {
        // No additional logic needed here, as delegation handles it
    }

    // Delegating constructor for a point on the y-axis
    Point(double y_coord) : Point(0, static_cast<int>(y_coord)) {
        // Explicit cast just for clarity
    }
 
    // Delegating constructor for the origin
    Point() : Point(0, 0) {
        //No additional logic needed here
    }
 
    void print() const {
        cout << "Point(" << x << ", " << y << ")" << endl;
    }
};
 
int main() {
    Point p1(5, 10); // Uses the primary constructor
    Point p2(7);     // Uses the delegating constructor (7, 0)
    Point p3(9.0);   // Uses the delegating constructor (0, 9)
    Point p4;        // Uses the delegating constructor (0, 0)

    p1.print();
    p2.print();
    p3.print();
    p4.print();

    return 0;
}

/*
:: Here, you have two constructors with a single parameter:
Point(int x_coord) → (x, 0)
Point(double y_coord) → (0, y)
=> But if you pass something like Point(9), the compiler prefers the int version (so you get (9, 0) instead of (0, 9)).
=> To force (0, y), you must pass a floating-point literal like 9.0 or static_cast<double>(9).
*/