#include <iostream>
#include <typeinfo>
#include <stdexcept>
using namespace std;

// Template function for index checking
template <typename T>
void checkIndex(int index, int size, const char* context) {
    if (index < 0 || index >= size)
        throw out_of_range(context);
}

// Template class definition
template <typename T>
class MyArray {
private:
    T* arr;
    int size;

public:
    MyArray(int s) : size(s) {
        arr = new T[size];
        cout << "MyArray<" << typeid(T).name() << "> created with size " << size << "." << endl;
    }

    ~MyArray() {
        delete[] arr;
        cout << "MyArray<" << typeid(T).name() << "> destructor called." << endl;
    }

    void setElement(int index, const T& value) {
        checkIndex<T>(index, size, "Index out of bounds for setElement.");
        arr[index] = value;
    }

    T getElement(int index) const {
        checkIndex<T>(index, size, "Index out of bounds for getElement.");
        return arr[index];
    }
};

int main() {
    // Demonstrate MyArray<int>
    MyArray<int> intArray(5);
    try {
        intArray.setElement(0, 10);
        cout << "Element at index 0: " << intArray.getElement(0) << endl;
        intArray.setElement(4, 50);
        cout << "Element at index 4: " << intArray.getElement(4) << endl;

        cout << "\nAttempting to access out of bounds for intArray:" << endl;
        cout << intArray.getElement(5) << endl;
    } catch (const out_of_range& e) {
        cout << "Caught exception: " << e.what() << endl;
    }

    cout << endl;

    // Demonstrate MyArray<double>
    MyArray<double> doubleArray(3);
    try {
        doubleArray.setElement(1, 3.14);
        cout << "Element at index 1: " << doubleArray.getElement(1) << endl;

        cout << "\nAttempting to set out of bounds for doubleArray:" << endl;
        doubleArray.setElement(5, 2.71);
    } catch (const out_of_range& e) {
        cout << "Caught exception: " << e.what() << endl;
    }

    cout << endl;

    return 0;
}