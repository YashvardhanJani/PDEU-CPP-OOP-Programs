// WAP program to create Array class, also use Generic Programming Techaniques.

#include <iostream>
#include <string>
using namespace std;

// Generic Array class using Template
template <typename T>
class Array {
private:
    T* arr;   // pointer to dynamic array
    int size; // size of the array
    string typeName; // to store type name

public:
    // Constructor
    Array(int s, string tname) {
        size = s;
        typeName = tname;
        arr = new T[size];
    }

    // Destructor
    ~Array() {
        delete[] arr;
    }

    // Function to input elements
    void inputElements() {
        cout << "\nEnter " << size << " elements for " << typeName << ": ";
        for (int i = 0; i < size; i++) {
            cin >> arr[i];
        }
    }

    // Function to display elements
    void displayElements() const {
        cout << "\n" << typeName << " elements are: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Get element by index
    T getElement(int index) const {
        if (index >= 0 && index < size)
            return arr[index];
        else {
            cout << "Index out of range!" << endl;
            return T(); // default value of T
        }
    }

    // Set element by index
    void setElement(int index, T value) {
        if (index >= 0 && index < size)
            arr[index] = value;
        else
            cout << "Index out of range!" << endl;
    }
};

// Driver code
int main() {
    int choice, n;

    cout << "Choose data type for Array:\n";
    cout << "1. Integer\n2. Float\n3. Character\n4. String\n";
    cout << "Enter your choice: ";
    cin >> choice;

    cout << "Enter size of array: ";
    cin >> n;

    switch (choice) {
        case 1: {
            Array<int> a(n, "Integer Array");
            a.inputElements();
            a.displayElements();
            break;
        }
        case 2: {
            Array<float> a(n, "Float Array");
            a.inputElements();
            a.displayElements();
            break;
        }
        case 3: {
            Array<char> a(n, "Character Array");
            a.inputElements();
            a.displayElements();
            break;
        }
        case 4: {
            Array<string> a(n, "String Array");
            a.inputElements();
            a.displayElements();
            break;
        }
        default:
            cout << "Invalid choice!" << endl;
    }

    return 0;
}