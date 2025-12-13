#include <iostream>
using namespace std;

class Employee {
protected:
    int empId;
    string name;

public:
    virtual void getData() {
        cout << "Enter Employee ID: ";
        cin >> empId;
        cin.ignore();

        cout << "Enter Name: ";
        getline(cin, name);
    }

    virtual void displayData() {
        cout << "Employee ID : " << empId << endl;
        cout << "Name        : " << name << endl;
    }

    virtual ~Employee() {}
};

class Salary : public Employee {
protected:
    float basic, hra, da;

public:
    void getSalary() {
        cout << "Enter Basic Salary: ";
        cin >> basic;
        cout << "Enter HRA: ";
        cin >> hra;
        cout << "Enter DA: ";
        cin >> da;
    }

    void displaySalary() {
        cout << "Basic Salary : " << basic << endl;
        cout << "HRA          : " << hra << endl;
        cout << "DA           : " << da << endl;
    }
};

class NetSalary : public Salary {
private:
    float gross, tax, net;

public:
    void calculate() {
        cout << "Enter Tax: ";
        cin >> tax;

        gross = basic + hra + da;
        net = gross - tax;
    }

    void displayData() override {
        cout << "\n--- Employee Payroll Details ---\n";
        cout << "Employee ID : " << empId << endl;
        cout << "Name        : " << name << endl;
        cout << "Basic       : " << basic << endl;
        cout << "HRA         : " << hra << endl;
        cout << "DA          : " << da << endl;
        cout << "Gross Salary: " << gross << endl;
        cout << "Net Salary  : " << net << endl;
        cout << "--------------------------------\n";
    }
};

int main() {
    Employee* emp;
    NetSalary n;
    emp = &n;
    n.getData();
    n.getSalary();
    n.calculate();

    // Runtime polymorphism
    emp->displayData();
    return 0;
}