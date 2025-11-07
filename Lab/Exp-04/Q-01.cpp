#include <iostream>
using namespace std;

class Rectangle {
private:
    double length;
    double width;

public:
    Rectangle(double l, double w) {
        length = l;
        width = w;
    }

    double calculateArea() {
        return length * width;
    }

    void displayDimensions() {
        cout << "Length: " << length << ", Width: " << width << endl;
    }
};

int main() {
    float l, w;
    cout << "Rectangle dimensions: " ;
    cin >> l >> w;

    Rectangle r1(l, w);

    cout << "\nRectangle:\n";
    r1.displayDimensions();
    cout << "Area of Rectangle: " << r1.calculateArea() << endl;

    return 0;
}