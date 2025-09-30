// Write a C++ program to illustrate the usage of this pointer and base class member access.

#include<iostream>
#include<string>
using namespace std;

class Vehicle {
protected:
    string color;
    
public:
    Vehicle(string color){
        this->color = color;
        cout << "Vehicle constructor called.." << endl;
    }    

    void displayColor(){
        cout << "   Color: " << color << endl;
    }
};

class Car : public Vehicle {
private:
    string model;
    int year;

public:

    Car() : Car("White", "Unknown Model", 2023) {
        cout << "Car default constructor called (delegating)." << endl;
    }

    Car(string color, string model, int year) : Vehicle(color), model(model), year(year) {
        this->model = model;
        this->year = year;
        cout << "Car parameterized constructor called.." << endl;
    }    

    void displayCarDetails(){
        cout << "Car Details:" << endl;
        displayColor();
        cout << "   Model: " << model << endl;
        cout << "   Year: " << year << endl;
    }
};

int main()
{
    Car c1("Black", "Sedan", 2025);
    c1.displayCarDetails();
    Car c2;
    c2.displayCarDetails();

    return 0;
}