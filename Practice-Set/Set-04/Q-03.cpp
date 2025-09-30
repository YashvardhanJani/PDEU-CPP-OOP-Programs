/*
Exam Result Statistics

Platform style: LeetCode Design Problem

Statement:
You are creating an exam result tracker for a school. The tracker must:
1.	Count the total number of students who have appeared.
2.	Maintain the average score across all students.

Each Student object has:
•	name (string)
•	score (int)

Requirements:
•	Use static data members:
o	totalStudents
o	totalScore
•	Use a static member function getAverageScore() to return the class average as a double.

Input: N
<name> <score>
(repeat N times)

Static usage:
•	Constructor updates totalStudents and totalScore.
•	Average score calculated directly in the static function without needing any object.
*/

#include <bits/stdc++.h>
using namespace std;

class Student {  
public:
    // Non-static members
    string name;
    int score;

    // Static data member 
    static int totalStudents;
    static int totalScore;    

    // Default Constructor
    Student() {
        name = "";
        score = 0;
    }

    // Parameterized Constructor
    Student(string n, int s) {
        name = n;
        score = s;
        totalStudents++;
        totalScore+=s;
    }
    
    // Static member function
    static double getAverageScore() {
        if (totalStudents == 0) return 0.0;
        return (double)totalScore/totalStudents;
    }
};

// Definition of static members
int Student::totalStudents = 0;
int Student::totalScore = 0;

int main()
{
    int num;
    cout << "Enter number of Students: ";
    cin >> num;

    Student students[100]; // Fixed-size array, supports up to 100 students

    // Input Name & Score of each Student
    for (int i=0;i<num;i++) {
        string name;
        int score;
        cout << "\nEnter name & score of student (separated by space): ";
        cin >> name >> score;
        students[i] = Student(name,score);
    }

    cout << "\nTotal Students: " << Student::totalStudents << endl;
    cout << "Average Score: " << Student::getAverageScore() << endl;

    return 0;
}