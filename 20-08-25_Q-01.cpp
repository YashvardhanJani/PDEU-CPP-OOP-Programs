// Create two classes rectangle & circle. Each class should store its dimentions as private member. Write a friend function to compare the area of both.

#include <bits/stdc++.h>
using namespace std;

class Rectangle;
// Note: This early declaration is mandatory bcz we declare friend function inside Circle class and pass Rectange class into it.

class Circle {
private:
    float radius;

public:
    Circle(float r) {
        radius = r;
    }

    // Declare friend function
    friend void compareArea(Circle, Rectangle);
};

class Rectangle {
private:
    float length, breadth;

public:
    Rectangle(float l, float b) {
        length = l;
        breadth = b;
    }

    // Declare friend function
    friend void compareArea(Circle, Rectangle);
};

// Friend function definition
void compareArea(Circle c, Rectangle r) {
    float areaCircle = 3.14 * c.radius * c.radius;
    float areaRect   = r.length * r.breadth;

    cout << "Area of Circle: " << areaCircle << endl;
    cout << "Area of Rectangle: " << areaRect << endl;

    if (areaCircle > areaRect) {
        cout << "\nCircle has larger area." << endl;
    } else if (areaCircle < areaRect) {
        cout << "\nRectangle has larger area." << endl;
    } else {
        cout << "\nBoth have equal area." << endl;
    }
}

int main()
{
    float r, l, b;

    cout << "Enter the value of radius(for Circle): ";
    cin >> r;
    cout << "Enter the value of length & breadth(for Rectangle): ";
    cin >> l >> b;

    Circle c1(r);
    Rectangle r1(l,b);

    compareArea(c1, r1);

    return 0;
}