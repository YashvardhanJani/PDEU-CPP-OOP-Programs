/*
Create a Student class with:
•	Default constructor setting name to "Unknown" and marks to 0.
•	Parameterized constructor that accepts name and marks.
•	Display function to print student details.
Task:
•	Create multiple student objects using different constructors.
•	Show constructor overloading in action.
*/

#include<bits/stdc++.h>
using namespace std;

class Student {
    const char *name;
    double marks;
    int roll_no;

public:
    Student(){
        name = new char[8];
        name = "Unknown";
        marks = 0;
        roll_no = 0; 
    }

    Student(const char *n, double m, int roll){
        name = n;
        marks = m;
        roll_no = roll;
    }

    void displayDetails(){
        cout << "Roll No: " << roll_no << " , Name: " << name << " , Marks: " << marks << endl;
    }

    ~Student(){
        delete name;
    }
};

int main()
{
    Student s1("Anirudh", 99, 101);
    Student s2("Maharshi", 98, 102);
    s1.displayDetails();
    s2.displayDetails();
    return 0;
}