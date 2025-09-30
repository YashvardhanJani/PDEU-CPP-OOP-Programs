/*
Employee Salary Tracker

Platform style: HackerRank / GFG

Statement:
You need to track employee salaries for a company. The system should:
1.	Keep a record of the total salary paid to all employees.
2.	Keep track of the highest individual salary.

Each Employee object has:
•	name (string)
•	salary (int)

Requirements:
•	Use static data members to store:
o	totalSalaryPaid
o	highestSalary
•	Use a static member function getCompanyStats() to return (totalSalaryPaid, highestSalary).

Input: N
<name> <salary>
(repeat N times)

Static usage:
•	Update totals and highest salary in each constructor call.
•	Call the static function to retrieve final stats without needing an extra object.
*/

#include <bits/stdc++.h>
using namespace std;

class Employee {
public:
    // Non-static members
    string name;
    int salary;

    // Static members
    static long long totalSalaryPaid;
    static int highestSalary;

    // Default Constructor
    Employee() {
        name = "";
        salary = 0;
    }

    // Parameterized Constructor
    Employee(string n, int s) {
        name = n;
        salary = s;
        totalSalaryPaid += s;
        if (s>highestSalary) {
            highestSalary = s;
        }

    }

    // Static member function
    static pair<long long,int> getCompanyStats() {
        return {totalSalaryPaid, highestSalary};
    }
};

// Definition of Static members
long long Employee::totalSalaryPaid = 0;
int Employee::highestSalary = 0;

int main()
{
    int num;
    cout << "Enter the number of Employees: ";
    cin >> num;

    Employee employees[100]; // Fixed-size array, max 100 employees

    // Input Name & Salary of each Employee
    for (int i=0;i<num;i++) {
        string name;
        int salary;
        cout << "\nEnter name & salary of employee (separated by space): ";
        cin >> name >> salary;
        employees[i] = Employee(name,salary);
    }

    // Display Total Salary Paid & Highest Salary
    auto stats = Employee::getCompanyStats();
    cout << "\nTotal Salary Paid: " << stats.first << "\n";
    cout << "Highest Salary: " << stats.second << "\n";

    // Display names of Employee(s) with highest salary
    cout << "Employee(s) with highest salary: ";
    for (int i = 0; i < num; i++) {
        if (employees[i].salary == Employee::highestSalary) {
            cout << employees[i].name << "  ";
        }
    }

    return 0;
}