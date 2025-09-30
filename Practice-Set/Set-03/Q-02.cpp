// [Star-Problem]
// Write a C++ program to implement a class called Date that has private member variables for day, month, and year. Include member functions to set and get these variables, as well as to validate if the date is valid.

#include<bits/stdc++.h>
using namespace std;

class Date {
private:
    int day,month,year;

public:
    Date(int d, int m, int y){
            day = d;
            month = m;
            year = y;
            if (validate(day,month,year)) cout << "Date is valid." << endl;
            else {
                cout<<"Invalid Date!!" << endl;
                day = month = year = 0;
            }    
        }

    bool isleap(int year){
            if ((year%4 == 0 && year%100 != 0)|| (year%400 == 0)) return true;
            else return false;
    }  

    bool validate(int day, int month, int year) {
            int daysInMonth[12] = {31,(isleap(year)?29:28),31,30,31,30,31,31,30,31,30,31};
            if(year>0 && 0<month<13 && day>0 && day<=daysInMonth[month-1]) return true;
            else return false;
        }
    
    // Set new date
    void setDate(int d, int m, int y) {
        if (validate(d, m, y)) {
            day = d;
            month = m;
            year = y;
            cout << "Date updated successfully." << endl;
        } else {
            cout << "Invalid date, update failed!" << endl;
        }
    }  
    
    // Getter
    void getDate() {
        if (day == 0 && month == 0 && year == 0)
            cout << "No valid date stored." << endl;
        else
            cout << setw(2) << setfill('0') << day << "/" << setw(2) << setfill('0') << month << "/" << year << endl; // 5/7/2005 is also valid after using setw & setfill
    }

    ~Date(){}
};

int main()
{
    int d, m, y;
    char sep;  // for '/' separator

    cout << "Enter date (dd/mm/yyyy): ";
    cin >> d >> sep >> m >> sep >> y;

    Date d1(d, m, y);

    cout << "Stored date: ";
    d1.getDate();

    return 0;
}