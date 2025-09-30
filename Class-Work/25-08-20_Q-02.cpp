// Create two classes Point & Line, Point store coordinate x,y and line is define by 2 points write a friend function to get length with one argument line that calculate line using distance formula.

#include <bits/stdc++.h>
using namespace std;

class Line;  // Forward declaration

class Point {
private:
    int x, y;

public:
    Point(int x = 0, int y = 0) {
        this->x = x;
        this->y = y;
    }

    // Declare friend function
    friend double getLength(Line line_1);
};

class Line {
private:
    Point p1, p2;

public:
    Line(Point p1, Point p2) {
        this->p1 = p1;
        this->p2 = p2;
    }

    // Declare friend function
    friend double getLength(Line line_1);
};

// Friend function definition
double getLength(Line line_1) {
    return sqrt(pow(line_1.p2.x - line_1.p1.x, 2) + pow(line_1.p2.y - line_1.p1.y, 2));
}

int main() {
    int x1, y1, x2, y2;
    cout << "Enter coordinates of first point (x1 y1): ";
    cin >> x1 >> y1;
    cout << "Enter coordinates of second point (x2 y2): ";
    cin >> x2 >> y2;

    Point p1(x1, y1), p2(x2, y2);
    Line l1(p1, p2);

    cout << "Length of Line: " << getLength(l1) << endl;

    return 0;
}