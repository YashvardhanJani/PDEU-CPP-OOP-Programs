/* [OOP Practical Eaxm 2025 - Set 02]
a) Develop a C++ program using Object-Oriented Programming concepts
to perform the following tasks:
Define a base class Employee with data members emplD, name and a static data member
count to keep track of the total number of employees created.
b) Create a parameterized constructor in Employee to initialize the data members and increment
count each time a new object is created. Also create a destructor for the class displaying
an appropriate message.
c) Derive a class Manager from Employee. Use constructor delegation to call the base class
constructor from the derived class constructor. Add a protected data member department in the
derived class. Also create a destructor for the derived class displaying an appropriate message.
d) In the main() function:
Create three Manager objects by taking input from the user for emplD, name and department.
Display each manager's details.
Finally, display the total number of employees created using the static member.
*/

#include <iostream>
using namespace std;

class Employee {
protected:
    int empID;
    string name;
    static int count;   

public:
    Employee(int id, string n) {
        empID = id;
        name = n;
        count++;
        cout << "Employee Constructor Called\n";
    }

    void displayEmployee() {
        cout << "Employee ID   : " << empID << endl;
        cout << "Employee Name : " << name << endl;
    }

    static int getCount() {
        return count;
    }

    ~Employee() {
        cout << "Employee Destructor Called for ID: " << empID << endl;
    }
};

int Employee::count = 0;

class Manager : public Employee {
protected:
    string department;

public:
    // Constructor delegation to base class
    Manager(int id, string n, string dept)
        : Employee(id, n) {
        department = dept;
        cout << "Manager Constructor Called\n";
    }

    void displayManager() {
        displayEmployee();
        cout << "Department    : " << department << endl;
        cout << "---------------------------\n";
    }

    ~Manager() {
        cout << "Manager Destructor Called\n";
    }
};

int main() {
    int id;
    string name, dept;

    Manager* m[3];

    for (int i = 0; i < 3; i++) {
        cout << "\nEnter details for Manager " << i + 1 << endl;
        cout << "Employee ID: ";
        cin >> id;
        cin.ignore();

        cout << "Name: ";
        getline(cin, name);

        cout << "Department: ";
        getline(cin, dept);

        m[i] = new Manager(id, name, dept);
    }

    cout << "\n--- Manager Details ---\n";
    for (int i = 0; i < 3; i++) {
        m[i]->displayManager();
    }

    cout << "Total Employees Created: "
         << Employee::getCount() << endl;

    for (int i = 0; i < 3; i++) {
        delete m[i];
    }

    return 0;
}