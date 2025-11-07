#include <iostream>
using namespace std;

class DynamicArray {
private:
    int* arr;   // Pointer to dynamically allocated array
    int size;   // Size of array

public:
    DynamicArray(int s) {
        size = s;
        arr = new int[size]; // Dynamic allocation
        for (int i = 0; i < size; i++)
            arr[i] = 0; // Initialize to 0
        cout << "DynamicArray constructor called for size " << size << "." << endl;
    }

    ~DynamicArray() {
        cout << "DynamicArray destructor called for size " << size << "." << endl;
        delete[] arr;   // Free dynamically allocated memory
        arr = nullptr;  // Prevent dangling pointer
    }

    // Method to set element at specific index
    void setElement(int index, int value) {
        if (index >= 0 && index < size)
            arr[index] = value;
        else
            cout << "Error: Index " << index << " out of bounds!" << endl;
    }

    // Method to get element at specific index
    int getElement(int index) {
        if (index >= 0 && index < size)
            return arr[index];
        else {
            cout << "Error: Index " << index << " out of bounds!" << endl;
            return -1;
        }
    }

    void displayArray() {
        for (int i = 0; i < size; i++) {
            cout << "Element at index " << i << ": " << arr[i] << endl;
        }
    }
};

int main() {
    // Create first dynamic array
    DynamicArray arr1(5);
    arr1.setElement(0, 10);
    arr1.setElement(1, 20);
    arr1.setElement(4, 50);

    // Create second dynamic array
    DynamicArray arr2(3);
    arr2.setElement(0, 100);
    arr2.setElement(2, 300);

    cout << "\nArray 1:\n";
    arr1.displayArray();

    cout << "\nArray 2:\n";
    arr2.displayArray();

    return 0;
}