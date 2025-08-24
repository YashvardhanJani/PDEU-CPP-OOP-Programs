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
 
    // Delegating constructor for the origin
    Point() : Point(0, 0) {
        //No additional logic needed here
    }
 
    void print() const {
        cout << "Point(" << x << ", " << y << ")" << endl; // requires <iostream>
    }
};
 
int main(){

    Point p1(5, 10); // Uses the primary constructor
    Point p2(7);    // Uses the delegating constructor (x_coord, 0)
    Point p3;       // Uses the delegating constructor (0, 0)

    p1.print();
    p2.print();
    p3.print();

    return 0;
}