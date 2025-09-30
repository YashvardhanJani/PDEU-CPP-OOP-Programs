// Write a C++ program to demonstrate runtime polymorphism using a Shape class hierarchy.

#include <iostream>
#define _USE_MATH_DEFINES  // To overcome error in M_PI
#include <cmath>
#include <vector>
#include <iomanip>
using namespace std;

class Shape {
public:    
    virtual void displayInfo() const = 0;   // pure virtual function
    virtual double calculateArea() const = 0;   // pure virtual function
    virtual ~Shape() {}  // virtual destructor
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    void displayInfo() const override {
        cout << "This is a circle with radius " << radius << endl;
    }

    double calculateArea() const override {
        return M_PI * radius * radius;
    }

    ~Circle(){
        cout << "Destructor for Circle called." << endl;
    }
};

class Rectangle : public Shape {
private:
    double length;
    double width;    

public:    
    Rectangle(double l, double b) : length(l), width(b) {}

    void displayInfo() const override {
        cout << "This is a rectangle with length " << length 
             << " and width " << width << endl;
    }

    double calculateArea() const override {
        return length * width;
    }

    ~Rectangle() {
        cout << "Destructor for Rectangle called." << endl;
    }
};

int main()
{
    Shape* circle1 = new Circle(5.0);
    Shape* rect1 = new Rectangle(10.0, 4.0);

    vector<Shape*> shapes;
    shapes.push_back(circle1);
    shapes.push_back(rect1);

    // Loop through vector and use polymorphism
    cout << fixed << setprecision(2); // Format output to 2 decimal places
    for (Shape* shape : shapes) {
        shape->displayInfo();
        cout << "Area = " << shape->calculateArea() << endl << endl;
    }

    // Delete allocated memory
    for (Shape* shape : shapes) {
        delete shape;
    }
    shapes.clear();

    return 0;
}