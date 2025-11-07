#include <iostream>
#include <string>
using namespace std;

class Product {
private:
    int id;
    string name;

public:
    Product(int id, string name) {
        this->id = id;
        this->name = name;
        cout << "Parameterized constructor called: ID=" << id
             << ", Name=" << name << endl;
    }

    // Default constructor delegating to parameterized one
    Product() : Product(0, "Unknown") { 
        cout << "Default constructor called, delegating to parameterized." << endl;
    }

    void displayProduct() {
        cout << "Product ID: " << id << ", Name: " << name << endl;
    }
};

int main() {
    Product p1;                // Calls default (delegates)
    p1.displayProduct();

    cout << endl;

    Product p2(101, "Laptop"); // Calls parameterized directly
    p2.displayProduct();

    return 0;
}