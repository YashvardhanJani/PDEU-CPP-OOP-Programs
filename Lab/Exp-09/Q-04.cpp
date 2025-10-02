#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <limits> // for clearing input buffer
using namespace std;

class Student {
private:
    int id;
    string name;
    double gpa;

public:
    Student(int id, string name, double gpa) {
        this->id = id;
        this->name = name;
        this->gpa = gpa;
    }
    // Also write as: Student(int i, const string &n, double g) : id(i), name(n), gpa(g) {}


    // Default constructor (needed for file loading)
    Student() : id(0), name(""), gpa(0.0) {}

    void displayStudent() const {
        cout << "ID: " << id << "| Name: " << name << "| GPA: " << gpa << endl;
    }

    // File save helper
    void saveToFile(ofstream &out) const {
        out.write(reinterpret_cast<const char*>(&id), sizeof(id));  // Write ID
        out.write(reinterpret_cast<const char*>(&gpa), sizeof(gpa));// Write GPA
        size_t nameLength = name.size(); // Write string length and data (name)
        out.write(reinterpret_cast<const char*>(&nameLength), sizeof(nameLength));
        out.write(name.c_str(), nameLength);
    }

    // File load helper
    void loadFromFile(ifstream &in) {
        in.read(reinterpret_cast<char*>(&id), sizeof(id));   // Read ID
        in.read(reinterpret_cast<char*>(&gpa), sizeof(gpa)); // Read GPA
        size_t nameLength;  // Read string length
        in.read(reinterpret_cast<char*>(&nameLength), sizeof(nameLength));
        char *buffer = new char[nameLength + 1];  // Read characters
        in.read(buffer, nameLength);
        buffer[nameLength] = '\0';
        name = string(buffer);
        delete[] buffer;
    }
};

int main() {
    vector<Student> students;
    int choice;

    while (true) {
        cout << "\nStudent Manager Menu:\n";
        cout << "1. Add Student\n";
        cout << "2. List Students\n";
        cout << "3. Save Students\n";
        cout << "4. Load Students\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail()) { 
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Try again.\n";
            continue;
        }

        if (choice == 1) {
            int id;
            string name;
            double gpa;

            cout << "Enter Student ID: ";
            cin >> id;
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear buffer

            cout << "Enter Student Name: ";
            getline(cin, name);

            cout << "Enter Student GPA: ";
            cin >> gpa;

            students.push_back(Student(id, name, gpa));
            cout << "Student added.\n";
        } 
        else if (choice == 2) {
            cout << "Listing Students:\n";
            if (students.empty()) {
                cout << "No students available.\n";
            } else {
                for (const auto &student : students) {
                    student.displayStudent();
                }
            }
        } 
        else if (choice == 3) {
            ofstream outFile("students.dat", ios::binary);
            if (!outFile) {
                cout << "Error opening file for writing.\n";
            } else {
                for (const auto &student : students) {
                    student.saveToFile(outFile);
                }
                cout << "Students saved to students.dat.\n";
            }
        } 
        else if (choice == 4) {
            ifstream inFile("students.dat", ios::binary);
            if (!inFile) {
                cout << "Error opening file for reading.\n";
            } else {
                students.clear(); // Replace existing data
                while (inFile.peek() != EOF) {
                    Student s;
                    s.loadFromFile(inFile);
                    if (inFile) // avoid pushing incomplete reads
                        students.push_back(s);
                }
                cout << "Students loaded from students.dat.\n";
            }
        } 
        else if (choice == 5) {
            cout << "Exiting program.\n";
            break;
        } 
        else {
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}