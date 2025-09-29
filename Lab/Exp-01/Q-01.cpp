// Write a C++ program to calculate and display the grade of a student based on marks in 5 subjects.

#include <iostream>
using namespace std;    

int main() {
    int marks[5];
    int total = 0;
    float average;

    cout << "Enter marks for 5 subjects: ";
    for (int i = 0; i < 5; i++) {
        cin >> marks[i];
        total += marks[i];
    }

    average = total / 5.0;

    cout << "Total Marks: " << total << endl;
    cout << "Average Marks: " << average << endl;

    if (average >= 90)
        cout << "Grade: A" << endl;
    else if (average >= 80)
        cout << "Grade: B" << endl;
    else if (average >= 70)
        cout << "Grade: C" << endl;
    else if (average >= 60)
        cout << "Grade: D" << endl;
    else if (average >= 50)
        cout << "Grade: E" << endl;
    else
        cout << "Grade: F" << endl;

    return 0;
}