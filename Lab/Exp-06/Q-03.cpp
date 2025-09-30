#include <iostream>
#include <string>
using namespace std;

class Animal {
public:
    // final method: cannot be overridden by subclasses
    virtual void makeSound() final {
        cout << "Animal makes a generic sound." << endl;
    }
    // Non-final virtual method
    virtual void eat() {
        cout << "Animal is eating." << endl;
    }
};

class Dog : public Animal {
public:
    // Attempt to override makeSound() results in compile-time error
    // Uncommenting the below code produces:
//    void makeSound() override { 
//        cout << "Dog barks." << endl;
//    }
    // Overriding non-final method eat()
    void eat() override {
        cout << "Dog is eating kibble." << endl;
    }
};

class ImmutablePoint final {
private:
    int x, y;
public:
    ImmutablePoint(int x_, int y_) : x(x_), y(y_) {}

    int getX() const { return x; }
    int getY() const { return y; }
};

// Attempt to subclass final class (compile error)
// Uncommenting below will produce:
// error: cannot derive from 'final' class 'ImmutablePoint'
// class ColoredPoint : public ImmutablePoint {
// public:
//     ColoredPoint(int x, int y, string color)
//         : ImmutablePoint(x, y), color(color) {}
// private:
//     string color;
// };

int main() {
    cout << "--- Demonstrating final methods ---" << endl;

    Animal* myAnimal = new Animal();
    myAnimal->makeSound();
    myAnimal->eat();
    delete myAnimal;

    Dog* myDog = new Dog();
    myDog->makeSound(); // Calls Animal's final method
    myDog->eat();       // Calls Dog's overridden method
    delete myDog;
    cout << "(Note: Attempting to override makeSound() in Dog would cause a compilation error.)" << endl;

    cout << "\n--- Demonstrating final classes ---" << endl;
    ImmutablePoint p(10, 20);
    cout << "Point: (" << p.getX() << ", " << p.getY() << ")" << endl;
    cout << "(Note: Attempting to inherit from ImmutablePoint would cause a compilation error.)" << endl;

    // Uncomment above ColoredPoint definition for compile error demonstration
    return 0;
}