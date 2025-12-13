/* [OOP Practical Eaxm 2025 - Set 03]
Write a C++ program using the following specifications:
a) Create a class Student with: Data members: roll, name
Default constructor, Parameterized constructor
Destructor that prints: "Destroying Student object: <roll>"
b) Create another class Marks with: Data members: ml, m2, m3 (three subject marks)
Parameterized constructor
Destructor that prints: "Destroying Marks object"
c) Create a friend function. This function should:
Access private members of both classes
Calculate total marks and percentage
Display all details in formatted output
d) In main():
Create one Student object using parameterized constructor
Create one Marks object using parameterized constructor
Call the friend function to display the total and percentage
*/

#include <iostream>
using namespace std;

class Marks;   // Forward declaration

class Student {
private:
    int roll;
    string name;

public:
    Student() {
        roll = 0;
        name = "NULL";
    }

    Student(int r, string n) {
        roll = r;
        name = n;
    }

    // Friend Function Declaration
    friend void displayResult(Student, Marks);

    ~Student() {
        cout << "Destroying Student object: " << roll << endl;
    }
};

class Marks {
private:
    int m1, m2, m3;

public:
    Marks(int a, int b, int c) {
        m1 = a;
        m2 = b;
        m3 = c;
    }

    // Friend Function Declaration
    friend void displayResult(Student, Marks);

    ~Marks() {
        cout << "Destroying Marks object" << endl;
    }
};

// Friend Function Definition 
void displayResult(Student s, Marks m) {
    int total;
    float percentage;

    total = m.m1 + m.m2 + m.m3;
    percentage = total / 3.0;

    cout << "\n----- Student Result -----\n";
    cout << "Roll No     : " << s.roll << endl;
    cout << "Name        : " << s.name << endl;
    cout << "Marks 1     : " << m.m1 << endl;
    cout << "Marks 2     : " << m.m2 << endl;
    cout << "Marks 3     : " << m.m3 << endl;
    cout << "Total Marks : " << total << endl;
    cout << "Percentage  : " << percentage << " %" << endl;
    cout << "***************************"<< endl;
}

int main() {
    Student s1(101, "Devhuti");
    Marks m1(100, 98, 97);

    displayResult(s1, m1);

    return 0;
}