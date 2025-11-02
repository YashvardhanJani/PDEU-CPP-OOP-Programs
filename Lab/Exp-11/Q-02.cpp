#include <iostream>
#include <string>
#include <map>
#include <set>
#include <limits>  // For std::numeric_limits
using namespace std;

class Student {
private:
    int id;
    string name;
    double gpa;

public:
    Student(int i = 0, string n = "", double g = 0.0)
        : id(i), name(n), gpa(g) {}

    void displayStudent() const {
        cout << "ID: " << id << ", Name: " << name << ", GPA: " << gpa << endl;
    }

    int getId() const { return id; }
};

int main() {
    map<int, Student> studentRecords;  
    set<string> uniqueNames;           
    int choice;

    do {
        cout << "\n=== Student Record Manager ===\n";
        cout << "1. Add Student\n";
        cout << "2. Search by ID\n";
        cout << "3. Check Name Existence\n";
        cout << "4. Display All Students\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // Clear invalid input
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a number.\n";
            continue;
        }

        switch (choice) {
            case 1: {
                int id;
                string name;
                double gpa;

                cout << "Enter Student ID: ";
                cin >> id;

                // Check if student ID already exists
                if (studentRecords.find(id) != studentRecords.end()) {
                    cout << "Student with ID " << id << " already exists. Update not performed.\n";
                    break;
                }

                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
                cout << "Enter Student Name: ";
                getline(cin, name);
                cout << "Enter Student GPA: ";
                cin >> gpa;

                // Create and insert Student object
                Student s(id, name, gpa);
                studentRecords.insert({id, s});
                uniqueNames.insert(name);

                cout << "Student added.\n";
                break;
            }

            case 2: {
                int searchId;
                cout << "Enter Student ID to search: ";
                cin >> searchId;

                auto it = studentRecords.find(searchId);
                if (it != studentRecords.end()) {
                    cout << "Student Found: ";
                    it->second.displayStudent();
                } else {
                    cout << "Student not found.\n";
                }
                break;
            }

            case 3: {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                string searchName;
                cout << "Enter Student Name to check: ";
                getline(cin, searchName);

                if (uniqueNames.count(searchName)) {
                    cout << "Name '" << searchName << "' exists.\n";
                } else {
                    cout << "Name '" << searchName << "' does not exist.\n";
                }
                break;
            }

            case 4: {
                if (studentRecords.empty()) {
                    cout << "No student records found.\n";
                } else {
                    cout << "--- All Students (Sorted by ID) ---\n";
                    for (const auto& pair : studentRecords) {
                        pair.second.displayStudent();
                    }
                }
                break;
            }

            case 5:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice! Please enter a valid option.\n";
        }

    } while (choice != 5);

    return 0;
}