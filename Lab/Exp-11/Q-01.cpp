#include <iostream>
#include <vector>
#include <numeric>  // For std::accumulate (optional for average calculation)
using namespace std;

int main() {
    int numStudents;
    vector<double> studentMarks;  
    cout << "Enter the number of students: ";
    cin >> numStudents;

    for (int i = 0; i < numStudents; i++) {
        double mark;
        cout << "Enter mark for student " << i + 1 << ": ";
        cin >> mark;
        studentMarks.push_back(mark);  // Add to vector
    }

    cout << "\nStudent Marks: ";
    for (double mark : studentMarks) {
        cout << mark << " ";
    }
    cout << endl;

    if (!studentMarks.empty()) {
        double sum = accumulate(studentMarks.begin(), studentMarks.end(), 0.0);
        double average = sum / studentMarks.size();
        cout << "Average Mark: " << average << endl;
    }

    return 0;
}
