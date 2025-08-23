// Demonstrate the difference between Vectors and Arrays in C++ with a suitable example.

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // Array example
    int arr[5] = {1, 2, 3, 4, 5};
    cout << "Array elements: ";
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Vector example
    vector<int> vec = {1, 2, 3, 4, 5};
    cout << "Vector elements: ";
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;

    // push back element to vector (Dynamic resizing of vector)
    vec.push_back(6);
    cout << "Vector after push_back: ";
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;

    cout << "-> Size of Array is Static!" << endl;

    return 0;
}