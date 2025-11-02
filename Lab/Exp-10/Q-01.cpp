#include <iostream>
#include <string>
using namespace std;

template <typename T>
T findMax(T val1, T val2, T val3) {
    if (val1 > val2 && val1 > val3) return val1;
    else if (val2 > val1 && val2 > val3) return val2;
    else if (val3 > val1 && val3 > val2) return val3;
    else return -1;
}


int main()
{
    int i1 = 10, i2 = 25, i3 = 15;
    cout << "Maximum of (10, 25, 15): " << ((findMax(i1,i2,i3)== -1) ? false : findMax(i1,i2,i3)) << endl;
    double d1 = 3.14, d2 = 2.71, d3 = 5.0;
    cout << "Maximum of (3.14, 2.71, 5): " << findMax(d1,d2,d3) << endl;
    char c1 = 'X', c2 = 'A', c3 = 'Z';
    cout << "Maximum of (X, A, Z): " << findMax(c1,c2,c3) << endl;

    return 0;
}